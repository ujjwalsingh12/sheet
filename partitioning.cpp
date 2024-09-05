#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    bool ispalin(string s){
        for(int i=0;i<s.size();i++){ if(s[i]!=s[s.size()-1-i]) return false;}
        return true;
    }

    void partpalin(string& s,int i,vector<string> r,vector<vector<string> >& ans){
        if(i>=s.size()){
            ans.push_back(r);
            return;
        }
        string cur;
        for(int j=i;j<s.size();j++){
            cur += s[j];
            if(ispalin(cur)){
                r.push_back(cur);
                partpalin(s,j+1,r,ans);
                r.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> r;
        partpalin(s,0,r,ans);
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input string
    string s = "aab";

    // Get the partitioned palindromes
    vector<vector<string> > result = solution.partition(s);

    // Print the result
    cout << "Palindromic partitions of the string \"" << s << "\":" << endl;
    for (const auto& partition : result) {
        cout << "[ ";
        for (const auto& str : partition) {
            cout << "\"" << str << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}