#include<iostream>
#include<climits> 

using namespace std;
//maximum continuous sub-array
//if the sum is negetive start right from the beginning
// also call kadean algo

int maxSubArr(int arr[], int n){
    int max_on_whole = INT_MIN, current_max = 0;
    for(int i = 0; i < n ; i ++){
        current_max += arr[i];
        if(max_on_whole < current_max) max_on_whole = current_max;
        if(current_max < 0){
            current_max = 0;
        }
    }return max_on_whole;
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
        printf("%d\n",maxSubArr(arr,n));
    }
	return 0;
}

