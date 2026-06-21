#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t, c = 0;
  scanf("%d", &t);
  while (t--)
  {
    int n, s;
    scanf("%d %d", &n, &s);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &p[i]);

    sort(p.begin(), p.end());

    // dp[sum] = минимальное количество стрел
    vector<int> dp(s + 1, INT_MAX);
    dp[0] = 0;

    // prev[sum] = последнее использованное значение (для восстановления)
    vector<int> prev(s + 1, -1);

    // Сначала находим минимальное количество стрел
    for (int sum = 1; sum <= s; sum++)
      for (int i = 0; i < n; i++)
        if (sum >= p[i] && dp[sum - p[i]] != INT_MAX)
          if (dp[sum - p[i]] + 1 < dp[sum])
          {
            dp[sum] = dp[sum - p[i]] + 1;
            prev[sum] = p[i];
          }

    if (dp[s] == INT_MAX)
      printf("Case %d: impossible", ++c);
    else
    {
      // Теперь восстанавливаем лексикографически максимальный ответ
      // с минимальным количеством стрел
      vector<int> ans;
      int cur = s;
      int arrows_left = dp[s];

      while (cur > 0)
        // Пробуем взять максимально возможное значение
        for (int i = n - 1; i >= 0; i--)
          if (cur >= p[i] && dp[cur - p[i]] == arrows_left - 1)
          {
            ans.push_back(p[i]);
            cur -= p[i];
            arrows_left--;
            break;
          }

      // ans уже в порядке добавления (от больших к меньшим)
      printf("Case %d: [%d]", ++c, dp[s]);
      for (int x : ans)
        printf(" %d", x);
    }

    if (t > 0)
      printf("\n");
  }
  return 0;
}

// (Это неправильно). Я пробовал и Recursive Backtracking, но он получает TLE, если сохранять все ответы, а затем
// отсортировать и вывести подходящие, иначе если выводить только первый, тогда Wrong Answer, т.к. хотя он и выведет
// первый по первым элементам, но не самое минимальное кол-во выстрелов. Тут же через дп получается Wrong Answer
// Я пробовал разные варианты, но все мои тесты проходят проверку, что у них там за тест, я не представляю