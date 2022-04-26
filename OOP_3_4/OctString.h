///////////////////////////////////////////
// OctString.cpp
#pragma once
#include "SymString.h"

class OctString 
    :public SymString
{
    string oct_identifier;
    string octstring;
public:
    OctString();
    OctString(const int);
    OctString(const string, const int);
    string GetIdentifier() const { return oct_identifier; }
    string GetOctString() const { return octstring; }
    void SetOctString(const int tostr);
    string ShowBin() const;

    friend OctString operator + (const OctString&, const OctString&);
    friend ostream& operator << (ostream&, const OctString&);
    friend istream& operator >> (istream&, OctString&);
    operator string() const;
};