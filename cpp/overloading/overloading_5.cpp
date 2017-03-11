#include<iostream>

class Point {
    private:
        double m_x;
    public:
        Point(double x):m_x(x) {
            std::cout<<"constructor call"<<std::endl;
        }
        Point operator-() const;

        int getpoint()const {
            return m_x;
        }
};

Point Point::operator-()const {
    std::cout<<" uniary operator will call"<<std::endl;
    return -m_x;
}

int main() {
    const Point nickle(5);
    std::cout<<"The val is "<<(-nickle).getpoint()<<std::endl;
    return 0;
}



