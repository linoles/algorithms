
#include <bits/stdc++.h>
using namespace std;

// UVa 11351 - Last Man Standing, O(n)
int main()
{
  int t, n, k, c = 0;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);

    // Циклически вычисляем ответ
    int cur = 0;
    for (int i = 1; i <= n; i++)
      cur = (cur + k) % i;
    printf("Case %d: %d\n", ++c, cur + 1); // cur - 0-indexed для удобства счёта формулы
  }

  return 0;
}

// Да, это именно задача Иосифа Флавия без каких-либо изменений
// Суть: просто найти последнего выжившего