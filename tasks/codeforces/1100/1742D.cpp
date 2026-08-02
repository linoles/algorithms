

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 1742D (1100) - Взаимно простые, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    // Так как числа <= 1000, мы находим для каждого индекс последней встречи
    vector<int> last_inds(1000, -1);
    for (int i = 0; i < n; i++)
    {
      last_inds[a[i]] = i;
    }

    // Перебираем все числа
    int max_res = 0;
    for (int x = 0; x <= 1000; x++)
      for (int y = 0; y <= 1000; y++)
        if (last_inds[x] != -1 && last_inds[y] != -1 && gcd(x, y) == 1) // Проверяем, встречаются ли в массиве и НОД(x, y)
          max_res = max(max_res, last_inds[x] + last_inds[y] + 2);      // 1-indexed, поэтому +1 * 2 = +2

    printf("%d\n\n", (max_res == 0) ? -1 : max_res);
  }

  return 0;
}