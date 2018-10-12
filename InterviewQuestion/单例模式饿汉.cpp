#include <bits/stdc++.h>
using namespace std;
class Singleton {
protected:
    Singleton() {}
public:
    static Singleton* getSingleton();
private:
    static Singleton *p;
};
Singleton* Singleton :: getSingleton() {
    return p;
}
Singleton* Singleton :: p = new Singleton();
int main() {
    Singleton *a = Singleton :: getSingleton();
    Singleton *b = Singleton :: getSingleton();
    if(a == b) {
        puts("1");
    } else {
        puts("0");
    }
    return 0;
}
