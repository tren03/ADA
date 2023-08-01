#include <iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

// Merge two sorted arrays into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n = right - left + 1;
    int tempArray[n]; // Temporary array to hold the elements

    int i = left;    // Index for the left subarray
    int j = mid + 1; // Index for the right subarray
    int k = 0;       // Index for the temporary array

    // Merge the two subarrays into the temporary array
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArray[k] = arr[i];
            i++;
        } else {
            tempArray[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of the left subarray (if any)
    while (i <= mid) {
        tempArray[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of the right subarray (if any)
    while (j <= right) {
        tempArray[k] = arr[j];
        j++;
        k++;
    }

    // Copy the elements from the temporary array back to the original array
    for (int x = 0; x < n; x++) {
        arr[left + x] = tempArray[x];
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Sort the two halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);
}

int main() {
    // int arr[] = {12, 11, 13, 5, 6, 7};
    int size=1000;
    int arr[size];
    // int n = sizeof(arr) / sizeof(arr[0]);    
    for(int i=0;i<size;i++)
    {
        arr[i]=rand()%1000;
    }

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    auto startTime = std::chrono::high_resolution_clock::now();



    mergeSort(arr, 0, size - 1);

   auto endTime = std::chrono::high_resolution_clock::now();



    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    std::cout<<"time = "<< fixed << duration << " microseconds" << std::endl;


    return 0;
}
