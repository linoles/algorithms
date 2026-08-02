#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
  int t, n;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d", &n);
    char s[n]; int a[n];
    scanf(" %s", &s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    // Будем хранить возрастающую последовательность кол-ва журналов в коробках без крышек
    // Бин. поиском будем вставлять коробки без крышек в правильном порядке
    vector<int> ncov; ll ans = 0;
    for (int i = 0; i < n; i++)
    {
      // Определяем позицию, на которую встанет коробка a[i]. первый ncov[j] > a[i]
      auto it = upper_bound(ncov.begin(), ncov.end(), a[i]);

      if (s[i] == '0')
        ncov.insert(it, a[i]);
      else
      {
        if (ncov.size() == 0 || a[i] >= ncov[ncov.size()-1]) ans += a[i];
        else
        {
          ncov.insert(it, a[i]);
          ans += ncov[ncov.size()-1];
          ncov.pop_back();
        }
      }
    }
    printf("%lld\n\n", ans);
  }
}

// Этот код подошёл бы к задаче 1743C, если бы не было условия "каждая крышка будет перемещена не
// более одного раза". Да, я не умею читать условие