#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Бинарный поиск

  * На вход подаётся отсортированный массив и заданное число
  * Возвращается индекс или -1, если не найдено
  * Скорость: O(log n), память: O(1)
*/
int binary_search(vector<int> &nums, int query) {
  int l = 0; int r = size(nums) - 1; // Границы расссматриваемого массива

  while (l <= r) {
    int mid = floor((l + r) / 2);
    int guess = nums[mid];
    if (guess == query) {
      return mid;
    } else if (guess > query) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

int main() {
  // Проверка работы алгоритма вводом числа
  int n; // Кол-во чисел в массиве
  scanf("%d\n", &n);

  vector<int> nums; // Отсортированный массив
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d ", &temp);
    nums.push_back(temp);
  }

  int query;
  scanf("%d", &query);

  printf("\nResult: %d", binary_search(nums, query));

  return 0;
}
