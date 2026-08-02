#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  string s, w;
  cin >> s >> w;
  if (find(w.begin(), w.end(), '?') != w.end() || find(w.begin(), w.end(), '*') != w.end())
    swap(s, w);

  int n = s.size(), m = w.size();
  // dp[i][j] = можно ли сопоставить первые i символов шаблона с первыми j символами слова
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
  dp[0][0] = 1;

  // Если шаблон начинается с '*'
  for (int i = 1; i <= n; i++)
    if (s[i - 1] == '*')
      dp[i][0] = dp[i - 1][0];

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      if (s[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (s[i - 1] == '*')
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      else
        dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == w[j - 1]);
    }
  
  cout << (dp[n][m] ? "YES" : "NO");
}
