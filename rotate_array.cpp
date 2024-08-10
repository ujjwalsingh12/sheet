//rotate_array.cpp
#include <iostream>

using namespace std;
void reverse(int arr[],int p,int q){
    for(int j=p;j<q;j++){
        cout << arr[j] << " " << arr[q] << endl;
        int t = arr[j];
        arr[j] = arr[q];
        arr[q] = t;
        q--;
    }
}
void Rotateeleftoright(int arr[],int n,int k){
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n = 7;
  int k = 2;
//   reverse(arr,0,7-1);
  Rotateeleftoright(arr, n, k);
  cout << "After Rotating the k elements to right ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}