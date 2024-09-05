
// THIS IS STRIVER SOLUTION
// BELOW THAT IS MY SOLUTION
#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int res = 0;
  int maxLeft = 0, maxRight = 0;
  while (left <= right) {
    if (height[left] <= height[right]) {
      if (height[left] >= maxLeft) {
        maxLeft = height[left];
      } else {
        res += maxLeft - height[left];
      }
      left++;
    } else {
      if (height[right] >= maxRight) {
        maxRight = height[right];
      } else {
        res += maxRight - height[right];
      }
      right--;
    }
  }
  return res;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}

// MY SOLUTION
class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        stack<int> stk;
        for(int i=0;i<height.size()-1;i++){
            int curelement  = height[i];
            int nextelement = height[i+1];
            if(curelement<nextelement){
                int start_of_container = 0;
                for(int j=i;(j>0 && height[j]<nextelement);j--){
                    if(height[j-1]>height[j]){
                        start_of_container = j;
                    }
                }
                if(start_of_container!=0){
                    int level = min(height[start_of_container-1],nextelement);
                    for(int j = start_of_container;j<i+1;j++){
                        int diff = (level-height[j]);
                        count += diff;
                        height[j] = level;
                    }
                }
            }
        }
        for(auto i: height){ cout<<i<<",";} cout << endl;
        return count;
    }
};