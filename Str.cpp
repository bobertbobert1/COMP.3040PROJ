#include "Str.hpp"
#include <iostream>
using namespace std;


//Checks if char is in our alphabet and if so adds it
void Str::add(Char cobj)
{
	if(aobj.contains(cobj))
	{
		chars.push_back(cobj);
	}
	else
	{
		throw "Char wasn't found in Alpha :(";
	}
}

ostream& operator<<(ostream& output, Str& s)
{
	for(int i=0;i<s.chars.size();i++)
	{
		output << s.chars[i];
	}
	return output;
}