#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Alloc>
int find_smallest(vector<T, Alloc> &nums)
{
  int smallest = nums[0];
  int smallest_ind = 0;

  for (int i = 0; i < size(nums); ++i)
  {
    if (nums[i] < smallest)
    {
      smallest = nums[i];
      smallest_ind = i;
    }
  }

  return smallest_ind;
}

/*
  ## Сортировка выбором

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(1)

  Тут просто vector<int> func(vector<int>) {}
  Я использую Alloc для тестов /tests/
*/
template <typename T, typename Alloc>
vector<T, Alloc> selection_sort(vector<T, Alloc> nums)
{
  vector<T, Alloc> res;
  int nums_size = size(nums);

  for (int i = 0; i < nums_size; ++i)
  {
    int smallest_ind = find_smallest(nums);
    res.push_back(nums[smallest_ind]);
    nums.erase(nums.begin() + smallest_ind);
  }

  return res;
}