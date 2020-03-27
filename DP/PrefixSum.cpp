#include<iostream>
using namespace std;

bool isValid(int x , int y){
    if((x < 0 || x > 3) || (y < 0 || x > 4)){
        return  false;
    }return true;
}
int main(){
    int arr[4][5] = { { 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1 },
                      { 1, 1, 1, 1, 1 } };

    for(int i = 0; i < 4 ; i ++){
        for(int j = 0; j < 5; j ++){
            if(isValid(i - 1,j)){
                arr[i][j] += arr[i - 1][j];
            }
            if(isValid(i, j - 1)){
                arr[i][j] += arr[i][j - 1];
            }
            if(isValid(i - 1, j - 1)){
                arr[i][j] -= arr[i - 1][j - 1];
            }
            cout << arr[i][j] << " ";
        }cout << "\n";
    }
}