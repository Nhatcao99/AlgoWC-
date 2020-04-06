#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high) {
    if (high >= low) {
        int mid = (low + high) / 2; /*low + (high - low)/2;*/ if (mid == arr[mid])
            return mid;
        if (mid > arr[mid])
            return binarySearch(arr, (mid + 1), high);
        else
            return binarySearch(arr, low, (mid - 1));
    }
}

int main(){
    int arr[] = {-10, -5, 0, 3, 7};
    int size = sizeof(arr)/sizeof(*arr);
    cout << binarySearch(arr,0,size);
}
