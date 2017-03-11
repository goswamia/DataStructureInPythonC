#include<iostream>
using namespace std;

class sample {
    private:
        int x, y;
    public:
        sample();
        sample(int x, int y);
        int getX();
        int getY();
};

sample::sample() {
    x = y = 0;
}

sample::sample(int x, int y) {
    this->x = x;
    this->y = y;
}

int sample::getX() {
    return x;
}

int sample::getY() {
    return y;
}

int main() {
    sample p;
    cout<<"x="<<p.getX()<<"  "<<"y="<<p.getY()<<endl;
    sample p1(4,5);
    cout<<"x="<<p1.getX()<<"  "<<"y="<<p1.getY()<<endl;
    return 0;
}
