
#include <bits/stdc++.h>
using namespace std;

// Codeforces 463B (1100) - Caisa и колонны, O(n)
int main()
{
  int n;
  scanf("%d", &n);
  int h[n + 2];
  h[0] = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &h[i + 1]);

  // Проходимся по колонне, считаем текущие характеристики:
  // потраченные деньги и текущая энергия
  int money = 0;
  int energy = 0;
  for (int i = 0; i < n; i++) {
    // меняем энергию
    energy += h[i] - h[i + 1];
    // Если энергии не хватает, докупаем
    if (energy < 0) {
      money -= energy;
      energy = 0;
    }
  }

  printf("%d", money);

  return 0;
}