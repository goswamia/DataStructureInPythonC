#include<iostream>
using namespace std;

template<class T>
class node {
    public:
        T data;
        node *next;
};

template<class T>
class link {
    public:
        node *first;
        link();
        void add_node(T data);
        void create_link_list();
        void insert_data_link_list(T data);
        void add_node_link_list(T data);
        void delete_node_after_data_node(T data);
        void delete_node_before_data_node(T data);
        friend ostream& operator
}
