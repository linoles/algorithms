
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1704B (1000) - Люк гурман, O(n)
int main()
{
  int t, n, x;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &x);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // x >= |v - a[i]|  =>  v принадл. [a[i] - x; a[i] + x]
    // Изначально принимаем такие границы с a[0]
    int res = 0;
    int l = a[0] - x;
    int r = a[0] + x;
    for (int i = 1; i < n; i++)
    {
      // Дальше сравниваем пересечение новых границ и текущих
      int new_l = max(l, a[i] - x);
      int new_r = min(r, x + a[i]);
      // Если пересечение - пустое множество, то делаем изменение
      if (new_l > new_r)
      {
        res++;
        l = a[i] - x;
        r = x + a[i];
      }
      else
      {
        l = new_l;
        r = new_r;
      }
    }

    printf("%d\n\n", res);
  }

  return 0;
}