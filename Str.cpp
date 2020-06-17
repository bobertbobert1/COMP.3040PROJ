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

//Pushs  given character value to front of string object if it's found in the alphabet
void Str::pushf(Char cobj)
{
	if(aobj.contains(cobj))
	{
		vector<Char>::iterator run = chars.begin();
		chars.insert(run, cobj);
	}
	else
	{
		throw "Unable to push character not found in alphabet";
	}
}

//Returns the char value at the front of the string
Char String::first()
{
	if(chars.size!=0)
	{
		return chars[0];
	}
	else
	{
		throw "Empty string no values to return";
	}
}

//Removes the last character from a given string
void Str::pop_back()
{
	if(chars.size() > 0)
	{
		chars.pop_back();
	}
	else
	{
		throw "String is too small to execute pop_back";
	}
}

void setfail()
{
	failed=true;
}

bool failed()
{
	return failed;
}
ostream& operator<<(ostream& output, Str& s)
{
	for(int i=0;i<s.chars.size();i++)
	{
		output << s.chars[i];
	}
	return output;
}