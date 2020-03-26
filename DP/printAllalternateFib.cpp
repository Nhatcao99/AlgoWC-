//
// Created by Cao Minh Nhat on 3/26/20.
//
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int number1 = 0 , number2 = 1;
    for(int i = 2 ; i <= n ; i ++){
        int number3 = number1 + number2;
        if(i % 2 == 0) cout << number3 << " ";
        number1 = number2;
        number2 = number3;
    }
}