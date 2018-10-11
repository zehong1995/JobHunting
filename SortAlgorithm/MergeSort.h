class MergeSort : public Sort{
public:
    void doSort() override;
private:
    void mergeSort(vector<int>&num, int from, int to);
    void merge(vector<int>&num, int from, int mid, int to);
};
void MergeSort::doSort() {
    int n = num.size();
    mergeSort(num, 0, n - 1);
}
void MergeSort::mergeSort(vector<int>&num, int from, int to) {
    if (from >= to) {
        return;
    }
    int mid = from + to >> 1;
    mergeSort(num, from, mid);
    mergeSort(num, mid + 1, to);
    merge(num, from, mid, to);
}
void MergeSort::merge(vector<int>&num, int from, int mid, int to) {
    vector<int>tmp;
    int pos1 = from, pos2 = mid + 1;
    while(pos1 <= mid && pos2 <= to) {
        if (num[pos1] < num[pos2]) {
            tmp.push_back(num[pos1++]);
        } else {
            tmp.push_back(num[pos2++]);
        }
    }
    while(pos1 <= mid) {
        tmp.push_back(num[pos1++]);
    }
    while(pos2 <= to) {
        tmp.push_back(num[pos2++]);
    }
    for (int i = from; i <= to; ++ i) {
        num[i] = tmp[i - from];
    }
}
