#include <iostream>
#include <conio.h>
#include "Stack.h"
#include "MyLong.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int v=1;
	int stack_size = 0, value = 0; //переменные размера стека и вводимых данных
	int flag = 1, c;
	int b;
	Stack st;
	myLong a;
	while (v != 0)
	{
		int v;
		cout << "1 - Унарные операции\n2 - Бинарные операции\n0 - Выйти из программы\nВы выбрали: ";
		cin >> v;
		switch (v)
		{

		case 1:
			system("cls");
			cout << "Задание №1 - Унарные операции" << endl;
			cout << "Операция a++\t" << a++ << endl;
			cout << "Операция ++a\t" << ++a << endl;
			cout << "Операция a--\t" << a-- << endl;
			cout << "Операция --a\t" << --a << endl;
			cout << "Операция  !a\t" << !a << endl;
			break;
		case 2:
			system("cls");
			cout << "Задание №2 - Бинарные операции (стек)\nВведите размер стека: ";
			cin >> stack_size;
			system("cls");
			cout << "Заполните стек: " << endl;
			for (int i = 0; i < stack_size; i++)
			{
				cin >> value;
				st.push(value);
			}
			system("cls");
			while (flag == 1)
			{
				cout << "Операции над стеком:" << endl;
				cout << "1 - Добавление элемента" << endl;
				cout << "2 - Удаление элемента" << endl;
				cout << "3 - Вывод стека на экран" << endl;
				cout << "4 - Сложение '+'" << endl;
				cout << "5 - Сложение-назначение '+='" << endl;
				cout << "6 - Вычитание '-'" << endl;
				cout << "7 - Вычитание-назначение '-='" << endl;
				cout << "8 - Умножение '*'" << endl;
				cout << "9 - Умножение-назначение '*='" << endl;
				cout << "10 - Деление '/'" << endl;
				cout << "11 - Деление-назначение'/='" << endl;
				cout << "0 - Вернуться в меню" << endl;
				cout << "Вы выбрали - ";
				cin >> c;

				switch (c)
				{
				case 1: //добавление
					system("cls");
					cout << "Введите новый элемент: " << endl;
					cin >> value;
					st.push(value);
					cout << "Элемент добавлен в стек\n " << endl;
					break;
				case 2: //удаление
					system("cls");
					value = st.pop();
					cout << "Извлечённый элемент: " << value << endl;
					break;
				case 3: //вывод на консоль
					system("cls");
					st.print();
					cout << "\n";
					break;
				case 4: //операция сложение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st + b;
					st.print();
					break;
				case 5: //операция сложение/назначение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st += b;;
					st.print();
					break;
				case 6: //операция вычитание
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st - b;
					st.print();
					break;
				case 7: //операция вычитание/назначение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st -= b;
					st.print();
					break;
				case 8: //операция умножение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st* b;
					st.print();
					break;
				case 9: //операция умножение/назначение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st *= b;
					st.print();
					break;
				case 10: //операция деление
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st / b;
					st.print();
					break;
				case 11: //операция деление/назначение
					system("cls");
					cout << "Введите число: " << endl;
					cin >> b;
					cout << "Исходный стек: ";
					st.print();
					cout << "Преобразованный стек: ";
					st /= b;
					st.print();
					break;
				case 0: //Выход из задания 2
					system("cls");
					flag = 0;
					break;
				default:
					cout << "\n";
					flag = 0;
					break;
				}
			}
			break;
		case 0:
			system("cls");
			cout << "Завершение работы" << endl;
			return 0;			
		}
	}
}