#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();

  // dp[i][j] = расстояние между a[1...i] и b[1...j]
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  // Превратить строку длины i в пустую
  for (int i = 0; i < n; i++) dp[i][0] = i; // i удалений
  // Превратить пустую строку в строку длины j
  for (int j = 0; j < m; j++) dp[0][j] = j; // j вставок

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = min({
        dp[i-1][j-1] + ((a[i-1] == b[j-1]) ? 0 : 1), // замена
        dp[i-1][j] + 1,                              // удаление
        dp[i][j-1] + 1,                              // вставка
      });
  cout << dp[n][m];
}
