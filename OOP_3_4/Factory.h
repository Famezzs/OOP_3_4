///////////////////////////////////////////
// Factory.h
#pragma once
#include "OctString.h"

class Factory
{
	SymString** syms;
	OctString** octs;
	const size_t size;
public:
	Factory();
	~Factory();
	SymString** GetSyms() const { return syms; }
	OctString** GetOcts() const { return octs; }
	void AddObject(const string);
	void AddObject(const int);
	bool DeleteObject(const string, const int);
	void Print() const;

	friend ostream& operator << (ostream&, const Factory&);
	operator string() const;
};

