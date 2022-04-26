///////////////////////////////////////////
// Source.cpp
#include "Factory.h"

int main()
{
	Factory a;

	string str;
	size_t _oct;
	size_t index;
	char choice;
	do
	{
		cout << "\nWhat do you wish to do?\n[a] - Add a SymString\n[b] - Add an OctString\n[c] - Show fabric's list\n[d] - Show a SymString\n[e] - Show an OctString\n[f] - Edit a SymString\n[g] - Edit an OctString\n[h] - Delete a SymString\n[i] - Delete an OctString\n[j] - Add up SymStrings\n[k] - Add up OctStrings\n[l] - Add up a SymString and an OctString\n\n[0] - Exit the program\n";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			cin.get();
			cin.sync();
			do
			{
				cout << "SymString : "; getline(cin, str);
			} while (str == "");
			a.AddObject(str);
			break;
		case 'b':
			cin.get();
			cin.sync();
			do
			{
				cout << "SymString : "; getline(cin, str);
			} while (str == "");
			cout << "Int to OctString : "; cin >> _oct;
			a.AddObject(str, _oct);
			break;
		case 'c':
			a.Print();
			break;
		case 'd':
			a.Print();
			cout << "No : "; cin >> _oct;
			if (a.GetSyms()[_oct - 1])
				cout << *(a.GetSyms()[_oct - 1]);
			else
				cout << "There is no object with such No.\n\n";
			break;
		case 'e':
			a.Print();
			cout << "No : "; cin >> _oct;
			if (a.GetOcts()[_oct - 1])
				cout << *(a.GetOcts()[_oct - 1]);
			else
				cout << "There is no object with such No.\n\n";
			break;
		case 'f':
			a.Print();
			cout << "No : "; cin >> _oct;
			if (a.GetSyms()[_oct - 1])
				cin >> *(a.GetSyms()[_oct - 1]);
			else
				cout << "There is no object with such No.\n\n";
			break;
		case 'g':
			a.Print();
			cout << "No : "; cin >> _oct;
			if (a.GetOcts()[_oct - 1])
				cin >> *(a.GetOcts()[_oct - 1]);
			else
				cout << "There is no object with such No.\n\n";
			break;
		case 'h':
			a.Print();
			cout << "Identifier : "; cin >> str;
			if (!a.DeleteObject(str, 1))
				cout << "Could not delete \"" << str << "\".\n\n";
			break;
		case 'i':
			a.Print();
			cout << "Identifier : "; cin >> str;
			if (!a.DeleteObject(str, 2))
				cout << "Could not delete \"" << str << "\".\n\n";
			break;
		case 'j':
			a.Print();
			cout << "1 No : "; cin >> _oct;
			if (!a.GetSyms()[_oct - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}
			cout << "2 No : "; cin >> index;
			if (!a.GetSyms()[index - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}

			cout << *(a.GetSyms()[_oct - 1]) + *(a.GetSyms()[index - 1]);
			break;
		case 'k':
			a.Print();
			cout << "1 No : "; cin >> _oct;
			if (!a.GetOcts()[_oct - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}
			cout << "2 No : "; cin >> index;
			if (!a.GetOcts()[index - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}

			cout << *(a.GetOcts()[_oct - 1]) + *(a.GetOcts()[index - 1]);
			break;
		case 'l':
			a.Print();
			cout << "1 No (SymString) : "; cin >> _oct;
			if (!a.GetSyms()[_oct - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}
			cout << "2 No (OctString) : "; cin >> index;
			if (!a.GetOcts()[index - 1])
			{
				cout << "There is no object with such No.\n\n";
				break;
			}

			cout << *(a.GetSyms()[_oct - 1]) + *(a.GetOcts()[index - 1]);
			break;
		case '0':
			break;
		default:
			cout << "Wrong option selected.\n\n";
			break;
		}
	} while (choice != '0');

	return 0;
}