
#include <bits/stdc++.h>
using namespace std;

// Kattis set, O(1)
int main()
{
  char cards[5][4][5];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 3; j++)
      scanf(" %s", cards[i][j]);

  // Перебираем все возможные комбинации из трёх карт
  vector<tuple<int, int, int>> res;
  for (int idx1 = 0; idx1 < 12; idx1++)
  {                    // карта 1
    int i1 = idx1 / 3; // строка
    int j1 = idx1 % 3; // столбец
    for (int idx2 = idx1 + 1; idx2 < 12; idx2++)
    {                    // карта 2
      int i2 = idx2 / 3; // строка
      int j2 = idx2 % 3; // столбец
      for (int idx3 = idx2 + 1; idx3 < 12; idx3++)
      {                    // карта 3
        int i3 = idx3 / 3; // строка
        int j3 = idx3 % 3; // столбец

        // Проверяем, не совпадают ли карты
        if (
            (i1 != i2 || j1 != j2) &&
            (i1 != i3 || j1 != j3) &&
            (i2 != i3 || j2 != j3))
        {
          // Сами карты
          string card1 = cards[i1][j1];
          string card2 = cards[i2][j2];
          string card3 = cards[i3][j3];

          bool add = 1;
          // Проверяем каждую характеристику карты
          for (int type = 0; type < 4; type++)
          {
            if (
                // Все равны или все различны
                !((card1[type] == card2[type] && card1[type] == card3[type]) ||
                  (card1[type] != card2[type] && card1[type] != card3[type] && card2[type] != card3[type])))
            {
              add = 0;
              break;
            }
          }

          if (add)
            res.push_back(make_tuple(i1 * 3 + j1 + 1, i2 * 3 + j2 + 1, i3 * 3 + j3 + 1));
        }
      }
    }
  }

  for (const auto &[c1, c2, c3] : res)
    printf("%d %d %d\n", c1, c2, c3);

  if (res.size() == 0)
    printf("no sets");

  return 0;
}