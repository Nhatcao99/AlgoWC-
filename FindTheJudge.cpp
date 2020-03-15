//
// Created by Cao Minh Nhat on 3/15/20.
//

int findJudge(int n, vector<vector<int>>& trust) {
    int being_trusted[n + 1] = {0};
    int trust_other[n + 1] = {0};
    int size = trust.size();
    for(int i = 0 ; i < size ; i ++){
        trust_other[trust[i][0]] += 1;
        being_trusted[trust[i][1]] += 1;
    }
    for(int i = 1; i <= n ; i++){
        if(trust_other[i] == 0 && being_trusted[i] == n - 1){
            return i;
        }
    }
    return -1;
}