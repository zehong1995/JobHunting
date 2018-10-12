#include <bits/stdc++.h>
using namespace std;
//整个过程就是把进位和不进位两种情况分开，累加不进位的，直到不用进位为止
int solve(int a, int b) {
    while(b != 0) {           //b等于0表示全部累加到a了
        int cxor = a ^ b;     //表示不用进位的位
        int cand = a & b;     //表示要进位的位
        b = cand << 1;        //把进位后的值赋给b
        a = cxor;             //把累加的值赋给a
    }
    return a;
}
int main() {
    int a, b;
    while(cin >> a >> b) {
        cout << solve(a, b) << endl;
    }
}
