#include <iostream>
#include "HeapSortHeader.h"

using namespace std;

Heap::Heap() {}

void Heap::printArray(int Arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << Arr[i] << " ";
       cout << endl;
}

// Max Heap Functions
void Heap::max_heapify(int Arr[], int i, int n) {
    int largest = i;
    int left = 2* i + 1;
    int right = 2 * i +2;

    if (left < n && Arr[left] > Arr[largest])
        largest = left;

    if (right < n && Arr[right] > Arr[largest])
        largest = right;

    if (largest != i) {
        swap(Arr[i], Arr[largest]);
        max_heapify(Arr, largest, n);
    }
}

void Heap::buildMaxHeap(int Arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(Arr, i, n);
}

void Heap::ascendingHeapSort(int Arr[], int n) {
    buildMaxHeap(Arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(Arr[0], Arr[i]);
        max_heapify(Arr, 0, i);
    }
}

int Heap::extract_maximum(int Arr[], int &n) {
    if (n<= 0)
        return -1;
    int maxVal = Arr[0];
    Arr[0] = Arr[n-1];
    n--;
    max_heapify(Arr, 0, n);
    return maxVal;
}

void Heap::insert_value_maxHeap(int Arr[], int val, int &n) {
    Arr[n] = val;
    int i = n;
    n++;
    while (i > 0 && Arr[(i-1) / 2] > Arr[i]) {
        swap(Arr[i], Arr[(i-1) / 2]);
    }
}

int n;
// Min Heap Function
void Heap::min_heapify(int Arr[], int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (right < n && Arr[right] < Arr[smallest])
        smallest = left;

    if(right < n && Arr[right] > Arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(Arr[i], Arr[smallest]);
        min_heapify(Arr, smallest);
    }
}

void Heap::buildMinHeap(int Arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(Arr, i);
}

void Heap::descendingHeapSort(int Arr[], int n) {
    buildMinHeap(Arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(Arr[0], Arr[i]);
        min_heapify(Arr, 0);
    }
}

int Heap::extract_minimum(int Arr[]) {
    if (n <= 0)
        return -1;
    int minVal = Arr[0];
    Arr[0] = Arr[n - 1];
    n--;
    min_heapify(Arr, 0);
    return minVal;
}

void Heap::insert_value_minHeap(int Arr[], int val, int &n) {
    Arr[n] = val;
    int i = n;
    n++;
    while (i > 0 && Arr[(i-1) / 2] < Arr[i]) {
        swap(Arr[i], Arr[(i-1) / 2]);
        i = (i - 1) / 2;
    }
}

// Main function for user input
int main() {
    Heap heap;
    int choice, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int Arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> Arr[i];

    cout << "Choose operation:\n1. Build Max Heap\n2. Build Min Heap\n";
    cin >> choice;

    if (choice == 1) {
        heap.buildMaxHeap(Arr, n);
        cout << "Max Heap: ";
        heap.printArray(Arr, n);
    }else{
        heap.buildMinHeap(Arr, n);
        cout << "Min Heap: ";
        heap.printArray(Arr, n);
    }

    cout << "Choose sorting order:\n1. Ascending (Heapsort)\n2. Descending (Heapsort)\n";
    cin >> choice;
    if (choice == 1) {
        heap.ascendingHeapSort(Arr, n);
        cout << "Sorted (Ascending): ";
    } else {
        heap.descendingHeapSort(Arr, n);
        cout << "Sorted (Descending): ";
    }
    heap.printArray(Arr, n);

    cout << "Choose operation:\n1. Extract Max\n2. Extract Min\n";
    cin >> choice;
    if (choice == 1)
        cout << "Extracted Max: " << heap.extract_maximum(Arr, n) << endl;
    else
        cout << "Extracted Min: " << heap.extract_minimum(Arr) << endl;

    heap.printArray(Arr, n);

    return 0;
}
