set<string> myset; // storing string of the vector to check if similar vector exists
void getSet(vector<vector<int>> &arr, vector<int>& nums, int n, int pos, bool visited[]){
    if(pos == n){
        vector<int> small;
        string s = "";
        for(int i = 0; i < n ; i ++){
            if(visited[i]){
                small.push_back(nums[i]);
                s += to_string(nums[i]);
            }
        }
        set<string>::iterator it = myset.find(s);
        if(it == myset.end()){
            myset.insert(s);
            arr.push_back(small);
        }
        return;
    }
    visited[pos] = 0;
    getSet(arr,nums,n,pos + 1,visited);
    visited[pos] = 1;
    getSet(arr,nums,n,pos + 1,visited);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    int n = nums.size();
    bool visited[100] = {0};
    vector<vector<int>> subset;
    sort (nums.begin(), nums.end());
    getSet(subset,nums,n,0,visited);
    return subset;
}