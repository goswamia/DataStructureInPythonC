#include<iostream>
using namespace std;

class Test {
    private:
        ~Test() {
            cout<<"Destructing object"<<endl;
        }
    public:
        Test() {
            cout<<"Constructing object"<<endl;
        }
        friend void destructTest(Test *ptr) {
            delete ptr;
        }
};

int main() {
    Test *t = new Test;
    Test t2;
}
