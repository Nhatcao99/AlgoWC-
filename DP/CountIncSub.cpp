#include<iostream>
using namespace std;
//in the following implementation
//I will use the fact that input range from 0 - 9
//the problem quiet similar to longest subsequence

unsigned long countSub(int arr[], int n){
    unsigned long int count[10] = {0},maximus = 0;
    
    for(int i = 0; i < n; i ++){
        for(int j = arr[i] - 1; j >= 0; j --){
            count[arr[i]] += count[j]; // add the number of subsequence from smaller element
        } count[arr[i]] ++; // add self
    }
    for(int i = 0; i < 10 ; i ++)
        maximus += count[i];
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
        printf("%d\n",countSub(arr,n));
    }
	return 0;
}
