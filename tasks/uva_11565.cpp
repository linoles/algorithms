#include <bits/stdc++.h>
using namespace std;

// UVa 11565 - Simple Equations
int main()
{
  int a, b, c; // 1 <= a, b, c <= 10000
  scanf("%d %d %d", &a, &b, &c);
  
  // a, b, c <= 10000. x² + y² + z² = c  =>  x² <= c  =>  x <= +-100, x принадл. [-100; 100]. Также с y, z
  for (int x = -100; x <= 100; x++)
    if (x * x <= c) // Сужение интервала
      for (int y = -100; y <= 100; y++)
        if (y != x && x * x + y * y <= c)
          for (int z = -100; z <= 100; z++)
            // x != y, y != z, x != z
            // x + y + z = a
            // x * y * z = b
            // x² + y² + z² = c
            if (y != z && x != z && x + y + z == a && x * y * z == b && x * x + y * y * +z * z == c)
            {
              printf("%d %d %d\n", x, y, z);
              return 0;
            };

  return 0;
}

// Минимальные a, b, c, которые принесут ответ - 1 8 20
// Их очень сложно подобрать. Задача легко решается, но сложно проверяется