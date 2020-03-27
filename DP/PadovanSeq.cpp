#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 1, arr[1] = 1, arr[2] = 1;
    for(int i = 3; i < n; i ++){
        arr[i] = ((arr[i - 2] % 1000000007) + (arr[i - 3] % 1000000007)) % 1000000007;
    }
    cout << arr[i] << " ";
}