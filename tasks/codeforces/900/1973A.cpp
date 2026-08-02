#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, p1, p2, p3;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d", &p1, &p2, &p3);

    int ans = 0;
    while ((p1 >= 1 && p2 >= 1) || (p2 >= 1 && p3 >= 1) || (p1 >= 1 && p3 >= 1))
    {
      // Сортируем
      if (p2 < p3)
        swap(p2, p3);
      if (p1 < p2)
        swap(p1, p2);
      if (p2 < p3)
        swap(p2, p3);

      p1--;
      p2--;
      ans++;
    }
    
    if ((p1 + p2 + p3) % 2 != 0)
      printf("-1\n\n");
    else
      printf("%d\n\n", ans);
  }
}