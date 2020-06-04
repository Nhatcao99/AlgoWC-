//
// Created by Cao Minh Nhat on 6/4/20.
//

//fill 3 x n board with 2 x 1 dominoes
#include <iostream>
using namespace std;
int main(){
    int A[101] , B[101];
    A[0] = 1, A[1] = 0, B[0] = 0 , B[1] = 1;
    for(int i = 2; i <= 100 ; i ++){
        A[i] = A[i - 2] + 2 * B[i - 1];
        B[i] = A[i - 1] + B[i - 2];
    }
    cout << A[8];
}