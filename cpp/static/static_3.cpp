#include<iostream>
using namespace std;

class Test  {
    public:
        //virtual void sample () {}
        static void sample_2() { cout<<"Test"<<endl; }
};

int main() {
    Test b;
    cout<<sizeof(Test);
    return 0;
}

