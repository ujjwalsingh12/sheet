#include <iostream>
#include <vector>

using namespace std;
    vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        // int top = 0;
        for(auto ele:intervals){
            if(ele[0]<=res[res.size()-1][1]){
                res[res.size()-1][1] = max(res[res.size()-1][1],ele[1]);
            }
            else{
                res.push_back(ele);
            }
        }
        return res;
    }

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
