#include<iostream>
#include<vector>

int main() {
    std::vector<int> v = { 1, 2 , 3, 4, 5, 6};
    for(std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
        std::cout<<*it<<std::endl;
    return 0;
}
