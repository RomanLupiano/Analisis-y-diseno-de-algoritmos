#include <iostream>
#include <string>

using namespace std;


int binarySearch(int arr[], int min, int max, int number){
    if (min > max) {
        return -1;
    }

    int mid = (max + min) / 2;
    if (arr[mid] == number){
        return mid;
    }

    if (number > arr[mid]){
        return binarySearch(arr, mid+1, max, number);
    }

    return binarySearch(arr, min, mid-1, number);
}

int main (){
    int array [] = {-1, 0, 2, 5, 6, 7, 9, 11, 12, 13};
    int find = 12;
    int max = sizeof(array) / sizeof(array[0]);
    int pos = binarySearch(array, 0, max, find);
    cout << pos;
    return 0;
}