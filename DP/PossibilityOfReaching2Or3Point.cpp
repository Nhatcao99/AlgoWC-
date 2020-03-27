#include<iostream>
using namespace std;

int main(){
    int n ;
    float p;
    cin >> n >> p;
    float posi[n + 1];
    posi[0] = 1; // you can just stand there
    posi[1] = 0; // no way you can reach 1 with 2 or three step
    posi[2] = p; // must take to step
    posi[3] = 1 - p; // you must take 3 step
    for(int i = 4; i <= n ; i ++){
        posi[i] = p * posi[i - 2] + (1-p) * posi[i - 3];
    }
    cout << posi[n];
}