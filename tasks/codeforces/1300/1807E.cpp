#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

// Codeforces 1807E - Интервью
int main()
{
  int t, n, w;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    vi pref(n + 1, 0); // Преф. суммы куч
    forab(i, 1, n + 1) pref[i] = pref[i - 1] + a[i - 1];

    // Каждый раз уменьшаем диапазон возможного ответа в два раза таким образом:
    // Выбираем первые ((hi - lo + 1) / 2) кучки. Если их вес не соответствует кол-ву камней, то
    // уменьшаем диапазон до [lo ... lo + sz - 1], иначе до [lo + sz ... hi]
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
      // Размер рассматриваемого диапазона и кол-во камней в нём
      int sz = (hi - lo + 1) / 2, sum = pref[lo + sz] - pref[lo];
      printf("? %d", sz, sum);
      forab(i, lo, lo + sz) printf(" %d", i + 1);
      printf("\n");
      fflush(stdout);

      scanf("%d", &w);
      if (w != sum)
        hi = lo + sz - 1;
      else
        lo += sz;
    }

    printf("! %d\n\n", lo + 1);
    fflush(stdout);
  }

  return 0;
}