#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis cudoviste, O(c * r)
int main()
{
  int r, c;
  scanf("%d %d\n", &r, &c);
  char places[r + 1][c + 1];
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++)
    {
      scanf(" %c", &places[i][j]);
    }

  // Ключ - кол-во машин, значение - кол-во вариантов парковки с таким кол-вом раздавленных машин
  unordered_map<int, int> res;
  for (int i = 0; i < 5; i++)
    res[i] = 0; // Заполняем нулями
  for (int x = 0; x < c - 1; x++)
    for (int y = 0; y < r - 1; y++)
    {
      // Тут квадрат 2х2:
      // (x;y)   (x+1;y)
      // (x;y+1) (x+1;y+1)
      // Начало координат в точке (0;0), конец в (c;r)

      // printf("%c%c\n%c%c\n\n", places[y][x], places[y][x + 1], places[y + 1][x], places[y + 1][x + 1]);
      // выведет все рассмотренные комбинации квадратов
      if (
          places[y][x] == '#' || places[y][x + 1] == '#' ||
          places[y + 1][x] == '#' || places[y + 1][x + 1] == '#')
        continue;

      int cars = 0;
      if (places[y][x] == 'X')
        cars++;
      if (places[y][x + 1] == 'X')
        cars++;
      if (places[y + 1][x] == 'X')
        cars++;
      if (places[y + 1][x + 1] == 'X')
        cars++;

      res[cars]++;
    }

  printf("%d\n%d\n%d\n%d\n%d\n", res[0], res[1], res[2], res[3], res[4]);
}