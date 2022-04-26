///////////////////////////////////////////
// SymString.h
#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <sstream>

using namespace std;

class SymString
{
	string sym_identifier;
	string symstring;
public:
	SymString();
	SymString(const string);
	SymString(const SymString&);
	string GetIdentifier() const { return sym_identifier; }
	string GetSymString() const { return symstring; }
	void SetSymString(const string);

	friend string operator + (const SymString&, const SymString&);
	friend ostream& operator << (ostream&, const SymString&);
	friend istream& operator >> (istream&, SymString&);
	operator string() const;
};

