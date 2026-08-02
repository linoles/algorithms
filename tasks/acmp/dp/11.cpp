#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

// Прибавить к a число b
vi add(vi a, vi &b)
{
  int carry = 0;
  for (int i = 0; i < max(a.size(), b.size()) || carry; i++)
  {
    if (i == a.size()) a.push_back(0);
    int sum = a[i] + carry;
    if (i < b.size()) sum += b[i];
    a[i] = sum % 10;
    carry = sum / 10;
  }
  return a;
}

int main()
{
  int k, n;
  scanf("%d %d", &k, &n);

  // dp[i] = кол-во способов допрыгнуть до ступеньки i
  // ull и даже int128 не пройдут, т.к. число до 10^90, поэтому используем массив
  vector<vi> dp(n + 1, vector<int>(1, 0)); // dp[i][j] - j-ный разряд числа dp[i]
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= min(i, k); j++)
      dp[i] = add(dp[i], dp[i - j]);
  
  // Собираем ответ
  for (int i = dp[n].size() - 1; i >= 0; i--)
    printf("%d", dp[n][i]);
}