#include<iostream>
#include<string>
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
        node<T> *first;
        link();
        void add_node(T data);
        void insert_data_link_list(T data);
        void add_node_link_list(T data);
        void delete_node_after_data_node(T data);
        void delete_node_before_data_node(T data);
        template<class U>
        friend ostream& operator<< (ostream &o, link<U> &link_list);
};

template<class T>
link<T>::link() {
    first = NULL;
}

template<class T>
void link<T>::add_node(T data) {
    node<T> *p = new node<T>;
    p->data = data;
    p->next = NULL;

    if(first == NULL)
        first = p;
    else 
    {
        node<T> *last = first;
        while(last->next!=NULL) 
            last = last->next;
        last->next = p;
    }
}

template<class T>
void link<T>::insert_data_link_list(T data) {
    node<T> *p = new node<T>;
    p->data = data;
    p->next = NULL;

    if(first==NULL)
        first = p;
    else if(first->next == NULL)
        first->next = p;
    else {
        node<T> *last = first;
        while(last->next != NULL) {
            p->next = last->next;
            last->next = p;
            last = p->next;
        }
    }
}


template<class T>
void link<T>::add_node_link_list(T data) {
    node<T> *p = new node<T>;
    p->data = data;
    p->next = NULL;

    if(first==NULL)
        first = p;
    else if(first->next==NULL){
        p->next = first;
        first=p;
    }
    else {
        node<T> *last = first;
        while(last->next !=NULL) {
            p->next = last->next;
            last->next = p;
            last = p->next;
        }
    }
}

template<class T>
void link<T>::delete_node_before_data_node(T data) {
    node<T> *last;
    node<T> *p;
    if(first->data == data && first->next == NULL) {
        cout<<" you have only one node"<<endl;
    }
    else if(first->next->data == data) {
        p = first->next;
        first = p;
        delete p;
    }
    else
    {
        last = first;
        while(last->next!=NULL) {
            if(last->next->next->data == data) {
                p = last->next;
                last->next = p->next;
                delete p;
            }
        }
    }
}

template<class T>
void link<T>::delete_node_after_data_node(T data) {
    node<T> *last;
    node<T> *p;
    if(first->data == data && first->next->next == NULL) {
        p = first->next;
        delete first;
        first = p;
    }
    else {
        last = first;
        while(last->next!=NULL) {
            if(last->data==data){
                p = last->next;
                last->next = p->next;
                delete p;
            }
        }
    }
}

template<class T>
ostream& operator<< (ostream &o, link<T> &link_list) {
    node<T> *last = link_list.first;
    while(last != NULL){
        o<<last->data<<" --->";
        last = last->next;
    }
    return o;
}

int main() {
    link<string> data;
    data.add_node("2");
    data.add_node("2");
    data.add_node("2");
    data.add_node("2");
    data.add_node("2");
    cout<<data;
    cout<<endl;
    return 0;
}
