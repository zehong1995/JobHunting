//#include "Sort.h"
class QuickSort : public Sort{
public:
    void doSort() override;
private:
    int Partion(vector<int>&num, int from, int to);
    void quickSort(vector<int>&num, int from, int to);
};
void QuickSort::doSort() {
    int n = num.size();
    quickSort(num, 0, n - 1);
}
int QuickSort::Partion(vector<int>&num, int from, int to) {
    int pos = rand() % (to - from + 1);
    swap(num[from], num[from + pos]);
    int l = from, r = to, cmp = num[from];
    while(l < r) {
        while(l < r && num[r] >= cmp) r--;
        swap(num[r], num[l]);
        while(l < r && num[l] < cmp) l++;
        swap(num[l], num[r]);
    }
    num[l] = cmp;
    return l;
}
void QuickSort::quickSort(vector<int>&num, int from, int to) {
    if(from >= to) {
        return;
    }
    int pos = Partion(num, from, to);
    quickSort(num, from, pos - 1);
    quickSort(num, pos + 1, to);
}
