#ifndef HASHNODE_H
#define HASHNODE_H

#include <string>
using namespace std;

struct HashNode {
    int key;            // can be generic
    string value;       // can be generic
    HashNode* next;     // reference to next HashNode

    HashNode(int inputKey, const string& inputValue) : key(inputKey), value(inputValue), next(nullptr) {}
};

#endif
