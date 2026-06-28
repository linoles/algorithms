#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 96B - Счастливые числа (упрощенная версия), O(1)
int main()
{
  int n;
  scanf("%d", &n);

  // Генерация очень счастливых чисел
  vector<ll> very_lucky; // В них только числа с чётным кол-вом цифр
  for (int i = 2; i <= 10; i += 2)
    // Генерируем очень счастливые числа длиной i
    for (int mask = 0; mask < (1 << i); mask++)
    {
      // 0 - 4, 1 - 7
      ll res = 0;
      int r = 0, fours = 0, sevens = 0;
      // Собираем результат из маски
      for (int j = 0; j < i; j++)
      {
        if (mask & (1 << j))
        {
          res += pow(10, r++) * 7;
          fours++;
        }
        else
        {
          res += pow(10, r++) * 4;
          sevens++;
        }
      }

      if (fours == sevens)
        very_lucky.push_back(res);
    }

  // Хоть и бинарный поиск не обязателен
  int lo = 0, hi = very_lucky.size() - 1;
  while (lo < hi)
  {
    int mid = lo + (hi - lo) / 2;
    if (very_lucky[mid] < n)
      lo = mid + 1;
    else
      hi = mid;
  }

  printf("%lld", very_lucky[lo]);

  return 0;
}