#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка подсчётом

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n + k), память O(n)
*/
vector<int> counting_sort(vector<int> nums) {
  if (size(nums) <= 1) return nums;

  // Узнаём максимум и минимум
  int max = nums[0];
  int min = nums[0];
  for (int x : nums) {
    if (x > max) max = x;
    if (x < min) min = x;
  }
  int range = max - min + 1; // Размах массива

  vector<int> counts(range, 0); // Массив вхождений
  vector<int> res(size(nums));

  // Заполнение массива вхождений
  for (int x : nums) {
    counts[x - min]++;
  }

  // Окончательное заполнение
  for (int i = 1; i < range; i++) {
    counts[i] += counts[i - 1];
  }

  // Восстановление массива
  for (int i = size(nums) - 1; i >= 0; --i) {
    res[counts[nums[i] - min] - 1] = nums[i];
    counts[nums[i] - min]--;
  }

  return res;
}

int main()
{
  // Проверка работы алгоритма вводом
  int n; // Кол-во чисел в массиве
  scanf("%d", &n);

  vector<int> nums; // Начальный массив
  for (int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  vector<int> res = counting_sort(nums);

  // Вывод результата
  for (int num : res)
  {
    printf("%d ", num);
  }

  return 0;
}