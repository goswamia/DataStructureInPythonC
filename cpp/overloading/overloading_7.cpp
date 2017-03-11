#include<iostream>

class cents {
    private:
        int m_cents;
    public:
        friend bool operator >(const cents &c1, const cents &c2);
        friend bool operator<=(const cents &c1, const cents &c2);

        friend bool operator<(const cents &c1, const cents &c2);
        friend bool operator>=(const cents &c1, const cents &c2);
};

bool operator>(const cents &c1, const cents &c2) {
    return c1.m_cents > c2.m_cents;
}

bool operator>=(const cents &c1, const cents &c2) {
    return c1.m_cents > c2.m_cents;
}

bool operator<(const cents &c1, const cents &c2) {
    return c1.m_cents < c2.m_cents;
}

bool operator<=(const cents &c1, const cents &c2) {
    return c1.m_cents <= c2.m_cents;
}

int main() {
    cents dime(0);
    return 0;
}
