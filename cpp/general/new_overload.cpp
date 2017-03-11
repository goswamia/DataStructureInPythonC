#include<iostream>
#include<malloc.h>

using namespace std;
class sample {
    private:
        int ii;
        char c;
    public:
        void* operator new(size_t s, int ii, char c) {
            sample *q = (sample *)malloc(s);
            q->ii = ii;
            q->c = c;
        }
        void operator delete(void *q) {
            cout<<"Delete s"<<endl;
            delete q;
        }
        void display() {
            cout<<ii<<"  "<<c<<endl;
        }
};

int main() {
    sample *s = new(7, 'a')sample;
    s->display();
    delete s;
}
