//
// Created by Cao Minh Nhat on 3/26/20.
//
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num0 = 0 , num1 = 1, num2 = 1 , num3 = 2;
    for(int i = 4; i <= n;  i++){
        int num4 = num0 + num1 + num2 + num3;
        num0 = num1;
        num1 = num2;
        num2 = num3;
        num3 = num4;
    }
    cout << num3;
}