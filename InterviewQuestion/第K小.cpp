#include <bits/stdc++.h>
using namespace std;
int a[1000100];
int FindminK(int* a, int from, int to, int k) {
    int pos = from + rand() % (to - from + 1);
    swap(a[pos], a[from]);
    int l = from, r = to, cmp = a[from];
    while(l < r) {
        while(l < r && a[r] >= cmp) r--;
        swap(a[l], a[r]);
        while(l < r && a[l] < cmp) l++;
        swap(a[l], a[r]);
    }
    a[l] = cmp;
    if(l == k) {
        return a[l];
    } else if(l > k) {
        return FindminK(a, from, l - 1, k);
    } else {
        return FindminK(a, l + 1, to, k);
    }
}
int main() {
    int n, k;

    srand(time(NULL));
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    int ans = FindminK(a, 0, n - 1, k - 1);
    cout << ans << endl;
}
