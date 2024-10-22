#include "CString.h"

int CString::count = 0;

CString::CString()
{
	s = "";
	count++;
}

CString::~CString()
{
	count--;
}

CString::CString(const string& s)
{
	this->s = s;
	count++;
}

string CString::GetCString() const
{
	return s;
}

void CString::SetCString(const string& s)
{
	this->s = s;
}

CString CString::operator+(const CString& other) const
{
	return CString(s + other.s);
}

CString& CString::operator=(const CString& other)
{
	if (this != &other) {
		s = other.s;
	}
	return *this;
}

bool CString::operator==(const CString& other) const
{
	return (s == other.s);
}

bool CString::operator!=(const CString& other) const
{
	return (s != other.s);
}

bool CString::operator<(const CString& other) const
{
	return (s < other.s);
}

bool CString::operator>(const CString& other) const
{
	return (s > other.s);
}

istream& operator>>(istream& in, CString& c) 
{
	getline(in, c.s);
	c.count++;
	return in;
}

ostream& operator<<(ostream& out, const CString& c) 
{
	out << c.s;
	return out;
}