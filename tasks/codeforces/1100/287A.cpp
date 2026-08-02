
#include <bits/stdc++.h>
using namespace std;

// Codeforces 287A (1100) - IQ-тест, O(1)
int main()
{
  char list[5][5];
  scanf("%s", list[0]);
  scanf("%s", list[1]);
  scanf("%s", list[2]);
  scanf("%s", list[3]);

  int possible = 0;
  // Проходимся по квадратам 2x2 и смотрим, сколько закрашенных и незакрашенных клеток
  for (int i = 1; i < 4; i++) // i = 1, т.к. проверяем квадрат с левого нижнего края
    for (int j = 0; j < 3; j++)
    {
      int white = 0, black = 0;
      if (list[i - 1][j] == '.') white++; // Верхний левый
      else black++;
      if (list[i - 1][j + 1] == '.') white++; // Верхний правый
      else black++;
      if (list[i][j] == '.') white++; // Нижний левый
      else black++;
      if (list[i][j + 1] == '.') white++; // Нижний правый
      else black++;

      // Если 3 одинаковых цвета, мы закрасим одну клетку и получим квадрат
      // Если 4 одинаковых, то это уже квадрат
      if (white >= 3 || black >= 3) {
        possible = 1;
        break;
      }
    }

  printf(possible ? "YES" : "NO");

  return 0;
}