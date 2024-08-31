#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the string

        string s;
        cin >> s; // The string itself

        // Logic implementation will go here
        sort(s.begin(),s.end());
        cout << s << endl;
    }

    return 0;
}