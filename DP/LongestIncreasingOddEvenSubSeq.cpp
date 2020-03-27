#include <iostream>
using namespace std;
int main(){
    int arr[] = {1, 12, 2, 22, 5, 30, 31, 14, 17, 11};
    int lioes[10] = {0}; // last index of the odd even sub sequence
    for(int i = 0; i < 10; i ++) lioes[i] = 1;
    // lioes is the ending index of a seq
    //if lioes[i] == 1 that mean there is no sequence at that index
    for(int i = 1; i < 10; i ++){
        for(int j = 0; j < i; j ++){
            if(((arr[i] + arr[j]) % 2 != 0) && (arr[j] < arr[i]) && (lioes[j] + 1 > lioes[i])) {
                lioes[i] = lioes[j] + 1;
            }
        }
    }
    int maximus = lioes[0];
    for(int i = 0; i < 10; i ++){
        if(maximus < lioes[i])
            maximus = lioes[i];
    }cout << maximus;
}