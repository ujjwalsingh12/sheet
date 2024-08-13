#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
    string twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        string ret ="";
        for(int i=0;i<nums.size();i++){
            int s = target - nums[i];
            if(hash.find(s)!=hash.end()){
                res.push_back(hash[s]);
                res.push_back(i);
                ret = "YES";
            }
            hash[nums[i]] = i;
        }
        // ret = "NO";
        return ret;
    }

int main()
{
    int n = 5;
    vector<int> arr = {2,3, 6, 5, 8, 11};
    int target = 99;
    string ans = twoSum(arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}