#include<iostream>
#include<tr1/unordered_set>
using namespace std;

int getoddoccurence(int a[]) {
    int size = sizeof(a)/sizeof(a[0]);
    int res = 0;
    for(int i=0; i<size; i++) {
        res = res ^ a[i];
    }
    return res;
}

int main() {
    int a [] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 };
    cout<<getoddoccurence(a)<<endl;
    std::tr1::unordered_multiset<int> um1({1,2,2,3});

}
