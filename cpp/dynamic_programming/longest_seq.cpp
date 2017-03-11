#include<iostream>
using namespace std;

int lis(int a[], int n) {
    int max = 0;
    int *lis_data = new int[n]();
    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++){
            if(a[i] > a[j] && lis_data[i] < lis_data[j]+1)
                lis_data[i] = lis_data[j]+1;
        }
    for(int k=0; k<n; k++)
    {
        if (max < lis_data[k]){
            max = lis_data[k];
            cout<<lis_data[k];
        }
    }
    cout<<"\n";
    return max;
}
int main() {
    int arr [] = {10, 22, 9, 33, 21, 50, 41, 60, 70, 80, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<" Answer is"<<lis(arr, n)<<endl;;
    return 0;
}
