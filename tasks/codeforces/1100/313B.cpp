#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  // dp[i] = кол-во одинаковых соседних элементов на отрезке [0...i]
  vector<int> dp(n, 0);
  for (int i = 1; i < n; i++)
  {
    dp[i] = dp[i - 1];
    if (s[i - 1] == s[i])
      dp[i]++;
  }

  int m, l, r;
  cin >> m;
  while (m--)
  {
    cin >> l >> r;
    r--, l--;
    cout << dp[r] - dp[l] << "\n";
  }
}

// Аналогия преф. суммам