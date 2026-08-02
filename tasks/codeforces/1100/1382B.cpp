#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    int k = 0;
    while (k < n && a[k] == 1)
      k++;
    printf((k == n) ^ (k % 2) ? "Second\n" : "First\n");
  }
}