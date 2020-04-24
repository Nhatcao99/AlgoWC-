#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
int main(){
    int T ,N;
    scanf("%d",&T);
    for(int c = 0;c < T; c ++){
        scanf("%d",&N);
        int arr[N];
        for(int i = 0; i < N; i ++){
            scanf("%d",&arr[i]);
        }sort(arr,arr + N);
        int count = 0;
        for(int i = 0; i < N - 2; i ++){
            for(int j = N - 1; j > i + 1; j --){
                if(arr[i] + arr[i + 1] > arr[j]) break;
                for(int k = i + 1; k < j; k ++){
                    if(arr[i] + arr[k] == arr[j]) count ++;
                    if(arr[i] + arr[k] > arr[j]) break;
                }
            }
        }printf("%d\n",count);
    }
}

