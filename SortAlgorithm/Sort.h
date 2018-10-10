#include <bits/stdc++.h>
using namespace std;
class Sort {
public:
    virtual void doSort() = 0;
    void show_data();
    void test_by_person(int T);
    void test_by_rand(int T, int n);
protected:
    vector<int>num;
};
void Sort::show_data() {
    cout << "After sort:" << endl;
    for(int i = 0; i < num.size(); ++ i) {
        if(i > 0) cout << ' ';
        cout << num[i];
    }
    cout << endl;
}
void Sort::test_by_person(int T) {
    int n, x;
    while(T--) {
        cin >> n;
        num.clear();
        num.shrink_to_fit();
        for (int i = 0; i < n; ++ i) {
            cin >> x;
            num.push_back(x);
        }
        doSort();
        show_data();
    }
}
void Sort::test_by_rand(int T, int n) {
    num.reserve(n);
    vector<int>cmp;
    num.reserve(n);
    cmp.reserve(n);
    int ac = 0, wa = 0;
    for(int cas = 0; cas < T; ++ cas) {
        num.clear();
        cmp.clear();
        for (int i = 0; i < n; ++ i) {
            int x = rand() % 100;
            num.push_back(x);
        }
        cmp = num;
        doSort();
        sort(cmp.begin(), cmp.end());
        bool flag = true;
        for (int i = 0; i < n; ++ i) {
            flag &= (num[i] == cmp[i]);
        }
        if (flag) {
            ac++;
        } else {
            wa++;
        }
    }
    cout << "Total:\t" << T << endl;
    cout << "Accept:\t" << ac << endl;
    cout << "Wrong:\t" << wa << endl;
}
