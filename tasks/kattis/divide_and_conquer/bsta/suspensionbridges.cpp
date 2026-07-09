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

// Kattis suspensionbridges, O(1)
int main()
{
  int d, s;
  scanf("%d %d", &d, &s);

  double lo = 0, hi = 1e9;
  while (hi - lo > 1e-9)
  {
    double mid = (lo + hi) / 2, f = mid * (cosh(d / (2 * mid)) - 1) - s;

    if (f > 0)
      lo = mid;
    else
      hi = mid;
  }

  double a = (lo + hi) / 2, len = 2 * a * sinh(d / (2 * a));
  printf("%f", len);

  return 0;
}