#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
int coinChange(int S[], int n, int m){
    //make a calulate table
    //row stand for money value you are having
    // collumn stand for value 
    // bottom up method with base column m = 0 , arr[n][m] = 1
    int table[m + 1][n];
    memset(table, 0, sizeof(table)); // initializing all variable to zero
    for(int i = 0; i < n ; i ++){
        // not having to pay zero be count as one way
        table[0][i] = 1;
    }
    for (int i = 1; i < m + 1; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            int x , y;
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 
            // if s[j] <= i include money at table[i - s[j][j] or 0 
            // basically use the money then reduce the current price
            // to smaller price
            
            // Count of solutions excluding S[j] 
            y = (j >= 1) ? table[i][j - 1] : 0; 
            //and also add the way of paying from previous column(price)
            
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[m][n - 1];
}
int main(){
	int t, n,m;
	scanf("%d",&t);
	for(int c = 0; c < t; c ++){
	    scanf("%d",&n);
	    int arr[n];
	    for(int i = 0; i < n; i ++){
	        scanf("%d",&arr[i]);
	    }scanf("%d",&m);
	    printf("%d\n",coinChange(arr,n,m));
	}
	return 0;
}
