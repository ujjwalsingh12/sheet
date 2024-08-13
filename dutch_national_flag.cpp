class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> countings;
        int a=0,b=0,c=nums.size()-1;
        while(b<=c){
            if(nums[b]==0){
                swap(nums[a],nums[b]);
                a++;
            }
            else if(nums[b]==1){
                b++;
            }
            else if(nums[b]==2){
                swap(nums[c],nums[b]);
                c--;
            }
            
            if(a>b) b++;
        }

    }
};