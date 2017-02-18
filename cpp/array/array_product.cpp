#include<iostream>
#include<vector>
using namespace std;

int main() {
    int a[] = {10, 3, 5, 6, 2};
    vector<int> v;
    int a_size = sizeof(a)/sizeof(a[0]);
    int sum = 1;
    for(int i=0; i<a_size; i++)
        sum = sum*a[i];
    for(int j=0; j<a_size; j++) {
        int r = sum/a[j];
        v.push_back(r);
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout<<*it<<endl;
    }
}
