class Solution {
public:
    vector<vector<int>> sol;
    void gensubsets(vector<int>& arr,int n,vector<int> selected){
        sol.push_back(selected);
        if(n==arr.size()){
            return;
        }
        selected.push_back(-1);
        for(int i=n;i<arr.size();i++){
            selected[selected.size()-1] =  arr[i];
            gensubsets(arr,i+1,selected);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        gensubsets(nums,0,{});
        return sol;
    }
};