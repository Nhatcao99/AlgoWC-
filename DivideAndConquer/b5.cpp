//count pair that a[i] > a[j] while i < j.

//enhanced merge sort

#include<iostream>
using namespace std;

int mergeSort(int arr[] , int temp[] , int low , int high);
int merge(int arr[] , int temp[] , int low, int mid , int high);
int mergeSort(int arr[] , int temp[] , int low , int high){
    int mid , count_inv = 0;
    if(low < high){
        mid = (low + high) /2;
        count_inv += mergeSort(arr,temp,low,mid);
        count_inv += mergeSort(arr,temp,mid + 1,high);
        count_inv += merge(arr,temp,low,mid + 1,high);
    } return count_inv;
}

int merge(int arr[] , int temp[] , int low, int mid , int high){
    int i = low , j = mid, k = low;
    int count_inv = 0;
    while((i <= mid - 1) && (j <= high)){
        if(arr[i] <= arr[j]){
            temp[k ++] = arr[i ++];
        }else{
            temp[k ++] = arr[j ++];

            count_inv += (mid - i);
        }
    }
    while(i <= mid - 1)
        temp[k ++] = arr[i ++];
    while(j <= high)
        temp[k ++] = arr[j ++];
    for(int i = low; i < high; i ++)
        arr[i] = temp[i]; // instead of returning an array we return int
        // so change the array
    return count_inv;
}

int main(){
    int arr[] = {1,20,6,4,5};
    int *temp = (int*)malloc(sizeof(int)*5);
    cout << mergeSort(arr,temp,0,4);
}
