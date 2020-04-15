#include <iostream>
#include <thread>

#include "thread_pools.h"
#include <unistd.h>

class A
{
public:
    A(int a) :a_(a) {}
    void run() {
        while(1){
            std::cout << a_ << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
private:
    int a_ = 10;
};


void test(int a, int b) 
{
    while (1) {
        std::cout << "I'm test!!!" << std::endl;
        sleep(2);
        return;
    }
}

void func(int i) 
{
    while (1) {
        std::cout << "I'm func!!!" << i << std::endl;
        sleep(3);
    }
}

int main()
{
    ThreadPool pool(4);

    A abc(10);

    auto resut = pool.enqueue([&abc](){ abc.run(); });
    

    auto mm = pool.enqueue(test, 3, 10);

    //std::cout << result.get() << std::endl;

    return 0;
}