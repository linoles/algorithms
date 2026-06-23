#include <bits/stdc++.h>
using namespace std;

// Codeforces 1996A - Ноги, O(1)
int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    // Макс. кол-во коров + кол-во возможных оставшихся куриц
    printf("%d\n", n / 4 + n % 4 / 2);
  }

  return 0;
}