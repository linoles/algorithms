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

// Codeforces 1899C - Ярик и массив, O(n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    forn(i, n) scanf("%d", &a[i]);

    // Макс. результат и сумма текущего отрезка
    ll ans = LONG_LONG_MIN, cur = 0;
    // Проходимся по концу отрезка
    forn(i, n)
    {
      // Различная чётность - начинаем новый отрезок
      if (i > 0 && abs(a[i - 1] % 2) == abs(a[i] % 2))
        cur = a[i];
      else
        // Если это выгодно, то прибавляем текущий элемент, иначе начинаем новый отрезок
        cur = max(cur + a[i], (ll)a[i]);
      ans = max(ans, cur);
    }

    printf("%lld\n\n", ans);
  }

  return 0;
}