class ShellSort : public Sort{
public:
    void doSort() override;
private:
    void shellSort(vector<int>&v);
};
void ShellSort::doSort() {
    shellSort(num);
}
void ShellSort::shellSort(vector<int>&v) {
    int n = v.size(), i, j, k, gap;
    //分gap，其余和直接插入排序一样
    for(gap = n / 2; gap > 0; gap /= 2) {
        for(i = 0; i < gap; ++ i) {
            for(j = i + gap; j < n; j += gap) {
                if(v[j] < v[j - gap]) {
                    int tmp = v[j];
                    for(k = j - gap; k >= i && v[k] > tmp; k -= gap) {
                        v[k + gap] = v[k];
                    }
                    v[k + gap] = tmp;
                }
            }
        }
    }
}
