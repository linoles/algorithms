#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int a1, a2;
  scanf("%d %d", &a1, &a2);

  int ans = 0;
  while (a1 > 0 && a2 > 0 && a1 + a2 >= 3)
  {
    if (a2 > a1)
      swap(a2, a1);
    a2++, a1 -= 2, ans++;
  }

  printf("%d\n", ans);
}