#include <iostream>
#include <vector>
using namespace std;

void painting(vector<vector<int>> &path, vector<vector<bool>> &visit, int i , int j, int &n, int &m,\
int &color_now, int &color_later){
    if(i < 0 || i > n - 1) return;
    if(j < 0 || j > m - 1) return;
    if(!visit[i][j]) visit[i][j] = true;
    else return;
    if(path[i][j] != color_now) return;
    else path[i][j] = color_later;
    painting(path,visit,i-1,j,n,m,color_now,color_later);
    painting(path,visit,i,j-1,n,m,color_now,color_later);
    painting(path,visit,i,j+1,n,m,color_now,color_later);
    painting(path,visit,i+1,j,n,m,color_now,color_later);
}

int main() {
    int T;
    cin >> T;
    for(int c = 0; c < T; c ++){
        int n , m;
        cin >> n >> m;
        vector<vector<int>> path;
        vector<vector<bool>> visit;
        for(int i = 0; i < n; i ++){
            vector<int>tmp;
            vector<bool>zero;
            for(int j = 0; j < m; j ++){
                int num;
                cin >> num;
                tmp.push_back(num);
                zero.push_back(false);
            }
            path.push_back(tmp);
            visit.push_back(zero);
        }
        int pos1 , pos2 , color_now , color_then;
        cin >> pos1 >> pos2 >> color_then;
        color_now = path[pos1][pos2];
        painting(path,visit,pos1,pos2,n,m,color_now,color_then);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++)
                cout << path[i][j] << " ";
        }cout << "\n";
    }
    //7 5 3 5 6 2 9 1 2 7 0 9 3 6 30 6 2 6 1 8 7 9 2 0 2 3 7 5
    //0 0 3 4 9 2 7 4 2 5 2 4 4 3 8 6 0 8 9 66 66 3 1 8 3 4 66 66 4 5 1 7
}