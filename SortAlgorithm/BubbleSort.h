class BubbleSort : public Sort{
public:
    void doSort() override;
private:
    void bubbleSort(vector<int>&v);
};
void BubbleSort::doSort() {
    bubbleSort(num);
}
void BubbleSort:: bubbleSort(vector<int>&v) {
    int n = v.size();
    //将最大数移到右边
//    for(int i = 0; i < n - 1; ++ i) {
//        for(int j = 1; j < n - i; ++ j) {
//            if(v[j] < v[j - 1]) {
//                v[j] = v[j] ^ v[j - 1];
//                v[j - 1] = v[j] ^ v[j - 1];
//                v[j] = v[j] ^ v[j - 1];
//            }
//        }
//    }
    //将最小数移到左边
    for(int i = 0; i < n - 1; ++ i) {
        for(int j = n - 1; j >= i + 1; -- j) {
            if(v[j] < v[j - 1]) {
                v[j] = v[j] ^ v[j - 1];
                v[j - 1] = v[j] ^ v[j - 1];
                v[j] = v[j] ^ v[j - 1];
            }
        }
    }
}