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
	string identifier;
	string symstring;
public:
	SymString();
	SymString(const string);
	SymString(const SymString&);
	string GetIdentifier() const { return identifier; }
	string GetString() const { return symstring; }
	void SetString(const string);
	void SetIdentifier(const string);

	friend string operator + (const SymString&, const SymString&);
	friend ostream& operator << (ostream&, const SymString&);
	friend istream& operator >> (istream&, SymString&);
	operator string() const;
};

