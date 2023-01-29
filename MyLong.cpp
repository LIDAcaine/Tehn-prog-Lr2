#include "MyLong.h"

myLong::myLong(long a) //êîíñòðóêòîð ñ ïàðàìåòðîì
{
	value = new long(a);
}
myLong::myLong() //êîíñòðóêòîð áåç ïàðàìåòðà 
{
	value = new long(0);
}
myLong::myLong(const myLong& _long) //êîïèðîâàíèå
{
	value = new long(*_long.value);
}
myLong::~myLong() //äåñòðóêòîð
{
	delete value;
}

myLong& myLong::operator --()
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "Ââåäèòå çíà÷åíèå çíà÷åíèå äëÿ ïðåôèêñíîãî âû÷èòàíèÿ: ";
	cin >> a;
	*value -= a;
	return *this;
}
myLong& myLong::operator --(int)
{
	--* value;
	return *this;
}
long myLong::operator !() const
{
	return -*value;
}
myLong& operator ++(myLong& op)
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "Ââåäèòå çíà÷åíèå äëÿ ïðåôèêñíîãî ïðèáàâëåíèÿ: ";
	cin >> a;
	*op.value += a;
	return op;
}
myLong& operator ++(myLong& op, int)
{
	long a;
	setlocale(LC_ALL, "Rus");
	cout << "Ââåäèòå èçíà÷àëüíîå çíà÷åíèå: ";
	cin >> a;
	*op.value = a;
	++* op.value;
	return op;
}
ostream& operator <<(ostream& stream, myLong& a)
{
	 int i = 0;
    	while (true){
       	 i++;
        	cout << i;
    	}
	stream << *a.value;
	return stream;
}
