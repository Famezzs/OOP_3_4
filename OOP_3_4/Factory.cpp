///////////////////////////////////////////
// Factory.cpp
#include "Factory.h"

Factory::Factory()
	:size(25)
{
	syms = new SymString *[size];
	for (size_t i = 0; i < size; i++)
		syms[i] = nullptr;
		
	octs = new OctString * [size];
	for (size_t i = 0; i < size; i++)
		octs[i] = nullptr;
}

Factory::~Factory()
{
	for (size_t i = 0; i < size; i++)
		if (syms[i] != nullptr)
			delete syms[i];

	for (size_t i = 0; i < size; i++)
		if (octs[i] != nullptr)
			delete octs[i];

	delete[] syms;
	delete[] octs;
}

void Factory::AddObject(const string sym_string)
{
	for (size_t i = 0; i < size; i++)
		if (!syms[i])
		{
			syms[i] = new SymString(sym_string);
			return;
		}
	cout << "List of SymStrings is full.\n\n";
}

void Factory::AddObject(const string sym_string, const int oct_string)
{
	for (size_t i = 0; i < size; i++)
		if (!octs[i])
		{
			octs[i] = new OctString(sym_string, oct_string);
			return;
		}
	cout << "List of OctStrings is full.\n\n";
}

bool Factory::DeleteObject(const string identifier, const int option)
{
	if (option == 1)
	{
		for (int i = 0; i < size; i++)
			if (syms[i])
				if (syms[i]->GetIdentifier() == identifier)
				{
					delete syms[i];
					syms[i] = NULL;
					return true;
				}
		return false;
	}

	for (int i = 0; i < size; i++)
		if (octs[i])
			if (octs[i]->GetIdentifier() == identifier || octs[i]->SymString::GetIdentifier() == identifier)
			{
				delete octs[i];
				octs[i] = NULL;
				return true;
			}
	return false;
}

void Factory::Print() const
{
	cout << "\nSymString objects' list :\n";
	cout << "========================================\n";
	cout << "|No| Identifier |      SymStrings      |\n";
	cout << "========================================\n";
	for (size_t i = 0; i < size; i++)
		if (syms[i])
		{
			cout << "|" << setw(2) << right << i+1 << "| " << setw(10) << left << syms[i]->GetIdentifier() << " | " 
				<< setw(20) << left << syms[i]->GetSymString()
				<< " |\n";
		}
	cout << "========================================\n\n\n";

	cout << "OctString objects' list :\n";
	cout << "==========================================================================\n";
	cout << "|No| SymIdentifiers |      SymStrings      | OctIdentifiers | OctStrings |\n";
	cout << "==========================================================================\n";
	for (size_t i = 0; i < size; i++)
		if (octs[i])
		{
			cout << "|" << setw(2) << right << i+1 << "| " << setw(14) << left << octs[i]->SymString::GetIdentifier() 
				<< " | " << setw(20) << left << octs[i]->GetSymString()
				<< " | " << setw(14) << left << octs[i]->GetIdentifier() 
				<< " | " << setw(10) << left << octs[i]->GetOctString() << " |\n";
		}
	cout << "==========================================================================\n";
}

Factory::operator string() const
{
	stringstream sout;
	sout << "\nSymString objects' list :\n";
	sout << "========================================\n";
	sout << "|No| Identifier |      SymStrings      |\n";
	sout << "========================================\n";
	for (size_t i = 0; i < size; i++)
		if (syms[i])
		{
			sout << "|" << setw(2) << right << i + 1 << "| " << setw(10) << left << syms[i]->GetIdentifier() << " | "
				<< setw(20) << left << syms[i]->GetSymString()
				<< " |\n";
		}
	sout << "========================================\n\n\n";

	sout << "OctString objects' list :\n";
	sout << "==========================================================================\n";
	sout << "|No| SymIdentifiers |      SymStrings      | OctIdentifiers | OctStrings |\n";
	sout << "==========================================================================\n";
	for (size_t i = 0; i < size; i++)
		if (octs[i])
		{
			sout << "|" << setw(2) << right << i + 1 << "| " << setw(14) << left << octs[i]->SymString::GetIdentifier()
				<< " | " << setw(20) << left << octs[i]->GetSymString()
				<< " | " << setw(14) << left << octs[i]->GetIdentifier()
				<< " | " << setw(10) << left << octs[i]->GetOctString() << " |\n";
		}
	sout << "==========================================================================\n";

	return sout.str();
}

ostream& operator << (ostream& out, const Factory& _out)
{
	out << string(_out) << endl;
	return out;
}
