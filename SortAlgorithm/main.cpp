#include "Sort.h"
#include "QuickSort.h"
#include "SelectSort.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "InsertSort.h"
int main() {
    srand(time(NULL));
    cout << "Test Quick Sort:" << endl;
    shared_ptr<Sort>sortPtr(new QuickSort);
    sortPtr->test_by_rand(100, 10000);

    cout << "Test Select Sort:" << endl;
    sortPtr.reset(new SelectSort);
    sortPtr->test_by_rand(100, 1000);

    cout << "Test Merge Sort:" << endl;
    sortPtr.reset(new MergeSort);
    sortPtr->test_by_rand(100, 10000);

    cout << "Test Bubble Sort:" << endl;
    sortPtr.reset(new BubbleSort);
    sortPtr->test_by_rand(100, 1000);

    cout << "Test Insert Sort:" << endl;
    sortPtr.reset(new InsertSort);
    sortPtr->test_by_rand(100, 1000);

    cout << "Test Shell Sort:" << endl;
    sortPtr.reset(new ShellSort);
//    sortPtr->test_by_person(10);
    sortPtr->test_by_rand(100, 1000);
}
