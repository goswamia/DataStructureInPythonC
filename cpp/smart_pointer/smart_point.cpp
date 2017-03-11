#include<iostream>
using namespace std;

class Person 
{
    private:
        int age;
        const char *pName;
    public:
        Person():pName(0), age(0) {
        }
        Person(const char *pName, int age): pName(pName), age(age) {
            cout<<"Person parameter constructor"<<endl;
        }
        ~Person() {
        }
        void display () {
            cout<<pName << "   "<<age<<endl;
        }
};

class RC 
{
    private:
        int count;
    public:
        void Addref() {
            count = count+1;
            cout<<"Addref::count"<<count<<endl;
        }
        int Release() {
            --count;
            cout<<"Relase::count"<<count<<endl;
            return count;
        }
};

template<class T>
class SP 
{
    private:
        T *pdata;
        RC *reference;
    public:
        SP():pdata(0), reference(0) {
            reference = new RC();
            reference->Addref();
        }
        SP(T *pdata):pdata(pdata), reference(0){
            reference = new RC();
            reference->Addref();
            cout<<"smart pointer constrcutor"<<endl;
        }
        SP(const SP<T>& sp):pdata(sp.pdata), reference(sp.reference) {
            reference->Addref();
        }
        ~SP() {
            int release = reference->Release();
            if(release==0) {
                delete pdata;
                delete reference;
            }
        }
        T& operator* () {
            return *pdata;
        }
        T* operator->(){
            cout<<"directional operator"<<endl;
            return pdata;
        }
        SP<T>& operator=(const SP<T>& sp) {
            if(this != &sp) {
                if(reference->Release()==0) {
                    delete pdata;
                    delete reference;
                }
                pdata = sp.pdata;
                reference=sp.reference;
                reference->Addref();
            }
        }
};

int main() {
    Person *p = new Person("john", 30);
    p->display();

    SP<Person>ps(new Person("john", 30));
    {
        SP<Person>q = ps;
        q->display();
    }
    ps->display();
    return 0;
}
