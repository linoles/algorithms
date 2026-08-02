#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // Ищем idx наименьшего и наибольшего
    int mn = 0, mx = 0;
    for (int i = 1; i < n; i++)
    {
      if (a[mn] > a[i])
        mn = i;
      if (a[mx] < a[i])
        mx = i;
    }

    // Перебор всех вариантов
    printf("%d\n\n",
           min({
               max(mn, mx) + 1, // идти слева до встречи наименьшего и наибольшего
               n - min(mn, mx), // идти справа до встречи наименьшего и наибольшего
               n - mx + mn + 1, // идти слева до встречи мин. и справа до встречи макс.
               n - mn + mx + 1, // идти слева до встречи макс. и справа до встречи мин.
           }));
  }
}