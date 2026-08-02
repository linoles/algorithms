
#include <bits/stdc++.h>
using namespace std;

// UVa 10774 - Repeated Josephus, O()
int main()
{
  // J(n, k), n = input, k = 2
  int t, n, c = 0;
  scanf("%d", &t);
  while (t--)
  {
    c++;
    scanf("%d", &n);

    // Проводим процесс: находим последнего выжившего, обрезаем выживших до его номера
    // Если не обрезалось ни одного участника, выходим
    int cur = 0, alive = n, opers = -1;
    while (true)
    {
      opers++;
      for (int i = 1; i <= alive; ++i)
        cur = (cur + 2) % i;
      if (alive - cur == 1)
        break;
      alive -= alive - cur - 1;
    }
    printf("Case %d: %d %d\n", c, opers, cur + 1);
  }

  return 0;
}