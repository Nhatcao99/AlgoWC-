#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int jab[n + 1] , jab_lucas[n + 1];
    jab[0] = 0 , jab[1] = 1 , jab_lucas[0] = 2 , jab_lucas[1] = 1;
    for(int i = 2; i <= n ; i ++){
        jab[i] = jab[i - 1] + 2 * jab[i - 2];
        jab_lucas[i] = jab_lucas[i - 1] + 2 * jab_lucas[i - 2];
    }
    cout << jab[n] << " " << jab_lucas[n];
}