#include<iostream>
using namespace std;
int maxPath(int **cost, int n){
    int path[n][n];

    for(int i = 0; i < n ; i ++){
        path[0][i] = cost[0][i];
    }

    for(int i = 1; i < n; i ++){
        for(int j = 0; j < n; j ++){
            int tmp = path[i - 1][j];
            if(j > 0) tmp = max(tmp,path[i - 1][j - 1]);
            if(j < n - 1) tmp = max(tmp,path[i - 1][j + 1]);
            path[i][j] = tmp + cost[i][j];
        }
    }
//    for(int i = 0; i < n; i ++){
//        for(int j = 0; j < n; j ++){
//            cout << path[i][j] << " ";
//        }cout << "\n";
//    }
    int maximus = path[n - 1][0];
    
    for(int i = 1; i < n; i ++){
        if(maximus < path[n - 1][i]) maximus = path[n - 1][i];
    }return maximus;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n;
    scanf("%d",&T);
    for(int c = 0; c < T; c ++){
        scanf("%d",&n);
        int **arr;
        arr = new int*[n];
        for(int i = 0; i < n; i ++){
            arr[i] = new int[n];
            for(int j = 0; j < n; j ++)
                scanf("%d",&arr[i][j]);
        }
        printf("%d\n",maxPath(arr,n));
    }
    return 0;
}

