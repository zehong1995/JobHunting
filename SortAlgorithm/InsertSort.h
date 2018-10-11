class InsertSort : public Sort {
public:
    void doSort() override;
private:
    void insertSort(vector<int>&v);
};
void InsertSort::doSort() {
    insertSort(num);
}
void InsertSort::insertSort(vector<int>&v) {
    int n = v.size(), i, j;
    //a[0] -> a[i - 1]为有序序列，每次在a[0] -> a[i -1]中找到插入a[i]的位置
    for(i = 1; i < n; ++ i) {
        if(v[i] < v[i - 1]) {
            int tmp = v[i];
            for(j = i - 1; j >= 0 && v[j] > tmp; -- j) {
                v[j + 1] = v[j];
            }
            v[j + 1] = tmp;
        }
    }
}
