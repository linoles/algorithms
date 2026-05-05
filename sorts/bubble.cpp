#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка пузырьком

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(1)

  Тут просто vector<int> func(vector<int>) {}
  Я использую Alloc для тестов /tests/
*/
template <typename T, typename Alloc>
vector<T, Alloc> bubble_sort(vector<T, Alloc> nums)
{
  for (int i = 0; i < size(nums); i++)
  {
    for (int j = 1; j < size(nums) - i; j++)
    {
      if (nums[j - 1] > nums[j])
      {
        swap(nums[j - 1], nums[j]);
      }
    }
  }

  return nums;
}