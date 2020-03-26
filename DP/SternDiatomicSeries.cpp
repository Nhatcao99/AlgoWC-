//
// Created by Cao Minh Nhat on 3/26/20.
//
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0, arr[1] = 1;
    for(int i = 2; i <= n ; i ++){
        if(i % 2 == 0){
            arr[i] = arr[i / 2];
        }
    }
    for(int i = 2; i <= n ; i ++){
        if(i % 2 != 0){
            arr[i] = arr[(i - 1) / 2] + arr[(i + 1) / 2];
        }
    }
    cout << arr[n];
}
