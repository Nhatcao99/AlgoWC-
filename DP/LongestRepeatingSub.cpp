#include<iostream>
#include<string>

using namespace std;

int LongestRepeatSub(string s){
    int n = s.length();
    int dp[n + 1][n + 1]; // to make algorithm convience and advoid matrix overflow

    for (int i=0; i<=n; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n ; j ++){
            if(s[i - 1] == s[j - 1] && i != j){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
//    string result = "";
//    int i = n , j = n;
//    while(i > 0 && j > 0){
//        if(dp[i][j] == dp[i - 1][i - 1] + 1){
//            result += s[i - 1];
//            i -= 1;
//            j -= 1;
//        }else if(dp[i][j] == dp[i - 1][j]){
//            i -= 1;
//        }else{
//            j -= 1;
//        }
//    }
//    int l = result.length();
//    for(int i = 0; i < l/2; i ++){
//        swap(result[i],result[l - i - 1]);
//    }
//
//    return result;
    return dp[n][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    cin >> T;
    for(int c = 0; c < T; c ++){
        cin >> n;
        string s;
        cin >> s;
        cout << LongestRepeatSub(s) << "\n";
    }
    return 0;
}
