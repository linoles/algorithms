#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

// UVa 11621 - Small Factors, O(k + k * log k), k = log2(m) * log3(2m)
int main()
{
  ll m;
  while (scanf("%lld", &m) && m != 0)
  {
    // Генерируем все возможные значения C, которые меньше удвоенного m
    vector<ll> nums;
    for (int i = 0; i <= ceill(log2l(m)); i++)
      for (int j = 0; powl(2, i) * powl(3, j) <= m * 2; j++)
        nums.push_back(powl(2, i) * powl(3, j));

    sort(nums.begin(), nums.end());

    // Первое встречное число и будет ответом
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] >= m)
      {
        printf("%lld\n", nums[i]);
        break;
      }
  }

  return 0;
}