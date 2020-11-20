#include "CArray.h"
#include <iostream>

// Конструктор по умолчанию
template<typename TData>
inline CArray<TData>::CArray()
{
  theArray = nullptr;
  length = 0;
}

// Копирующий конструктор 
//Peredelat
template<typename TData>
CArray<TData>::CArray(
	const CArray& _array
  )
{
  if(_array[0]){
    TData* temp = new TData[length];
    for (size_t i = 0; i < length; i++)
      temp[i] = _array[i];
    theArray = temp;
  }
  else
  {
    theArray = nullptr;
    size = 0;
  }
}

// Деструктор
template<typename TData>
CArray<TData>::~CArray()
{
  delete[] theArray;
}

// Добавить элемент в конец массива
template<typename TData>
void CArray<TData>::push_back(
	const TData& _value
  )
{
  if(theArray)
  {
    TData *temp = new TData[length + 1];
    for (size_t i = 0; i < length; i++)
      temp[i] = theArray[i];
    temp[length] = _value;

    delete[] theArray;
    theArray = temp;
    length++;
  }
  else
  {
    theArray = new TData[1];
    theArray[0] = _value;
    length++;
  }
}

// Добавить элемент в массив по заданному индексу
template<typename TData>
void CArray<TData>::insert(
    unsigned int _index, 
    const TData& _value
  )
{
  if (_index <= length)
  {
    length++;
    TData* temp = new TData[length];

    for (size_t i = 0; i < _index; i++)
      temp[i] = theArray[i];

    temp[_index] = _value;

    for (size_t i = _index + 1; i < length; i++)
      temp[i] = theArray[i - 1];

	delete theArray;
    theArray = temp;
  }
}

// Удалить элемент массива по заданному индексу
template<typename TData>
void CArray<TData>::erase(
    unsigned int _index
  )
{
  if (_index <= length && theArray)
  {

    TData* temp = new TData[length - 1];

    for (size_t i = 0; i < _index; i++)
      temp[i] = theArray[i];

    for (size_t i = _index + 1; i < length; i++)
      temp[i - 1] = theArray[i];

    length--;
    delete theArray;
    theArray = temp;
    }
}

// Очистить массив
template<typename TData>
void CArray<TData>::clear()
{
    delete[] theArray;
    theArray = nullptr;
    length = 0;
}

// Получить размер массива
template<typename TData>
unsigned int CArray<TData>::size() const
{
	return length;
}

// Получить элемент массива по заданному индексу
template<typename TData>
TData& CArray<TData>::operator[](unsigned int _index)
{
  if(_index<=length)
    return theArray[_index];// TODO: вставьте здесь оператор return
  if(!theArray)
    std::cout << "Массив пуст";
  return 0;
}

template<typename TData>
void CArray<TData>::show()
{
  if (theArray)
  {
    std::cout << "( ";
    for (size_t i = 0; i < length-1; i++)
      std::cout << theArray[i] << " | ";

    std::cout << theArray[length-1] << " )" << std::endl;
  }
  else 
  {
    std::cout << "Массив пуст";
    return;
  }
  
}
