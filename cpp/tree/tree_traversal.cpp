#include<iostream>
#include<stack>
using namespace std;

class node {
    int data;
    node *left;
    node *right;
};

class tree {
    public:
        node *root;
        tree();
        void create_tree(int data);
        void inorder(node *s);
        void print_data();
};





int main()
{
    return 0;
}
