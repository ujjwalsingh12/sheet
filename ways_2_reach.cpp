class Solution {
public:
    int climbStairs(int n) {
        vector<int> w2r;//ways_to_reach;
        w2r.push_back(0);
        w2r.push_back(1);
        w2r.push_back(2);
        for(int i=3;i<=n;i++){
            w2r[i%3]=w2r[(i-1)%3]+w2r[(i-2)%3];
        }
    return w2r[n%3];
    }

};