#include<iostream>
#include<cctype>
using namespace std;
int maximumIncSum(int arr[] , int n){
    int lis[n], maximus = 0;
    lis[0] = arr[0];
    
    for(int i = 1; i < n ; i ++){
        lis[i] = arr[i];
        for(int j = 0; j < i; j ++){ // it is subsequense not sub array
            if(arr[i] > arr[j] && lis[i] < lis[j] + arr[i]){
                lis[i] = lis[j] + arr[i];
            }
        }
    }  
    for(int i = 0; i < n; i ++){
        if(lis[i] > maximus) maximus = lis[i];
    }
    return maximus;
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
        printf("%d\n",maximumIncSum(arr,n));
    }
	return 0;
}

