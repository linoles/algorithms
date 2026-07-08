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

// Kattis speed, O(n * log n)
int main()
{
  int n, t;
  scanf("%d %d", &n, &t);
  int d[n + 1], s[n + 1];
  forn(i, n) scanf("%d %d", &d[i], &s[i]);

  double lo = -*min_element(s, s + n) + 1e-9, hi = 1e9;
  while (hi - lo > 1e-9)
  {
    double mid = (lo + hi) / 2, time = 0;
    // Считаем общее потраченное время
    forn(i, n) time += d[i] / (s[i] + mid);

    if (time > t)
      lo = mid;
    else
      hi = mid;
  }

  printf("%f", lo);

  return 0;
}