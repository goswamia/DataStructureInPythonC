#include<iostream>
#include<vector>

int check_product(std::vector<int> &v1, int product) {
    int pro = 1;
    for(std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
        re = product / *it;
        
    }
}

int main() {
    std::vector<int> v = {10, 29, 9, 40};
    std::cout<<"  "<<check_product(v, 400)<<std::endl;
    return 0;
}
