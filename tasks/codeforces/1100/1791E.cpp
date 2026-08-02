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
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) if (a[i] <= 0) cnt++;

    ll sum = 0;
    if (cnt % 2 == 0) for (int i = 0; i < n; i++) sum += abs(a[i]);
    else
    {
      sort(a, a + n);
      int i = 0;
      while (cnt > 1)
      {
        sum += -a[i];
        cnt--; i++;
      }
      if (i < n-1 && abs(a[i]) > a[i+1])
      {
        sum += -a[i] - a[i+1];
        i += 2;
      }
      for (; i < n; i++) sum += a[i];
    }
    printf("%lld\n\n", sum);
  }
}

// Для любой тройки (a[i-1],a[i],a[i+1]):
// 1. Если 1 элемент отрицательный, то отрицательным делаем наименьший по модулю
// 2. Если только 2 отрицательных, то все три станут положительными
// 3. Если отрицательные все 3, то отрицательным делаем наименьший по модулю