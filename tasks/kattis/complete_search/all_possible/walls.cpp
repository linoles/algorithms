#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis walls, O(n)
int main()
{
  int l, w, n, r;
  scanf("%d %d %d %d", &l, &w, &n, &r);

  // Координаты центров стен. Все координаты умножены на 2, чтоб работать с int
  int walls[4][2] = {{-l, 0}, {l, 0}, {0, -w}, {0, w}};
  int r2 = 2 * r;

  vector<int> crane_masks;
  crane_masks.reserve(n);

  for (int i = 0; i < n; i++)
  {
    int x, y;
    scanf("%d %d", &x, &y);

    // Для каждой стены определяем, может ли центр быть захвачен этим краном
    int mask = 0;
    for (int wall = 0; wall < 4; wall++)
    {
      int dx = walls[wall][0] - 2 * x;
      int dy = walls[wall][1] - 2 * y;
      if (dx * dx + dy * dy <= r2 * r2)
        mask |= (1 << wall);
    }

    // Сохраняем только полезные
    if (mask > 0)
      crane_masks.push_back(mask);
  }

  int target = (1 << 4) - 1;
  vector<int> best(1 << 4, 5); // Максимум нужно 4 крана
  best[0] = 0;

  // Подбираем варианты
  for (int mask : crane_masks)
    for (int state = target; state >= 0; state--)
      if (best[state] < 5)
      {
        int new_state = state | mask;
        best[new_state] = min(best[new_state], best[state] + 1);
      }

  if (best[target] > 4)
    printf("Impossible\n");
  else
    printf("%d\n", best[target]);

  return 0;
}