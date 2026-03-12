#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to measure sorting time
void measureSortingTime(vector<int> arr, void (*sortFunction)(vector<int>&), const string& sortName, const string& caseType) {
    cout << sortName << " - " << caseType << " Before Sorting: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << sortName << " - " << caseType << " After Sorting:  ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << sortName << " - " << caseType << ": " << duration.count() << " milliseconds" << endl;
    cout << "------------------------------------------------------" << endl;
}

int main() {
    vector<int> sortedList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> halfSortedList = {1, 3, 2, 5, 4, 7, 6, 9, 8, 10};
    vector<int> reversedList = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    measureSortingTime(sortedList, selectionSort, "Selection Sort", "Sorted List");
    measureSortingTime(halfSortedList, selectionSort, "Selection Sort", "Half-Sorted List");
    measureSortingTime(reversedList, selectionSort, "Selection Sort", "Reversed List");

    measureSortingTime(sortedList, [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, "Merge Sort", "Sorted List");
    measureSortingTime(halfSortedList, [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, "Merge Sort", "Half-Sorted List");
    measureSortingTime(reversedList, [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }, "Merge Sort", "Reversed List");

    return 0;
}


