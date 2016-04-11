#include<iostream>
using namespace std;

template<class T>
class NamedObject
{
    public:
        NamedObject(const char *name, const T& value);
        NamedObject(const std::string &name, const T& value);
    private:
        std::string nameValue;
        T objectValue;
};

int main()
{

    return 0;
}
