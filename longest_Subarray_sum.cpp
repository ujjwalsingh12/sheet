//{ Driver Code Starts

//https://takeuforward.org/arrays/longest-subarray-with-sum-k-postives-and-negatives/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// } Driver Code Ends

    
    int lenOfLongSubarr(vector<int> A,  int N, int K) 
    { 
        // Complete the function
        int maxL = 0;
        map<int,int> psums;
        int summ = 0;
        for(int i=0;i<N;i++){ 
            summ = summ + A[i];
            if(summ==K){ maxL = max(maxL,i+1); }
            
            int rem = summ - K;
            if(psums.find(rem)!=psums.end()){
                maxL = max(maxL,i-psums[rem]);
            }
            
            if(psums.find(summ)==psums.end()){
                psums[summ] = i;
            }
        
    }
        
    return maxL; 
    } 

int main()
{
    std::vector<int> a({-1,1,1});
    int k = 1;
    int len = lenOfLongSubarr(a,a.size(), k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}

//{ Driver Code Starts.

// int main() {
// 	//code
	
// 	int t;cin>>t;
// 	while(t--)
// 	{
// 	    int n, k;
// 	    cin>> n >> k;
// 	    int a[n];
	    
// 	    for(int i=0;i<n;i++)
// 	        cin>>a[i];
// 	   Solution ob;
// 	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
// 	}
	
// 	return 0;
// }
// } Driver Code Ends