#include <bits/stdc++.h>
using namespace std;
bool judge(const vector<int>& v) {
    int n = v.size();
    vector<int>pre;
    pre.push_back(v[0]);
    for (int i = 1; i < v.size(); ++ i) {
        pre.push_back(min(pre[i - 1], v[i]));
    }
    stack<int>sta;
    sta.push(v[n - 1]);
    for (int i = n - 2; i >= 1; -- i) {
        if (v[i] < sta.top()) {
            sta.push(v[i]);
        } else {
            int top;
            while(!sta.empty() && v[i] >= sta.top()) {
                top = sta.top();
                sta.pop();
            }
            cout << i << ' ' << pre[i - 1] << ' ' << top << endl;
            if (pre[i - 1] < top && top < v[i]) {
                return true;
            }
            sta.push(v[i]);
        }
    }
    return false;
}
int main() {
    int n, x;
    vector<int>v;
    while(cin >> n) {
        v.clear();
        for (int i = 0; i < n; ++ i) {
            cin >> x;
            v.push_back(x);
        }
        cout << judge(v) << endl;
    }
}
