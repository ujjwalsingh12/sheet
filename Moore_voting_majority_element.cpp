/**
one approach that i can think of in nlogn is to sort the array and select the middle element
but MOORE'S ALGO IS BETTER SINCE IT WORKS IN O(N)
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();
    int votes = 1; // count
    int major=v[0]; // Element
    for(int i=0;i<n;i++){
        if(major==v[i]) votes++;
        else{
            votes--;
            if(votes==0){ //implies equal has occured between matches and non matches
            //which leaves possibility of 50% or more for the majority element in next part
            major = v[i];
            votes = 1;
            }
        }
    }
    //verification part (if necessary)
    votes = 0;
    for(int i=0;i<n;i++) if(v[i]==major) votes++;
    if(votes>=floor(n/2)){ return major;}
    else return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}

