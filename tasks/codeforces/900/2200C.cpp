#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 2200C (900) - Специальная строка, операций на тест приблизительно (n/2) * n = O(n²)
int main()
{
  int t; // 1 ≤ t ≤ 100, 1 ≤ n ≤ 5000
  scanf("%d", &t);
  while (t--)
  {
    int n;
    scanf("%d", &n);
    string s;
    char temp[n]; // C-style char массив быстрее, но тут я использую строку, чтобы удалять элементы
    scanf("%s", &temp);
    s = temp;

    if (n % 2 == 1) // Если строка нечётной длины, робот не может выиграть
    {
      printf("NO\n\n");
      continue;
    }

    bool found = 0;
    for (int i = 0; i < n / 2; i++)
    {
      // Ищем подстроку длины 2 с одинаковыми символами (Например, jj)
      int dupl = -1;
      for (int j = 1; j < s.length(); j++)
      {
        if (s.at(j) == s.at(j - 1))
          dupl = j - 1;
      }

      // Если текущая строка не пуста, но дублирующихся символов не найдено
      // Тогда робот не может выиграть
      if (dupl == -1 && size(s) != 0)
      {
        found = 0;
        break;
      }
      // Если та подстрока (jj) найдена, то удаляем эти оба символа
      else if (size(s) != 0)
      {
        s.erase(s.begin() + dupl); // Удаляем элемент с индексом dupl
        s.erase(s.begin() + dupl); // Удаляем элемент с индексом dupl + 1
                                   // (После первого удаления индексы сдвинулись)
      }

      // По итогу массив должен опустеть
      if (size(s) == 0)
      {
        found = 1;
        break;
      }
    }

    cout << (found ? "YES\n\n" : "NO\n\n");
  }

  return 0;
}