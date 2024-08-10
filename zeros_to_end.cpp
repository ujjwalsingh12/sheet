#include<iostream>

using namespace std;
int removeDuplicates(int arr[], int n)
{
  int i = 0;
  for (int j = 1; j < n; j++) {
    if (arr[j] != 0) {
      i++;
      arr[i] = arr[j];
    }
  }
  for(int j=i+1;j<n;j++){
    arr[j] = 0;
  }
  return n;
}
int main() {
  int arr[] = {1,0,2,0,2,0,0};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after zeros to end is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
  
}