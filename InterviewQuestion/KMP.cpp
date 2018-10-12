#include <bits/stdc++.h>
using namespace std;
void GetNext(char* p, int *Next, int len) {
    int j = 0, k = -1;
    Next[0] = -1;
    while(j < len) {
        if(k == -1 || p[j] == p[k]) {
            Next[++j] = ++k;
        } else {
            k = Next[k];
        }
    }
}
int KMP(char* p, char* t) {
    int tlen = strlen(t);
    int plen = strlen(p);
    int Next[110];
    GetNext(p, Next, plen);
    for (int i = 0; i <= plen; ++ i) {
        cout << Next[i] << ' ';
    }
    cout << endl;
    int j = 0, ans = 0;
    for(int i = 0; i < tlen; ++ i) {
        while(j > 0 && t[i] != p[j]) {
            j = Next[j];
        }
        if(t[i] == p[j]) {
            j++;
        }
        if(j == plen) {
            ans++;
            j = Next[j];
        }
    }
    return ans;
}
int main() {
    char p[110], t[110];
    while(cin >> t >> p) {

        int ans = KMP(p, t);
        cout << ans << endl;
    }
}
