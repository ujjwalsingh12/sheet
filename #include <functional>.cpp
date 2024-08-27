#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    // cout << "Enter the number of test cases: ";
    cin >> t;

    while(t--) {
        int n;
        long long k; // Using long long to handle large values of k
        // cout << "Enter the number of items (n) and the maximum total increase (k): ";
        cin >> n >> k;

        vector<long long> a(n);
        // cout << "Enter the initial costs of the items: ";
    
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        sort(a.begin(),a.end(),greater<long long>());

        for(int i=0;(i<n && k>0);i++){
            if((i&1)==1){
                int g = a[i-1]-a[i];
                if(g>k) { g=k;}
                a[i]+=g;
                k-=g;
            }
            // else { bob+=a[i];}
        }
        // for(int i=0;i<)
        int al=0,bob=0;
        for(int i=0;i<n;i++){
            if((i&1)==0){ al+=a[i];}
            else { bob+=a[i];}
        }
        if(al-bob>0){ cout << al-bob-k;}
        else cout << 0;
        cout << endl;
    }

    return 0;
}