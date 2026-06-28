#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 251A - Точки на прямой, O(n)
int main()
{
  int n, d;
  scanf("%d %d", &n, &d);
  int x[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &x[i]);

  // Перебираем конец отрезка, затем ищем левую точку указателем
  ll ans = 0;
  int l = 0;
  for (int r = 0; r < n; r++)
  {
    // Двигаем левый указатель, пока расстояние не станет > d
    while (x[r] - x[l] > d)
      l++;
    int k = r - l;              // Точек внутри
    ans += (ll)k * (k - 1) / 2; // C(k, 2) - троек можно образовать
  }

  printf("%lld", ans);

  return 0;
}