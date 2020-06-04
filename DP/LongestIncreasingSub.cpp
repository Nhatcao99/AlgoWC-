#include<iostream>
#include<cctype>
using namespace std;
int longestIncSub(int arr[] , int n){
    int lis[n], maximus = 0;
    lis[0] = 1;
    
    for(int i = 1; i < n ; i ++){
        lis[i] = 1;
        for(int j = 0; j < i; j ++){ // it is subsequense not sub array
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        } if(lis[i] > maximus) maximus = lis[i];
    }  return maximus;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d",&n);
        int arr[n];
        for(int i = 0; i < n; i ++){
            scanf("%d",&arr[i]);
        }
        printf("%d\n",longestIncSub(arr,n));
    }
	return 0;
}
