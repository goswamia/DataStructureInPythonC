#include<iostream>
#include<algorithm>
using namespace std;

int sum(int a[], int size) {
    int *sum_t = new int[size];
    int i =0;
    for(int i=0; i<size; i++)
    {
        if(i==0)
            sum_t[0] = a[0];
        else if(i==1)
            sum_t[1] = max(sum_t[0], a[i]);
        else
            sum_t[i] = max(sum_t[i-2]+a[i], sum_t[i-1]);
    }
    return sum_t[size-1];
}

int sum_recursion(int a[], int i) {
    if(i==0)
        return a[0];
    else if(i==1)
        return max(a[0], a[1]);
    else
        return max(sum_recursion(a, i-2)+a[i], sum_recursion(a, i-1));
}

int main() {
    int a [] = {5, 5, 10, 100, 10, 5};
    int size = sizeof(a)/sizeof(a[0]);
    int output = sum(a, size);
    cout<<"The max sum is"<<output<<endl;
    output = sum_recursion(a, size);
    cout<<"The recursion sum is"<<output<<endl;
    return 0;
}
