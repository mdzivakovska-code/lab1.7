//Cursor.h
#pragma once
#include "LongLong.h"
#include<string>

using namespace std;
class Cursor
{
private:
	LongLong x;
	LongLong y;
	string view;
	int size;
	bool visible;

public:
	LongLong getX() const { return x; }
	LongLong getY() const { return y; }
	string getView() const { return view; }
	int getSize() const { return size; }
	bool isVisible() const { return visible; }
	
	bool setX(const LongLong& newX);
	bool setY(const LongLong& newY);
	bool setView(const string& newView);
	bool setSize(int newSize);

	bool Init(LongLong nx, LongLong ny, string nView, int nSize);
	void Read();
	void Display() const;
	string toString()const;

	void changeCoords(const LongLong& nx, LongLong& ny);
	void changeView(const string nView);
	void changeSize(int nSize);
	void hide();
	void restore();
};

