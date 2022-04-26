///////////////////////////////////////////
// OctString.cpp
#pragma once
#include "SymString.h"

class OctString 
    :public SymString
{
public:
    OctString();
    OctString(const int);
    OctString(const string);
    void SetOctString(const int tostr);
    string ShowBin() const;

    friend OctString operator + (const OctString&, const OctString&);
    friend ostream& operator << (ostream&, const OctString&);
    friend istream& operator >> (istream&, OctString&);
    using SymString::operator string;
};