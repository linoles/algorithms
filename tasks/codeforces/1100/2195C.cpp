#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool ok(int x, int y)
{
  return x != y && x + y != 7;
}

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // На самом деле, посл. b - посл. бросков кубика, если все соседние a[i] и a[i+1]
    // удовлетворяют условию: a[i] != a[i+1] && a[i] != 7 - a[i+1] && a[i+1] != 7 - a[i]

    // dp[x] = мин. кол-во замен для текущего элемента, если мы установим его = x
    vector<int> dp(7, 1e9);
    for (int x = 1; x <= 6; x++) // Просчитываем для первого элемента
      dp[x] = (a[0] != x);

    for (int i = 1; i < n; i++)
    {
      vector<int> ndp(7, 1e9);
      for (int cur = 1; cur <= 6; cur++)      // Текущий после замен
        for (int prev = 1; prev <= 6; prev++) // Предыдущий после замен
          if (ok(prev, cur))                  // Проверка, можем ли поставить
            ndp[cur] = min(ndp[cur], dp[prev] + (a[i] != cur));
      // dp[prev]      = сколько было изменений при таком предыдущем
      // (a[i] != cur) = поменялся ли текущий
      // ndp[cur]      = минимальный вариант с таким же cur
      dp = ndp;
    }

    printf("%d\n\n", *min_element(dp.begin(), dp.end()));
  }
}