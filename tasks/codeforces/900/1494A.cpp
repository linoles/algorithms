#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;

// Codeforces 1494A (900) - Строка ABC, итераций t * 8 * (3n + n + n) = 40 * t * n  =>  O(n) на каждый тест
int main()
{
  int t;      // 1 ≤ t ≤ 1000
  char s[51]; // 2 ≤ n ≤ 50. Проблема в том, что из-за размера 50 вылетает RTE. Я не знаю, с чем это связано
  bool found = 0, exited = 0;
  scanf("%d", &t);

  while (t--)
  {
    scanf("%s", s);
    int bit = 0;  // bitmask для перебора, 000 - правый бит A, средний B, левый C
    char old[51]; // Массив будет изменён для удобства, чтобы потом вернуть, делаем дубликат
    strcpy(old, s);

    while (bit < 1 << 3)
    {
      stack<char> brackets;
      replace(s, s + strlen(s), 'A', ((bit & 1 << 0) ? ')' : '(')); // 101 & 001 = 1: )
      replace(s, s + strlen(s), 'B', ((bit & 1 << 1) ? ')' : '(')); // 101 & 010 = 0: (
      replace(s, s + strlen(s), 'C', ((bit & 1 << 2) ? ')' : '(')); // 101 & 100 = 1: )

      exited = 0; // Флаг для проверки, вышли ли из следующего цикла

      for (int c = 0; c < strlen(s); c++)
      {
        if (s[c] == '(')
          brackets.push('(');
        else
        {
          if (brackets.empty())
          {
            exited = 1; // Нужен флаг, чтобы не засчитать это как правильную последовательность
            break;
          }
          else
            brackets.pop(); // Если ) и у неё есть пара, удаляем пару
        }
      }

      bit++;
      strcpy(s, old); // Возвращение массива на место

      if (!exited && brackets.empty())
      {
        found = 1;
        break;
      }
    }

    cout << (found ? "YES\n" : "NO\n");
    found = 0;
  }

  return 0;
}