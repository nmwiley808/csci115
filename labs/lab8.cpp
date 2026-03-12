#include <iostream>
#include "List.h"

using namespace std;

int main() {
    BST tree;
    int values[] = {7, 20, 8, 9, 6, 1, 19, 15, 2, 10};

    cout << "Inserted elements: ";
    for (int val : values) {
        cout << val << " ";
        tree.Insert(val);
    }

    cout << "\n\nPost-order: ";
    tree.PrintPostOrder();
    cout << endl;

    tree.PrintLargest();

    int lookup;
    cout << "\nInsert a number for look up >> ";
    cin >> lookup;
    tree.Find(lookup);

    cout << "\nInsert a number for look up >> ";
    cin >> lookup;
    tree.Find(lookup);

    return 0;
}
