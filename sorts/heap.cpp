#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Функция восстановления кучи в сортирующее дерево
template <typename T, typename Alloc>
void heapify(vector<T, Alloc> &nums, int n, int i)
{
  while (true)
  {
    int largest = i;       // Самый большой элемент
    int left = i * 2 + 1;  // Левый дочерний
    int right = i * 2 + 2; // Правый дочерний

    // Левый дочерний больше наибольшего
    if (left < n && nums[left] > nums[largest])
      largest = left;

    // Правый дочерний больше наибольшего
    if (right < n && nums[right] > nums[largest])
      largest = right;

    if (largest == i)
      break;

    // Самый больший не корень - случились перестановки, свапаем
    swap(nums[largest], nums[i]);
    i = largest;
  }
}

/*
  ## Сортировка кучей

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n * log n) всегда, память O(1)

  Тут просто vector<int> func(vector<int>) {}
  Я использую Alloc для тестов /tests/
*/
template <typename T, typename Alloc>
vector<T, Alloc> heap_sort(vector<T, Alloc> nums)
{
  int n = size(nums);

  // Строим Max-Heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    heapify(nums, n, i);
  }

  // Извлекаем элементы
  for (int i = n - 1; i > 0; i--)
  {
    swap(nums[0], nums[i]); // Максимум в конец
    heapify(nums, i, 0);
  }

  return nums;
}