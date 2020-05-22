#include <iostream>
#include <Alpha.hpp>
#include <Char.hpp>
#include <Str.hpp>

int main(void)
{
	//Initialize alphabet and characters
	Char first(4);
	Char second(2);
	Alpha bet;
	
	//Insert the characters into alphabet
	bet.insert(first);
	bet.insert(second);
	
	//Initialize string and give it characters
	Str s(bet);
	s.add(first);
	
	//Output
	cout << first << " " << second << "0/n";
	cout << bet << "/n";
	cout << s << "/n" ;
	
	return 0;
}