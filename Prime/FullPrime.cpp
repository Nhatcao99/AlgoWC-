#include<iostream>
#include<map>
#include<cctype>
#include<cmath>
#include<string>
using namespace std;

bool isPrime(int n){
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
    int T, n;
    scanf("%d",&T);
    bool prime[100001] = {false};
    for(int i = 2; i < 100001; i ++){
        if(isPrime(i)){
            prime[i] = true;
        }
    }
    for(int c = 0; c < T; c ++){
        scanf("%d",&n);
        bool flag = true;
        if(prime[n]){
            string tmp = to_string(n);
            for(int i = 0; i < tmp.length(); i ++){
                int num = tmp[i] - '0';
                if(!prime[num]){
                    flag = false; break;
                }
            }
        }else flag = false;
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
