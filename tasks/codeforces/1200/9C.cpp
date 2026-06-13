#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int to_binary(int x)
{
  int res = 0;
  int r = 0;
  while (x > 0)
  {
    res += x % 2 * pow(10, r);
    x = x / 2;
    r++;
  }
  return res;
}

// Codeforces 9C (1200) - Числа Хексадесимал, O(n * log10 n)
int main()
{
  int n;
  scanf("%d", &n);

  // Пусть r - число разрядов, тогда кол-во таких чисел будет
  // r = 1: 1
  // r = 2: a1 + 2
  // r = 3: a2 + 4
  // r = 4: a3 + 8
  // То есть a[r - 1] + 2^r / 2, т.к. все комбинации с ведущими нулями не подходят

  // Можно посчитать a[r - 1] - они точно будут все, а затем посчитать, сколько Хексадесимал
  // примет с кол-вом разрядов = r

  string n_str = to_string(n);
  int r = n_str.size();

  int ans = 0;
  for (int i = 1; i <= r - 1; i++)
  {
    if (i == 1)
      ans += 1;
    else
      ans += (1<<i) / 2;
  }

  // От 100...0 до 111...1
  for (int mask = 1<<(r - 1); mask <= (1<<r) - 1; mask++)
  {
    int num = to_binary(mask);
    if (num > n) break;
    ans++;
  }

  printf("%d", ans);

  return 0;
}