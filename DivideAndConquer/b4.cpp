//find if x is majority using divide and conquer

#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x, int n){
    if(low <= high){
        int mid = (low + high) / 2;
        if((mid == 0 || arr[mid - 1] < x) && arr[mid] == x){
            return mid;
        }else{
            //consider two case:
            //arr[mid] < x
            // arr[min] >= mid
            if(arr[mid] < x){
                return binarySearch(arr,mid + 1,high,x,n);
            }else{
                return binarySearch(arr,low,mid - 1,x,n);
            }
        }
    }
    return -1;
}

bool isMajority(int arr[], int n, int x){
    int first_i = binarySearch(arr,0,n-1,x,n);
    if(first_i == -1) return false;
    if((first_i + n/2) <= (n-1) && arr[first_i] == x){
        return true;
    }return false;
}

int main(){
    int arr[7] = {1, 2, 3, 3, 3, 3, 10};
    int n = 7;
    int x = 3;
    cout << isMajority(arr,n,x);
}
