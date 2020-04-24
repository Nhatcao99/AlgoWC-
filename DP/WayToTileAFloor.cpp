#include<iostream>
#include<cctype>
using namespace std;
int main(){
    unsigned long long arr[71] = {0};
    arr[1] = 1 , arr[2] = 2;
    for(int i = 3; i < 71; i++) 
    arr[i] = arr[i - 1] + arr[i - 2]; 
	int T , n;
	scanf("%d",&T);
	for(int c = 0; c < T; c ++){
	    scanf("%d",&n);
	    printf("%d\n",arr[n]);
	}
	return 0;
}
