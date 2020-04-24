#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    int T, N, X;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d %d",&N,&X);
        int arr[N], count = 0;
        for(int i = 0; i < N; i ++){
            scanf("%d",&arr[i]);
        }
        sort(arr, arr + N);
        for(int i = 0; i < N - 2; i ++){
            for(int j = i + 2; j < N; j ++){
                if(arr[i] + arr[j] >= X) break;
                for(int k = i + 1; k < j; k ++){
                    int sum = arr[i] + arr[k] + arr[j];
                    if(sum < X) count ++;
                    else break;
                }
            }
        }printf("%d\n",count);
    }
	return 0;
}

