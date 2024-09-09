class Solution {
  public:
    int minimizeCost(vector<int>& arr, int& k) {
    int n = arr.size();
        if (n == 0) return 0;
        std::vector<int> mic(n, INT_MAX); // Initialize with a large number
        mic[0] = 0; // Cost to reach the first stone is 0

        for (int i = 1; i < n; i++) {
            for (int j = std::max(0, i - k); j < i; j++) {
                mic[i] = std::min(mic[i], abs(arr[i] - arr[j]) + mic[j]);
            }
        }
        return mic[n - 1];
    }
};

//-------------------------------MY WRONG CODE
class Solution {
    public:
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        vector<int> mic;//min_energy_to_step_n
        mic.push_back(0);
        if(arr.size()>1) mic.push_back(arr[1]-arr[0]);
        for(int i=2;i<arr.size();i++){
            
            int something;
            
            for(int j=max(0,i-k);j<i;j++){
                cout << something << " " << j << endl;
                if( j==max(0,i-k) || (abs(arr[something]-arr[i])+mic[something] > abs(arr[i]-arr[j]))+mic[j] ){
                    something = j;
                }
            }
            cout << abs(arr[something]-arr[i]) + mic[something] << " " << arr[i] << endl;
            mic.push_back(abs(arr[something]-arr[i]) + mic[something]);
        }
        for(int c: mic) cout << c << " "; cout << endl;
        return mic[(arr.size()-1)];
    }
};