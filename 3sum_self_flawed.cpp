//3sum_self_flawed.cpp

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,vector<int>> sums;
        vector<vector<int>> res;
        set<vector<int>> r;
        for(int i=0;i<nums.size()-1;i++){
            if(sums.find(nums[i]+nums[i+1])==sums.end()){
                vector<int> r;
                sums[nums[i]+nums[i+1]]=r;
            }
                sums[nums[i]+nums[i+1]].push_back(i);
                sums[nums[i]+nums[i+1]].push_back(i+1);
        }
        for(auto i: sums){
            cout << i.first << ":";
            for(auto j: i.second){
                cout << j << ",";
            }
            cout << endl;
        }
        for(int i=0;i<nums.size();i++){
            int rem = nums[i];
            if(sums.find(-1*rem)!=sums.end()){
                for(int j=0;j<sums[-1*rem].size()-1;j=j+2){
                    if(sums[-1*rem][j]==i || sums[-1*rem][j]+1==i){
                        j = j+2; continue;
                    }
                    // for(auto x: nums){ cout << x << ",";}
                    // cout << i << " " << j << endl;
                    // cout << endl;
                    // cout << nums[sums[-1*rem][j]] << endl;
                    vector<int> rr = {nums[i],nums[sums[-1*rem][j]],nums[sums[-1*rem][j+1]]};
                    sort(rr.begin(),rr.end());
                    r.insert(rr);
                }
                
            }
        }
        for(auto i: r){
            res.push_back(i);
        }
        return res;
    }
};