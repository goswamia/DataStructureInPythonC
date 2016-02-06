/*program to count number of inversion */
#include<iostream>
using namespace std;

class count {
    private:
        int b;
    public:
        int get_count(int a[], int n);
        int get_data(int a[], int n);
        int merge(int a[], int temp[], int left, int mid, int  right);
        int merge_sort(int a[], int n);
        int merge_sort_1(int a[], int temp[], int left, int right);
};

int count::get_count(int a[], int n){
    int inv_count = 0;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                inv_count += 1;
            }
        }
    }
    return inv_count;
}

int count::get_data(int a[], int n)
{
    int count_1 = this->get_count(a, n);
    std::cout<<"The count is"<<count_1<<std::endl;
    cout<<"Merge sort is"<<endl;
    count_1 = this->merge_sort(a, n);
    cout<<" count is"<<count_1<<endl;
}

int count::merge_sort(int arr[], int n)
{
    int *temp = new int[n];
    return merge_sort_1(arr, temp, 0, n-1);
}

int count::merge_sort_1(int arr[], int temp[], int left, int right)
{

    int mid, inv_count =0;
    if (right > left)
    {
        mid =  (right + left)/2;
        inv_count =  merge_sort_1(arr, temp, left, mid);
        inv_count += merge_sort_1(arr, temp, mid+1, right);

        inv_count += merge(arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int count::merge(int arr[], int  temp[], int left, int mid, int right)
{
    int i,j,k;
    int inv_count = 0;
    i = left;
    j =  mid;
    k = right;

    while((i<=mid-1) && (j<=right))
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
        inv_count = inv_count + (mid-i);
    }

    while(i<=mid-1)
        temp[k++] = arr[i++];
    while(j<=right)
        temp[k++] = arr[j++];

    for(i=left; i<=right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int main()
{
    count C;
    int arr [] = {1, 20, 6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (C.get_data(arr, n))
    {
        cout<<endl<<"Getting Expected result"<<endl;
    }
    else
    {
        cout<<"Algo Fail"<<endl;
    }
    return 0;
}

