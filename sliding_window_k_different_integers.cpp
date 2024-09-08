class Solution {
public:
    int subarraysWithAtmostK(vector<int>& nums, int k) {
        int count=0;
        map<int,int> freq;
        int lef=0;                         //lef = left
        for(int ri=0;ri<nums.size();ri++){ //ri = right
            freq[nums[ri]]++;
            while(freq.size()>k){
                freq[nums[lef]]--;
                if(freq[nums[lef]]==0){
                    freq.erase(nums[lef]);
                }
                lef++;
            }
            count+= ri-lef+1; 
            /**
             the procedure of count here  means that for every next element the number of new subarrays will increment by the
             size of the sub aarrya
             sz 1 => 1 subarray
             sz 2 => 1+2 subaarrys
             sz 3 => 1+2+3 sub arrays
             */

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