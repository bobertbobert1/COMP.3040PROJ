#ifndef CHAR_HPP
#define CHAR_HPP

class Char 
{
	public:
		Char(int x) 
		{
			c = x;
		}
	
	std::ostream& operator<<(std::ostream& out, Char& x);
	bool operator>(Char l, Char r);
	bool operator<(Char l, Char r);
	bool operator==(Char l, Char r);
	//Maybe use int value as a place holder for characters?
	private:
		int c;
};

#endif