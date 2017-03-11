#include<iostream>
using namespace std;

class Accumulator {
    private:
        int m_value;
    public:
        Accumulator();
        void add(int value);

        void reset(Accumulator &accumulator);
};

Accumulator::Accumulator() {
    m_value = 0;
}

void Accumulator::add(int value) {
    m_value += value;
}

void Accumulator::reset(Accumulator &accumulator) {
    accumulator.m_value = 0;
}

int main() {
    Accumulator acc;
    acc.add(5);
    acc.reset(acc);
    return 0;
}
