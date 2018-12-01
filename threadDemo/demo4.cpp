//多线程竞争
#include <unistd.h>
#include <iostream>
#include <thread>
using namespace std;
int tot = 20;
void thread1() {
    while(tot > 0) {
        cout << "Thread 1: " << tot << endl;
        tot--;
        sleep(1);
    }
}
void thread2() {
    while(tot > 0) {
        cout << "Thread 2: " << tot << endl;
        tot--;
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
 * Thread 2: 20
 * Thread 1: 18
 * Thread 2: 18
 * Thread 1: 16
 * Thread 2: 16
 * Thread 1: Thread 2: 1414
 *
 * Thread 1: 12
 * Thread 2: 11
 * Thread 2: 10
 * Thread 1: 10
 * Thread 1: 8
 * Thread 2: 8
 * Thread 1: Thread 2: 66
 *
 * Thread 1: 4
 * Thread 2: 3
 * Thread 1: 2
 * Thread 2: 2
 */
