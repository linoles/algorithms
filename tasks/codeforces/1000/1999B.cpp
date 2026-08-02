
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1999B (1000) - Карточная игра, O(1) - выполнится 4 итерации в любом случае
int main()
{
  int t, a[3], b[3];
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);

    int bitmask = 00; // Первый разряд: 0, если Сунит выбрал 1-ую карту, 1, если выбрал 2-ую карту
                      // Второй разряд: 0, если Славик выбрал 1-ую карту, 1, если выбрал 2-ую карту

    int res = 0;
    for (; bitmask < (1 << 2); bitmask++)
    {
      int a_val = a[bitmask & 1];                      // bitmask = 10: a[10 & 01] = a[0], bitmask = 11: a[11 & 01] = a[1]
      int b_val = b[((bitmask & 2) == 0) ? 0 : 1];     // bitmask = 01: b[01 & 10] = b[0], bitmask = 11: b[11 & 10] = b[10b] = b[2d]
      int oth_a_val = a[!(bitmask & 1)];               // Находим следующий выбор Сунита
      int oth_b_val = b[((bitmask & 2) == 0) ? 1 : 0]; // Находим следующий выбор Славика

      // Тут важный момент: я долго не мог понять, в чём ошибка, но я забыл учесть:
      if ((a_val > b_val && oth_a_val > oth_b_val) ||
          (a_val == b_val && oth_a_val > oth_b_val) || // Когда 1-ый раунд ничья, а 2-ой победа
          (a_val > b_val && oth_a_val == oth_b_val))   // Или 1-ый раунд победа, а 2-ой ничья
        res++;
    }

    printf("%d\n", res);
  }

  return 0;
}

// Да, тут можно просто перебрать все варианты в одном if, но я решил сделать решение чуть поумнее