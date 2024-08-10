#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> FindUnion(int arr1[],int arr2[],int n,int m){
    int p=0,q=0;
    bool b1=true,b2=true;
    vector<int> res;
    while(p<n || q<m){
        int t = min(arr1[p],arr2[q]);
        res.push_back(t);
        while(arr1[p]==t) p++;
        while(arr2[q]==t) q++;
        if(p>=n) b1 = false;
        if(q>=m) b2 = false;
    }
    return res;
}
int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}