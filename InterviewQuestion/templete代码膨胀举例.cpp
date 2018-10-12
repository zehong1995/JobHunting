#include <bits/stdc++.h>
using namespace std;
template<class T, int num>
class A {
public:
    void work() {
        static int i = 0;
        cout << "work()" << i++ << endl;
        cout << num << endl;
    }
};

int main() {
    A<int,1>v1;
    A<int,2>v2;
    A<int,3>v3;
    A<int,4>v4;
    v1.work();
    v2.work();
    v3.work();
    v4.work();
    return 0;
}
