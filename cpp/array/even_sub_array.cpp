#include<iostream>
using namespace std;

int main() {
    int a [] = {1, 2, 2, 3, 4, 1};
    int a_size = sizeof(a)/sizeof(a[0]);
    int count = 0;
    for(int i=0; i<a_size; i++) {
        int sum = 0;
        if (a[i]%2 ==0)
            count = count+1;
        for(int j=i+1; j<a_size; j++) {
            sum = a[i]+a[j];
            if (sum%2==0)
                count = count+1;
        }
    }
    cout<<"the Final count : "<<count<<endl;
    return 0;
}
