//leaders.cpp
//accepted gfg

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        int max = INT_MIN;
        vector<int> leads;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=max){ leads.push_back(arr[i]); max=arr[i];}
        }
        reverse(leads.begin(),leads.end());
        return leads;
    }
};