class Solution {
public:
    int subarraysWithAtmostK(vector<int>& nums, int k) {
        int count=0;
        map<int,int> freq;
        int lef=0;
        for(int ri=0;ri<nums.size();ri++){
            freq[nums[ri]]++;
            while(freq.size()>k){
                freq[nums[lef]]--;
                if(freq[nums[lef]]==0){
                    freq.erase(nums[lef]);
                }
                lef++;
            }
            count+= ri-lef+1;

        }
        cout << count << endl;
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = subarraysWithAtmostK(nums,k);
        int b = subarraysWithAtmostK(nums,k-1);
        return a-b;
    }
};