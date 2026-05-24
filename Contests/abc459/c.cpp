#include <bits/stdc++.h>
using namespace std;
#define int long long
// const int N = 6e5 + 5; // 2nd type query can for large y
const int N = 3e5 + 5; // but there cant be no more than q blocks any where. so shift+y > q is 0
int32_t main()
{
  int n, q;
  cin >> n >> q;
  vector<int> arr(n + 1, 0);
  vector<int> k(N, 0);
  int shift = 0;
  int max_inc = q;
  while (q--)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      arr[x]++;
      k[arr[x]]++;
      if (k[arr[x]] == n)
        shift = arr[x];
    }
    else
    {
      if (x + shift > max_inc)
        cout << 0 << endl;
      else
        cout << k[x + shift] << endl;
    }
  }
  return 0;
}
