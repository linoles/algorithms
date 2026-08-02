
#include <bits/stdc++.h>
using namespace std;

// Проверка палиндрома
bool is_pal(int mm, int hh)
{
  int u = mm % 10;        // Единицы в минутах
  int t = floor(mm / 10); // Десятки в минутах
  int temp = u * 10 + t;  // Перевёрнутые минуты
  if (temp == hh)
    return 1;
  else
    return 0;
}

// Codeforces 1692D (1100) - Часы, O(n)
int main()
{
  int t, x;
  scanf("%d", &t);

  // Составляем все возможные палиндромы времени
  vector<int> palindroms;
  for (int h = 0; h < 24; h++)
    for (int m = 0; m < 60; m++)
      if (is_pal(m, h))
        palindroms.push_back(h * 60 + m);

  while (t--)
  {
    int hh, mm;
    scanf("%d:%d %d", &hh, &mm, &x);
    int s = hh * 60 + mm; // Кол-во минут

    int pals_count = 0; // Кол-во найденных палиндромов
    for (int i = 0; i < palindroms.size(); i++)
    {
      // Проверяем, встретится ли Виктору этот палиндром
      int d = gcd(x, 1440);
      if (palindroms[i] % d == s % d)
        pals_count++;
    }

    printf("%d\n", pals_count);
  }

  return 0;
}