#include<iostream>
#include<cctype>
using namespace std;
void permutate(string num, int idx, int n, int k){
    if(idx == n||k== 0){
        cout << num << endl;
        return;
    }
    int max_index = idx;
    char max = num[idx];
    for(int i = idx + 1; i < n; i ++){
        if(max < num[i]){
            max = num[i];
            max_index = i;
        }
    }
    if(idx != max_index){
    swap(num[idx],num[max_index]);
    permutate(num,idx + 1,n,k-1);
    }else{
        permutate(num,idx + 1,n,k);
    }
}
int main()
 {
	int T , k;
	string num;
	scanf("%d",&T);
	for(int c = 0; c < T; c ++){
	    scanf("%d",&k);
	    cin >> num;
	    permutate(num,0,num.length(),k);
	}
	return 0;
}
