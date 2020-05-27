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
	
	//Empty String DFA
	DFA<int> es([](int qi) 
	{ 
		return qi == 0 || qi == 1; 
	}, 0,
    [](int qi, Character c) 
	{
        if (qi == 0) 
		{
            return 1;
        } 
		else 
		{
            return 0;
        }
    },
    [](int qi) 
	{ 
		return qi == 0;
	});
	
	//No Strings DFA
	DFA<int> ns([](int qi)
	{
		return qi==0 || qi==1;
	}, 0, [](int qi, Char cobj)
	{
		return 0;
	}, [](int qi)
	{
		return qi==0;
	});
	
	//Character DFA Function
	DFA<int> cDFA (Char dc)
	{
		DFA<int> dfa([](int qi)
		{
			return qi==0 || qi==1 || qi==2;
		},0,
		[dc](int qi, Char c)
		{
			if(c==dc&&qi==0)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		},
		[](int qi)
		{
			return qi==1;
		});
		return dfa;
	}
	
	//Output
	cout << first << " " << second << "0/n";
	cout << bet << "/n";
	cout << s << "/n" ;
	bet.lex(0);
	let.lex(1);
	
	return 0;
}