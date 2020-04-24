#include<iostream>
#include<map>
#include<cctype>
#include<cmath>
using namespace std;
bool isPrime(int n ){
    if(n < 2) return false;
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0){
            return false;
        }
    }return true;
}
int main()
{
    int T, m, n;
    scanf("%d",&T);
    bool prime[100001] = {false};
    bool visited[100001] = {false};
    for(int i = 0; i < 100001; i ++){
        prime[i] = false;
        visited[i] = false;
    }
    for(int c = 0; c < T; c ++){
        scanf("%d %d",&m,&n);
        for(int i = m; i <= n; i ++){
            if(!visited[i] && isPrime(i)){
                int index = 1;
                while(index * i < 100001){
                    visited[index * i] = true;
                    index ++;
                }
                if(isPrime(i)){
                    prime[i] = true;
                    printf("%d ",i);
                }
            }else{
                if(prime[i]){
                    printf("%d ",i);
                }
            }
        }printf("\n");
    }
    return 0;
}