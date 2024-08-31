class Solution {
public:
    vector<string> res;
    void g(int lefttoopen,int lefttoclose,string r){
        if(lefttoopen==0 && lefttoclose==0){
            res.push_back(r);
        }
        if(lefttoclose>0){
            g(lefttoopen,lefttoclose-1,r+")");
        }
        if(lefttoopen>0){
            g(lefttoopen-1,lefttoclose+1,r+"(");
        }
    }
    vector<string> generateParenthesis(int n) {
        g(n,0,"");
        return res;
    }
};