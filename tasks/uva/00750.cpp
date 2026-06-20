#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cells(8, vector<int>(8, 0));
int sol = 0;

bool can_place(int x, int y, vector<int> &cols)
{
  // Уже проверено, есть ли на этом ряду ферзь,
  // так что проверяем все колонки на наличие ферзя на этой вертикал
  for (int col = 0; col < 8; col++)
  {
    // Пропускаем пустые колонки и текущую колонку
    if (cols[col] == -1 || col == x)
      continue;

    int row = cols[col]; // ряд ферзя в этой колонке

    // Проверяем ряд и диагональ
    if (row == y || abs(x - col) == abs(y - row))
      return false;
  }

  return true;
}

// Recursive Backtracking функция
void gen(vector<int> &cols, int count)
{
  // Выводим, если расставлены восемь ферзей
  if (count == 8)
  {
    printf("%2d      ", ++sol);
    for (int i = 0; i < 8; i++)
      printf((i == 7) ? "%d" : "%d ", cols[i] + 1);
    printf("\n");
    return;
  }

  // Находим следующую пустую строку
  int i = 0;
  for (; i < 8; i++)
    if (cols[i] == -1)
      break;

  // Подбираем столбец
  for (int j = 0; j < 8; j++)
    if (cols[i] == -1 && can_place(i, j, cols))
    {
      cells[i][j] = 1;
      cols[i] = j;
      gen(cols, count + 1); // Продолжаем с этим столбцом
      cols[i] = -1;
      cells[i][j] = 0;
    }
}

// UVa 00750 - 8 Queens Chess Problem, O()
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int x, y;
    scanf("%d %d", &y, &x);
    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    x--; // Переводим в 0-indexed
    y--;
    cells[x][y] = 1; // Отмечаем первого ферзя

    // Отмечаем его уже в cols
    vector<int> cols(8, -1);
    cols[x] = y;
    gen(cols, 1);

    // Опустошаем cells, обнуляем число решений и выводим пустую строку
    cells.assign(8, vector<int>(8, 0));
    sol = 0;
    if (t > 0)
      printf("\n");
  }

  return 0;
}