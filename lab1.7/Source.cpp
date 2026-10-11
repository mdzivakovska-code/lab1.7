//Soure.cpp
#include <iostream>
#include<Windows.h>
#include "Cursor.h"

using namespace std;

Cursor makeCursor(LongLong x, LongLong y, string view, int size) {
	Cursor c;
	if (!c.Init(x, y, view, size)) {
		cout << "Помилкові параметри при створені через makeCursor" << endl;
		exit(1);
	}
	return c;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Робота з об'єктом через LongLong" << endl;
	LongLong a = LongLong::fromInt64(100);
	LongLong b = LongLong::fromInt64(30);

	cout << "a =" << a.toString() << ", b =" << b.toString() << endl;
	cout << "a + b = " << a.add(b).toString() << endl;
	cout << "a - b = " << a.sub(b).toString() << endl;
	cout << "a * b = " << a.mul(b).toString() << endl;
	cout << "a / b = " << a.div(b).toString() << endl;

	cout << "Робота з об'єктом через makeCursor" << endl;
	LongLong x0 = LongLong::fromInt64(10);
	LongLong y0 = LongLong::fromInt64(20);
	Cursor cur1 = makeCursor(x0, y0, "horizontal", 5);
	cur1.Display();

	cout << "Зміна розміру на 12 та гасіння" << endl;
	cur1.changeSize(12);
	cur1.hide();
	cur1.Display();

	cout << "Відновлення курсору" << endl;
	cur1.restore();
	cur1.Display();

	cout << "Масив курсорів" << endl;
	Cursor arr[2];
	arr[0].Init(LongLong::fromInt64(5), LongLong::fromInt64(5), "horizontal", 3);
	arr[1].Init(LongLong::fromInt64(50), LongLong::fromInt64(100), "vertical", 10);

	for (int i = 0; i < 2; ++i) {
		cout << "arr[" << i << "]:";
		arr[i].Display();

	}
	cout << "" << endl;
	Cursor userCursor;
	userCursor.Read();
	userCursor.Display();
	return 0;
}