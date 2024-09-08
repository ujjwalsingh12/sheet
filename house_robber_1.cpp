class Solution {
public:
    int steal(int choose,vector<int>& hval,vector<bool> chosen,vector<int>& maxsteal){
        
            // for(int b: maxsteal) cout << b << " "; cout << endl;
        if(choose>=hval.size()){
            return 0;
        }
        if(maxsteal[choose]!=-1){
            return maxsteal[choose];
        }
        int a,b;
        a = steal(choose+1,hval,chosen,maxsteal);
        if(!chosen[choose]){
            for(
                int i=max(choose-1,0);
                i< min(choose+2,(int)hval.size());
                i++
            )
            {chosen[i]=1;}
            b = hval[choose] + steal(choose+2,hval,chosen,maxsteal);
        }
        maxsteal[choose] = max(a,b);
        return maxsteal[choose];

    }
    int rob(vector<int>& nums) {
        vector<bool> chosen(nums.size(),0);
        vector<int> maxsteal(nums.size()+1,-1);
        return steal(0,nums,chosen,maxsteal);
    }
};