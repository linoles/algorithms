#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Kattis misa, O()
int main()
{
  int r, s;
  scanf("%d %d", &r, &s);
  char places[r + 1][s + 1];
  for (int i = 0; i < r; i++)
    scanf("%s", &places[i]);

  bool has_empty = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
      if (places[i][j] == '.')
      {
        has_empty = 1;
        break;
      }

  if (has_empty)
  {
    vector<int> shakes(r * s + 1, 0); // Количество рукопожатий по индексу
    int best_i = -1, best_j = -1, best_sum = -1;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < s; j++)
      {
        // i - номер ряда, j - номер столбца
        if (places[i][j] == 'o')
          continue;

        // Всё, что слева от места
        if (j > 0)
        {
          if (i > 0 && places[i - 1][j - 1] == 'o')
            shakes[i * s + j]++;
          if (places[i][j - 1] == 'o')
            shakes[i * s + j]++;
          if (i < r - 1 && places[i + 1][j - 1] == 'o')
            shakes[i * s + j]++;
        }
        // Сверху
        if (i > 0 && places[i - 1][j] == 'o')
          shakes[i * s + j]++;
        // Снизу
        if (i < r - 1 && places[i + 1][j] == 'o')
          shakes[i * s + j]++;
        // Всё, что справа от места
        if (j < s - 1)
        {
          if (i > 0 && places[i - 1][j + 1] == 'o')
            shakes[i * s + j]++;
          if (places[i][j + 1] == 'o')
            shakes[i * s + j]++;
          if (i < r - 1 && places[i + 1][j + 1] == 'o')
            shakes[i * s + j]++;
        }

        // Сохраняем наибольшее
        if (shakes[i * s + j] > best_sum)
        {
          best_sum = shakes[i * s + j];
          best_i = i;
          best_j = j;
        }
      }

    places[best_i][best_j] = 'o';
  }

  // Теперь считаем кол-во рукопожатий
  vector<pair<pair<int, int>, pair<int, int>>> res;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
    {
      // i - номер ряда, j - номер столбца
      if (places[i][j] == '.')
        continue;

      // Всё, что слева от места
      if (j > 0)
      {
        if (i > 0 && places[i - 1][j - 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i - 1, j - 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i - 1, j - 1))) == res.end())
          res.push_back(make_pair(make_pair(i - 1, j - 1), make_pair(i, j)));
        if (places[i][j - 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j - 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i, j - 1))) == res.end())
          res.push_back(make_pair(make_pair(i, j - 1), make_pair(i, j)));
        if (i < r - 1 && places[i + 1][j - 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i + 1, j - 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i + 1, j - 1))) == res.end())
          res.push_back(make_pair(make_pair(i + 1, j - 1), make_pair(i, j)));
      }
      // Сверху
      if (i > 0 && places[i - 1][j] == 'o' &&
          find(res.begin(), res.end(), make_pair(make_pair(i - 1, j), make_pair(i, j))) == res.end() &&
          find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i - 1, j))) == res.end())
        res.push_back(make_pair(make_pair(i - 1, j), make_pair(i, j)));
      // Снизу
      if (i < r - 1 && places[i + 1][j] == 'o' &&
          find(res.begin(), res.end(), make_pair(make_pair(i + 1, j), make_pair(i, j))) == res.end() &&
          find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i + 1, j))) == res.end())
        res.push_back(make_pair(make_pair(i + 1, j), make_pair(i, j)));
      // Всё, что справа от места
      if (j < s - 1)
      {
        if (i > 0 && places[i - 1][j + 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i - 1, j + 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i - 1, j + 1))) == res.end())
          res.push_back(make_pair(make_pair(i - 1, j + 1), make_pair(i, j)));
        if (places[i][j + 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j + 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i, j + 1))) == res.end())
          res.push_back(make_pair(make_pair(i, j + 1), make_pair(i, j)));
        if (i < r - 1 && places[i + 1][j + 1] == 'o' &&
            find(res.begin(), res.end(), make_pair(make_pair(i + 1, j + 1), make_pair(i, j))) == res.end() &&
            find(res.begin(), res.end(), make_pair(make_pair(i, j), make_pair(i + 1, j + 1))) == res.end())
          res.push_back(make_pair(make_pair(i + 1, j + 1), make_pair(i, j)));
      }
    }

  printf("%d", res.size());

  return 0;
}