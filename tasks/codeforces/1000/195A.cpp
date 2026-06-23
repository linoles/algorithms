#include <bits/stdc++.h>
using namespace std;

// Codeforces 195A - Посмотрим футбол, O(a / b * c²)
int main()
{
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  // Нужно подобрать такое t секунд (время ожидания перед началом просмотра), чтобы
  // за это время успело прогрузиться столько данных, чтобы потом при фоновой загрузке b данных в секунду
  // не пришлось ждать ещё

  // Подбираем ответ
  int t = 1;
  for (;; t++)
  {
    bool ok = 1;
    // Симулируем процесс просмотра видео
    int resources = t * b;
    for (int i = 0; i < c && ok; i++)
    {
      resources -= a - b;
      if (resources < 0)
        ok = 0;
    }

    if (ok)
      break;
  }

  printf("%d", t);

  return 0;
}