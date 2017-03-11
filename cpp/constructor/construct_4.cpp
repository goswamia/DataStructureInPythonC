#include<iostream>
using namespace std;

class Test {
    private:
        void *operator new(size_t size);
        void *operator new[](size_t size);
        int x;
    public:
        Test();
        void display();
        ~Test();
};

int main() {
    Test *t = new Test;
    return 0;
}
