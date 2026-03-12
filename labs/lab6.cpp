#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int low, int high, int choice) {
    int pivotIndex = low;
    if (choice == 2) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(low, high);
        pivotIndex = dis(gen);
    } else if (choice == 3) {
        pivotIndex = low + (high - low) / 2;
    }

    int pivot = arr[pivotIndex];
    swap (arr[pivotIndex], arr[high]);
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap (arr[j], arr[i]);
        }
    }

    swap (arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high, int choice) {
    if (low < high) {
        int par = partition(arr, low, high, choice);
        quickSort(arr, low, par - 1, choice);
        quickSort(arr, par + 1, high, choice);
    }
}

int main() {
    int choice;
    cout << "Choice a pivot method:\n"
         << "1. First Element\n"
         << "2. Random Element\n"
         << "3. Median Element\n";
    cin >> choice;

    vector<int> arr = {42, 5, 16, 8, 23, 0, 66, 76, 25, 10, 44, 19, 3, 1};

    auto start = high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1, choice);
    auto stop = high_resolution_clock::now();

    duration<double> elapsed = stop - start;
    cout << "\nSorting duration: " << elapsed.count() << " seconds\n";

    cout << "Sorted Array: ";
    for (const int num: arr | views:: all) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
