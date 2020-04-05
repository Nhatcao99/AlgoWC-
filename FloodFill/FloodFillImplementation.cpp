
#include<iostream>
#include<vector>
using namespace std;

void checking(vector<vector<bool>> &path, vector<vector<bool>> &visit, int i , int j, int des_x, int des_y, bool &flag){
    if(i == des_x && j == des_y){
        flag = true;
        return;
    }
    if(i < 0 || i > des_x) return;
    if(j < 0 || j > des_y) return;
    if(!visit[i][j]) visit[i][j] = true;
    else return;
    if(path[i][j] == 0) return;
    // checking(path,visit,i-1,j-1,des_x,des_y,flag);
    checking(path,visit,i-1,j,des_x,des_y,flag);
    // checking(path,visit,i-1,j+1,des_x,des_y,flag);
    checking(path,visit,i,j-1,des_x,des_y,flag);
    checking(path,visit,i,j+1,des_x,des_y,flag);
    // checking(path,visit,i+1,j-1,des_x,des_y,flag);
    checking(path,visit,i+1,j,des_x,des_y,flag);
    // checking(path,visit,i+1,j+1,des_x,des_y,flag);
}
int main(){
    int n , m, value;
    cin >> n >> m;
    vector<vector<bool>> path;
    vector<vector<bool>> visit;
    bool flag = false;
    for(int i = 0; i < n; i ++){
        vector<bool>tmp;
        vector<bool>zero;
        for(int j = 0; j < m; j ++){
            cin >> value;
            tmp.push_back(value);
            zero.push_back(false);
        }
        path.push_back(tmp);
        visit.push_back(zero);
    }
    checking(path,visit,0,0,n - 1,m - 1,flag);
    if(!flag){
        cout << "No";
    }else cout << "Yes";
}