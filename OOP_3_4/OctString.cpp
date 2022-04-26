///////////////////////////////////////////
// OctString.cpp
#include "OctString.h"

OctString::OctString()
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		SetIdentifier(to_string(guid.Data1));
	else
		SetIdentifier("invalid");
}

OctString::OctString(const int tostr)
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		SetIdentifier(to_string(guid.Data1));
	else
		SetIdentifier("invalid");

	SetOctString(tostr);
}

OctString::OctString(const string tosym)
	:SymString(tosym) {}

void OctString::SetOctString(const int tostr)
{
	stringstream sout;
	sout << oct << tostr;
	SetString(sout.str());
}

string OctString::ShowBin() const
{
	stringstream sout;
	for (size_t i = 0; i < GetString().size(); i++)
	{
		switch (GetString().at(i))
		{
		case '0':
			sout << "000 ";
			break;
		case '1':
			sout << "001 ";
			break;
		case '2':
			sout << "010 ";
			break;
		case '3':
			sout << "011 ";
			break;
		case '4':
			sout << "100 ";
			break;
		case '5':
			sout << "101 ";
			break;
		case '6':
			sout << "110 ";
			break;
		case '7':
			sout << "111 ";
			break;
		}
	}
	return sout.str();
}

OctString operator + (const OctString& a, const OctString& b)
{
	int decstring_a = 0;
	int decstring_b = 0;

	int k = a.GetString().size() - 1;
	for (size_t i = 0; i < a.GetString().size(); i++)
		decstring_a += (a.GetString().at(i) - '0') * static_cast<int>(pow(8, k--));

	k = b.GetString().size() - 1;
	for (size_t i = 0; i < b.GetString().size(); i++)
		decstring_b += (b.GetString().at(i) - '0') * static_cast<int>(pow(8, k--));

	return OctString(decstring_a + decstring_b);
}

ostream& operator << (ostream& out, const OctString& to_out)
{
	out << string(to_out) << ", BinString : " << to_out.ShowBin() << endl;
	return out;
}

istream& operator >> (istream& in, OctString& _in)
{
	unsigned int _oct;
	in >> dynamic_cast<SymString&>(_in);
	cout << "OctString : "; in >> _oct;
	_in.SetOctString(_oct);

	return in;
}