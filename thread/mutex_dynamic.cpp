#include<iostream>
#include<pthread.h>
using namespace std;

class my_struct {
    public:
        pthread_mutex_t mutex;
        int value;
};
int main(int argc, char *argv[])
{
    my_struct *data;
    int status;

    data = new my_struct;
    status = pthread_mutex_init(&data->mutex, NULL);
    cout<<" The staus is "<<status;
    return 0;
}


