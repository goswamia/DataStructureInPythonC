#include<iostream>
#include<map>
using namespace std;

void printMajority(int a[], int size) {
    std::map<int, int> first;
    for(int i=0; i<size; i++)
        first[a[i]]++;
    int check = 0;
    std::map<int, int>::iterator it_type;
    for(it_type = first.begin(); it_type != first.end(); ++it_type) {
        std::cout<<it_type->first<< "   "<<it_type->second<<"   "<<endl;
        if (it_type->second > size/2)
            check = it_type->second;
    }
    if(check == 0)
        std::cout<<"No majoirty element";
}

int main() {
    int a[] = {1, 3, 3, 1, 2};
    int size = sizeof(a)/sizeof(a[0]);
    cout<<size<<endl;
    printMajority(a, size);
    return 0;
}
