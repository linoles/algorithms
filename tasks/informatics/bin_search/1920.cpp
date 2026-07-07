#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
  int n;
  scanf("%d", &n);
  vector<string> a(n);
  char buffer[n + 1];
  forn(i, n)
  {
    scanf("%s", &buffer);
    a[i] = buffer;
  }

  // Пусть dp[i][j] - размер макс. квадрата, у которого правый нижний угол находится в (i, j)
  // Если (i, j) закрашена: dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
  vii dp(n, vi(n, 0));
  int ans = 0;
  forn(i, n) forn(j, n) if (a[i][j] == '#')
  {
    if (i == 0 || j == 0)
      dp[i][j] = 1;
    else
      // Верхний, левый и левый верхний
      dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
    ans = max(ans, dp[i][j]);
  }

  printf("%d\n", ans);

  return 0;
}