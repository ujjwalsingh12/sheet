
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}



/* in python
rel = [0] # 0 decrement 1 incement
for i in range(1,len(arr)):
    if(arr[i-1]<arr[i]):
        rel.append(1)
    else:
        rel.append(0)
print(rel)
countzeros = 0
for i,v in zip(reversed(arr),reversed(rel)):
    if(v==0):
        countzeros+=1
    else:
        break

if(countzeros==len(arr)):
    arr = list(reversed(arr))
else:
    print(arr)
    pre = arr[:len(arr)-1-1-countzeros]
    print(pre)
    afr = list(reversed(arr[len(arr)-countzeros:]))
    print(afr)
    a = arr[len(arr)-1-1-countzeros]
    b = arr[len(arr)-1-countzeros]
    print(a,b)
    arr = pre+[b,a]+afr
    print(countzeros)
print(arr)
*/
