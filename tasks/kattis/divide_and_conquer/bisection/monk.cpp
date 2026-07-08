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

// Kattis monk, O((d + a) * log time)
int main()
{
  int a, d;
  scanf("%d %d", &a, &d);
  vi ah(a), at(a), dh(d), dt(d);
  ll atime = 0, dtime = 0, top = 0; // Общее время на подъём и спуск
  forn(i, a)
  {
    scanf("%d %d", &ah[i], &at[i]);
    atime += at[i];
  }
  forn(i, d)
  {
    scanf("%d %d", &dh[i], &dt[i]);
    dtime += dt[i];
    top += dh[i];
  }

  // Поиск ответа - временную точку
  double lo = 0, hi = max(atime, dtime);
  while (hi - lo > 1e-6)
  {
    double mid = (lo + hi) / 2;

    // Ищем позицию в это время на подъёме
    double h = 0, t = 0, asc_h = -1, desc_h = -1;
    forn(i, a)
    {
      if (t + at[i] >= mid)
      {
        double fr = (mid - t) / at[i];
        asc_h = h + fr * ah[i];
        break;
      }
      t += at[i];
      h += ah[i];
    }
    if (asc_h == -1)
      asc_h = h;

    // Ищем позицию на спуске
    h = top, t = 0;
    forn(i, d)
    {
      if (t + dt[i] >= mid)
      {
        double fr = (mid - t) * ((double)dh[i] / dt[i]);
        desc_h = h - fr;
        break;
      }
      t += dt[i];
      h -= dh[i];
    }
    if (desc_h == -1)
      desc_h = 0;

    if (asc_h >= desc_h)
      hi = mid; // Ищем более раннее время
    else
      lo = mid;
  }

  printf("%f", lo);

  return 0;
}