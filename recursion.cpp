class Solution {
public:
    vector<vector<int> > ans;
    void combine(int val,int k,int rsum,vector<int> choices){
        int cur_sum = reduce(choices.begin(),choices.end(),0);
        
        if(cur_sum>rsum || val>10 || choices.size()>k);
        else if(cur_sum == rsum && choices.size()==k){
            ans.push_back(choices);
        }
        else{
            combine(val+1,k,rsum,choices);
            choices.push_back(val);
            combine(val+1,k,rsum,choices);
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        combine(1,k,n,vector<int>());
        return ans;
    }
};