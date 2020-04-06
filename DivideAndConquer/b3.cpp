//find max min
//using div and conquer almost like mergesort
#include <iostream>
#include <cmath>
using namespace std;

struct minmax{
    int min;
    int max;
};

struct minmax getMinMax(int arr[], int low, int high){
        struct minmax mm , lmm, rmm; // mimax, left minimax , right minimax
        if(low == high){ // n == 1 --> both max and min
            mm.min = arr[low];
            mm.max = arr[low];
            return mm;
        }
        if(low == high - 1){ // n == 2 -> the bigger is max , smaller is min
            mm.max = max(arr[low],arr[high]);
            mm.min = min(arr[low],arr[high]);
            return mm;
        }
        int mid = (low + high) / 2;
        lmm = getMinMax(arr,low,mid);
        rmm = getMinMax(arr,mid + 1,high);
        mm.min = min(lmm.min,rmm.min);
        mm.max = max(lmm.max,rmm.max);
        return mm;
}

int main(){
    int arr[] = {1,1,2,-5,2,7,2,2,3,6,6};
    int size = sizeof(arr)/sizeof(*arr);
    struct minmax result = getMinMax(arr,0,size-1);
    cout << result.min << " " << result.max;
}