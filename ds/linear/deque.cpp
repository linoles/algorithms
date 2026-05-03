#include <deque>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  deque<int> q;
  deque<int> q2(q); // Копирование

  q.push_back(10);  // Вставка в конец: {10}
  q.push_back(20);  // {10, 20}
  q.push_back(30);  // {10, 20, 30}
  q.push_front(40); // Вставка в начало: {40, 10, 20, 30}
  q.push_front(50); // {50, 40, 10, 20, 30}

  printf("Size: %d\n", q.size());        // Размер
  printf("First item: %d\n", q.front()); // Первый элемент
  printf("Third item: %d\n", q[2]);      // Элемент по индексу
  printf("Last item: %d\n", q.back());   // Последний элемент
  printf("Is empty: %d\n\n", q.empty()); // Проверка, пуст ли

  q.pop_back();  // Удаление последнего: {50, 40, 10, 20}
  q.pop_front(); // Удаление первого: {40, 10, 20}

  // Вставка внутрь O(n)
  auto pos = q.begin();
  advance(pos, 1);
  q.insert(pos, 25);

  // Удаление по индексу O(n)
  pos = q.begin();
  advance(pos, 2);
  q.erase(pos);

  // Итераторы (работают как в vector)
  for (auto it = q.begin(); it != q.end(); ++it)
  {
    cout << *it << " ";
  }

  printf("\nIs empty: %d", q.empty()); // Проверка, пуст ли

  return 0;
}