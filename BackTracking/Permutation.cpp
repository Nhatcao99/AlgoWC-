set<string> sub;
void permutate(vector<int> nums, vector<vector<int>>& per, int pos, int end){
    if(pos == end){
        string s = "";
        for(int i = 0; i <= end; i ++){
            s+= to_string(nums[i]);
        }
        // cout << s << " ";
        set<string>::iterator it = sub.find(s);
        if(it == sub.end()){
            sub.insert(s);
            per.push_back(nums);
        }
        return;
    }
    for(int i = pos; i <= end; i ++){
        swap(nums[pos] , nums[i]);
        permutate(nums,per,pos + 1,end);
        swap(nums[pos] , nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> mp;
    permutate(nums,mp,0,size - 1);
    return mp;
}