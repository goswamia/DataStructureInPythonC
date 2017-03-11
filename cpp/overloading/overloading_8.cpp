#include<iostream>

class Digit {
    private:
        int m_digit;
    public:
        Digit(int digit=0):m_digit(digit){
        }
        Digit& operator++();
        Digit& operator++(int);

        friend std::ostream& operator<<(std::ostream &out, const Digit &d);
};

Digit& Digit::operator++() {
    if(m_digit == 9)
        m_digit=0;
    else
        ++m_digit;

    return *this;
}

Digit& Digit::operator++(int) {
    if(m_digit == 9)
        m_digit = 0;

    else
        m_digit++;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Digit &d) {
    out<<d.m_digit<<std::endl;
    return out;
}

int main() {
    Digit digit(8);
    std::cout<<digit++;
    std::cout<<++digit;
}

