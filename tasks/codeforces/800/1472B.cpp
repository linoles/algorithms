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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a.begin(), a.end(), greater<int>());

    // Прибавляем каждый вес к текущему наименьшему
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
      (cnt1 > cnt2) ? cnt2 += a[i] : cnt1 += a[i];

    printf((cnt1 == cnt2) ? "YES\n\n" : "NO\n\n");
  }
}