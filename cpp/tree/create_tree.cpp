#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class Tree {
    private:
        node *root;
    public:
        Tree();
        void create_tree(int data);
        void inorder_traverse(node *s);
        void preorder_traverse(node *root);
        void postorder_traverse(node *root);
        void level_order_traverse(node *root);
        int  height_of_tree(node *root);
        int height_tree(node *root);
        void print_data();
};

Tree::Tree(){
    root = NULL;
}


void Tree::create_tree(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
        root = temp;
    else
    {
        node *p = root;
        node *trail = NULL;
        while(p!=NULL)
        {  
            trail = p;
            if(p->data > data)
                p = p->left;
            else
                p = p->right;
        }

        if(trail->data > data)
            trail->left = temp;
        else
            trail->right = temp;
    }
}

void Tree::inorder_traverse(node *s)
{
    if(s)
    {
        inorder_traverse(s->left);
        cout<<s->data<<"   ";
        inorder_traverse(s->right);
    }
}

void Tree::postorder_traverse(node *root)
{
    if(root)
    {
        postorder_traverse(root->left);
        postorder_traverse(root->right);
        cout<<root->data<< "   ";
    }
}

void Tree::preorder_traverse(node *root)
{
    if(root)
    {
        cout<<root->data<<"    ";
        preorder_traverse(root->left);
        preorder_traverse(root->right);
    }
}

void Tree::level_order_traverse(node *root)
{
    node *data_storage [10] = {NULL};
    int size = 0;
    int follow_variable = 0;
    while(root)
    {
        cout<<root->data<<"  ";
        if(root->left)
            data_storage[size++] = root->left;
        if(root->right)
            data_storage[size++] = root->right;
        root = data_storage[follow_variable++];
    }
}

int Tree::height_of_tree(node *root)
{
    if(root == NULL)
        return 0;
    else
    {
         return height_of_tree(root->left) + 1 + height_of_tree(root->right);
    }

}

int Tree::height_tree(node *root)
{
    int leftheight, rightheight;
    if(root == NULL)
        return 0;
    else
    {
        leftheight = height_tree(root->left);
        rightheight = height_tree(root->right);
        if(leftheight > rightheight)
            return (leftheight+1);
        else
            return (rightheight+1);
    }
}

void Tree::print_data()
{
   int height = 0;
   cout<<endl<<"Inorder Traversal...."<<endl; 
   inorder_traverse(root); 
   cout<<endl<<"PreOrder Traversal "<<endl;
   preorder_traverse(root);
   cout<<endl<<"PostOrder Traversal..."<<endl;
   postorder_traverse(root);
   cout<<endl<<"Level Order Traversal ..."<<endl;
   level_order_traverse(root);
   height = height_of_tree(root);
   cout<<endl<<" Height of Tree ...."<<height<<endl;
   height = height_tree(root);
}
int main()
{
    Tree t;
    for(int i=0; i<10; i++)
    {
        int number = rand() % 100;
        t.create_tree(number);   
    }
    t.print_data();
    return 0;
}


