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

// Kattis carefulscent, O(1)
int main()
{
  int x, y, n;
  scanf("%d %d", &x, &y);
  scanf("%d", &n);
  int l[n + 1], u[n + 1];
  double f[n + 1];
  forn(i, n) scanf("%d %d %lf", &l[i], &u[i], &f[i]);

  // Нужно подобрать такое начальное vx, чтобы после всех умножений на fi итоговое смещение было x
  double lo = -1e9, hi = 1e9;
  while (hi - lo > 1e-7)
  {
    double v = (hi + lo) / 2;

    // Теперь симулируем процесс
    ld s = 0, prev_h = 0;
    forn(i, n)
    {
      s += v * (l[i] - prev_h); // Процесс до блока
      s += v * f[i] * (u[i] - l[i]); // Внутри блока
      prev_h = u[i]; // Устанавливаем прошлую высоту
    }
    s += v * (y - prev_h); // Последняя часть после последнего блока

    if (s < x)
      lo = v;
    else
      hi = v;
  }

  printf("%f\n", lo);

  return 0;
}