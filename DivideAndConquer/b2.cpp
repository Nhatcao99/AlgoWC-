#include <iostream>
using namespace std;

// Div and Con:
// find the first element
// find the last element
// use the index_last - index_first + 1 == the number of element
int first(int arr[], int low, int high, int x , int n){
    if(low <= high){
        int mid = (low + high) / 2;
        if((mid == 0 || arr[mid - 1] < x) && arr[mid] == x){
            // as array is sorted if mid != 0 , and is first element
            // it must bigger then previous
            return mid;
        }else if(arr[mid] < x){
            return first(arr,mid + 1,high,x,n);
        }else{
            return first(arr,low,mid - 1,x,n);
        }
    }
    return -1;
}

int last(int arr[], int low , int high , int x ,int n){
    if(low <= high){
        int mid = (low + high) / 2;
        if((mid == n - 1 || arr[mid + 1] > x) && arr[mid] == x) {
            return mid;
        }else if(x < arr[mid]){
            return last(arr,low,mid - 1, x, n);
        }else{
            return last(arr,mid + 1,high,x,n);
        }
    }
    return -1;
}

int count(int arr[], int x, int n){
    int index_fist;
    int index_last;
    index_fist = first(arr,0,n-1,x,n);
    if(index_fist == -1) return -1;
    //if first is available of course it can be also be last
    // so index_last need no condition
    index_last = last(arr,index_fist,n-1,x,n);
    return index_last - index_fist + 1;
}

int main(){
    int arr[] = {1,1,2,2,2,2,3};
    int x = 5;
    int size = sizeof(arr)/sizeof(*arr);
    cout << count(arr,x,7);
}