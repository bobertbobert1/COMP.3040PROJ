#include <iostream>
#include <Alpha.hpp>
#include <Char.hpp>
#include <Str.hpp>

//Test functions
bool lexitest();
bool defDFA();
bool c1DFA();
bool c2DFA();
bool c3DFA();
bool nS();

//Initialize the dictionary
Alpha dictionary;
Char a(1);
Char b(2);
Char c(3);
Char d(4);
Char e(5);
Char f(6);
Str t1(dictionary);
Str t2(dictionary);
Str t3(dictionary);
Str t4(dictionary);
Str t5(dictionary);
Str t6(dictionary);
Str t7(dictionary);
Str t8(dictionary);
Str t9(dictionary);
Str t10(dictionary);
Str t11(dictonary);
Str t12(dictionary);

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

int main(void)
{

	//Initialize alphabet and characters
	Char first(4);
	Char second(2);
	Alpha bet;
	
	int pass = 0;
	int fail = 0;
	
	
	//Insert the characters into alphabet
	bet.insert(first);
	bet.insert(second);
	
	//Initialize string and give it characters
	Str s(bet);
	s.add(first);
	
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
	
	//Output
	cout << first << " " << second << "0/n";
	cout << bet << "/n";
	cout << s << "/n" ;
	bet.lex(0);
	let.lex(1);
	bool eNum()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> eNumaccept([](int qi)
		{
			return qi==0 || qi==1;
		}, 0,
		[](int qi, Char c)
		{
			if(c==a)
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
			return qi==0;
		});
		
		eNumaccept.accepts(t1)== true ? pass++ : fail++;
		eNumaccept.accepts(t2)== false ? pass++ : fail++;
		eNumaccept.accepts(t3)== true ? pass++ : fail++;
		eNumaccept.accepts(t4)== false ? pass++ : fail++;
		eNumaccept.accepts(t5)== true ? pass++ : fail++;
		eNumaccept.accepts(t6)== false ? pass++ : fail++;
		eNumaccept.accepts(t7)== true ? pass++ : fail++;
		eNumaccept.accepts(t8)== false ? pass++ : fail++;
		eNumaccept.accepts(t9)== true ? pass++ : fail++;
		eNumaccept.accepts(t10)== false ? pass++ : fail++;
		eNumaccept.accepts(t11)== true ? pass++ : fail++;
		eNumaccept.accepts(t12)== false ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "eNum failed 1 or more tests/n";
		}
		return fail==0;
	}
	bool defDFA()
	{
		int pass = 0;
		int fail = 0;
		
		DFA<int> defDFA([](int qi) 
		{ 
			return qi == 0 || qi == 1; 
		}, 0,
		[](int qi, Char c) 
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
		defDFA.accepts(t1) == true ? pass++ : fail++;
		defDFA.accepts(t2) == false ? pass++ : fail++;
		defDFA.accepts(t3) == true ? pass++ : fail++;
		dfaDFA.accepts(t4) == false ? pass++ : fail++;
		if(fail > 0)
		{
			cout << "defDFA failed 1 or more tests/n";
		}
		return fail==0;
	}
	bool c1DFA()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> c1accept = cDFA(a);
		c1accept.accepts(t1) == true ? pass++ : fail++;
		c1accept.accepts(t2) == false ? pass++ : fail++;
		c1accept.accepts(t3) == false ? pass++ : fail++;
		c1accept.accepts(t4) == false ? pass++ : fail++;
		if(fail > 0)
		{
			cout << "c1DFA failed 1 or more tests/n";
		}
		return fail==0;
	}
	bool c2DFA()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> c2accept = cDFA(b);
		c2accept.accepts(t1) == false ? pass++ : fail++;
		c2accept.accepts(t2) == true ? pass++ : fail++;
		c2accept.accepts(t3) == false ? pass++ : fail++;
		c2accept.accepts(t4) == false ? pass++ : fail++;
		if(fail > 0)
		{
			cout << "c2DFA failed 1 or more tests/n";
		}
		return fail==0;
	}
	bool c3DFA()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> c3accept = cDFA(c);
		c3accept.accepts(t1) == false ? pass++ : fail++;
		c3accept.accepts(t2) == false ? pass++ : fail++;
		c3accept.accepts(t3) == true ? pass++ : fail++;
		c3accept.accepts(t4) == false ? pass++ : fail++;
		if(fail > 0)
		{
			cout << "c3DFA failed 1 or more tests/n";
		}
		return fail==0;
	}
	bool nS()
	{
		ns.accepts(t1) == false ? pass++ : fail++;
		ns.accepts(t2) == false ? pass++ : fail++;
		ns.accepts(t3) == false ? pass++ : fail++;
		ns.accepts(t4) == false ? pass++ : fail++;
		ns.accepts(t5) == false ? pass++ : fail++;
		ns.accepts(t6) == false ? pass++ : fail++;
		ns.accepts(t7) == false ? pass++ : fail++;
		ns.accepts(t8) == false ? pass++ : fail++;
		ns.accepts(t9) == false ? pass++ : fail++;
		ns.accepts(t10) == false ? pass++ : fail++;
		ns.accepts(t11) == false ? pass++ : fail++;
		ns.accepts(t12) == false ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "noString failed 1 or more tests/n";
		}
		return fail==0;
	}
	return 0;
}

















