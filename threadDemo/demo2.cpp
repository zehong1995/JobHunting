//detach
#include <unistd.h>
#include <iostream>
#include <thread>
using namespace std;
void thread1() {
    for (int i = 0; i < 5; ++ i) {
        cout << "Thread 1 is working." << endl;
        sleep(1);
    }
}
void thread2() {
    for (int i = 0; i < 5; ++ i) {
        cout << "Thread 2 is working." << endl;
        sleep(1);
    }
}
int main() {
    thread t1(thread1);
    thread t2(thread2);
    t1.detach();
    t2.detach();
    for (int i = 0; i < 5; i++) {
        cout << "Main thread is working." << endl;
        sleep(1);
    }
}
/*
 * Main thread is working.
 * Thread 1 is working.
 * Thread 2 is working.
 * Main thread is working.
 * Thread 2 is working.
 * Thread 1 is working.
 * Main thread is working.
 * Thread 2 is working.
 * Thread 1 is working.
 * Main thread is working.
 * Thread 2 is working.
 * Thread 1 is working.
 * Main thread is working.Thread 1 is working.
 *
 * Thread 2 is working.
 */
