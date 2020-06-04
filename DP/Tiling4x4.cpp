#include<iostream>
using namespace std;
int main()
 {
    int arr[81] = {0};
    arr[0] = 0;
    arr[1] = 1 , arr[2] = 1, arr[3] = 1 ,arr[4] = 2;
    for(int i = 5; i < 81; i ++){
        arr[i] = arr[i - 1] + arr[i - 4];
    }
	int T, n;
	cin >> T;
	for(int c = 0; c < T; c ++){
	    cin >> n;
	    cout << arr[n] << endl;
	}
	return 0;
}
