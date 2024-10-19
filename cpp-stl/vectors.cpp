#include<bits/stdc++.h>
using namespace std; 

int main() {
    vector <int> v; // vectors are dynamic

    v.push_back(1); // {1}
    v.emplace_back(2);  // {1, 2}

    vector <pair<int, int>> vec; 

    vec.push_back({1, 2});    // have to use {} for assigning a pair
    vec.emplace_back(3, 4);  // emplace_back assumes it as pair

    vector <int> ve(5, 100); 

    vector <int> vect(5); // if we push_back new element even after predefining the size it'll dynamically increase the size and store more elements

    vector <int> v1(5, 20); 
    vector <int> v2(v1); // v2 will store a copy of v1

    // vector's indexing is similar to arrays
    cout << v[0]; 

    vector<int>::iterator it = v.begin(); 
    it++; 
    cout << *(it) << " " << endl; 

    it = it + 2; 
    cout << *(it) << " " << endl; 

    // {10, 20, 30, 40}
    vector<int>:: iterator it = v.end(); // it will point to right after 40. In this iterator we have to do it-- then it'll move to 40.
    vector<int>:: iterator it = v.rend(); 
    vector<int>:: iterator it = v.rbegin();

    cout << v.back(); // 40

    // printing vectors:
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " "; 
    }

    // shortened way:
    for (auto it = v.begin(); it != v.end(); it++) // according to the data the data type is automatically assigned
    {
        cout << *(it) << " ";
    }

    for (auto it : v)
    {
        cout << it << " "; 
    }
    
    // deletion in vectors: 
    v.erase(v.begin() + 1); 
    // {10, 20, 12, 23, 35} 
    v.erase(v.begin() + 2, v.begin() + 4); // {10, 20, 35}

    // insertion: 
    vector<int>v(2, 100);       // {100, 100}
    v.insert(v.begin(), 300);  // {300, 100, 100}
    v.insert(v.begin(), 2, 5); // {5, 5, 300, 100, 100}

    vector<int>copy(2, 50); 
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 5, 5, 300, 100, 100}

    v.size();    // length
    v.pop_back(); // pops last element
    v1.swap(v2); // swaps two vectors
    v.clear(); // empty the vector
    cout << v.empty(); // boolean values if vector is empty or not
}

