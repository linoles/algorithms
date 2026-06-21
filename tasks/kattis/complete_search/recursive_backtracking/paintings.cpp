#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<string> c;
vector<vector<bool>> bad;
vector<int> best;
int total;
bool found;

// Проверяем, можно ли достроить картину до конца
bool can_complete(vector<int> &perm, vector<bool> &used)
{
  // Если использовали все цвета - успех
  if (perm.size() == n)
    return true;

  // Перебираем все цвета в порядке предпочтения
  for (int i = 0; i < n; i++)
  {
    // Пропускаем использованные
    if (used[i])
      continue;
    // Проверяем конфликт с последним цветом
    if (!perm.empty() && bad[perm.back()][i])
      continue;

    // Пробуем поставить цвет
    used[i] = true;
    perm.push_back(i);

    if (can_complete(perm, used))
    {
      perm.pop_back();
      used[i] = false;
      return true;
    }

    perm.pop_back();
    used[i] = false;
  }

  // Не нашли способ достроить
  return false;
}

// Считаем общее количество допустимых картин
void gen(vector<int> &perm, vector<bool> &used)
{
  // Если использовали все цвета - нашли одну картину
  if (perm.size() == n)
  {
    total++;
    return;
  }

  // Перебираем все цвета в порядке предпочтения
  for (int i = 0; i < n; i++)
  {
    // Пропускаем использованные
    if (used[i])
      continue;
    // Проверяем конфликт с последним цветом
    if (!perm.empty() && bad[perm.back()][i])
      continue;

    used[i] = true;
    perm.push_back(i);
    gen(perm, used);
    perm.pop_back();
    used[i] = false;
  }
}

// Находим любимую картину Кэтрин
void find_favorite(vector<int> &perm, vector<bool> &used)
{
  // Если использовали все цвета - нашли любимую картину
  if (perm.size() == n)
  {
    // Сохраняем первую найденную (она и будет любимой)
    if (!found)
    {
      best = perm;
      found = true;
    }
    return;
  }

  // Перебираем цвета в порядке убывания предпочтения
  for (int i = 0; i < n; i++)
  {
    // Пропускаем использованные
    if (used[i])
      continue;
    // Проверяем конфликт с последним цветом
    if (!perm.empty() && bad[perm.back()][i])
      continue;

    // Пробуем поставить цвет
    used[i] = true;
    perm.push_back(i);

    // Проверяем, можно ли достроить картину с этим цветом
    vector<int> temp_perm = perm;
    vector<bool> temp_used = used;
    if (can_complete(temp_perm, temp_used))
    {
      // Если можно - идём дальше
      find_favorite(perm, used);

      if (found)
      {
        perm.pop_back();
        used[i] = false;
        return;
      }
    }

    perm.pop_back();
    used[i] = false;
  }
}

int main()
{
  int t;
  scanf("%d", &t);

  while (t--)
  {
    scanf("%d", &n);
    c.resize(n);
    char buffer[21], buffer2[21];
    for (int i = 0; i < n; i++)
    {
      scanf("%s", buffer);
      c[i] = string(buffer);
    }

    scanf("%d", &m);
    bad.assign(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
      scanf(" %s %s", buffer, buffer2);
      int a = -1, b = -1;

      // Находим индексы цветов
      for (int j = 0; j < n; j++)
      {
        if (string(buffer) == c[j])
          a = j;
        if (string(buffer2) == c[j])
          b = j;
      }

      // Отмечаем конфликт (если оба цвета найдены)
      if (a != -1 && b != -1)
      {
        bad[a][b] = true;
        bad[b][a] = true;
      }
    }

    // Считаем общее количество допустимых картин
    total = 0;
    vector<int> perm;
    vector<bool> used(n, false);
    gen(perm, used);

    // Находим любимую картину
    best.clear();
    found = false;
    perm.clear();
    used.assign(n, false);
    find_favorite(perm, used);

    printf("%d\n", total);
    for (int i = 0; i < n; i++)
    {
      if (i > 0)
        printf(" ");
      printf("%s", c[best[i]].c_str());
    }
    printf("\n");
  }

  return 0;
}