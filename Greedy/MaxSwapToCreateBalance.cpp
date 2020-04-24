//minium of swap to create balance bracket (you time swap you allow to swap to position next to each other)
#include<iostream>
#include<vector>
#include<cctype>

using namespace std;

int countSwap(string &s, int n){
    vector<int> pos;
    for(int i = 0; i < n ; i ++){
        if(s[i] == '[')
            pos.push_back(i); // store the position
    }
    int p = 0;
    int count = 0, sum = 0;
    for(int i = 0; i < n ; i ++){
        if(s[i] == '['){
            count ++;
            p ++;//move up to the next [
        }else{
            count --;
        }if(count < 0){
            sum += pos[p] - i; // number of swap have to do
            swap(s[pos[p]],s[i]); // simply swap the number in string
            p ++;// move up to the next [
            count = 1; // at the moment s[i] == '[' so set count to 1
        }
    }
    return sum;
}

int main(){
    int T , n;
    string s;
    scanf("%d",&T);
    for(int c = 0;c < T;c ++){
        scanf("%d",&n);
        cin >> s;
        printf("%d\n",countSwap(s,n));
    }
}

