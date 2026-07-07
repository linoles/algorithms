#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;

int main()
{
  int n1, n2, n3, n4, n5, q;
  scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
  // 5D-массив (n1+1) × (n2+1) × (n3+1) × (n4+1) × (n5+1)
  vector<vector<vector<vector<vector<ll>>>>> a(
      n1 + 1,
      vector<vector<vector<vector<ll>>>>(n2 + 1,
                                         vector<vector<vector<ll>>>(n3 + 1,
                                                                    vector<vector<ll>>(n4 + 1,
                                                                                       vector<ll>(n5 + 1, 0)))));

  // Построение префиксных сумм
  forab(i1, 1, n1 + 1) forab(i2, 1, n2 + 1) forab(i3, 1, n3 + 1) forab(i4, 1, n4 + 1) forab(i5, 1, n5 + 1)
  {
    ll temp;
    scanf("%lld", &temp);

    // Перебираем маски
    ll sum = temp;
    forn(mask, (1 << 5))
    {
      int idx[5] = {i1, i2, i3, i4, i5}, bits = 0;
      forn(d, 5) if (mask & (1 << d))
      {
        idx[d]--; // Уменьшаем индекс этого измерения
        bits++; // Считаем, сколько измерений уменьшили для чередования знаков
      }

      // Если все индексы неотрицательны
      if (idx[0] >= 0 && idx[1] >= 0 && idx[2] >= 0 && idx[3] >= 0 && idx[4] >= 0)
      {
        if (bits % 2 == 1)
          sum += a[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]];
        else
          sum -= a[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]];
      }
      a[i1][i2][i3][i4][i5] = sum;
      // Грубо говоря: pref[i1][i2][i3][i4][i5] = a[i1][i2][i3][i4][i5] +
      // Σ(pref[с уменьшенными индексами] * (-1)^(количество уменьшений))
    }
  }

  scanf("%d", &q);
  while (q--)
  {
    int l1, r1, l2, r2, l3, r3, l4, r4, l5, r5;
    scanf("%d %d %d %d %d %d %d %d %d %d", &l1, &l2, &l3, &l4, &l5, &r1, &r2, &r3, &r4, &r5);
    l1--, l2--, l3--, l4--, l5--; // Переводим гиперпрямоугольник в полуинтервалы

    // Также масками получение суммы
    ll ans = 0;
    forn(mask, (1 << 5))
    {
      int idx[5] = {r1, r2, r3, r4, r5}, bits = 0;
      forn(d, 5) if (mask & (1 << d))
      {
        idx[d] = (d == 0 ? l1 : (d == 1 ? l2 : (d == 2 ? l3 : (d == 3 ? l4 : l5))));
        bits++;
      }
      ll val = a[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]];

      if (bits % 2 == 0)
        ans += val;
      else
        ans -= val;
    }

    printf("%lld\n", ans);
  }

  return 0;
}