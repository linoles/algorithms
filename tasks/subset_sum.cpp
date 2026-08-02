
#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a;

// O(2^n)
bool gen(vector<int> &nums, vector<bool> &used, int sum)
{
  if (sum == x)
    return true;
  if (sum > x)
    return false;

  for (int i = 0; i < n; i++)
    if (!used[i])
    {
      nums.push_back(a[i]);
      used[i] = 1;
      if (gen(nums, used, sum + a[i]))
        return true;
      nums.pop_back();
      used[i] = 0;
    }

  return false;
}

// Задача: узнать, есть ли подмножество с заданной суммой
int main()
{
  scanf("%d %d", &n, &x);
  a.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  vector<bool> used(n, 0);
  vector<int> nums = {};
  bool res = gen(nums, used, 0);

  if (!res)
    printf("NO");
  else
    // Значения передаются по ссылке, чтоб не копировать массив каждый раз, поэтому можно прям тут увидеть результат
    for (int i = 0; i < nums.size(); i++)
      printf((i == nums.size() - 1) ? "%d" : "%d + ", nums[i]);

  return 0;
}