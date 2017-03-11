#include<iostream>

class sample {
    private:
        static int s_value;
    public:
        static int getValue() {
            return s_value;
        }
        static int printvalue();
};

inline int sample::printvalue() {
    return s_value;
}

int sample::s_value = 5;

int main() {
    std::cout<<sample::getValue()<<std::endl;
    std::cout<<"check as member function"<<std::endl;
    std::cout<<sample::printvalue()<<std::endl;
    return 0;
}
