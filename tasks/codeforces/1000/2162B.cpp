

#include <bits/stdc++.h>
using namespace std;

// Codeforces 2162B (1000) - Красивая строка, O(2^n * n)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char s[n + 1];
    scanf("%s", s);

    bool found = 0;
    for (int mask = 0; mask < (1 << n); mask++)
    {
      vector<int> p_indices; // Индексы символов в подстроке
      string p_chars;        // Сами символы в подстроке
      string x_chars;        // Символы снаружи подстроки

      for (int i = 0; i < n; i++)
      {
        // mask >> i & 1  -  сдвигает на i битов и проверяет, включен ли он,
        // чтобы проверить, используется ли этот символ
        if (mask >> i & 1)
        {
          p_indices.push_back(i + 1);
          p_chars.push_back(s[i]);
        }
        else
        {
          x_chars.push_back(s[i]);
        }
      }

      // Проверяем, является ли подпоследовательность неубывающей
      bool is_non_decreasing = 1;
      for (int j = 1; j < p_indices.size(); j++)
      {
        if ((int)p_chars[j] < (int)p_chars[j - 1])
        {
          is_non_decreasing = 0;
          break;
        }
      }
      if (!is_non_decreasing)
        continue;

      // Проверяем, является ли подпоследовательность палиндромом
      bool is_palindrome = 1;
      for (int j = 0; j < x_chars.size() / 2; j++)
      {
        if ((int)x_chars[j] != (int)x_chars[x_chars.size() - j - 1])
        {
          is_palindrome = 0;
          break;
        }
      }
      if (!is_palindrome)
        continue;

      // Выводим ответ
      printf("%d\n", p_indices.size());
      for (int j = 0; j < p_indices.size(); j++)
        printf("%d ", p_indices[j]);
      printf("\n\n");

      found = 1;
      break;
    }

    if (!found)
      printf("-1\n\n");
  }

  return 0;
}

// Кстати, время выполнения почти достигло лимита (593мс/1с),
// но тут я не вижу другого решения быстрее