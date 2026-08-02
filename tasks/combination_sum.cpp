
#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a;

// O(n^(x / min(a)))
void gen(vector<int> &nums, int sum, int last_ind)
{
  if (sum == x)
  {
    for (int i : nums)
      printf("%d ", i);
    printf("\n");
    return;
  }

  if (sum >= x) return;

  for (int i = last_ind; i < n; i++)
  {
    nums.push_back(a[i]);
    gen(nums, sum + a[i], i);
    nums.pop_back();
  }
}

// Задача: вывести все наборы чисел, сумма которых равна x, но числа можно
// использовать только из данного массива a
int main()
{
  scanf("%d %d", &n, &x);
  a.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  vector<int> temp = {};
  gen(temp, 0, 0);

  return 0;
}