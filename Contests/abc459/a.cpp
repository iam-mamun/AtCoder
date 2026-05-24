#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str = "HelloWorld";
  int x;
  cin >> x;
  for (int i = 0; i < 10; i++)
  {
    if (i + 1 == x)
      continue;
    cout << str[i];
  }
  cout << '\n';
}
