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

// Codeforces 1840C - Горнолыжный курорт, O(n)
int main()
{
  int t, n, k, q;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &n, &k, &q);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Ищем отрезки длиной >= k, где каждое ai >= q
    ll ans = 0;
    int len = 0;
    forn(i, n)
    {
      // Если ai <= q, то прибавляем длину
      if (a[i] <= q)
        len++;
      // Иначе отрезок заканчивается
      else
      {
        // Если длина отрезка >= k, отрезок найден
        if (len >= k)
          // (len - k + 2) * (len - k + 1) / 2 - кол-во способов
          ans += (len - k + 2) * ll(len - k + 1) / 2;
        len = 0;
      }
    }

    // Учитываем последний отрезок
    if (len >= k)
      ans += (len - k + 2) * ll(len - k + 1) / 2;

    printf("%lld\n", ans);
  }

  return 0;
}

// 1, 1 2, 2, 1 2 3, 2 3, 3