// Online C++ compiler to run C++ program online
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
void subseq(vector<vector<int>>& mat,string subs,int i,int j,string& str1,string& str2,int lcs){
    // cout << "h";
    if((i>=str1.size() || j>=str2.size())){
        if(subs.size()==lcs)
        cout << subs << endl;
        return;
    }
    if(mat[i+1][j+1]>mat[i][j] && mat[i+1][j+1]>mat[i+1][j] && mat[i+1][j+1]>mat[i][j+1]){
        subseq(mat,subs+str1[i],i+1,j+1,str1,str2,lcs);
    }
    else{
        subseq(mat,subs,i+1,j,str1,str2,lcs);
        subseq(mat,subs,i,j+1,str1,str2,lcs);
    }
}

int lst(string str1,string str2){
    vector<vector<int> > mat(str1.size()+1,vector<int>(str2.size()+1,0));
    for(int i=0;i<str1.size();i++){
        for(int j=0;j<str2.size();j++){    
            if(str1[i]==str2[j]){ 
                mat[i+1][j+1]=mat[i][j]+1;
            }
            else{
                mat[i+1][j+1] = max(mat[i+1][j],mat[i][j+1]);
            }
        }
    }
    for (const auto& row : mat) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl; // Move to the next line after printing each row
    }
    int lcs = mat[str1.size()][str2.size()];
    subseq(mat,"",0,0,str1,str2,lcs);
    
    return lcs;
    }
int main() {
    // Write C++ code here
    // std::cout << lst("abcde","abdcd"); //4 is answer
    std::cout << lst("abcdefghajab","abdcdfghbxab"); //9 is answer

    return 0;
}