//多线程竞争,加锁
#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
int tot = 20;
mutex mtx;
void thread1() {
    while (tot > 0) {
        mtx.lock();
        cout << "Thread 1: " << tot << endl;
        tot--;
        mtx.unlock();
        sleep(1);
    }
}
void thread2() {
    while (tot > 0) {
        mtx.lock();
        cout << "Thread 2: " << tot << endl;
        tot--;
        mtx.unlock();
        sleep(1);
    }
}
int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
}
/*
 * Thread 1: 20
 * Thread 2: 19
 * Thread 2: 18
 * Thread 1: 17
 * Thread 2: 16
 * Thread 1: 15
 * Thread 2: 14
 * Thread 1: 13
 * Thread 2: 12
 * Thread 1: 11
 * Thread 1: 10
 * Thread 2: 9
 * Thread 2: 8
 * Thread 1: 7
 * Thread 1: 6
 * Thread 2: 5
 * Thread 2: 4
 * Thread 1: 3
 * Thread 1: 2
 * Thread 2: 1
 */
