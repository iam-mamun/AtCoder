#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str, ans = "";

    for(int i = 0; i < n; i++) {
        cin >> str;

        char ch = str[0];

        if(ch <= 'c') ans.push_back('2');

        else if(ch <= 'f') ans.push_back('3');

        else if(ch <= 'i') ans.push_back('4');

        else if(ch <= 'l') ans.push_back('5');

        else if(ch <= 'o') ans.push_back('6');

        else if(ch <= 's') ans.push_back('7');

        else if(ch <= 'v') ans.push_back('8');

        else
            ans.push_back('9');
    }

    cout << ans << endl;
}
