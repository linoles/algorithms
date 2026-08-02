#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int ans = 0;
  vector<int> res(a.begin(), a.end());
  for (int i = 1; i < n; i++)
  {
    ans += max(k - (res[i - 1] + a[i]), 0);
    res[i] += max(k - (res[i - 1] + a[i]), 0);
  }

  printf("%d\n", ans);
  for (int i = 0; i < n; i++)
    printf("%d ", res[i]);
}