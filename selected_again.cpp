class Solution {
public:
    vector<string> ans;
    void makeit(vector<string>& a,int x,int n,string r){
        if(x>=n){
            ans.push_back(r);
            return;
        }
        else{
            for(char letter: a[x]){
                makeit(a,x+1,n,r+letter);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> lett{
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> selected;
        int i=0;
        for(auto digit: digits){
            selected.push_back(lett[digit-'0']);
        }
        if(selected.size()==0){ return {};}
        makeit(selected,0,selected.size(),"");

        return ans;
    }
};