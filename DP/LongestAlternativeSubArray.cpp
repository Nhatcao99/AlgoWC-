#include <iostream>
using namespace std;

int main(){
    int arr[] = {-5, -1, -1, 2, -2, -3};
    int lai[] = {1, 1, 1, 1, 1, 1};
    for(int i = 4 ; i >= 0; i --){
        if((arr[i] * arr[i + 1] < 0) && lai[i] < lai[i + 1] + 1){
            lai[i] = lai[i + 1] + 1;
        }
    }
    for(int i = 0; i < 6;  i++) cout << lai[i] << " ";
}