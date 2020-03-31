#include<iostream>
#include<vector>
using namespace std;

int maximum(vector<int> &Q){
    if(Q.size() > 1){
        return Q[1];
    }return -1;
}

void max_heapify(vector<int> &Q, int index, int N){
    int left = 2 * index;
    int right = 2 * index + 1;
    int max = index;
    if(left <= N && Q[left] > Q[index]){
        max = left;
    }
    if(right <= N && Q[right] > Q[index]){
        max = right;
    }
    if(max != index){
        swap(Q[max] , Q[index]);
        max_heapify(Q,max,N);
        // upon insert , use this and it make sure the heap is max heapified
    }
}

void insert_value(vector<int> &Q , int value){
    Q.push_back(value);
    int index = Q.size() - 1;
    while(index > 1 && Q[index / 2] < Q[index]){
        swap(Q[index/2], Q[index]);
        index /= 2;
    }
}

int extract_maximum(vector<int> &Q){ // used for heap sort
    if(Q.size() == 0){
        return -1; // there is literally nothing to return
    }
    int max = Q[1];
    Q[1] = Q[Q.size() - 1];
    Q.pop_back(); // delete the max
    max_heapify(Q,1,Q.size() - 1);
    return max;
}

int main(){
    int n;
    cin >> n;
    vector<int> Q;
    Q.push_back(0);
    for(int i = 0 ; i < n ; i ++){
        int tmp;
        cin >> tmp;
        insert_value(Q,tmp);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q ; i ++){
        int tmp;
        cin >> tmp;
        if(tmp == 1){
            int num;
            cin >> num;
            insert_value(Q,num);
        }
        else{
            cout << maximum(Q) << "\n";
        }
    }
}