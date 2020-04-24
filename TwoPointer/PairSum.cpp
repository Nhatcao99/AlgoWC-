#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    long T , n , k;
    scanf("%ld",&T);
    for(int c = 0; c < T; c++){
        scanf("%ld",&n);
        long arr[n] , flag = 0;
        for(int i = 0; i < n; i ++){
            scanf("%ld",&arr[i]);
        }
        int l = 0, r = n - 1;
        scanf("%ld",&k);
        while(l < r){
            if(arr[l] + arr[r] == k){
                flag = 1;
                printf("%ld %ld %ld\n",arr[l],arr[r],k);
                l ++; r --;
            }else if(arr[l] + arr[r] < k) l ++;
            else r --;
        }if(flag == 0){
            printf("-1\n");
        }
    }
    return 0;
}

