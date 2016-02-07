#include<vector>
#include<iostream>
#include<stdexcept>

template<typename T>
class Stack
{
    private:
        std::vector<T> elems;
    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty () const {
            return elems.empty();
        }

};

template<typename T>
void Stack<T>::push(T const& elem)
{
    elems.push_back(elem);
}

template<typename T>
void Stack<T>::pop() 
{
    if(elems.empty())
    {
        throw std::out_of_range("Empty stack");
    }
    elems.pop_back();
}

template<typename T>
T Stack<T>::top() const
{
    if(elems.empty())
        throw std::out_of_range("empty stack");
    return elems.back();
}

int main()
{
    try {
        Stack<int> intStack;
        Stack<std::string> stringStack;

        intStack.push(7);
        std::cout<<intStack.top()<<std::endl;

        stringStack.push("Hello");
        std::cout<<stringStack.top()<<std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch(std::exception const &ex)
    {
        std::cerr<<"Exception :"<< ex.what()<<std::endl;
        return 0;
    }

    return 0;
}



