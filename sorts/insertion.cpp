#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка вставкой

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(1)

  Тут просто vector<int> func(vector<int>) {}
  Я использую Alloc для тестов /tests/
*/
template <typename T, typename Alloc>
vector<T, Alloc> insertion_sort(vector<T, Alloc> nums)
{
  vector<T, Alloc> res = nums;

  for (int i = 1; i < size(nums); i++)
  {
    int key = nums[i];
    int j = i - 1;
    while (j >= 0 && res[j] > key)
    {
      swap(res[j + 1], res[j]);
      --j;
    }
  }

  return res;
}