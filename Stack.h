typedef struct Unit
{
	int data;
	Unit* next;
} Unit; //элемент стека

class Stack
{
private:
	Unit* top = 0; //указатель на начальный элемент стека - инициализированный элемент
	int size = 0; //размер стека
public:
	Stack(); //конструктор без параметров
	explicit Stack(int size_st); //конструктор с параметрами
	~Stack(); //деструктор
	Stack(const Stack& Stack_copy); //конструктор копирования

	void push(int value); //добавление элемента в стек
	int pop(); //извлечение вершины
	void print(); //вывод стека на экран

	Unit* get_top(); //взять элемент стека
	void set_size(int& value); //поместить значение в стек
	int get_size() const; //взять размер стека 

	friend void operator+ (int, Stack& St);
	friend void operator+ (Stack& St, int);
	friend void operator+= (int, Stack & St);
	friend void operator+= (Stack& St, int);
	friend void operator-(int, Stack& St);
	friend void operator- (Stack& St, int);
	friend void operator-=(int, Stack& St); 
	friend void operator-= (Stack& St, int);
	friend void operator*(int, Stack& St); 
	friend void operator* (Stack& St, int);
	friend void operator*=(int, Stack& St); 
	friend void operator*= (Stack& St, int);
	friend void operator/(int, Stack& St); 
	friend void operator/ (Stack& St, int);
	friend void operator/=(int, Stack& St);
	friend void operator/= (Stack& St, int);
	/*Stack& operator+(int);
	Stack& operator+=(int);
	Stack& operator-(int);
	Stack& operator-=(int);
	Stack& operator*(int);
	Stack& operator*=(int);
	Stack& operator/(int);
	Stack& operator/=(int);*/
};
