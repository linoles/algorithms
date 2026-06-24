#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2024B - Покупка лимонада, O(n * log n)
int main()
{
  int t, n, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d", &n, &k);

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
      scanf("%lld", &a[i]);

    sort(a.begin(), a.end());

    ll got = 0; // сколько банок уже гарантированно получили
    int x = 0;  // сколько дополнительных нажатий (на пустые ячейки)

    for (int i = 0; i < n; i++)
    {
      // Высота текущего слоя и сколько банок даст этот слой
      ll height = a[i] - (i > 0 ? a[i - 1] : 0), take = height * (n - i);

      if (got + take >= k)
      {
        // Нужное кол-во лежит в этом слое
        printf("%lld\n", (ll)k + x);
        break;
      }

      // Берем весь слой и добавляем одно лишнее нажатие (которое может быть неуспешным)
      got += take;
      x++;
    }
  }

  return 0;
}