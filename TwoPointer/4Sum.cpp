#include<iostream>
using namespace std;
int main(){
	int T , n , x;
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d",&n);
        int arr[n];
        bool count = 0;
        for(int i = 0; i < n; i ++) scanf("%d",&arr[i]);
        scanf("%d",&x);
        for(int h = 3; h < n; h ++){
            if(count == true) break;
            for(int k = 2; k < h; k ++){
                if(count == true) break;
                for(int j = 1; j < k; j++){
                    if(count == true) break;
                    for(int i = 0; i < j; i ++){
                        if(count == true) break;
                            if(arr[i] + arr[j] + arr[k] + arr[h] == x){
                                count = 1;
                                break;
                            }
                    }
                }
            }
        }
        printf("%d\n",count);
    }
	return 0;
}
