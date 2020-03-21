#include<iostream>
#include<set>
using namespace std;
set<string> set1;

string s;

void substr(int pos , int n, bool visited[]){
    if(pos == n){
        string str = "";
        for(int i = 0 ; i < n ; i ++){
            if(visited[i]){
                str += s[i];
            }
        }
        if(str != ""){
            set1.insert(str);
        }
        return;
    }
    for(int i = 0 ; i < n ; i ++){
        visited[pos] = false;
        substr(pos + 1, n , visited);
        visited[pos] = true;
        substr(pos + 1, n , visited);
    }
}

int main(){
    cin >> s;

    bool visited[15] = {false};
    substr(0,s.length(),visited);
    for (set<string>::iterator it=set1.begin(); it!=set1.end(); ++it)
        cout << ' ' << *it;
}