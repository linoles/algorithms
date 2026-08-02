
#include <bits/stdc++.h>
using namespace std;

// Kattis flexible, O(n * m²)
int main()
{
  int w, p;
  scanf("%d %d", &w, &p);
  int a[p + 3];
  a[0] = 0;
  a[p + 1] = w;
  for (int i = 1; i < p + 1; i++)
    scanf("%d", &a[i]);

  // Ищем все возможные результаты
  for (int x = 1; x <= w; x++)
  {
    bool found = 0; // Чтобы не вывести лишний раз
    for (int i = 0; i < p + 1 && !found; i++)
      for (int j = i + 1; j < p + 2 && !found; j++)
        if (a[j] - a[i] == x)
        {
          printf("%d ", x);
          found = 1;
        }
  }

  return 0;
}