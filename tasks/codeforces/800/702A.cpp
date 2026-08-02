#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, a, len = 0, max_len = 0, prev = INT_MIN;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a);

    (a > prev) ? len++ : len = 1;
    max_len = max(max_len, len);
    prev = a;
  }

  printf("%d", max_len);
}