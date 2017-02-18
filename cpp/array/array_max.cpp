#include<iostream>
#include<algorithm>
#include<vector>

int main() {
    std::vector<int> v = {1, 2, 6, 80, 100};
    int max = v[1]-v[0];
    int min = v[0];
    for(int i = 0; i<v.size(); i++) {
        if(v[i]-min > max)
            max = v[i]-min;
        else if(v[i] < min)
            min = v[i];
    }
    std::cout<<max<<std::endl;
}
