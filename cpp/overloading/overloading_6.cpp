#include<iostream>
#include<string>

class Car {
    private:
        std::string m_make;
        std::string m_model;
    public:
        Car(std::string make, std::string model):m_make(make), m_model(model) {
        }
        friend bool operator==(const Car &c1, const Car &c2);
        friend bool operator!=(const Car &c1, const Car &c2);
};

bool operator==(const Car &c1, const Car &c2) {
    return(c1.m_make==c2.m_make && c1.m_model == c2.m_model);
}

bool operator!=(const Car &c1, const Car &c2) {
    return !(c1==c2);
}

int main() {
    Car cor("Toyo", "coro");
    Car cam("Toyo", "cam");
    if(cam==cor)
        std::cout<<" both object same"<<std::endl;
    else 
        std::cout<<"both object are not same"<<std::endl;
    return 0;
}
