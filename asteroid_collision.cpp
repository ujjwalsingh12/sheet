class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int a : asteroids){
            if(a>0){
                st.push(a);
            }
            if(a<0){
                while(!st.empty() && st.top()<abs(a) && st.top()>0){
                    st.pop();

                }
                if(!st.empty() && st.top()==abs(a) && st.top()>0){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(a);
                }
                
            }
        }
        while(!st.empty()){
            int i = st.top();
            st.pop();
            ans.push_back(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};