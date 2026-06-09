#include <iostream>
#include <vector>
using namespace std;

// Codeforces 635A (1100) - Оркестр, O(r² * c² * n)
int main()
{
  int r, c, n, k;
  scanf("%d %d %d %d", &r, &c, &n, &k);
  vector<pair<int, int>> xy(n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &xy[i].first, &xy[i].second);
    xy[i].first--;
    xy[i].second--;
  }

  // r * c прямоугольник, n альтистов и k минимально альтистов на фотографии

  // Проходимся по всем фотографиям, которые можно сделать на поле (макс. 10x10 поле, 3025 фото)
  int res = 0;
  for (int x1 = 0; x1 < r; x1++)
    for (int y1 = 0; y1 < c; y1++)
      for (int h = 1; h <= r - x1; h++)
        for (int w = 1; w <= c - y1; w++)
        {
          int cnt = 0;
          for (auto p : xy)
            if (p.first >= x1 && p.first < x1 + h &&
                p.second >= y1 && p.second < y1 + w)
              cnt++;
          if (cnt >= k)
            res++;
        }

  printf("%d\n", res);
  return 0;
}