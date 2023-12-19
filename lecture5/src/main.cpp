#include <iostream>
#include <memory>

template <typename T>

class my_smart_ptr {
    T *data;

    public: 
    my_smart_ptr() {
        data = nullptr;
    }

    my_smart_ptr(T *tdata) {
        data = tdata;
    }

    ~my_smart_ptr() {
        delete data;
    } 

    T& operator * () {
        return *data;
    }

    T* operator -> () {
        return data;
    }
};


int main() {
    std::shared_ptr<int> p(new int(42));

    my_smart_ptr<int> myp(new int(15));

    std::cout << *myp << std::endl;
    std::cout << *p << std::endl;

    return 0;
}