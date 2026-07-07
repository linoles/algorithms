#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)         // Перебор i...n
#define forr(i, n) for (int i = n - 1; i >= 0; i--)    // Перебор с конца
#define forab(i, a, b) for (int i = (a); i < (b); i++) // Перебор в диапазоне
#define LSOne(S) ((S) & -(S))                          // Наименьший значащий бит
#define PI acos(-1.0)                                  // Число pi
#define all(x) (x).begin(), (x).end()                  // Итераторы 0...n

typedef long long ll;

// Преф. суммы
vector<ll> find_pref(vector<ll> a)
{
  int n = a.size();
  vector<ll> b(n + 1, 0);
  forn(i, n) b[i + 1] = b[i] + a[i];
  return b;
}

// Разностный массив
vector<ll> find_diff(vector<ll> b)
{
  int n = b.size();
  vector<ll> a(n, 0);
  if (n > 0)
    a[0] = b[0];
  forab(i, 1, n) a[i] = b[i] - b[i - 1];
  return a;
}

int main()
{
  int n, q, l, r;
  ll d;
  scanf("%d", &n);
  vector<ll> c(n);
  forn(i, n) scanf("%lld", &c[i]);

  // a - разностный массив разностного массива c
  vector<ll> a = find_diff(find_diff(c));

  scanf("%d", &q);
  while (q--)
  {
    scanf("%d %d %lld", &l, &r, &d);
    l--, r--;

    a[l] += d;
    if (r + 1 < n)
      a[r + 1] -= (r - l + 2) * d;
    if (r + 2 < n)
      a[r + 2] += (r - l + 1) * d;
  }

  // Восстанваливаем массив
  vector<ll> res = find_pref(find_pref(a));

  forn(i, n) printf("%lld ", res[i + 2]);

  return 0;
}

// Допустим, l = 2, r = 6, d = 1 ( Учитывая, что это полуинтервал - [l, r) )

//        +d   +d  +d   +d
// 0   1   2    0   4    1   5    3
//   1   1   -2   4   -3   4   -2

// 0   1   1    -2   4    -3   4   -2
//   1   0   -3    6   -7    7   -6

// ==================================

// 0   1   3    2   7    5   5    3
//   1   2   -1   5   -2   0   -2
//      +d   +d  +d   +d  -4d

// 0   1   2    -1   5    -2   0   -2
//   1   1   -3    6   -7    2   -2
//      +d                 -5d  +4d
