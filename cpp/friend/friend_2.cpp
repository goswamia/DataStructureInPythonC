#include<iostream>
using namespace std;

class Humidity;

class Temperature {
    private:
        int m_t2;
    public:
        Temperature(int temp=0) {
            m_t2 = temp;
        }
        friend void printweather(Temperature &te, Humidity &h);
};

class Humidity {
    private:
        int m_humid;
    public:
        Humidity(int temp=0) {
            m_humid = temp;
        }
        friend void printWeather(Temperature &te, Humidity &h);
};

void printWeather(Temperature &te, Humidity &h) {
    cout<<h.m_humid<<endl;
    cout<<te.m_t2<<endl;
    cout<<endl;
}

int main() {
    Temperature te(40);
    Humidity h(29);
    printWeather(te, h);
    return 0;
}
