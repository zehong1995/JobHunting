//#include "Sort.h"
#include "QuickSort.h"
#include "SelectSort.h"
int main() {
    srand(time(NULL));
    cout << "Test Quick Sort:" << endl;
    shared_ptr<Sort>sortPtr(new QuickSort);
    sortPtr->test_by_rand(100, 10000);

    cout << "Test Select Sort:" << endl;
    sortPtr.reset(new SelectSort);
    sortPtr->test_by_rand(100, 1000);
}
