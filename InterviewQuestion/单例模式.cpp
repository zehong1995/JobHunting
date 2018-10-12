//¶öººÄ£Ê½
#include <bits/stdc++.h>
using namespace std;
class Singleton {
protected:
    Singleton() {}
private:
    static Singleton *p;
public:
    static Singleton * getSingleton();
};
Singleton* Singleton :: p = new Singleton();
Singleton* Singleton :: getSingleton() {
    return p;
}
int main() {
    Singleton *a = Singleton :: getSingleton();
    Singleton *b = Singleton :: getSingleton();
    if(a == b) {
        cout << "Done" << endl;
    } else {
        cout << "Pardon?" << endl;
    }
}
