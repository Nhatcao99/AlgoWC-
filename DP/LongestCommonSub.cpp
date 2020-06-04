#include<iostream>
#include<cctype>
using namespace std;
int LongestCommonSub(string a, string b, int n, int m){
    int arr[n + 1][m + 1];
    for(int i = 0; i <= n; i++) arr[i][0] = 0;
    for(int i = 0; i <= m; i++) arr[0][i] = 0;

    for(int i = 1; i <= n ; i ++){
        for(int j = 1; j <= m ; j ++){
            if(a[i - 1] == b[j - 1]){
                arr[i][j] = arr[i - 1][j - 1] + 1;
            }else{
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }
    return arr[n][m];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, m;
    string s1 , s2;
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> n >> m;
        cin >> s1 >> s2;
        cout << LongestCommonSub(s1,s2,n,m) << endl;
    }
}
