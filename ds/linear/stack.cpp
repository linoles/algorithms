#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main()
{
  stack<int> st;
  stack<int> st2(st); // Копирование

  st.push(10); // Вставка
  st.push(20);
  st.push(30);
  st.push(40);
  st.push(50);

  st.pop(); // Удаление

  printf("Last item: %d\n", st.top());    // Верхний элемент
  printf("Size: %d\n", st.size());        // Размер
  printf("Is empty: %d\n\n", st.empty()); // Проверка, пуст ли

  // Вывод элементов
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }

  printf("\nIs empty: %d", st.empty()); // Проверка, пуст ли

  // Нет итераторов, нельзя изменять значения и получать по индексу, а также обращаться к любому элементу кроме последнего

  return 0;
}