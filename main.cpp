#include <iostream>
#include <Alpha.hpp>
#include <Char.hpp>

int main(void)
{
	Char first(4);
	Char second(2);
	Alpha perfectstring;
	perfectstring.insert(first);
	perfectstring.insert(second);
	
	cout << first << " " << second << "0/n";
	cout << perfectstring;
	
	return 0;
}