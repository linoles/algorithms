#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point
{
  ll x, y, sq_dist;
  int pop;
};

// Codeforces 424B - Город-миллионер, O(n * log n)
int main()
{
  int n, s;
  scanf("%d %d", &n, &s);
  vector<Point> a(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld %lld %d", &a[i].x, &a[i].y, &a[i].pop);
    a[i].sq_dist = a[i].x * a[i].x + a[i].y * a[i].y; // (т.к. Томск в точке (0, 0))
  }

  // В любом случае новые границы города должны заканчиваться именно на одном из (x, y) в a
  // Для этого сначала отсортируем a, чтобы понимать, до каких точек выгоднее всего расшириться
  sort(a.begin(), a.end(),
       [&](const Point &a, const Point &b)
       {
         return b.sq_dist > a.sq_dist; // Сортируем по возрастанию расстояния до Томска
       });

  int pop = s; // Текущяя популяция
  bool found = 0;
  // Присоединяем территории, пока население меньше 1млн
  for (const Point &x : a)
  {
    pop += x.pop;
    // 1млн = 10^6 = 1e6
    if (pop >= (int)1e6)
    {
      found = 1;
      printf("%.7f\n", sqrt((double)x.sq_dist)); // До 7 знаков после запятой
      break;
    }
  }

  if (!found)
    printf("-1");

  return 0;
}