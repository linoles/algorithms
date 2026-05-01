#include <cmath>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*
  ## Сортировка вставкой

  * На вход подаётся массив
  * Возвращается отсортированный массив
  * Скорость O(n²), память O(n)
*/
vector<int> insertion_sort(vector<int> nums) {
  vector<int> res = nums;

  for (int i = 1; i < size(nums); i++) {
    int key = nums[i];
    int j = i - 1;
    while (j >= 0 && res[j] > key) {
      swap(res[j + 1], res[j]);
      --j;
    }
  }
  
  return res;
}

int main() {
  // Проверка работы алгоритма вводом
  int n; // Кол-во чисел в массиве
  scanf("%d", &n);

  vector<int> nums; // Начальный массив
  for (int i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    nums.push_back(temp);
  }

  vector<int> res = insertion_sort(nums);

  // Вывод результата
  for (int num : res) {
    printf("%d ", num);
  }

  return 0;
}