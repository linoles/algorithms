#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 6A (900) - Треугольник, O(1), т.к. размер nums константный - 4 => сортировка будет за O(1)
int main()
{
  int nums[5]; // 0 <= nums[i] <= 100
  scanf("%d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3]);

  sort(nums, nums + 4);
  // Если сумма двух наименьших сторон меньше третьей, тогда треугольник не существует
  if (nums[0] + nums[1] < nums[2] && nums[1] + nums[2] < nums[3] && nums[0] + nums[2] < nums[3])
    printf("IMPOSSIBLE");
  // Если две стороны равны третьей, треугольник - просто отрезок
  else if ((nums[0] + nums[1] == nums[2] || nums[0] + nums[1] < nums[2]) &&
           (nums[1] + nums[2] == nums[3] || nums[1] + nums[2] < nums[3]) &&
           (nums[0] + nums[2] == nums[3] || nums[0] + nums[2] < nums[3]))
    printf("SEGMENT");
  // Иначе простой треугольник
  else
    printf("TRIANGLE");

  return 0;
}