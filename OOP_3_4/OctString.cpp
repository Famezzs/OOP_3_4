///////////////////////////////////////////
// OctString.cpp
#include "OctString.h"

OctString::OctString()
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		oct_identifier = to_string(guid.Data1);
	else
		oct_identifier = "invalid";
}

OctString::OctString(const int tostr)
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		oct_identifier = to_string(guid.Data1);
	else
		oct_identifier = "invalid";

	stringstream sout;
	sout << oct << tostr;
	octstring = sout.str();
}

OctString::OctString(const string tosym, const int tostr)
	:SymString(tosym)
{
	GUID guid;
	HRESULT result = CoCreateGuid(&guid);
	if (result == S_OK)
		oct_identifier = to_string(guid.Data1);
	else
		oct_identifier = "invalid";

	stringstream sout;
	sout << oct << tostr;
	octstring = sout.str();
}

void OctString::SetOctString(const int tostr)
{
	stringstream sout;
	sout << oct << tostr;
	octstring = sout.str();
}

string OctString::ShowBin() const
{
	stringstream sout;
	for (size_t i = 0; i < octstring.size(); i++)
	{
		switch (octstring.at(i))
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

	int k = a.octstring.size() - 1;
	for (size_t i = 0; i < a.octstring.size(); i++)
		decstring_a += (a.octstring.at(i) - '0') * static_cast<int>(pow(8, k--));

	k = b.octstring.size() - 1;
	for (size_t i = 0; i < b.octstring.size(); i++)
		decstring_b += (b.octstring.at(i) - '0') * static_cast<int>(pow(8, k--));

	return OctString(a.GetSymString() + b.GetSymString(), decstring_a + decstring_b);
}

OctString::operator string() const
{
	stringstream sout;
	sout << SymString::operator string() << ", OctIdentifier : " << oct_identifier << ", OctString : "
		<< octstring << ", OctToBinary : " << ShowBin();
	return sout.str();
}

ostream& operator << (ostream& out, const OctString& to_out)
{
	out << string(to_out) << endl;
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