#include<iostream>
#include<cctype>
#include<algorithm>
using namespace std;
int main()
 {
	int T ,N;
	scanf("%d",&T);
	for(int c = 0;c < T; c ++){
	    scanf("%d",&N);
	    int arr[N];
	    for(int i = 0; i < N; i ++){
	        scanf("%d",&arr[i]);
	    }sort(arr, arr + N);
	    int l = 0 , r = N - 1;
	    int min_z = arr[l] + arr[r];
	    while(l < r){
	        int sum = arr[l] + arr[r];
	        if(abs(sum) < abs(min_z)){
	            min_z = sum;
	        }
	        if(sum < 0){
	            l ++;
	        }else{
	            r --;
	        }
	    } printf("%d\n",min_z);
	}
	return 0;
}
