#include<vector>
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

