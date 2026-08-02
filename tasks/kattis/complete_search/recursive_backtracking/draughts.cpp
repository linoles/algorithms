
#include <bits/stdc++.h>
using namespace std;

// 0 - пусто, 1 - белая шашка, 2 - чёрная
vector<vector<int>> dr(10, vector<int>(10, 0));
int res = 0;

void gen(vector<pair<int, int>> &ate, int x, int y)
{
  res = max(res, (int)ate.size());

  int prev = dr[y][x];
  dr[y][x] = 0;

  // Следующие возможные ходы: (x - 1, y - 1), (x + 1, y - 1), (x - 1, y + 1), (x + 1, y + 1)
  if (x > 1 && y > 1 && dr[y - 1][x - 1] == 2 && // Проверка границ и самой клетки на чёрную шашку
      dr[y - 2][x - 2] == 0)                     // Проверка пустоты клетки за шашкой
  {
    ate.push_back(make_pair(x - 1, y - 1)); // Добавляем к съеденным
    dr[y - 1][x - 1] = 0;                   // Отмечаем на поле
    gen(ate, x - 2, y - 2);
    ate.pop_back();
    dr[y - 1][x - 1] = 2;
  }

  // ... Также с другими позициями
  if (x < 8 && y > 1 && dr[y - 1][x + 1] == 2 &&
      dr[y - 2][x + 2] == 0)
  {
    ate.push_back(make_pair(x + 1, y - 1));
    dr[y - 1][x + 1] = 0;
    gen(ate, x + 2, y - 2);
    ate.pop_back();
    dr[y - 1][x + 1] = 2;
  }

  if (x > 1 && y < 8 && dr[y + 1][x - 1] == 2 &&
      dr[y + 2][x - 2] == 0)
  {
    ate.push_back(make_pair(x - 1, y + 1));
    dr[y + 1][x - 1] = 0;
    gen(ate, x - 2, y + 2);
    ate.pop_back();
    dr[y + 1][x - 1] = 2;
  }

  if (x < 8 && y < 8 && dr[y + 1][x + 1] == 2 &&
      dr[y + 2][x + 2] == 0)
  {
    ate.push_back(make_pair(x + 1, y + 1));
    dr[y + 1][x + 1] = 0;
    gen(ate, x + 2, y + 2);
    ate.pop_back();
    dr[y + 1][x + 1] = 2;
  }

  dr[y][x] = prev;
}

// Kattis draughts
int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    vector<pair<int, int>> white; // Сохраняем пары координат белых шашек
    char buffer[11];
    for (int i = 0; i < 10; i++)
    {
      scanf(" %s", &buffer);
      for (int j = 0; j < 10; j++)
      {
        if (buffer[j] == 'W')
        {
          dr[i][j] = 1;
          white.push_back(make_pair(j, i));
        }
        else if (buffer[j] == 'B')
          dr[i][j] = 2;
      }
    }

    // Перебираем начальную точку
    for (pair<int, int> bl : white)
    {
      vector<pair<int, int>> ate = {};
      gen(ate, bl.first, bl.second);
    }

    printf("%d", res);

    // Очищаем всё, что касалось этого теста
    res = 0;
    dr.clear();
    dr.assign(10, vector<int>(10, 0));

    if (t > 0)
      printf("\n");
  }

  return 0;
}