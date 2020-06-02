#ifndef STR_HPP
#define STR_HPP

#include "Alpha.hpp"
#include "Char.hpp"
#include <vector>

class Str
{
	public:
		Str(Alpha bet)
		{
			aobj = bet;
		}
		void add(Char cobj);
		void pop_back();
		friend std::ostream& operator<<(std::ostream& output, Str& s);
		
	private:
		Alpha aobj;
		std::vector<Char> chars;
};

#endif