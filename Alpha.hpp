#ifndef ALPHA_HPP
#define ALPHA_HPP

#include <set>
#include "Char.hpp"

class Str;

class Alpha
{
	public:
		void insert(Char c);
		int size();
		Str lex(int x);
		Char at(int x);
		Char operator[](int v);
		std::ostream& operator<<(std::ostream& output, const Alpha& aobj);
		
	private:
		std::set<Char> chars;
}

#endif