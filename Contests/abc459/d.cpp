#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {

        string s;
        cin >> s;

        int n = s.size();

        vector<int> freq(26, 0);

        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int mx = *max_element(freq.begin(), freq.end());

        if(n - mx < mx - 1) {
            cout << "No" <<'\n';
            continue;
        }

        vector<pair<int,char>> vec;

        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                vec.push_back({freq[i], char('a' + i)});
            }
        }

        sort(vec.rbegin(), vec.rend());

        string ans(n, 'x');

        int idx = 0;

        for(auto [cnt, ch] : vec) {

            while(cnt--) {

                if(idx >= n)
                    idx = 1;

                ans[idx] = ch;

                idx += 2;
            }
        }

        cout << "Yes\n" << ans << '\n';
    }
}
