#include<iostream>
using namespace std;

class A {
};

class B {
    int i;
};

class C {
    void foo();
};

class D {
    virtual void foo();
};

class E {
    int i;
    virtual void foo();
};

class F {
    int i;
    void foo();
};

class G {
    void foo();
    int i;
    void foo1();
};

int main() {
    cout<<"sizeof class (A)"<<sizeof(A)<<endl;
    cout<<"sizeof class(B)"<<sizeof(B)<<endl;
    cout<<"sizeof class(C)"<<sizeof(C)<<endl;
    cout<<"sizeof class(D)"<<sizeof(D)<<endl;
    cout<<"sizeof class(E)"<<sizeof(E)<<endl;
    cout<<"sizeof class(F)"<<sizeof(F)<<endl;
    cout<<"sizeof class(G)"<<sizeof(G)<<endl;
    return 0;
}


