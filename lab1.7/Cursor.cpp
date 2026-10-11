//Cursor.cpp
#include "Cursor.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Cursor::setX(const LongLong& newX) {
	if (newX.toInt64() >= 0) {
		x = newX;
		return true;
	}
	cerr << "координата X не може бути від'ємною!" << endl;
	return false;
}
bool Cursor::setY(const LongLong& newY) {
	if (newY.toInt64() >= 0) {
		y = newY;
		return true;
	}
	cerr << "координата Y не може бути від'ємною!" << endl;
	return false;
}

bool Cursor::setView(const string& newView) {
	if (newView == "horizontal" || newView == "vertical") {
		view = newView;
		return true;
	}
	cerr << "невірний вигляд курсора!" << endl;
	return false;
}

bool Cursor::setSize(int newSize) {
	if (newSize >= 1 && newSize <= 15) {
		size = newSize;
		return true;
	}
	cerr << "невірний розмір курсора!" << endl;
	return false;
}

bool Cursor::Init(LongLong nx, LongLong ny, string nview, int nSize) {
	visible = true;
	return setX(nx) && setY(ny) && setView(nview) && setSize(nSize);
}

void Cursor::Read() {
	LongLong tempX, tempY;
	string tempView;
	int tempSize;
	do {
		cout << "Введення параметрів курсору" << endl;
		cout << "Введіть координату X:"<<endl;
		tempX.Read();
		cout << "Введіть координату Y:" << endl;
		tempY.Read();
		cout << "Введіть вигляд курсора (horizontal/vertical):" << endl;
		cin >> tempView;
		cout << "Введіть розмір курсора (1-15):" << endl;
		cin >> tempSize;
	}
	while (!Init(tempX, tempY, tempView, tempSize));
}

string Cursor::toString() const {
	stringstream sout;
	sout << "Координата X: " << x.toString() 
		<< ", Координата Y: " << y.toString() 
		<< ", Вигляд: " << view 
		<< ", Розмір: " << size 
		<< ", Видимий: " << (visible ? "Так" : "Ні");
	return sout.str();
}

void Cursor::Display()const {
		cout << toString() << endl;
}

void Cursor::changeCoords(const LongLong& nx, LongLong& ny) {
	setX(nx);
	setY(ny);
}

void Cursor::changeView(const string nView) {
	setView(nView);
}

void Cursor::changeSize(int nSize) {
	setSize(nSize);
}

void Cursor::hide() {
	visible = false;
}

void Cursor::restore() {
	visible = true;
}