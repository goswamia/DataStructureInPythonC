#!/usr/bin/env python
"""
create vector gen file based on engineer input
"""
import argparse
import glob
import math
import collections
import Run
import os
import subprocess
import sys
import shutil
import techinfo

def parse_args(argv):
    """Parse the argument"""
    parser = argparse.ArgumentParser(description=__doc__,
                                     epilog=""" Please drop mail logic-sw@synopsys.com for reporting any issue""",
                                     formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('-p', '--props', dest='props', required=True,
                        help="Provide Properties file full path")
    parser.add_argument('-wd', '--workdir', dest='wd', default="vector_work",
                        help="create vector genrate work data")
    parser.add_argument('-gp', '--gcell_path', dest='gpath', required=True,
                        help="Provide gcell path")
    parser.add_argument('-dest','--destion_place', dest='dest',
                        help="Place vector file into destination place")
    parser.add_argument('-pg', '--properies_generate', action='store_true', 
                        dest='pg',
                        help="properties generation based on some equation")
    args = parser.parse_args(argv)
    return args

class vector(object):
    """
    create vector class template
    """
    def __init__(self, props_data, prop):
        self.vector_file = []
        self.props_data = props_data
        self.prop = prop

    def create_clock_header(self):
        """
        creating clock header file
        """
        header = """
`ifndef CLOCK_GEN
`define CLOCK_GEN
module clock_gen(CLK);
   output CLK;
   reg    CLK;


   parameter t_start = 0.0;
   parameter t_high = 10.0;
   parameter t_low = 10.0;

   initial
     begin
        CLK <= 1'b0;
        #(t_start);
        forever
          begin
             CLK <= 1'b1;
             #(t_high);
             CLK <= 1'b0;
             #(t_low);
          end
     end // initial begin

endmodule // clock_gen
`endif
"""
        with open("clock.sv", "w") as fp:
            fp.write(header)

    def create_header(self):
        """
        Header of file
        """
        self.create_clock_header()
        header = """`include "clock.sv" \n """
        self.vector_file.append(header)

    def create_module_section(self):
        """
        module section
        """
        data = """
module vecfile;
        reg  {req};
        wire {wire};
        event trigger;
        integer vec_count;
        integer fh1;
        integer i, temp_value;
        wire {wire1};
        """
        for key in self.props_data:
            module_init = { 'req' : self.prop.GenericCells[key].Inputs,
                            'wire' : self.prop.GenericCells[key].Outputs,
                            'wire1' : ",".join(self.props_data[key]['clock'].keys())
                          }
            self.vector_file.append(data.format(**module_init))

    def create_clock_section(self):
        """
        create clock section
        """
        data = """
        clock_gen #({start}, {low}, {high}) CLK_INST_{index} (.CLK({clk})); """
        for key in self.props_data:
            clk = self.props_data[key]['clock']
            index = 0
            for clk_name in clk.keyorder:
                clk_data = {'start' : self.props_data[key]['clock'][clk_name]['start'],
                            'low' : self.props_data[key]['clock'][clk_name]['low'],
                            'high' : self.props_data[key]['clock'][clk_name]['high'],
                            'index' : index,
                            'clk' : clk_name
                            }
                self.vector_file.append(data.format(**clk_data))
                index += 1
            #Instantiate verilog model
            In = self.prop.GenericCells[key].Inputs.split(",")
            Ou = self.prop.GenericCells[key].Outputs.split(",")
            Outpin_data = ""
            for ou in Ou:
                Outpin_data += ".%s(%s), " %(ou, ou)
            Input_pin_data = ""
            for index, input_pin in enumerate(In):
                Input_pin_data += ".%s(%s)" %(input_pin, input_pin)
                if index < len(In)-1:
                    Input_pin_data += ","
            data = """
        %s_cell %s_INST (%s %s); 
            """ %(key, key.upper(), Outpin_data, Input_pin_data)
            self.vector_file.append(data)
            
            sim_data_deck = """
        task display_header;
        begin
        $fdisplay(fh1,";***************************************************");
        $fdisplay(fh1," radix {length}");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"vname  {pin_data}");
        $fdisplay(fh1,";****************************************************");
        $fdisplay(fh1,"{pin_info}");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"tunit ps");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"tdelay 10");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"odelay %%%%\(ODELAY_VAL\)");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"TRISE %%%%\(TRISE_VAL\)");
        $fdisplay(fh1,"TFALL %%%%\(TFALL_VAL\)");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"VIH CORE_Vdd");
        $fdisplay(fh1,"VIL CORE_Vss");
        $fdisplay(fh1,"VOH CORE_Voh");
        $fdisplay(fh1,"VOL CORE_Vol");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,"VTH CORE_ViTh");
        $fdisplay(fh1,";*****************************************************");
        $fdisplay(fh1,";*****************************************************");
         end
        endtask
        """
        pin_data_info =""
        for pin_data in In + Ou:
            pin_data_info += "%%%%%%%%\(PIN_%s\)  " %(pin_data)
        sim_data = {
                'length' : " ".join(map(str, [1] * (len(In) + len(Ou)))),
                'pin_data' : pin_data_info,
                'pin_info' : ("io " + " ".join(["i" for _ in range(0, len(In),1)])+
                              " ".join([" o" for _ in range(0, len(Ou), 1)]))
                   }
        self.vector_file.append(sim_data_deck.format(**sim_data))

    def create_task_section(self):
        """
        Overview : create task section
        """
        task_deck = """
        task apply{pin};
         input value;
         begin
         @(posedge {clk});
         {pin} <= value;
          end
        endtask"""
        always_deck = """
        
        always@(%(clk)s)
        begin
        %(ck)s <= %(clk)s;
        end
        
        """

        always_posedge_section = """
        always@(
        """

        #always@(posedge {clk1} or posedge {clk2} or posedge {clk3} or posedge {clk4}
        #or posedge {clk5} or negedge {clk5})
        always_pos = """
        begin
        vec_count = vec_count + 1;
        ->trigger;
        end
        
        always@(trigger)
        begin
        $fdisplay(fh1, "%d*%%%%(TSTEP_VAL)\t{In_format}", vec_count, {In});
        end
        """
        clk_name_data = dict()
        for key in self.props_data:
            clk = self.props_data[key]['clock']
            for clk_name in clk.keyorder:
                pin_info = self.props_data[key]['clock'][clk_name]['Pin']
                clk_name_data.setdefault('clk_posedge', []).append(clk_name)
                if pin_info == "," or not pin_info:
                    continue
                task_data = {'clk' : clk_name,  
                             'pin' : pin_info
                             }
                self.vector_file.append(task_deck.format(**task_data))
            clk_name_data['In'] = self.prop.GenericCells[key].Inputs + "," + self.prop.GenericCells[key].Outputs

            clk_name_data['In_format'] = "%" + "%".join(['b' for i in range(0, len(clk_name_data['In'].split(",")))])
            neg_edge = self.props_data[key]['pos_neg_edge'].split(",")
            
            al = self.props_data[key].get('always',None)
            if al:
                al = al.split(",")
                self.vector_file.append(always_deck % {'clk': al[1],'ck' : al[0]})
            for posedge in clk_name_data['clk_posedge']:
                always_posedge_section += "posedge %s or " %(posedge)
            always_posedge_section += " negedge %s )" %(neg_edge[1])
            self.vector_file.append(always_posedge_section)
            self.vector_file.append(always_pos.format(**clk_name_data))

    def create_initial_section(self):
        """
        create initial section
        """
        initial_deck = """
        initial 
         begin
         vec_count = 0;
	    fh1 = $fopen("%s.vec", "w");
	    display_header();
        end
        initial
        begin
	    $dumpfile("test.vcd");
        $dumpvars;
        end
        initial
        begin
        for (i=0; i<%s; i=i+1)
	    fork
        """
        end_initial_deck = """
        for (i=0; i<%s; i=i+1)
         fork
          temp_value = $random;
          %s
         join
	  $finish;
        end
       endmodule
        """
        for key in self.props_data:
            lcom = int(math.pow(2, len(self.prop.GenericCells[key].Inputs.split(","))+1))
            self.vector_file.append(initial_deck %(key, lcom))
            data = "\t"
            tmp_section = ""
            clk = self.props_data[key]['clock']
            index = 0
            for clk_name in clk.keyorder:
                pin_info = self.props_data[key]['clock'][clk_name]['Pin']
                if pin_info == ",":
                    continue
                data += "  apply%s(i[%s]);\n\t\t" %(pin_info, index)
                tmp_section += "apply%s(temp_value[%s]);\n\t\t  " %(pin_info, index)
                index += 1
            data += "join\n"
            self.vector_file.append(data)
            self.vector_file.append(end_initial_deck % (lcom*2, tmp_section))

    def create_vector_file(self, fname):
        self.create_header()
        self.create_module_section()
        self.create_clock_section()
        self.create_task_section()
        self.create_initial_section()
        self.write_vector_file(fname)

    def write_vector_file(self, fname):
        """
        write vector file
        """
        with open(fname, "w+") as fp:
            fp.writelines(self.vector_file)

class Rtlvec(object):
    def __init__(self, gcell_path, props_data):
        """setup gcell path and props data"""
        self.gpath = gcell_path
        self.pdata = props_data
        self.create_rtl()

    def create_rtl(self):
        for key in self.pdata.keys():
            self.copy_require_data(key)

    def copy_require_data(self, key):
        """copy require info"""
        gcell = os.path.join(os.getcwd(), "gcells")
        os.makedirs(gcell)
        src = os.path.join(self.gpath, key)
        dst = os.path.join(gcell, key)
        shutil.copytree(src, dst)

    def run_cmd(self):
        """ Running command"""
        env = os.environ.copy()
        env["CLASSPATH"] = "/depotbld/RHEL5.5/antlr4-4.0/lib/antlr-4.0-complete.jar"
        cmd = "/slowfs/us01dwt2p106/char_scripts/latest/vecGen/genRtlv -i gcells"
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE, shell=True, env=env)
        out, err = proc.communicate()
        if err:
            print err
        proc.stdout.close()
        return proc.returncode


    def update_rtl(self):
        """update rtlv file"""
        for key in self.pdata.keys():
            fname = os.path.join(os.getcwd(), "gcells", key, key + ".rtlv")
            data = []
            with open(fname, "r") as fp:
                for line in fp:
                    line = line.replace('%','').replace("PIN_","")
                    if 'CELL_NAME' in line:
                        line = line.replace('CELL_NAME' ,key+"_cell")
                        line = line.replace("(","").replace(")","").replace(";","").strip()
                        line = line.split(" ",2)
                        line = line[0] + "  " + line[1] + "  (" + " ".join(line[2:]) + ")" + ";\n"
                    elif 'input' in line or 'output' in line or 'wire' in line:
                        line = line.replace("(","").replace(")","")
                    elif 'assign' in line:
                        line_split = line.split('=')
                        line_split[0] = line_split[0].replace("(","").replace(")","")
                        line = " = ".join(line_split)
                    data.append(line)
            with open(key+".v", "w") as fp:
                fp.writelines(data)

class Propsetup(object):
    """
    create and generate properties setup. Rest flow only read properties file 
    """
    def __init__(self, prop, props_data):
        """
        Initialize
        """
        self.prop = prop
        self.props_data = props_data

    def get_clk_info(self, key):
        """
        Input : key name
        extract clock name and remove clock info
        """
        clk = None
        inputs = self.prop.GenericCells[key].Inputs
        if 'CK' in inputs:
            inputs = inputs.replace('CK','').split(',')
            clk = 'CK'
        elif 'CLK' in inputs:
            inputs = inputs.replace('CLK','').split(',')
            clk = 'CLK'
        if isinstance(inputs, list):
            return filter(None, inputs), clk
        return filter(None, inputs).split(','), clk


    def prop_setup(self):
        """
        set prop file attribute and generate template
        """
        sf = "  "
        props_file = "vector_properties"
        upd_props_file = "Vector_flow\n"
        for key in self.props_data:
            clk_data = sf + "%s\n" %(key)
            inputs, clk_name = self.get_clk_info(key)
            clk_data += self.get_clock_info(key, inputs, clk_name)
            pins = self.prop.GenericCells[key].PinOrder
            clk_data = clk_data + sf*2 + "PinOrder" + sf + pins + sf + ";\n";
            if clk_name:
                clk_data = clk_data + sf*2 + "always" + sf +  "%s,clk%s" %(clk_name, len(inputs)+1) + sf + ";\n";
                clk_data = clk_data + sf*2 + "pos_neg_edge" + sf +  "CK,clk%s" %(len(inputs)+2) + sf + ";\n";
            else:
                clk_data = clk_data + sf*2 + "pos_neg_edge" + sf +  "CK,clk%s" %(len(inputs)+1) + sf + ";\n";

            clk_data = clk_data + sf + "END\n"
            upd_props_file += clk_data
        upd_props_file += "END\n"

        with open(props_file, "w") as fvector:
            fvector.write(upd_props_file)
        #load properties file
        self.prop.read(props_file)
        return get_props_data(self.prop)

    def get_clock_info(self, key, inputs, clk_name):
        """
        Overview : update clock table with start low high parameter
                   responsible for creating all combination
        """
        sf = "  "
        clk_table_format = sf*2 + "clk%s\t%s\t%s\t%s\t%s  ;\n"
        clk_data = sf*2 + "clock table\tstart\tlow\thigh\tPin\n"
        start = (len(inputs)+1)*5
        low = high = 2*start
        for index, pin in enumerate(inputs):
            clk_data += clk_table_format%(index+1, start, low, high, pin)
            start += 5

        if clk_name:
            clk_data += clk_table_format%(len(inputs)+1, start, low, high, ',')
            #Equaction for not overlap edge and cover possible scenario
            start = start - 1
            low -= 2
            high = 2
            clk_data += clk_table_format%(len(inputs)+2, start, low, high, ',')
        else:
            start = start-6 
            low -= 2
            high = 2
            clk_data += clk_table_format%(len(inputs)+1, start, low, high, ',')

        clk_data = clk_data + sf*2 + "END clock \n"
        return clk_data


def run_tool(fname, props_data):
    """
    This command run tool
    """
    for key in props_data.keys():
        cmd = ["vcs","-R", fname, key+".v"]
        print "command for vector generation %s" %(" ".join(cmd))
        with open("%s.log" % fname, "w") as fout:
            state = Run.Popen(cmd, stdout=fout, stderr=fout).wait()
            if state != 0:
                print("Error: Simulation falied. See details in "
                    "%s.lis(or .log) file." % fname)
                return 1
    return 0

def validate_props(props_data):
    """
    validate props data when receive properties as Inpupt
    """
    keyword = ['always', 'pos_neg_edge', 'clock']
    for key in props_data:
        for key_val in props_data[key]:
            keyword.remove(key_val)
    if keyword:
        print "Error %s section not defined into properties" %(keyword)
        return 1
    return 0

def setup(workdir):
    """
    Creating setup directory
    """
    if os.path.exists(workdir):
        shutil.rmtree(workdir)
    os.makedirs(workdir)
    os.chdir(workdir)

def get_props_data(props):
    p_data = collections.defaultdict(dict)
    vec_data = getattr(props, "Vector_flow", None)
    if not vec_data:
        return p_data
    for attr in vec_data.keyorder:
        attr_item = getattr(vec_data, attr)
        if not attr_item.keyorder:
            p_data[attr] = collections.defaultdict(dict)
            continue
        for item in attr_item.keyorder:
            p_data[attr][item] = getattr(attr_item, item)
    return p_data

def main(args):
    ti = techinfo.TechInfo()
    prop = ti.properties
    if not os.path.isfile(args.props):
        raise Exception( "%s file not found" %(args.props))
    fname = "test.sv"
    prop.read(os.path.abspath(args.props))
    setup(args.wd)
    props_data = get_props_data(prop)

    #create properties file and load
    if args.pg:
        psetup = Propsetup(prop, props_data)
        props_data = psetup.prop_setup()
    else:
        if validate_props(props_data):
            return 1

    ve = vector(props_data, prop)
    ve.create_vector_file(fname)
    rtlvec = Rtlvec(args.gpath, props_data)
    if not rtlvec.run_cmd():
        print "rtlvec flow pass"
        rtlvec.update_rtl()
    if run_tool(fname, props_data):
        print "Jobs Fail"
        return 1
    print "Jobs pass"
    if args.dest:
        print "copy file into %s" %(args.dest)
        for vec_file in glob.glob('*.vec'):
            shutil.copy2(os.path.abspath(vec_file), args.dest)

if __name__ == "__main__":
    sys.exit(main(parse_args(sys.argv[1:])))

