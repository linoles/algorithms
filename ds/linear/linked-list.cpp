#include <list>
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
  list<int> l(5, 1);      // {1, 1, 1, 1, 1}
  list<int> l2(l);        // Копирование
  list<int> l3(move(l2)); // Перемещение l2 в l3. l2: {}, l3: {1, 1, 1, 1, 1}

  // Вставка O(1)
  l.push_back(10);
  l.push_front(0);

  // Удаление O(1)
  l.pop_back();
  l.pop_front();

  // Вставка по индексу O(1)
  auto it = l.begin();
  advance(it, 2);    // Перемещение итератора на третий элемент
  l.insert(it, 100); // Вставка

  // Удаление по индексу O(1)
  it = l.begin();
  advance(it, 3);
  l.erase(it);

  // Перебор
  for (int x : l)
  {
    printf("%d ", x);
  }

  // Чтение значения O(n)
  it = l.begin();
  advance(it, 2);
  printf("\n\nFirst item: %d", l.front()); // Первый
  printf("\nThird item: %d", *it);         // По итератору
  printf("\nLast item: %d", l.back());     // Последний

  cout << "\n\nMax size: "
       << l.max_size(); // Максимальный размер ограничен общим количеством памяти, а не выделенной части

  /*
   * Также есть функции sort, reverse, unique, merge, splice, remove и т.д., они почти те же, что у vector
   */

  return 0;
}