#include<iostream>
#include<string>
using namespace std;

void bracket(int n , string s , int count){
    if(s.length() == n){
        if(count == 0){
            cout << s << "\n";
        }
        return;
    }
    s += '(';
    bracket(n,s,count + 1);
    if(count > 0){
        s.pop_back();
        s += ')';
        bracket(n,s,count - 1);
    }
}
int main(){
    int n;
    cin >> n;
    string s = "";
    bracket(n * 2 ,s ,0);
}