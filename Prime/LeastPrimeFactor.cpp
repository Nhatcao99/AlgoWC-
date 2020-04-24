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
}return true;}
int main(){
    int T, n;
    int prime[1001] = {false};
    bool visited[1001] = {false};
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d",&n);
        printf("%d ",1);
        for(int i = 2; i <= n; i ++){
            if(!visited[i] && isPrime(i)){
                int index = 1;
                while(index * i < 1001){
                    if(!visited[index * i]){
                        visited[index * i] = true;
                        prime[index * i] = i;
                    }
                    index ++;
                }
                prime[i] = i;
            }printf("%d ",prime[i]);
        }
        printf("\n");
    }
}
