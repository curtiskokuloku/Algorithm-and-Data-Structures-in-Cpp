#include <iostream>
#include "hash_node.h"
using namespace std;

class HashTable {
    public:
        HashNode** buckets;
        int numOfBuckets;       // capacity
        int size;               // number of key-value pairs in the hash table

        // Constructor
        HashTable(int capacity) : numOfBuckets(capacity), size(0) {
            buckets = new HashNode*[numOfBuckets];
            for (int i = 0; i < numOfBuckets; ++i) {
                buckets[i] = nullptr;
            }
        }

        // Determine if the hash table is empty, meaning there are no nodes in any bucket
        bool isEmpty() {
            return size == 0;
        }

        // Return a bucket index for the given key in the hash table
        int hashIndex(int key) {
            return key % numOfBuckets;
        }

        // Add a key-value pair in the hash table
        void put(int key, const string& value) {
            if (value.empty()) throw invalid_argument("Value is invalid!");

            HashNode* newNode = new HashNode(key, value);
            int bucketIndex = hashIndex(key);
            HashNode* head = buckets[bucketIndex];

            while (head != nullptr) {   // check for duplicates
                if (head->key == key) {
                    head->value = value;
                    return;
                }
                head = head->next;
            }

            size++;
            head = buckets[bucketIndex];
            if (head == nullptr) {
                buckets[bucketIndex] = newNode;
            } else {
                while (head->next != nullptr) { // handling collisions
                    head = head->next;
                }
                head->next = newNode;
            }
         }

        // Return the value of the given key in the hash table
         string get(int key) {
            string result = "";
            if (!isEmpty()) {
                int bucketIndex = hashIndex(key);
                HashNode* head = buckets[bucketIndex];
                while (head != nullptr) {
                    if (head->key == key) {
                        result = head->value;
                    } else {
                        result = "Not found";
                    }
                    head = head->next;
                }
            }
            return result;
        }

        // Remove a key-value pair in the hash table
        string remove(int key) {
            if (!isEmpty()) {
                int bucketIndex = hashIndex(key);
                HashNode* head = buckets[bucketIndex];
                HashNode* prev = nullptr;

                while (head != nullptr) {
                    if (head->key == key) {
                        if (prev == nullptr) { // node to be removed is first in the bucket
                            buckets[bucketIndex] = head->next;
                        } else {
                            prev->next = head->next;
                        }
                        size--;
                        return head->value;
                    }
                    prev = head;
                    head = head->next;
                }
            }
            return "";
        }

        // Return the hash index of the given key-value pair in the hash table
        int indexOf(int key, const string& value) {
            if (value.empty()) throw invalid_argument("Value is null!");
            int bucketIndex = hashIndex(key);
            HashNode* head = buckets[bucketIndex];
            while (head != nullptr) {
                if (head->key == key && head->value == value) {
                    return bucketIndex;
                }
                head = head->next;
            }
            return -1;  // not found
        }

        // Print out the hash index, key-value pair, and next node
        string display() {
            string result = "";
            for (int i = 0; i < numOfBuckets; i++) {
                HashNode* head = buckets[i];
                if (head != nullptr) {
                    HashNode* ptr = head;
                    result += to_string(i) + ": (" + to_string(ptr->key) + ", " + ptr->value + ") ";
                    while (ptr->next != nullptr) {
                        ptr = ptr->next;
                        result += "--> (" + to_string(ptr->key) + ", " + ptr->value + ") ";
                    }
                    result += "--> null \n";
                }
            }
            return result;
        }

        // Destructor
        ~HashTable() {
            for (int i = 0; i < numOfBuckets; ++i) {
                HashNode* head = buckets[i];
                while (head != nullptr) {
                    HashNode* next = head->next;
                    delete head;
                    head = next;
                }
            }
            delete[] buckets;
        }
};

int main() {
    // Create a hash table with a capacity of 10
    HashTable hashTable(10);

    // Adding key-value pairs
    hashTable.put(1, "One");
    hashTable.put(2, "Two");
    hashTable.put(3, "Three");
    hashTable.put(4, "Four");

    // Display the hash table
    cout << "Initial Hash Table:" << endl;
    cout << hashTable.display() << endl;

    // Retrieve values using keys
    cout << "Value of key 2: " << hashTable.get(2) << endl;
    cout << "Value of key 5: " << hashTable.get(5) << endl;

    // Remove a key-value pair
    cout << "Removing key 2: " << hashTable.remove(2) << endl;

    // Display the updated hash table
    cout << "Updated Hash Table:" << endl;
    cout << hashTable.display() << endl;

    // Finding the index of a key-value pair
    cout << "Index of key 3 and value 'Three': " << hashTable.indexOf(3, "Three") << endl;
    cout << "Index of key 4 and value 'Five': " << hashTable.indexOf(4, "Five") << endl;

    return 0;
}
