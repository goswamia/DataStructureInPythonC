#include<iostream>
#include<cstring>
using namespace std;
template<class T, int size>
class StaticArray {
    private:
        T m_array[size];
    public:
        T *getArray() {
            return m_array;
        }
        T& operator[](int index) {
            return m_array[index];
        }
};

template<class T, int size>
void PrintArray(StaticArray<T, size> &array) {
    for(int count=0; count<size; ++count)
        std::cout<<array[count];
}

template<int size>
void PrintArray(StaticArray<char, size> &array) {
    for(int count=0; count<size; ++count)
        std::cout<<array[count];
    cout<<"\n\n";
}

int main() {
    StaticArray<char, 14>char14;
    strncpy(char14.getArray(), "hello", 14);
    PrintArray(char14);
    StaticArray<char, 40>char40;
    strncpy(char40.getArray(), "test", 40);
    PrintArray(char40);
    return 0;
}
