#include "Alpha.hpp"
#include <iostream>
using namespace std;

//Inserts character into alphabet
void Alpha::insert(Char c)
{
	chars.insert(c);
}

//Returns first character
Char Alpha::operator[](int v)
{
	set<Char>::iterator run = chars.begin();
	advance(run, v);
	
	Char first = *run;
	return first;
}


ostream& operator<<(ostream& output, const Alpha& aobj)
{
	for(set<Char>::iterator run = aobj.chars.begin(); run != aobj.chars.end(); run++)
	{
		output << *run << " ";
	}

	return output;
}