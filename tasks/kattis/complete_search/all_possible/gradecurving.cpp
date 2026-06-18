#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Рекурсивное получение результата
int f(float x, int times)
{
  // Базовые случаи
  if (times == 0)
    return ceil(x);
  if (times == 1)
    return ceil(10 * sqrtf(x));

  return f(10.0 * sqrtf(x), --times);
}

// Kattis gradecurving, O(1)
int main()
{
  int x, y_low, y_high;
  scanf("%d %d %d", &x, &y_low, &y_high);

  int k_low = -1, k_high = -1, last_f = x;
  // На всякий случай поставил высокую границу, но дальше 10 уходит только при x = 0
  for (int k = 0; k <= 100; k++)
  {
    int res = f((float)x, k);
    // Устанавливаем k_low
    if (k_low == -1 && res >= y_low && res <= y_high)
      k_low = k;
    // Устанавливаем k_high
    if (res > y_high)
    {
      k_high = k - 1;
      break;
    }
    // Только при y_high = 100 k_high = inf
    if (y_high == 100 && res >= y_low)
      break;

    // Сохраняем значение функции при предыдущем k, чтоб не вызывать лишний раз рекурсию
    last_f = res;
  }

  if (k_low == -1)
    printf("impossible");
  else if (k_high == -1)
    printf("%d inf", k_low);
  else
    printf("%d %d", k_low, k_high);

  return 0;
}