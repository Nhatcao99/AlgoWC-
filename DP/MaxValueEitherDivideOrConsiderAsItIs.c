#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0, arr[1] = 1;
    for(int i = 2; i <= n; i ++){
        arr[i] = max(i,arr[i/5] + arr[i/4] + arr[i/3] + arr[i/2]);
    }
    cout << arr[n];
}
