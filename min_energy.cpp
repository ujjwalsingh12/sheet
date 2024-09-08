class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> mes;//min_energy_to_step_n
        mes.push_back(0);
        mes.push_back(abs(height[1]-height[0]));
        mes.push_back(0);
        for(int i=2;i<n;i++){
            mes[i%3]=
                min(
                    abs(height[i]-height[i-1])+mes[(i-1)%3],
                    abs(height[i]-height[i-2])+mes[(i-2)%3]
                    );
                                                                        
        }
        return mes[(n-1)%3];
    }
};