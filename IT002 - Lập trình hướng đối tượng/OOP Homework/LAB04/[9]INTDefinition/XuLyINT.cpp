#include "DinhNghiaINT.h"

int INTEGER::count = 0;

INTEGER::INTEGER()
{
	data = 0;
	count++;
}

INTEGER::INTEGER(int data)
{
	this->data = data;
	count++;
}

INTEGER::~INTEGER()
{
	count--;
}

int INTEGER::getData() const
{
	return data;
}

void INTEGER::setData(int data)
{
	this->data = data;
}

INTEGER& INTEGER::operator=(int value)
{
	data = value;
	return *this;
}

INTEGER INTEGER::operator+(const INTEGER& x) const 
{
	return INTEGER(data + x.data);
}

INTEGER INTEGER::operator-(const INTEGER& x) const
{
	return INTEGER(data - x.data);
}

INTEGER INTEGER::operator*(const INTEGER& x) const
{
	return INTEGER(data * x.data);
}

INTEGER INTEGER::operator/(const INTEGER& x) const
{
	return INTEGER(data / x.data);
}

INTEGER& INTEGER::operator++()
{
	++data;
	return *this;
}

INTEGER& INTEGER::operator--()
{
	--data;
	return *this;
}

bool INTEGER::operator==(const INTEGER& x) const
{
	return data == x.data;
}

bool INTEGER::operator>(const INTEGER& x) const
{
	return data > x.data;
}

bool INTEGER::operator<(const INTEGER& x) const
{
	return data == x.data;
}

istream& operator>>(istream& in, INTEGER& value)
{
	in >> value.data;
	value.count++;
	return in;
}

ostream& operator<<(ostream& out, const INTEGER& value)
{
	out << value.data;
	return out;
}