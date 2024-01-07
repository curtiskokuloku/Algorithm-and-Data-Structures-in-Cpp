# C++ Cheat-sheet

## MAX, MIN VALUE

```cpp
#include <climits>
INT_MAX = ~(1 << 31)    // For 64-bit machine
INT_MIN = 1 << 31       // for 64bit machine
UINT_MAX = (uint)(~0)   // 32 bit all equal 1
LONG_MAX
LONG_MIN
ULONG_MAX
```

## string, char, int conversion

```pseudo
[int to string]         to_string(num);
[string to int]         stoi(s);            // i.e.  int val = stoi("1024");
[char to string]        string(1, ch); 
[charr array to string] string(charArr);
```

## string

- **Recall: In C++, string is mutable**

```cpp
string(char[] chArr) or string(char* chArr);    // string constructor
string(int n, char ch);                         // string constructor with n characters of ch

string str = "1234";
str[i];                                         // access ith character
str.size();  or str.length();
str.substr(start);                              // [start,  )              
str.substr(start, length);                      // [start, start + length - 1]
                                                // str doesn't change 

str.append("abc");                              
str.append(1, 'a');                             // append character
size_t found = str.find("ab");                  // return pos where "ab" first occur in str.  NOTE: the return pos is size_t !!!
if (found!=string::npos)  cout << "found";      // Prints "found" if "ab" is found (pos found)

str.erase(2);                                   // erase substring starting from 2.   [2, )    str changes !!!!!!!!!  str = "12"
str.erase(pos, length);                         // erase length characters starting from pos 
str.insert(2, "sz");                            // insert characters starting from pos 2.      str changes !!!!!!!!!  str = "12sz"
str.replace(pos, len, "newStr");                // replace substring starting from pos with length = len as "newStr"

str1.compare(str2);                             // 0 if equal; -1 if str1 comes first in lexicographic order; > 0 otherwise
void reverse(str.begin(), str.end());           // reverse string.       str changes!!!!!!!!!!  no return value

#include <sstream>                              // similar to StringBuilder in Java
stringstream ss;
ss << "year" << ' ' << 2017;                    // accept char, string and number(int, float, double)
ss.str();                                       // convert sstream to string    ss = "year 2017"

string input = "abc,def,ghi";                   // to implement the function like split(",") in Java
istringstream ss(input);
string token;

while(getline(ss, token, ',')) {                // if the delimiter is '\' we should use '\\' to explicitly specify the delimiter
    cout << token << '\n';
}
```

## Arrays

```cpp
int nums[10] = {0};
[array to vector]  vector<int> vec(&nums[0], &nums[10]);
```

## Vectors

```cpp
#include <vector>
vector<int> v;                                  // Vector of integers
vector<int> v(size, 0);                         // Create a vector with length of size and initialize all elements to 0
vector<vector<int>> v(N, vector<int>(M, 0));    // Initialize N * M 2d vector to zero

int val = v[i];             // (Random) Access ith element in vector v
v.empty();                  // Return bool to indicate empty or not; true = empty; false = not empty
v.push_back(e);             // Insert element to end    NOTE: void push_back(const type& val);
v.pop_back();               // Delete last element      NOTE: void pop_back(void);
v.clear();                  // Clear all elements
v.front();                  // Return first element     NOTE: reference front(void);
v.back();                   // Return last element
v.at(i);                    // Return ith element
v.begin();                  // Return iterator pointing to first element;    
v.end();                    // Return iterator pointing to null behind last element;
v.erase(v.begin() + 5);     // Delete 6th element; Can remove a range of elements ([first,last))
v.insert(v.begin(), var)    // Insert var in first position
                            //      std::vector<int> v (3,100);         // v = [100, 100, 100]
                            //      int arr [] = { 501,502,503 };
                            //      v.insert (v.begin(), arr, arr+3);   // v = [501, 502, 503]
vector<int>::iterator it = v.begin()
for(; it != v.end(); ++it) {
    cout << *it << endl;
}

v.resize(num);                      // Resize the length of vector
v.resize(num, val);                 // Resize vector by using val to padding  (default is 0);

#include <algorithm>
sort(v.begin(), v.end());           // Sort vector from min to max by default

struct cmp{
    bool operator() (int x, int y){
        return x > y;               // Descending order
    }
} cmpObj;
sort(v.begin(), v.end(), cmpObj);   // Sort with self-defined comparator
```

## unordered_map, map, unordered_set, set

```cpp
#include <unordered_map>
unordered_map<int, string> Map;                         // O(1) or constant time complexity     Map = {key(int) : value(string)}

#include <map>
map<int, string> treeMap;                               // O(logN) time complexity

Map[1] = "one";                                         // Insert     := equivalent to map.put(key, val)
string str = Map[1];                                    // Get        := equivalent to map.get(key)
if(Map.find(1) != Map.end()) cout << Map[1] << endl;    // Search key := equivalent to map.containsKey(key)
Map.erase(1);                                           // Delete     := equivalent to map.remove(key)

unordered_map<int, string>::iterator it = Map.find(1);  // Find by key
if(it != Map.end()) cout << it->second; 
else cout << "not found"; 

for(it = Map.begin(); it != Map.end(); ++it)
    cout << it->first << it->second <<end;              // Traverse

Map.erase("one");   // Delete
Map.empty();        // Return true if map is empty; false otherwise
Map.clear();        // Clear all elements from map
Map.size();         // Return the number of elements

unordered_set<int> Set; 
Set.insert(val);
Set.erase(val);
Set.erase(iterator);
Set.size();
Set.empty();
if(Set.find(1) != Set.end()) cout << "found" << endl;   // Find val  equivalent to set.contains(val)
for(iter = Set.begin(); iter != Set.end(); ++iter)      // Traverse
    cout << *iter <<endl;

set<int>::iterator it = Set.upper_bound(val);           // Return iterator pointing to first element after val             > val
set<int>::iterator it = Set.lower_bound(val);           // Return iterator pointing to first element not goes before val   >= val

struct cmp {
    bool operator()(Node* a, Node* b){
        return (a->val) < (b->val);
    }
};
set<Node*, cmp> s;                                      // Initialize ordered set with comparator
```

## stack, queue, heap, deque

```cpp
#include <stack>
#include <queue>
#include <priority_queue>

stack<int> s;
queue<int> q;

s.top();        // Access the top element in stack
s.push(val);    // Insert val at top of stack           NOTE: void push(type& value);
s.pop();        // Remove element at the top            NOTE: void pop(void);

q.front();      // Access the first element in queue    NOTE: void front(void);
q.pop();        // Remove first element from queue      NOTE: void pop(void);
q.empty();      // Check if queue is empty

priority_queue<int> pq;         // Max heap by default
pq.push(val);
pq.top();                       // Access first element
pq.pop();                       // Pop out first value, does not return element !!!!!

struct cmp{
  bool operator()(Node* a, Node* b){
    return a -> x > b -> x;                    // Build min heap               
  }
};

priority_queue<Node*, vector<Node*>, cmp> pq;  // NOTE:  the format is different for sort function!!!
pq.push(new Node(1, 2));

#include <deque>

deque<int> dq(2,0);
dq.push_back(1);
dq.push_front(-1);
cout << dq[0] << endl;
```

## pair / make_pair

```cpp
#include <utility>

pair<int, int> pr;
pr = make_pair(2, 3);           // Generate pair
cout << pr.first << endl;       // Access first value
cout << pr.second << endl;      // Access second value
```

## rand / srand

- **int rand(void);**
  - Returns a pseudo-random number in the range of `[0, RAND_MAX)`

```cpp
#include <stdlib.h>
#include <time.h>

srand((unsigned)time(0));       // Initialize rand seed
(rand()%(b-a))+ a;              // Random number from [a, b)
(rand()%(b-a+1))+ a;            // Random number from [a, b]
(rand()%(b-a))+ a + 1;          // Random number from (a, b)
(rand() % len + a);             // Random number from [a, len + a)
rand() / double(RAND_MAX);        // random floating number from [0.0, 1.0]
// c++ 11 supports default_random_engine
default_random_engine eng;
eng() % len;               // [0, len)
```

## math

```cpp
#include <math.h>

M_PI                        // pi in math
cos(angle)                  // cos takes angle in rad as input; rad = theta * M_PI / 180
acos(angle) = arc_angle;    // acos of angle (in rad); acos(-1) = M_PI;
sqrt(x)                     // Compute square root of x
round(x)                    // Round x value to closest integer
pow(n, k);                  // Compute n^k
```

## Format Output

```cpp
#include <iomanip>

const double value = 12.3456789;
cout << setprecision(4) << value << endl;           // 12.35
cout << fixed << setprecision(4) << value << endl;  // 12.3457

/* round vs floor vs ceil vs trunc */
#include <stdio.h>      /* printf */
#include <math.h>       /* round, floor, ceil, trunc */

const char * format = "%.1f \t%.1f \t%.1f \t%.1f \t%.1f\n";
printf ("value\tround\tfloor\tceil\ttrunc\n");
printf ("-----\t-----\t-----\t----\t-----\n");
printf (format, 2.3,round( 2.3),floor( 2.3),ceil( 2.3),trunc( 2.3));
```

## swap reference / pointer

- In bfs, we use two queues in Java.
- Similarly, we can swap two containers in C++

```cpp
cur.swap(next);     // Swap cur and next reference; map, set, queue, vector
```

- In cpp, the operator precedence is:  () > [] > *  >  >>  > &
  - That is: Function call > Array subscripting > Dereference > Bitwise shift > Bitwise AND

## rotate

```cpp
void rotate (Iterator first, Iterator middle, Iterator last);
// Rotates elements in the range [first,last), the element pointed by middle becomes the new first element.

// Example:
for (int i=1; i<10; ++i) vec.push_back(i);      // 1 2 3 4 5 6 7 8 9
rotate(vec.begin(),vec.begin()+3,vec.end());    // 4 5 6 7 8 9 1 2 3
```

## Node

```cpp
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class Node {
public:
    int x;
    int y;
    Node(int x, int y){
        this->x;
        this->y;
    }
    friend operator < (Node& a, Node& b){
        return this.x - that.y;
    }
    void print(){
        cout<< this->x << this->y <<endl;
    }
};
```

## Pointer

```cpp
Node* p = new Node(x, y);
p->x;                   // access class members;
p->print();             // access class member function;
delete p;
```
