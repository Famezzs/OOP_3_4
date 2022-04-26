///////////////////////////////////////////
// SymString.cpp
#include "SymString.h"

SymString::SymString()
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		sym_identifier = to_string(guid.Data1);
	else
		sym_identifier = "invalid";
}

SymString::SymString(const string str)
	:symstring(str)
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		sym_identifier = to_string(guid.Data1);
	else
		sym_identifier = "invalid";
}

SymString::SymString(const SymString& cpy)
	:symstring(cpy.symstring)
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		sym_identifier = to_string(guid.Data1);
	else
		sym_identifier = "invalid";
}

void SymString::SetSymString(const string str)
{
	symstring = str;
}

string operator + (const SymString &a, const SymString &b)
{
	return SymString(a.symstring + b.symstring);
}

SymString::operator string() const
{
	stringstream sout;
	sout << "SymIdentifier : " << sym_identifier << ", SymString : " << symstring;
	return sout.str();
}

ostream& operator << (ostream& out, const SymString& to_out)
{
	out << string(to_out) << endl;
	return out;
}

istream& operator >> (istream& in, SymString& to_in)
{
	cin.get();
	cin.sync();
	cout << "SymString : ";
	getline(in, to_in.symstring);

	return in;
}