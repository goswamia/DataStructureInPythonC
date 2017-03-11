#!/usr/bin/env python
import argparse
import sys

def parse_args(argv):
    """parse the argument"""
    parser = argparse.ArgumentParser(
                    description='This test module',
                    epilog="this is testing module")
    parser.add_argument('-d', '-debug', dest='debug', action='store_true',
                        help="dummy variable")
    args = parser.parse_args(argv)
    return args

def check_rule_1(args):
    """rule 1"""
    args.error_flag = True
    args.rule_status["check_rule_1"] = args.error_flag

def check_rule_2(args):
    """rule 2"""
    args.error_flag = False
    args.rule_status["check_rule_2"] = args.error_flag

def check_rule_3(args):
    args.error_flag = True
    args.rule_status["check_rule_3"] = args.error_flag
def check_rule(args):
    """check rule"""
    check_rule_1(args)
    check_rule_2(args)
    check_rule_3(args)

def main(args):
    print args
    args.error_flag = False
    args.rule_status = {}
    check_rule(args)
    f_data = ""
    for key, value in args.rule_status.items():
        f_data = f_data + "%20s  %20s" %(key, value) + "\n"
    with open("data.txt", "w") as fp:
        fp.write(f_data)

if __name__ == "__main__":
    ARGV = parse_args(sys.argv[1:])
    sys.exit(main(ARGV))

