//https://codeforces.com/contest/514/problem/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    // vector<vector<int>> mat;
    int x=0,y=0;
    for(int i=0;i<5;i++){
        for(int j =0;j<5;j++){
            int inp;
            cin >> inp;
            if(inp){
                x = i;y=j;
            }
        }
    }
    cout  << abs(x-3)+abs(y-3) << endl;
    return 1;

}