class Solution {
public:
    set<string> sub_set;
    void getTiles(int length, int pos , string titles , bool visited[]){
        if(pos == length){
            string s = "";
            int character[26] = {0};
            // have to use visited bool to make every string standard lexico order
            // if no there will be duplicate situation such as CD DC
            for(int i = 0; i < 7 ; i ++){
                if(visited[i]){
                    character[titles[i] - 'A'] ++;//store numbber of occurence
                }
            }
            for(int i = 0; i < 26; i ++){
                for(int j = 0 ; j < character[i] ; j ++){
                    s += (i + 'A');
                }
            }
            if(s != ""){
                sub_set.insert(s);
            }
            return;
        }
        visited[pos] = 0;
        getTiles(length, pos + 1, titles, visited);
        visited[pos] = 1;
        getTiles(length, pos + 1, titles, visited);
    }
    int factorial(int n){
        int fac = 1;
        for(int i = 1; i <= n ; i ++){
            fac *= i;
        }
        return fac;
    }
    int numTilePossibilities(string tiles) {
        int length = tiles.length();
        bool visited[7] = {false};
        getTiles(length,0,tiles,visited);
        int sum = 0;
        for (set<string>::iterator it=sub_set.begin(); it!=sub_set.end(); ++it){
            string tmp = *it;
            // cout << tmp << endl;
            map<char,int> mp;
            map<char,int>::iterator finding;
            int len = tmp.length();
            for(int i = 0; i < len; i++){
                finding = mp.find(tmp[i]);
                if(finding == mp.end()){
                    mp[tmp[i]] = 0;
                }mp[tmp[i]] ++;
            }
            int tu = factorial(len);
            int mau = 1;
            for(map<char,int>::iterator m = mp.begin(); m != mp.end() ; m ++){
                mau *= factorial(m->second);
            }
            // cout << tu<< " " << mau << endl;
            sum += (int)(tu/mau);
        }
        return sum;
    }
};