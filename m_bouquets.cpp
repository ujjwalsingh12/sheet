//m_bouquets.cpp
class Solution {
public:
    int howManyBouquets(vector<int>& bloomDay,int day,int k){
        int count=0,flowers = 0,next = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(flowers==0) { next=i;}
            if(bloomDay[i]<=day && next==i){ flowers++; next=i+1;}
            else { flowers =0;}
            if(flowers == k){ count++;flowers=0;}
            // cout << count << " " << bloomDay[i] << flowers << " " << next << " "<< day << " "  <<endl; 
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // vector<int> jj = {1,2,3,4,5,6};
        // int p = howManyBouquets(jj,5,2);
        // cout << p;
        int left=0,right=*max_element(bloomDay.begin(),bloomDay.end()),ans =-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            int possibleBouquets = howManyBouquets(bloomDay,mid,k);
            // cout << possibleBouquets << " " << mid << endl;
            if(possibleBouquets>=m){
                ans = mid;
                right = mid-1;
                
            }
            else if(possibleBouquets<m){
                left = mid+1;
            }
            // else{ return mid;}

        }
        return ans;
    }
};