#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка Хоара

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n * log n), память O(log n)

  Тут просто vector<int> func(vector<int>) {}
  Я использую Alloc для тестов /tests/
*/
template <typename T, typename Alloc>
void quick_sort(vector<T, Alloc> &nums, int low, int high)
{
  while (low < high)
  {
    T pivot = nums[low + rand() % (high - low + 1)]; // pivot - вариация со случайным элементом

    int i = low;
    int j = high;

    while (i <= j)
    {
      while (nums[i] < pivot)
        i++;
      while (nums[j] > pivot)
        j--;

      if (i <= j)
      {
        swap(nums[i], nums[j]);
        i++;
        j--;
      }
    }

    // Рекурсия
    if (j - low < high - i)
    {
      quick_sort(nums, low, j);
      low = i;
    }
    else
    {
      quick_sort(nums, i, high);
      high = j;
    }
  }
}

template <typename T, typename Alloc>
vector<T, Alloc> fast_sort(vector<T, Alloc> nums)
{
  quick_sort(nums, 0, nums.size() - 1);
  return nums;
}