#include <iostream>
#include <string>

using namespace std;

void merge(int arr [], int start, int mid, int end){
    int temp [(end - start + 1)];

    int i = start,      //index for the left half
        j = mid + 1,    //index for the right half
        k = 0;          //index for temp.

    // Merge both halves into temp[] in sorted order
    while (i <= mid && j <= end){   //while the sub-arrays has element
        if (arr[i] <= arr[j]){      //insert the numbers sorted in temp.
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {      // Copy any remaining elements from the left half
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end) {      // Copy any remaining elements from the right half
        temp[k] = arr[j];
        k++;
        j++;
    }

    // Copy the sorted temp[] back into the original array
    for ( k = start; k <= end; k++){
        arr[k] = temp[k - start];
    }
    
}

void mergeSort(int arr [], int start, int end){
    if (start < end){
        unsigned int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr [] = {6, 3, 7, 2, 5, 9, 0, -1, 1, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size);
    cout << "Sorted with MergeSort" << endl;
    mergeSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}