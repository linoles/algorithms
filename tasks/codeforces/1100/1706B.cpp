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
    int c[n];
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    // Каждый два цвета ai и aj можно выставить в башню, только если |j-i| % 2 == 1
    vector<int> last(n+1, -1), res(n+1, 0);
    for (int i = 0; i < n; i++)
    {
      if (last[c[i]] == -1 || ((i - last[c[i]]) % 2) == 1)
        res[c[i]]++;
      last[c[i]] = i;
    }
    for (int i = 1; i <= n; i++) printf("%d ", res[i]);
    printf("\n\n");
  }
}