#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 2050C (1200) - Неинтересное число, O(n²)
int main()
{
  int t;
  char n[(int)(10e4 + 1)];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", &n);

    // x² < 10  =>  x <= 3
    // Признак делимости на 9: сумма цифр делится на 9

    // Считаем текущую сумму цифр, пытаемся превратить её в кратное 9 число
    int sum = 0;
    for (int i = 0; i < strlen(n); i++)
      sum += n[i] - '0';

    // Варианты изменения суммы:
    // x = 2: sum += 2
    // x = 3: sum += 6

    // Считаем все цифры, которые смогут изменить сумму
    int threes = 0, twos = 0;
    for (int i = 0; i < strlen(n); i++)
    {
      if (n[i] - '0' == 2)
        twos++;
      else if (n[i] - '0' == 3)
        threes++;
    }
    
    bool found = 0;
    for (int used2 = 0; used2 <= twos; used2++)
      for (int used3 = 0; used3 <= threes; used3++)
        if ((sum + used2 * 2 + used3 * 6) % 9 == 0)
        {
          found = true;
          break;
        }

    if (!found)
      printf("NO\n");
    else
      printf("YES\n");
  }

  return 0;
}