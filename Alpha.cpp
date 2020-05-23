#include "Alpha.hpp"
#include "String.hpp"
#include <iostream>
#include <cmath>
using namespace std;

//Inserts character into alphabet
void Alpha::insert(Char c)
{
	chars.insert(c);
}

//Returns the current size of the alphabet
int Alpha::size()
{
	return chars.size();
}

//Returns first character
Char Alpha::operator[](int v)
{
	set<Char>::iterator run = chars.begin();
	advance(run, v);
	
	Char first = *run;
	return first;
}

//Function for Task 3 that returns Nth string in lexicographic order
Str Alpha::lex(int x)
{
	Str s(*this);
	
	//Empty string
	if(x==0)
	{
		return s;
	}
	
	int len = chars.size();
	int i=0;
	while(n >= pow(len, i))
	{
		n -= pow(len,i);
		i++;
	}
	
	for(int j=0; j<i; j++)
	{
		s.pushf(at(n%len));
		n = n/len;
	}
	cout << s << "/n";
	return s;
		
}


//Returns the char value found at specific spot in an alphabet
Char Alpha::at(int x)
{
	set<Char>::iterator run = chars.begin();
	advance(run, x);
	Char current = *run;
	return current;
	
}

ostream& operator<<(ostream& output, const Alpha& aobj)
{
	for(set<Char>::iterator run = aobj.chars.begin(); run != aobj.chars.end(); run++)
	{
		output << *run << " ";
	}

	return output;
}