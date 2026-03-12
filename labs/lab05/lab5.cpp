#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Counting Sort Function
void countingSort(vector<int>& arr, int exp = 1) {
    int n = arr.size();
    vector<int> output(n);
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(10, 0);

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build Output Array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy back original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort Function
void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());

    // Apply the counting sort for each digit
    for (int exp = 1; maxElement / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr1 = {2, 0, 2, 5};
    vector<int> arr2 = {50, 3, 324, 132, 495, 21, 345, 0, 43, 1};

    // Counting Sort Execution
    vector<int> countArr = arr1;
    clock_t start = clock();
    countingSort(countArr);
    clock_t end = clock();
    cout << "Counting Sort Result: ";
    for (int num : countArr) cout << num << " ";
    cout << "\nTime taken : " << (double) (end - start) / CLOCKS_PER_SEC << endl;

    // Radix Sort Execution
    vector<int> radixArr = arr2;
    start = clock();
    radixSort(radixArr);
    end = clock();
    cout << "Radix Sort Result: ";
    for (int num : radixArr) cout << num << " ";
    cout << "\nTime taken : " << static_cast<double>(end - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
