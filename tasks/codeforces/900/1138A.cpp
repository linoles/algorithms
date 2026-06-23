#include <bits/stdc++.h>
using namespace std;

// Codeforces 1138A - Суши для двоих, O(n)
int main()
{
  int n, best = 0, cur_type = 0, cur_start = 0, prev_len = 0;
  scanf("%d", &n);
  int t[n + 1];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &t[i]);
    // В первую итерацию устанавливаем только текущий тип
    if (i == 0)
      cur_type = t[i];
    if (t[i] != cur_type)
    {
      cur_type = t[i];                                    // Устанавливаем новый тип
      best = max(best, min(prev_len, i - cur_start) * 2); // Обновляем лучший результат
      prev_len = i - cur_start;                           // Устанавливаем прошлую длину - длину текущей посл.
      cur_start = i;                                      // Устанавливаем начало новой посл.
    }
  }

  best = max(best, min(prev_len, n - cur_start) * 2); // Не забываем про последовательность в конце

  printf("%d", best);

  return 0;
}