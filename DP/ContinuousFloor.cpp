#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int floors[21];
    int arr[] = {6, 8};
    floors[0] = 0;
    for(int i = 0; i <= 20 ; i ++){
        floors[i] = floors[i / 2] + i;
    }
    cout << floors[arr[0]] << " " << floors[arr[1]];
}