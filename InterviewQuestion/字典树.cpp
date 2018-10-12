#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4;
const int sigma_size = 26;
struct Trie {
    int sz;
    int ch[maxn][sigma_size];
    int val[maxn];
    void clear() {
        sz = 1;
        memset(ch, 0, sizeof(ch));
        memset(val, 0, sizeof(val));
    }
    void insert(const char* s) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; ++ i) {
            int c = s[i] - 'a';
            if(!ch[u][c]) {
                ch[u][c] = sz++;
            }
            u = ch[u][c];
            val[u]++;
        }
    }
    int find(const char* s) {
        int u = 0, n = strlen(s);
        for(int i = 0; i < n; ++ i) {
            int c = s[i] - 'a';
            u = ch[u][c];
            if(val[u] == 1) {
                return i;
            }
        }
        return n - 1;
    }
};
Trie trie;
char str[2020][30];
int main() {
    int T;
    scanf("%d", &T);
    getchar();
    getchar();
    bool cnt = false;
    while(T--) {
        trie.clear();
        int idx = 0;
        if(cnt) putchar('\n'); cnt = true;
        while(1) {
            gets(str[idx]);
            if(strcmp(str[idx], "") == 0) break;
            trie.insert(str[idx]);
            idx++;
        }
        for(int i = 0; i < idx; ++ i) {
            printf("%s ", str[i]);
            int pos = trie.find(str[i]);
            for(int j = 0; j <= pos; ++ j)
                putchar(str[i][j]);
            putchar('\n');
        }
    }
}
