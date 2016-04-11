#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

struct node {
    public:
        int data;
        node *left;
        node *right;
};

class Tree {
    public:
        node *root;
        Tree();
        void create_tree(int data);
        void inorder(node *s);
        void print_data();
        void level_order_traverse(node *s);
        int halfoftree(node *s);
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
    cout<<endl;
}

void Tree::print_data()
{
   cout<<endl<<"Inorder Traversal....."<<endl;
   inorder(root);
   cout<<endl;
   cout<<"level_order..."<<endl;
   level_order_traverse(root);
   cout<<endl<<" Halfoftree..."<<halfoftree(root);
   cout<<endl;
}

void Tree::inorder(node *s){
    if(s)
    {
        inorder(s->left);
        cout<<s->data<<"  ";
        inorder(s->right);
    }
}

int Tree::halfoftree(node *s)
{
   queue<node*> nodes;
   int count = 0;
   if(s == NULL)
       return 0;
   else
   {
       while(s!=NULL)
       {
           cout<<s->data<<"  ";
           if((s->left == NULL && s->right != NULL)||(s->left != NULL && s->right == NULL))
               count = count +1;
           if(s->left)
               nodes.push(s->left);
           if(s->right)
               nodes.push(s->right);
           s = nodes.front();
           nodes.pop();
       }

   }
   return count;
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
