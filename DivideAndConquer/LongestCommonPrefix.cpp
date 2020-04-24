#include<iostream>
#include<unordered_set>
#include<cctype>
#include<cmath>
using namespace std;
string commonPrefixUtil(string str1, string str2){
    int l1 = str1.length();
    int l2 = str2.length();
    string result = "";
    for(int i = 0 , j = 0; i < l1 && j < l2; i ++,j ++){
        if(str1[i] != str2[j]) break;
        result.push_back(str1[i]);
    }return result;
}


string commonPrefix(string arr[], int low, int high){
    if(low == high) // onstring only
        return arr[low];
    if(low < high){
        int mid = (low + high)/2;
        string str1 = commonPrefix(arr,low,mid);
        string str2 = commonPrefix(arr,mid + 1,high);
        return  commonPrefixUtil(str1,str2);
    }
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof (arr) / sizeof (arr[0]);

    string ans = commonPrefix(arr, 0, n-1);

    if (ans.length())
        cout << "The longest common prefix is "
             << ans;
    else
        cout << "There is no common prefix";
    return (0);
}

