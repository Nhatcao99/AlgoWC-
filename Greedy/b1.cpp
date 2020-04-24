#include<iostream>
#include<cctype>
#include<algorithm>
#include <map>
using namespace std;
// solution:
// get all arrival and departure in the same list
// sort list and set a count var
// if it is depart count+ | else count-

int main(){
    int T, N;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d",&N);
        int arr[2*N];
        map<int, bool> umap;
        for(int i = 0; i < 2*N; i ++){
            scanf("%d",&arr[i]);
            if(i < N){
                umap[arr[i]] = false;
            }else{
                map<int, bool>::iterator it = umap.find(arr[i]);
                if(it == umap.end()) umap[arr[i]] = true;
                else umap.erase(it);
            }
        } int count = 0 , max = 0;
        for(map<int, bool>::iterator i = umap.begin(); i != umap.end(); ++i){
            if(i->second == false) count ++;
            else count --;
            if(count > max) max = count;
        }printf("%d\n",max);
    }
}

