#pragma once
#ifndef CSTRING
#include <iostream>
#include <string>
using namespace std;
class CString
{
private:
	string s;
	static int count;
public:
	CString();
	~CString();
	static int GetCount() {
		return count;
	}
	CString(const string&);
	string GetCString() const;
	void SetCString(const string&);
	CString operator+(const CString&) const;
	CString& operator=(const CString&);
	bool operator==(const CString&) const;
	bool operator!=(const CString&) const;
	bool operator<(const CString&) const;
	bool operator>(const CString&) const;
	friend istream& operator>>(istream&, CString&);
	friend ostream& operator<<(ostream&, const CString&);
};
#endif // !CSTRING

