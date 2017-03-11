#include<iostream>
using namespace std;

class sample {
    private:
        int x,y;
    public:
        sample(int x, int y) {
            this->x = x;
            this->y = y;
        }
        sample(const sample &sample_1) {
            this->x = sample_1.x;
            this->y = sample_1.y;
        }
        int getx() {
            return this->x;
        }
        int gety() {
            return this->y;
        }
};

int main() {
    sample s(3, 2);
    sample s1 = s;
    cout<<"x : "<<s1.getx()<<" y: "<<s1.gety()<<endl;
    return 0;
}


