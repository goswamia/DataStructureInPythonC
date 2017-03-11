#include<iostream>
#include<cstring>
using namespace std;

class String {
    private:
        char *s;
        int size;
    public:
        String(const char *s = NULL);
        ~String();
        String(const String &s);
        void print();
        void change(const char *s);
};

String::String(const char *str) {
    size = strlen(str);
    s = new char[size+1];
    strcpy(s, str);
}

String::String(const String &old_str) {
    s = new char[old_str.size+1];
    strcpy(s, old_str.s);
}

void String::change(const char *new_str) {
    delete [] s;
    size = strlen(new_str);
    s = new char[size+1];
    strcpy(s, new_str);
}

void String::print() {
    cout<<s<<endl;
}

String:: ~String() {
    delete []s;
}

int main() {
    String s("abhishek goswami");
    String s2 = s;
    s.print();
    s2.print();

    s2.change("tosty goswami");
    s2.print();
    return 0;
}

