﻿// G5_Project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CArray.h"
#include "CArray.cpp"

int main()
{
  setlocale(LC_ALL, "Russian");
  //1.1  добавление в цикле 20 случайных чисел в диапазоне от 0 до 100.
  CArray<int> array;
  /*for (size_t i = 0; i < 20; i++)
    array.push_back((rand() % 100));
  array.show();*/
  array.push_back(10);
  array.push_back(2);
  array.push_back(8);
  array.push_back(6);
  array.push_back(5);
  array.push_back(11);
  array.push_back(7);
  array.push_back(3);
  array.push_back(9);
  array.push_back(1);
  array.show();

  //удаление каждого 2 элемента
  for (size_t i = 1; i < 11; i++)
    array.erase(i);
  array.show();

  for (size_t i = 0; i < 10; i++)
    array.insert((rand() % array.size()), (rand() % 100));
  array.show();
  
  array.clear();
  array.show();

  //
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
