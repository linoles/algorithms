#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 152B - Шаги, O(n)
int main()
{
  int n, m, xc, yc, k, dx, dy;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &xc, &yc);
  scanf("%d", &k);

  // За каждый вектор он делает max(|dx|, |dy|) шагов, если шаг корректный
  ll ans = 0;
  for (int i = 0; i < k; i++)
  {
    scanf("%d %d", &dx, &dy);

    ll steps_x = LLONG_MAX, steps_y = LLONG_MAX;

    // Максимальное кол-во шагов по оси x:
    if (dx > 0)
      steps_x = (n - xc) / dx;
    else if (dx < 0)
      steps_x = (xc - 1) / (-dx);

    // Максимальное кол-во шагов по оси y:
    if (dy > 0)
      steps_y = (m - yc) / dy;
    else if (dy < 0)
      steps_y = (yc - 1) / (-dy);

    // Итого шагов
    int steps = min(steps_y, steps_x);
    xc += steps * dx; // Перемещение
    yc += steps * dy; // Перемещение
    ans += steps;
  }

  printf("%lld", ans);

  return 0;
}