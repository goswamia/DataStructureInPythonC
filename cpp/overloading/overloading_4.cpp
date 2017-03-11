#include<iostream>

class Point {
    private:
        double m_x,m_y, m_z;
    public:
        Point(double x=0.0, double y=0.0, double z=0.0): m_x(x), m_y(y), m_z(z) {

        }
        friend std::ostream& operator<<(std::ostream &out, const Point &p);
        friend std::istream& operator>>(std::istream &in, Point &p);
};

std::ostream& operator<<(std::ostream &out, const Point &p) {
    out<< "Point "<<p.m_x << " " <<p.m_y<< "  "<<p.m_z<<std::endl;
    return out;
}

std::istream& operator>>(std::istream &in, Point &p) {
    in >> p.m_x;
    in >> p.m_y;
    in >> p.m_z;
    return in;
}

int main() {
    Point p;
    std::cin >> p;
    std::cout <<p;
    return 0;
}
