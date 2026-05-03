#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  queue<int> q;
  queue<int> q2(q); // Копирование

  q.push(10); // Вставка в начало (enqueue): {10}
  q.push(20); // {20, 10}
  q.push(30); // {30, 20, 10}
  q.push(40); // {40, 30, 20, 10}
  q.push(50); // {50, 40, 30, 20, 10}

  printf("Size: %d\n", q.size());        // Размер
  printf("First item: %d\n", q.front()); // Первый элемент
  printf("Last item: %d\n\n", q.back()); // Последний элемент
  printf("Is empty: %d\n\n", q.empty()); // Проверка, пуст ли

  q.pop(); // Удаление последнего (dequeue): {50, 40, 30, 20}

  // Вывод элементов
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  printf("\nIs empty: %d", q.empty()); // Проверка, пуст ли

  // Нет итераторов, нельзя изменять значения и получать по индексу, а также обращаться к любому элементу кроме последнего

  return 0;
}