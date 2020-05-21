#include "Char.hpp"
using namespace std;

//Output of Character Value
ostream& operator<<(ostream& output, Char cobj)
{
	output << cobj.c;
	return output;
}

//Greater than operator
bool operator>(Char l, Char r)
{
	return l.c > r.c;
}

//Less than operator
bool operator<(Char r)
{
	return l.c < r.c;
}

//Equal to operator
bool operator==(Char l, Char r)
{
	return l.c == r.c;
}