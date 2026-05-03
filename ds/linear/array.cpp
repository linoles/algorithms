#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int arr[5];

  // Перебор элементов массива (любого)
  for (int x : arr)
  {
    printf("%d ", x);
  }

  // Доступ по индексу
  printf("\nFirst item: %d", arr[0]);

  // Изменение элемента
  arr[2] = 5;
  arr[4] = -1;

  // Динамический массив
  vector<int> nums = {1, 3, 5, 8, 10};

  // Добавление элементов
  nums.push_back(15);           // в конец
  nums.insert(nums.begin(), 0); // в начало

  // Чтение и изменение также
  printf("\nFirst item: %d", nums.at(0));
  nums[2] = 5;
  nums[4] = -1;
  swap(nums[1], nums[3]); // Свап элементов местами
  // nums.assign(0); // Заменяет всё на нули
  // printf("\nItem: %d", nums[11]); // Может вернуть мусор из кеша или Assertion '__n < this->size()' failed.
  // printf("\nItem: %d", nums.at(11)); // Возвращает out_of_range, но медленнее

  // Удаление элементов
  nums.pop_back(); // Последний
  // nums.clear(); // Всё
  // nums.erase(nums.begin() + 3); // 3 - Индекс

  // Работа с памятью
  printf("\n\nCapacity: %d, size: %d", nums.capacity(), nums.size());
  nums.reserve(100);
  printf("\nCapacity: %d, size: %d", nums.capacity(), nums.size());
  nums.resize(10, 0);
  printf("\nCapacity: %d, size: %d", nums.capacity(), nums.size());
  /*
    vector::capacity - кол-во памяти, выделенное на массива. Удваивается при перемещении массива от нехватки места
    vector::size - используемое кол-во памяти
    vector::reserve - изменяет выделенное кол-во памяти, чтобы в будущем не тратить O(n) на перемещение массива в другое место
    vector::resize - изменить размер, добавив n чисел равных k, n - первый аттрибут, k - второй
  */

  // Итераторы
  auto start_it = nums.begin(); // Первый элемент
  auto end_it = nums.end();     // Указывает на пустоту - элемент после последнего. Используется также для проверки вхождения в массив - nums.find(num) == nums.end(), значит число не найдено
  /*
    vector::rbegin - последний элемент
    vector::rend - элемент до первого, также пустота
  */

  start_it++; // Переместить на следующий элемент
  end_it--;   // Предыдущий
  printf("\n\nSecond num: %d", *start_it);
  printf("\nPrelast num: %d", *(end_it - 1));

  // Сравнение массивов
  vector<int> a = {1, 2, 3};
  vector<int> b = {1, 2, 3};
  vector<int> c = {1, 2, 4};
  vector<int> d = {1, 2, 3, 4};

  cout << (a == b); // true
  cout << (a != b); // false
  cout << (a != c); // true

  cout << (a < c);           // true (Сравнивает последовательно каждый элемент, 3 < 4 => a < c)
  cout << (a > d) << "\n\n"; // false

  // Сортировка из C++ STL
  sort(nums.begin(), nums.end(), [](const int a, const int b)
       {
         return b > a; // a > b - в убывающем
       });

  for (int x : nums)
  {
    printf("%d ", x);
  }

  return 0;
}