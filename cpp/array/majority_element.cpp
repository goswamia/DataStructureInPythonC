#include<iostream>
using namespace std;

void printmajority(int a[], int size) {
    int maj_index =0;
    int count = 0;
    for(int i=0; i<size; i++) {
        if(a[maj_index]==a[i])
            count = count+1;
        else
            count = count-1;

        if (count==0) {
            maj_index = i;
            count = 1;
        }
    }
    if(a[maj_index]> size/2) {
        cout<<"element is : "<<a[maj_index]<<endl;
    }
}

int main() {
    int a[] = {1, 3, 3, 1, 3};
    int size = sizeof(a)/sizeof(a[0]);
    printmajority(a, size);
    return 0;
}
