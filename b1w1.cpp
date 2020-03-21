#include <iostream>
#include <map>
using namespace std;

void backTrackAB(int n , int position ,bool isB , string s){
    if(position == n ){
        cout << s << '\n';
    }else{
//        for(int i = 0 ; i < n ; i ++){
        s += 'A';
        backTrackAB(n,position + 1,0,s);
        s = s.substr(0, s.length()-1);
        if(isB != 1){
            s += 'B';
            backTrackAB(n,position + 1,1,s);
        }
//        }
    }
}

int main(){
    int n;
    cin >> n;
    string tmp = "";
    backTrackAB(n,0,0,tmp);
//    tmp = tmp.substr(0, tmp.length()-1);
//    cout << tmp;
}