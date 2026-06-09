#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 327A (1200) - Игра с переворачиванием, O()
int main() {
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  // Находим самую длинную последовательность из нулей
  // Параллельно считаем кол-во единиц
  int ones = 0, cur_start = -1, max_len = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 1)
    {
      ones++;
      max_len = max(max_len, i - cur_start);
    }
    else if (cur_start == -1)
      cur_start = i;
  }

  printf("%d\n\n", ones + max_len);

  return 0;
}