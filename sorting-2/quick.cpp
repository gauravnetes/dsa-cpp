#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pIndex = partition(arr, low, high);
            quickSort(arr, low, pIndex - 1); 
            quickSort(arr, pIndex + 1, high); 
        }
    }

    // Function that takes the first element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int i = low;
        int j = high;
        
        while (i < j) {
            // Move 'i' to the right until an element greater than pivot is found
            while (arr[i] <= pivot && i < high) {
                i++;
            }
            // Move 'j' to the left until an element less than or equal to pivot is found
            while (arr[j] > pivot && j > low) {
                j--;
            }
            // Swap elements at 'i' and 'j' if 'i' is still less than 'j'
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }
        // Place the pivot element at the correct position
        swap(arr[low], arr[j]);
        return j;  // Return the pivot index
    }
};
