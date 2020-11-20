#pragma once
template <typename TData>
class CArray
{
public: // Interface
 // ����������� �� ���������
  CArray();

	// ���������� �����������
  CArray(
    const CArray& _array
  );

	// ����������
  ~CArray();

	// �������� ������� � ����� �������
  void push_back(
    const TData& _value
  );

	// �������� ������� � ������ �� ��������� �������
  void insert(
    unsigned int _index,
    const TData& _value
  );

	// ������� ������� ������� �� ��������� �������
  void erase(
    unsigned int _index
  );

	// �������� ������
  void clear();

	// �������� ������ �������
  unsigned int size() const;

	// �������� ������� ������� �� ��������� �������
  TData& operator[](
    unsigned int _index
  );

  //�������� ������� 
  void swap(
	unsigned int _pos1,
	unsigned int _pos2
  );

  //����� ������� �� �����
  void show();

protected: // Attributes

  TData* theArray;
  unsigned int length;

};


