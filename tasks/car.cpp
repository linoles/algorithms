#include <bits/stdc++.h>
using namespace std;

// f(d, m, v, i) - остаток долга после m месяцев, если каждый месяц платить по d
double f(double d, int m, int v, double i)
{
  double dept = v;
  for (int month = 0; month < m; month++)
    dept = dept * (1 + i) - d;
  return dept;
}

// Задача описана в 3.3 Bisection Method в CP4
int main()
{
  // v - стоимость машины, m - кол-во месяцев для выплаты, i% - банк начисляет
  int m, v, i;
  scanf("%d %d %d", &m, &v, &i);

  // Вычисляем начальные значения границ a и b и предполагаемый ответ d
  double a = 0.01, b = double(1 + i / 100.0) * v, d = (a + b) / 2.0;
  double res = f(d, m, v, i / 100.0);
  while (fabs(res) >= 1e-4)
  {
    if (res > 0)
      a = d;
    else
      b = d;
    d = (a + b) / 2.0;
    res = f(d, m, v, i / 100.0);
  }

  // Ограничиваем до 6 знаков после запятой
  printf("%.6f", d);

  return 0;
}