#include <bits/stdc++.h>
using namespace std;

// Codeforces 181B - Сколько троек, O(n² * log n)
int main()
{
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> xy(n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", &xy[i].first, &xy[i].second);

  // Если есть отрезок AC и B - его середина,
  // тогда B находится в точке ((Ax + Cx) / 2; (Ay + Cy) / 2)
  // Для каждой точки проверяем, можно ли подобрать такие A и С:
  // Bx = (Ax + Cx) / 2  =>  Ax = 2Bx - Cx, Cx = 2Bx - Ax
  // By = (Ay + Cy) / 2  =>  Ay = 2By - Cy, Cy = 2By - Ay
  sort(xy.begin(), xy.end());

  // Заполняем красно-чёрное дерево (множество), чтобы искать за O(log n)
  set<pair<int, int>> points;
  for (pair<int, int> p : xy)
    points.insert(p); // (Для unordered_set пришлось бы писать свою хеш-функцию)

  int ans = 0;
  for (int b = 1; b < n - 1; b++)
    for (int a = 0; a < b; a++)
    {
      // Во первых, C будет дальше B на прямой, а во вторых C имеет следующие координаты:
      int cx = 2 * xy[b].first - xy[a].first, cy = 2 * xy[b].second - xy[a].second;
      // За O(log n) находим в points точку C
      auto c_it = points.find(make_pair(cx, cy));
      if (c_it != points.end())
        ans++;
    }

  printf("%d", ans);

  return 0;
}