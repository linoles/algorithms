#include <bits/stdc++.h>
using namespace std;

// Codeforces 1593C - Спасти больше мышек, O(n)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);
    int x[k + 1];
    for (int i = 0; i < k; i++)
      scanf("%d", &x[i]);

    // Сортируем по убыванию, чтобы видеть, какие мышки ближе к норе
    sort(x, x + k, greater<int>());

    // Нет смысла спасать тех, кто ближе к кошке. Иначе лучше брать по одной мышке с конца и
    // пытаться спасти её
    int cat = 0, res = 0;
    for (int i = 0; i < k; i++)
    {
      // Если мышка не успеет дойти до норки
      if (cat >= x[i])
        break;
      // Иначе считаем, что мышка прошла до норки, и кошка в этот момент двигалась
      cat += n - x[i];
      res++;
    }

    printf("%d\n", res);
  }

  return 0;
}