
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1097B (1200) - Пётр и кодовый замок, O(2^n * n)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  bool found = 0;
  for (int mask = 0; mask <= (1 << n) && !found; mask++)
  {
    // В битмаске 0 - не провернули, 1 - провернули
    int cur_sum = 0;
    for (int i = 0; i < n; i++)
      cur_sum += ((mask & (1 << i)) ? a[i] : -a[i]); // Прибавляем, если провернули, иначе вычетаем

    // 360 - один оборот
    if (cur_sum % 360 == 0)
      found = 1;
  }

  printf(found ? "Yes" : "No");

  return 0;
}