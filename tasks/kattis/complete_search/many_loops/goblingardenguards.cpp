#include <iostream>
#include <vector>
using namespace std;

// Kattis goblingardenguards, O(g + m * r²)
int main()
{
  int g;
  scanf("%d", &g);

  // Получаем гоблинов
  vector<pair<int, int>> goblins(g);
  for (int i = 0; i < g; i++)
    scanf("%d %d", &goblins[i].first, &goblins[i].second);

  // Сетка 10001х10001 (все координаты)
  // 1 - омывается кем-то, 0 - нет
  vector<vector<bool>> soaked(10001, vector<bool>(10001, false));

  int m;
  scanf("%d", &m);

  // Заполняем сетку
  for (int i = 0; i < m; i++)
  {
    int sx, sy, sr;
    scanf("%d %d %d", &sx, &sy, &sr);
    int r2 = sr * sr;

    // Координаты краев
    int x1 = max(0, sx - sr);
    int x2 = min(10000, sx + sr);
    int y1 = max(0, sy - sr);
    int y2 = min(10000, sy + sr);

    for (int x = x1; x <= x2; x++)
    {
      int dx = x - sx;
      int dx2 = dx * dx;
      for (int y = y1; y <= y2; y++)
      {
        int dy = y - sy;
        if (dx2 + dy * dy <= r2)
          soaked[x][y] = true;
      }
    }
  }

  int remaining = 0;
  for (auto [x, y] : goblins)
    if (!soaked[x][y])
      remaining++;

  printf("%d\n", remaining);
  return 0;
}