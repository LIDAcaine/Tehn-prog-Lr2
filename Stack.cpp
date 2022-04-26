#include "Stack.h"
#include <iostream>
#include <locale>

using namespace std;

Stack::Stack() //конструктор без параметров 
{
	top = 0;
	size = 0;
} 
Stack::Stack(int size_st) //конструктор с параметром
{
	top = 0;
	this->size = size_st; //вызванному объекту устанавливаем размер
}
Stack::~Stack() //деструктор
{
	if ((top == 0) || (size == 0))
	{
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
	else
	{
		while (top->next != 0) //пока не дойдем до нулевого указателя
		{
			Unit* temp = top; //временная переменная юнита, присваиваем ей значение вершины
			top = temp->next; //теперь вершина указывает на следующий за ней элемент,
			delete temp; //а временную - удаляеям
		}
		delete top; //удаляем вершину
		size = 0; //размер нулевой
	}
}
Stack::Stack(const Stack& Stack_copy) : size(Stack_copy.size) //копирование
{
	int* buff = new int[Stack_copy.size]; //вводим буферный массив, в котором будем хранить наши числа нового стека
	Unit* el_stack = Stack_copy.top; //новая переменная-вершина будущего стека

	for (int i = 0; i <= Stack_copy.size - 1; i++)
	{	//пока счетчик не дойдет до конца стека
		buff[i] = el_stack->data; //заносим в массив значения из стека
		el_stack = el_stack->next; //ставим указатель на следующий элемент стека
	}

	for (int i = 0; i < Stack_copy.size; i++)
		this->push(buff[i]); //вносим в новый стек значения из массива

	delete[] buff; //удаляем буфер
}

void Stack::push(int value)
{
	Unit* new_unit = new Unit; //инициализируем новый юнит стека и выделяем под него память
	new_unit->next = top; //теперь новый юнит стал вершиной
	top = new_unit; //и вершина указывает на новый юнит
	top->data = value; //вносим значение в вершину
	size++;
}
int Stack::pop()
{
	setlocale(LC_ALL, "Rus");

	if (!this)
	{
		cout << "Стек пуст, удалять нечего." << endl;
	}

	Unit* temp = top; //временная переменная-вершина 
	int deldata = 0; //место под удаленный элемент

	deldata = top->data; //присваиваем значение удаляемого элемента
	top = top->next; //вершина теперь тот юнит, который был под вершиной
	delete temp; //удаляем переменную-вершину
	size--;
	return deldata; //вернули удаленный элемент
}
void Stack::print()
{
	if (size == 0)
	{
		cout << "Стек пуст, выводить нечего." << endl;
	}
	else
	{
		Unit* temp = top;
		while (temp->next != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << temp->data << endl;
	}
}

Unit* Stack::get_top()
{
	return top;
}
int Stack::get_size() const
{
	return size;
}
void Stack::set_size(int& value)
{
	size = value;
}

void operator+ (int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(a+buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
}
void operator+ (Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i]+a); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
}
void operator += (int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}

	delete[] buff;
}
void operator += (Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}

	delete[] buff;
}
void operator -(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] - a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator -(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] - a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator -=(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
void operator -=(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
void operator *(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] * a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator *(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] * a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator *=(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
void operator *=(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
void operator /(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] / a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator /(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		St.push(buff[i] / a); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	delete[] buff;
}
void operator /=(int a, Stack& St)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
void operator /=(Stack& St, int a)
{
	int len = St.size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = St.pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		St.push(buff[i]); //в обратном порядке (как было до преобразования) заносим новые значения в стек
	}
	delete[] buff;
}
/*Stack& Stack::operator+(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
		this->push(buff[i] + a); //в обратном порядке (как было до преобразования) заносим новые значения в стек

	delete[] buff;
	return *this;
}
Stack& Stack::operator+=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] += a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator-(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] - a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator-=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] -= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator*(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] * a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator*=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] *= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator/(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		this->push(buff[i] / a);
	}
	delete[] buff;
	return *this;
}
Stack& Stack::operator/=(int a)
{
	Unit* tmp = top;
	int min = tmp->data;
	int len = this->size; //переменная размера вызванного объекта
	int* buff = new int[len]; //буферный массив, куда занесем значения стека
	for (int i = 0; i < len; i++)
		buff[i] = this->pop(); //вносим в массив значения стека, стек на время становится пустым
	for (int i = len - 1; i >= 0; i--)
	{
		buff[i] /= a;
		this->push(buff[i]);
	}
	delete[] buff;
	return *this;
}*/