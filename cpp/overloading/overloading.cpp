#include<iostream>

class Cents {
    private:
        int m_cents;
    public:
        Cents(int cents) {
            m_cents = cents;
        }

        friend Cents operator+(const Cents &c1, const Cents &c2);
        friend Cents operator-(const Cents &c1, const Cents &c2);

        int getCents() const {
            return m_cents;
        }
};

Cents operator+(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents+c2.m_cents);
}

Cents operator-(const Cents &c1, const Cents &c2) {
    return Cents(c1.m_cents-c2.m_cents);
}

int main() {
    Cents cents(10);
    Cents cent2(20);
    Cents c3 = cents + cent2;
    std::cout<<"Total is :"<<c3.getCents();
    Cents c4 = cents-cent2;
    std::cout<<"total is :"<<c4.getCents()<<std::endl;
    return 0;
}



