#include<iostream>
#include<memory>

using namespace std;
class Double {
    public:
        Double(double d=0):dvalue(d){
            cout<<"constructor"<<dvalue<<endl;
        }
        ~Double(){
            cout<<"destructor"<<endl;
        }
        void setdouble(double d) {
            dvalue = d;
        }
    private:
        double dvalue;
};

int main() {
    auto_ptr<Double>ptr(new Double(3.14));
    ptr->setdouble(30);
    return 0;
}
