#include<iostream>
using namespace std;

void movetoend(int m[], int m_size) {
    int  j = m_size-1;
    for(int i = m_size-1; i>=0; i--) {
        if(m[i] != -1){
            m[j] = m[i];
            j--;
            m[i] = -1;
        }
    }
}

void merge_array(int m[], int n[], int m_size, int n_size) {
    int k = n_size;
    int l = 0;
    cout<<k <<" "<<m_size<<"  "<<n_size<<endl;
    for (int i=0; i<m_size; i++) {
        if(m[k] > n[l])
        {
            m[i] = n[l];
            l++;
        } else if(k<m_size) {
            m[i] = m[k];
            k++;
        } else {
            m[i] = n[l];
            l++;
        }
    }
}


int main() {
    int m [] = {-1, -1, 4, 7, 14, 15, 16, 17, -1, -1, -1};
    int n [] = {5, 8, 10, 12, 13};
    int m_size = sizeof(m)/sizeof(m[0]);
    int n_size = sizeof(n)/sizeof(n[0]);
    movetoend(m, m_size);
    merge_array(m, n, m_size, n_size);
    for(int k=0; k<m_size; k++)
        cout<<" "<<m[k];
    cout<<endl;
}
