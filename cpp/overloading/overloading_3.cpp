#include<iostream>

class Point {
    private:
        double m_x,m_y,m_z;
    public:
        Point(double x=0.0, double y=0.0, double z=0.0):m_x(x), m_y(y), m_z(z)
        {
            cout<<"Point constructor"<<endl;
        }
        friend ostream& operator<<(ostream &out, const Point &p);
};

friend ostream& operator<<(ostream &out, const Point &p) {
    out<< "x : "<<p.x <<"y : "<<p.y<< "z : "<<p.z<<endl;
    return out;
}

int main() {
    Point p(3, 4, 5);
    cout<<p;
}


