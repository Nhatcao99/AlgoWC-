#include<iostream>
#include<unordered_set>
#include<cctype>
#include<cmath>
using namespace std;

int BinomialCoeff(int n , int k){
    int C[k + 1] = {0};
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    } return C[k];
}

int main(){
    int T,n,r;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d %d",&n,&r);
        printf("%d\n",BinomialCoeff(n,r));
    }
}

