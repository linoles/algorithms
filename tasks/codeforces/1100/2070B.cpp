#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Codeforces 2070B (1100) - Программа робота, O(n * k)
int main()
{
  int t, n, x;
  ll k;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %lld", &n, &x, &k);
    char s[n + 1];
    scanf("%s", s);

    // Сначала считаем, сколько нужно времени, чтоб добраться до 0 первый раз
    // Потом - сколько нужно, чтоб один раз из 0 попасть в 0
    // Затем считаем, сколько можно это сделать раз за k секунд

    int pos = x;
    ll start_time = 0;
    if (x != 0)
      while (start_time < k)
      {
        for (int i = 0; i < n; i++)
        {
          start_time++;
          // Меняем текущую позицию робота
          if (s[i] == 'R')
            pos++;
          else
            pos--;

          // Если робот достиг нуля, выходим
          if (pos == 0)
            break;
        }
        if (pos == 0)
          break;
      }

    // Если робот не достиг нуля, то been_in изначально будет = 0, иначе он уже один раз дошёл до 0
    ll zero_time = 0, been_in = (start_time > k || pos != 0) ? 0 : 1LL;
    while (zero_time + start_time < k)
    {
      for (int i = 0; i < n && zero_time + start_time < k; i++)
      {
        zero_time++;
        // Обновляем позицию
        if (s[i] == 'R')
          pos++;
        else
          pos--;

        if (pos == 0)
          break;
      }
      // Если дошёл до нуля
      if (pos == 0)
      {
        been_in++;
        break;
      }

      // Если время вышло
      if (zero_time + start_time >= k)
        break;
    }

    // Оставшееся время
    ll remain_time = max(0LL, (ll)(k - zero_time - start_time));

    // Исключаем деление на 0
    if (zero_time != 0)
      // Считаем, сколько раз он успеет ещё посетить 0
      // Тут уже целочисленное деление с округлением вниз, как и требуется, но я даже пытался
      // через floor((long double)remain_time / (long double)zero_time), ошибка та же
      been_in += remain_time / zero_time;

    printf("%lld\n\n", been_in);
  }

  return 0;
}

// wrong answer 81st numbers differ - expected: '0', found: '2'
// Я уже не знаю, как это решить, я думал, что просчитал все моменты, но я не понимаю,
// в чём проблемы кода. Я посмотрел hint, там такие же рассуждения

// Ещё я заметил, что это может вызвать TLE