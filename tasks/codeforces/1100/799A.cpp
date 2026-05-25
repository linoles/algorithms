#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Codeforces 799A (1100) - Морковные торты, O(?)
int main()
{
  int n, t, k, d;
  scanf("%d %d %d %d", &n, &t, &k, &d);

  // k тортов за t мин. Нужно n тортов. Можно построить печь за d мин
  // Изначально Аркадий пусть выпекает k тортов и параллельно строит печь, это лучший способ
  int without_second = ceil((float)n / (float)k) * t; // 1164

  // spent_time - текущее кол-во потраченного времени
  // cooked - кол-во приготовленных тортов
  // last_start_first - начало приготовления последнего торта в первой духовке;
  // last_start_sec - во второй
  int cooked = 0, last_start_first = 0, last_start_sec = -1, spent_time = 0;
  bool second_built = 0; // построена ли вторая печь
  while (cooked < n)
  {
    // Если торт в первой печи приготовился
    if (spent_time - last_start_first >= t)
    {
      cooked += k;
      last_start_first = spent_time;
    }

    // Если торт во второй печи приготовился
    if (second_built && spent_time - last_start_sec >= t)
    {
      cooked += k;
      last_start_sec = spent_time;
    }

    // Если закончилось построение первой печи
    else if (!second_built && spent_time >= d)
    {
      second_built = 1;
      last_start_sec = spent_time;
    }

    if (cooked < n)
      spent_time++;
  }

  printf((without_second <= spent_time) ? "NO" : "YES");

  return 0;
}

// Скорее всего тут есть какая-то простенькая формула для нахождения времени приготовления
// пирогов при построении второй печи, но я не смог её вывести, хотя изначально пытался