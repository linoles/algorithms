#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 2028A (900) - Приключения Алисы в "Шахматах", O(n) на тест
int main()
{
  int t, n, a, b, x = 0, y = 0; // 1 ≤ t ≤ 500, 1 ≤ n, a, b ≤ 10; (x, y) - координаты Алисы
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &n, &a, &b);
    char s[n];
    bool found = 0;
    scanf("%s", &s);

    // Выполняем действия Алисы
    for (int i = 0; x <= 30 && y <= 30 && i <= 100 * n; i++) // ограничения для x и y, наверное, можно не ставить
                                                             // 100 * n выбрал, чтобы точно успеть, но скорее всего тут что-то вроде 21 * n, хотя так тоже будет AC
    {
      char c = s[i % n]; // Текущий элемент, остаток от деления для цикличности
      if (c == *"N")
        y++; // Север
      else if (c == *"E")
        x++; // Запад
      else if (c == *"S")
        y--; // Юг
      else if (c == *"W")
        x--; // Восток

      if (x == a && y == b) // Алиса попала на клетку королевы
      {
        found = 1;
        break;
      };
    }

    cout << (found ? "YES\n" : "NO\n");
    x = 0;
    y = 0;
  }

  return 0;
}