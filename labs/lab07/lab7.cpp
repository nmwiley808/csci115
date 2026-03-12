#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

constexpr int HASHSIZE = 4001;  // Prime number for hashing

class HashTable {
private:
    vector<string> keys;
    vector<int> values;
    int numElements = 0;
    int lastProbes = 0;

    // Hash function: Sum of ASCII values % HASHSIZE
    static int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;  // Sum of ASCII values
        }
        return hash % HASHSIZE;
    }

public:
    HashTable() : keys(HASHSIZE, ""), values(HASHSIZE, 0) {}

    // Insert word or update count
    void update(const string& key) {
        int index = hashFunction(key);
        int probes = 1;

        while (!keys[index].empty() && keys[index] != key) {
            index = (index + 1) % HASHSIZE;  // Linear probing
            probes++;
        }

        if (keys[index].empty()) {
            keys[index] = key;
            values[index] = 1;
            numElements++;
            cout << "Inserted: " << key << " at index " << index << endl; // Debug print
        } else {
            values[index]++;
        }

        lastProbes = probes;
    }

    // Get number of unique words
    int size() const {
        return numElements;
    }

    // Get probes for last insertion
    int probes() const {
        return lastProbes;
    }
};

void processFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    HashTable hashTable;
    vector<int> updates(HASHSIZE, 0);
    vector<int> cost(HASHSIZE, 0);
    string word;

    while (file >> word) {
        // Convert to lowercase and remove punctuation
        string cleanWord;
        for (char c : word) {
            if (isalpha(c)) cleanWord += tolower(c);
        }

        if (!cleanWord.empty()) {
            hashTable.update(cleanWord);
            int size = hashTable.size();
            updates[size]++;
            cost[size] += hashTable.probes();
        }
    }

    // Output results
    cout << "Number of unique words: " << hashTable.size() << endl;
    cout << "Probe ratios (cost[i] / updates[i]):" << endl;
    for (int i = 1; i <= hashTable.size(); i++) {
        if (updates[i] > 0)
            cout << fixed << static_cast<double>(cost[i]) / updates[i] << ", ";
    }
    cout << endl;
}

int main() {
    processFile("RomeoAndJuliet.txt");
    return 0;
}
