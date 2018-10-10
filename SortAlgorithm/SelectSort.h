
//#include "Sort.h"
class SelectSort : public Sort{
public:
    void doSort() override;
private:
    void selectSort(vector<int>&v);
};
void SelectSort::doSort() {
    int n = num.size();
    selectSort(num);
}
void SelectSort::selectSort(vector<int>&v) {
    int n = v.size();
    //每次为a[i]选到一个最小值
    for(int i = 0; i < n; ++ i) {
        for(int j = i + 1; j < n; ++ j) {
            if(v[j] < v[i]) {
                v[j] = v[i] ^ v[j];
                v[i] = v[i] ^ v[j];
                v[j] = v[i] ^ v[j];
            }
        }
    }
}
