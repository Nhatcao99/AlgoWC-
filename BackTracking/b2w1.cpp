//
// Created by Cao Minh Nhat on 3/18/20.
//

#include<iostream>
using namespace std;
int n , k;
int sum[100] , group[100] , input[100];
bool satified = false;

void check(){
    for(int i = 1; i <= n ; i ++){
        cout << group[i] << " "; // add the sum of group
    }cout << "\n";
    for (int i = 1; i <= k; i ++) sum[i] = 0;
    // khoi tao lai cac tong = 0
    for(int i = 1; i <= n ; i ++){
        sum[group[i]] += input[i]; // add the sum of group
    }
    for(int i = 1; i < k; i ++){
        if(sum[i] != sum[i + 1]){
            return; // the sum of group isn't equal
        }
    }
    satified = true;
    for(int i = 1 ; i <= k ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            if(group[j] == i){
                cout << input[j] << " ";
            }
        }cout << "\n";
    }
}
void getGroup(int index){
    if(satified){
        return;
    }
    if(index == n + 1){
        check();
        return; // if you don't break it will be infinite loophole
    }
    for(int i = 1; i <= k; i ++){
        //for every group position put use k group number
        group[index] = i;
        getGroup(index + 1);
    }
}

int main(){
    cin >> n >> k;
    cout << n << " " << k << "\n";
    for(int i = 1; i <= n ; i ++){
        cin >> input[i];
    }
    getGroup(1);
}