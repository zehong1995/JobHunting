//add parameter
#include <unistd.h>
#include <iostream>
#include <thread>
using namespace std;
void thread1(int num) {
    for (int i = 0; i < num; ++ i) {
        cout << "Thread 1 is working." << endl;
        sleep(1);
    }
}
void thread2(int num) {
    for (int i = 0; i < num; ++ i) {
        cout << "Thread 2 is working." << endl;
        sleep(1);
    }
}
int main() {
    thread t1(thread1, 5);
    thread t2(thread2, 5);
    t1.join();
    t2.join();
    for (int i = 0; i < 5; i++) {
        cout << "Main thread is working." << endl;
        sleep(1);
    }
}
/*
 * Thread 1 is working.
 * Thread 2 is working.
 * Thread 1 is working.Thread 2 is working.
 *
 * Thread 1 is working.
 * Thread 2 is working.
 * Thread 2 is working.
 * Thread 1 is working.
 * Thread 1 is working.
 * Thread 2 is working.
 * Main thread is working.
 * Main thread is working.
 * Main thread is working.
 * Main thread is working.
 * Main thread is working.
 */
