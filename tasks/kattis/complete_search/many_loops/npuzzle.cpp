
#include <bits/stdc++.h>
using namespace std;

// Kattis npuzzle, O(1)
int main()
{
  char puzzle[5][5];
  for (int i = 0; i < 4; i++)
    scanf(" %s", puzzle[i]);

  int sum = 0;
  // O(1), т.к. кол-во проделанных итераций не зависит от входных данных
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    {
      char c = puzzle[i][j];
      if (c == '.') // Точку пропускаем
        continue;
      int real_col = (int)(c - 'A') % 4; // Настоящий столбец этого символа
      int real_row = (int)(c - 'A') / 4; // Настоящий ряд этого символа
      sum += abs(i - real_row) + abs(j - real_col);
    }

  printf("%d", sum);

  return 0;
}