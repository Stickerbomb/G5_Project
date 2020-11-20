#include <iostream>
#include "CArray.h"
#include "CArray.cpp"
#include <string.h>

//Генерация случайного слова с заданной максимальной длинной
std::string generate_randome_word(
  unsigned int _max_length
) 
{
  int size = (rand() % (_max_length-1)) + 1;
  std::string word = "";
  char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z' };
   
  for (size_t i = 0; i < size; i++)
    word += letters[rand() % 26];
  return word;
}

int main()
{
  setlocale(LC_ALL, "Russian");
  //1.1  добавление в цикле 20 случайных чисел в диапазоне от 0 до 100.
  CArray<int> i_array;
  for (size_t i = 0; i < 20; i++)
    i_array.push_back((rand() % 100));
  std::cout << "Первоначальный массив: " << std::endl;
  i_array.show();

  //1.2. упорядочивание получившегося набора чисел по возрастанию.
  for(size_t j = 0; j < i_array.size()-1; j++)
    for (size_t i = 0; i < i_array.size()-1-j; i++)
      if (i_array[i] > i_array[i + 1])
        i_array.swap(i, i + 1);
  std::cout << "Упорядоченный массив: " << std::endl;
  i_array.show();

  //1.3 удаление каждого 2 элемента
  for (size_t i = 1; i < 11; i++)
    i_array.erase(i);
  std::cout << "Массив после удаления каждых вотрых элементов: " << std::endl;
  i_array.show();

  //1.4 вставка 10 случайных чисел в диапазоне от 0 до 100 на случайные позиции
  for (size_t i = 0; i < 10; i++)
    i_array.insert((rand() % i_array.size()), (rand() % 100));
  std::cout << "Массив после добавления 10 случайных чисел: " << std::endl;
  i_array.show();
  
  //1.5. очистка контейнера
  i_array.clear();
  i_array.show();



  //2. Работа с объектами (std:string).
  std::cout << std::endl << "Работа с объектами (std:string)" << std::endl;
  CArray<std::string> s_array;

  //2.1.добавление в цикле 15 случайно выбранных слов, состоящих из латинских букв в нижнем регистре.
  for (size_t i = 0; i < 15; i++)
    s_array.push_back(generate_randome_word(10));
  std::cout << "Массив случайных слов: " << std::endl;
  s_array.show();

  //2.2.упорядочивание получившегося набора слов по возрастанию.
  for (size_t j = 0; j < s_array.size() - 1; j++)
    for (size_t i = 0; i < s_array.size() - 1 - j; i++)
      if (s_array[i].length() > s_array[i + 1].length())
        s_array.swap(i, i + 1);
  std::cout << "Упорядоченный массив: " << std::endl;
  s_array.show();

  //2.3.удаление каждого слова, включающего в себя любую из букв a, b, c, d, e.
  CArray<int> index_that_delete;
  for (size_t i = 0; i < s_array.size(); i++)
    for (size_t j = 0; j < s_array[i].length(); j++) 
      if(s_array[i][j]>96 && s_array[i][j]<102)
        index_that_delete.push_back(i);

  for (int i = index_that_delete.size()-1; i >= 0; i--)
      s_array.erase(index_that_delete[i]);
  std::cout << "Массив после удаления строу с буквами (a, b, c, d, e): " << std::endl;
  s_array.show();
  
  //2.4.вставка 3 новых случайно выбранных слов на случайные позиции.
  for (size_t i = 0; i < 3; i++)
      s_array.insert((rand() % s_array.size()), generate_randome_word(10));
  std::cout << "Массив после добавления 3 случайных слов: " << std::endl;
  s_array.show();
}