
#include <bits/stdc++.h>
using namespace std;

// Kattis communication, O(n)
int main()
{
  int n;
  scanf("%d", &n);
  int a[n + 1];
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 0; i < n; i++)
    // Подбираем результат
    for (int m = 0; m <= 255; m++)
      // Обрезаем до 8 бит
      if ((m ^ (m << 1) & 0xFF) == a[i])
      {
        printf("%d ", m);
        break;
      }

  return 0;
}