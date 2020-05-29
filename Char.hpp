#ifndef CHAR_HPP
#define CHAR_HPP

#include <iostream>

class Char 
{
	public:
		Char(int x) 
		{
			c = x;
		}
	
	friend std::ostream& operator<<(std::ostream& output, const Char& x);
	friend bool operator>(Char l, Char r);
	friend bool operator<(Char l, Char r);
	friend bool operator==(Char l, Char r);
	//Maybe use int value as a place holder for characters?
	private:
		int c;
};

#endif