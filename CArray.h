#pragma once
template <typename TData>
class CArray
{
public: // Interface
 // Конструктор по умолчанию
	CArray();

	// Копирующий конструктор
	CArray(
		const CArray& _array
	);

	// Деструктор
	~CArray();

	// Добавить элемент в конец массива
	void push_back(
		const TData& _value
	);

	// Добавить элемент в массив по заданному индексу
	void insert(
		unsigned int _index,
		const TData& _value
	);

	// Удалить элемент массива по заданному индексу
	void erase(
		unsigned int _index
	);

	// Очистить массив
	void clear();

	// Получить размер массива
	unsigned int size() const;

	// Получить элемент массива по заданному индексу
	TData& operator[](
		unsigned int _index
		);

protected: // Attributes
	...
};
