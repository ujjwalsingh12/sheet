class Solution{
    public:
    
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int maxL = 0;
        vector<int> sums;
        int summ = 0;
        for(int i=0;i<N;i++){ 
            summ = summ + A[i];
            sums.push_back(summ);
            if(summ==K){
                maxL = i+1;
            }
        
    }
        //
        for(int i=1;i<N;i++){ // i == starting index
            for(int j=i;j<N;j++){// to subtract from all
                sums[j] -= A[i-1];
                if(sums[j]==K){
                    maxL = max(maxL,j-i+1);
                }
            }
        }
    return maxL; 
    } 

};