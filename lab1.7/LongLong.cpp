//LongLong.cpp
#include "LongLong.h"
#include <iostream>

using namespace std;

long long LongLong::toInt64()const {
	return ((long long)high << 32) | (low & 0xFFFFFFFFULL);
}

LongLong LongLong::fromInt64(long long val) {
	LongLong res;
	res.setHigh((long)(val >> 32));
	res.setLow((unsigned long)(val & 0xFFFFFFFFULL));
	return res;
}

bool LongLong::Init(long h, unsigned long l) {
	setHigh(h);
	setLow(l);
	return true;
}

void LongLong::Read() {
	long h;
	unsigned long l;
	cout << "Введіть старшу частину(high):";
	cin >> h;
	cout << "Введіть молодшу частину(low):";
	cin >> l;
	Init(h, l);
}

string LongLong::toString() const {
	stringstream sout;
	sout << toInt64();
	return sout.str();
}

void LongLong::Display() const {
	cout << toString();
}

LongLong LongLong::add(const LongLong& r) const {
	return fromInt64(this->toInt64() + r.toInt64());

}

LongLong LongLong::sub(const LongLong& r) const {
	return fromInt64(this->toInt64() - r.toInt64());
}
LongLong LongLong::mul(const LongLong& r) const {
	return fromInt64(this->toInt64() * r.toInt64());
}
LongLong LongLong::div(const LongLong& r) const {
	if(r.toInt64() == 0){
		cerr << "Ділення на нуль!" << endl;
		return fromInt64(0);
	}
	return fromInt64(this->toInt64() / r.toInt64());
}

LongLong LongLong::mod(const LongLong& r) const {
	if (r.toInt64() == 0) {
		cerr << "Ділення на нуль!" << endl;
		return fromInt64(0);
	}
	return fromInt64(this->toInt64() % r.toInt64());
}

bool LongLong::isGreater(const LongLong& r) const {
	return toInt64() > r.toInt64();
}
bool LongLong::isLess(const LongLong& r) const {
	return toInt64() < r.toInt64();
}
bool LongLong::isEqual(const LongLong& r) const {
	return toInt64() == r.toInt64();
}
bool LongLong::isNotEqual(const LongLong& r) const {
	return toInt64() != r.toInt64();
}