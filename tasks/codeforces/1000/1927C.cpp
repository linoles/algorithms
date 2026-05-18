#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 1927C (1000) - Выбери различные!, O()
int main()
{
  int t, n, m, k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &n, &m, &k);
    int a[n + 1], b[m + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
      scanf("%d", &b[i]);

    int ab[n + m + 1];
    memcpy(ab, a, n * sizeof(int));
    memcpy(ab + n, b, m * sizeof(int));
    sort(ab, ab + n + m);

    bool res = 1;
    int cur_num = 1;
    bool num_used = 0;
    for (int i = 0; i < n + m; i++)
    {
      if (cur_num == k)
      {
        printf("DEBUG (cur_num = k): i: %d, ab[i]: %d, cur_num: %d, k: %d\n", i, ab[i], cur_num, k);
        break;
      }
      else if (ab[i] - cur_num == 0)
      {
        printf("DEBUG (ab[i] - cur_num = 0): i: %d, ab[i]: %d, cur_num: %d, k: %d\n", i, ab[i], cur_num, k);
        num_used = 1;
        continue;
      }
      else if (ab[i] - cur_num == 1 && num_used)
      {
        printf("DEBUG (ab[i] - cur_num = 1): i: %d, ab[i]: %d, cur_num: %d, k: %d\n", i, ab[i], cur_num, k);
        cur_num++;
        num_used = 0;
      }
      else
      {
        res = 0;
        break;
      }
    }

    if (res && cur_num != k)
      res = 0;

    printf(res ? "YES\n" : "NO\n");
  }

  return 0;
}

// 2 2 4 4 6