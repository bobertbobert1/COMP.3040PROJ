#include <iostream>
#include "Alpha.hpp"
#include "Char.hpp"
#include "Str.hpp"
#include "DFA.hpp"

//Test functions
bool lexitest();
bool defDFA();
bool c1DFA();
bool c2DFA();
bool c3DFA();
bool nS();
template <typename T>
bool successString(DFA<T> dfa, Str s);

template <typename T>
DFA<T> flippeddfa(DFA<T> dfa);

template <typename T, typename TT>
DFA<pair<T, TT>> uniondfa(DFA<T> d1, DFA<TT> d2);

template <typename T, typename TT>
DFA<pair<T, TT>> intersectdfa(DFA<T> d1, DFA<TT> d2);

template <typename T, typename TT>
bool subsetdfa(DFA<T> d1, DFA<TT> d2, Alpha bet);

template <typename T, typename TT>
bool equalitydfa(DFA<T> d1, DFA<TT>,d2, Alpha bet);

bool equalitytest();
bool subsettest();
bool intersecttest();
bool uniontest();
bool statestest();
bool stringfindtest();
bool flippeddfatest();

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
	
	bool successString(DFA<T> dfa, Str s)
	{
		return dfa.accepts(s);
	}
	
	bool statestest()
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

		vector<<pair<int, Char>> statelist = eNumaccept.acceptsandstates(t1);

		return true;
	}
	
	bool stringfindtest ()
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
		
		Str strong = findstr(eNumaccept, dictionary);
		Str ans(dictionary);
		if(strong.length()==ans.length())
		{
			for(int i=0; i<strong.length(); i++)
			{
				if(strong[i]!=ans[i])
				{
					fail++;
					break;
				}
			}
			
			if(fail!=0)
			{
				cout << "Oh no the findstr test failed!/n";
			}
			return fail==0;
		}
		
	}
	
	template <typename T>
	DFA<T> flippeddfa(DFA<T> dfa)
	{
		function<bool(T)> flipee = [dfa](T qi)
		{
			return !dfa.F(qi);
		};
		DFA<T> flipped(dfa.Q, dfa, q0, dfa.delta, flipee);
		return flipped;
	}
	
	bool flippeddfatest()
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
		
		
		DFA<int> oNumaccept = flippeddfa(eNumaccept);
		oNumaccept.accepts(t1) == false ? pass++ : fail++;
		oNumaccept.accepts(t2) == true ? pass++ : fail++;
		oNumaccept.accepts(t3) == false ? pass++ : fail++;
		oNumaccept.accepts(t4) == true ? pass++ : fail++;
		oNumaccept.accepts(t5) == false ? pass++ : fail++;
		oNumaccept.accepts(t6) == true ? pass++ : fail++;
		oNumaccept.accepts(t7) == false ? pass++ : fail++;
		oNumaccept.accepts(t8) == true ? pass++ : fail++;
		oNumaccept.accepts(t9) == false ? pass++ : fail++;
		oNumaccept.accepts(t10) == true ? pass++ : fail++;
		oNumaccept.accepts(t11) == false ? pass++ : fail++;
		oNumaccept.accepts(t12) == true ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "The inverse DFA that accepts odd length DFAs has failed 1 or more tests!/n";
		}
		
		return fail==0;
	}
	
	bool uniontest()
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
		
		DFA<int> c2accept = cDFA(b);
		
		DFA<pair<int, int>> eNumand2accept = uniondfa(eNumaccept,c2accept);
		
		eNumand2accept.accepts(t1) == true ? pass++ : fail++;
		eNumand2accept.accepts(t2) == true ? pass++ : fail++;
		eNumand2accept.accepts(t3) == false ? pass++ : fail++;
		eNumand2accept.accepts(t4) == true ? pass++ : fail++;
		eNumand2accept.accepts(t5) == false ? pass++ : fail++;
		eNumand2accept.accepts(t6) == true ? pass++ : fail++;
		eNumand2accept.accepts(t7) == false ? pass++ : fail++;
		eNumand2accept.accepts(t8) == true ? pass++ : fail++;
		eNumand2accept.accepts(t9) == false ? pass++ : fail++;
		eNumand2accept.accepts(t10) == true ? pass++ : fail++;
		eNumand2accept.accepts(t11) == false ? pass++ : fail++;
		eNumand2accept.accepts(t12) == true ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "The inverse DFA that accepts odd length DFAs has failed 1 or more tests!/n";
		}
		
		return fail==0;
		
	}
	
	bool intersecttest()
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
		
		DFA<int> c1accept = cDFA(a);
		
		DFA<pair<int, int>> only1accept = intersectdfa(eNumaccept,c1accept);
		
		only1accept.accepts(t1) == true ? pass++ : fail++;
		only1accept.accepts(t2) == false ? pass++ : fail++;
		only1accept.accepts(t3) == false ? pass++ : fail++;
		only1accept.accepts(t4) == false ? pass++ : fail++;
		only1accept.accepts(t5) == false ? pass++ : fail++;
		only1accept.accepts(t6) == false ? pass++ : fail++;
		only1accept.accepts(t7) == false ? pass++ : fail++;
		only1accept.accepts(t8) == false ? pass++ : fail++;
		only1accept.accepts(t9) == false ? pass++ : fail++;
		only1accept.accepts(t10) == false ? pass++ : fail++;
		only1accept.accepts(t11) == false ? pass++ : fail++;
		only1accept.accepts(t12) == false ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "The inverse DFA that accepts odd length DFAs has failed 1 or more tests!/n";
		}
		
		return fail==0;
	}
	
	bool subsettest()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> Aaccept = cDFA(a);
		DFA<int> Baccept = cDFA(b);
		DFA<int> A2accept = cDFA(a);
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
		DFA<int> oNumaccept = flippeddfa(eNumaccept);
		
		subsetdfa(Aaccept,Baccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(A2accept,Baccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(Aaccept,A2accept,dictionary) == true ? pass++ : fail++;
		subsetdfa(eNumaccept,oNumaccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(eNumaccept,Baccept,dictionary) == true ? pass++ : fail++;
		subsetdfa(oNumaccept,Aaccept,dictionary) == true ? pass++ : fail++;
		subsetdfa(eNumaccept,Aaccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(oNumaccept,Baccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(Aaccept,oNumaccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(Baccept,oNumaccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(Aaccept,eNumaccept,dictionary) == false ? pass++ : fail++;
		subsetdfa(Baccept,eNumaccept,dictionary) == false ? pass++ : fail++;
		
		if(fail > 0)
		{
			cout << "The inverse DFA that accepts odd length DFAs has failed 1 or more tests!/n";
		}
		
		return fail==0;
	}
	
	bool equalitytest()
	{
		int pass = 0;
		int fail = 0;
		DFA<int> Aaccept = cDFA(a);
		DFA<int> Baccept = cDFA(b);
		DFA<int> A2accept = cDFA(a);
		DFA<pair<int, int>> only1accept = intersectdfa(eNumaccept,Baccept);
		DFA<pair<int, int>> eNumand2accept = uniondfa(eNumaccept,Baccept);
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
		DFA<int> oNumaccept = flippeddfa(eNumaccept);
		
		subsetdfa(Aaccept,Baccept,dictionary) == false ? pass++ : fail++;
		equalitydfa(Aaccept,Baccept,dictionary) == false ? pass++ : fail++;	
		equalitydfa(Aaccept,A2accept,dictionary) == true ? pass++ : fail++;
		subsetdfa(Aaccept,A2accept,dictionary) == true ? pass++ : fail++;
		equalitydfa(eNumaccept,oNumaccept,dictionary) == false ? pass++ : fail++;
		equalitydfa(eNumand2accept,eNumaccept,dictionary) == false ? pass++ : fail++;
		equalitydfa(only1accept,Baccept,dictionary) == false ? pass++ : fail++;
		equalitydfa(Baccept,A2accept,dictionary) == false ? pass++ : fail++;
		
		
		if(fail > 0)
		{
			cout << "The inverse DFA that accepts odd length DFAs has failed 1 or more tests!/n";
		}
		
		return fail==0;
	}
	template <typename T, typename TT>
	bool equalitydfa(DFA<T> d1, DFA<TT> d2, Alpha bet)
	{
		DFA<TT> flippedd2 = flippeddfa(d2);
		DFA<pair<T,TT>> intersectdfa1 = intersectdfa(d1, flippedd2);
		
		DFA<T> flippedd1 = flippeddfa(d1);
		DFA<pair<TT, T>> intersectdfa2 = intersectdfa(d2, flippedd1);
		
		String ans1 = findstr(intersectdfa1, bet);
		String ans2 = findstr(intersectdfa2, bet);
		
		if(ans1.failed())
		{
			return true;
		}
		
		if(ans2.failed())
		{
			return true;
		}
		
		return false;
	}
	template <typename T, typename TT>
	bool subsetdfa(DFA<T> d1, DFA<TT> d2, Alpha bet)
	{
		DFA<TT> flippedd2 = flippeddfa(d2);
		DFA<pair<T,TT>> intersected = intersectdfa(d1,flippedd2);
		Str answer = findstr(intersected, bet);
		if(answer.failed())
		{
			return true;
		}
		return false;
	}
	
	template <typename T, typename TT>
	DFA<pair<T, TT>> uniondfa(DFA<T> d1, DFA<TT> d2)
	{
		function<bool(pair<T, TT>)> Q = [d1, d2](pair<T, TT> qi) 
		{
			return d1.Q(qi.first) || d2.Q(qi.second);
		};
		pair<T, TT> q0(d1.q0, d2.q0);
		function<pair<T, TT>(pair<T, TT>, Char)> delta =[d1, d2](pair<T, TT> qi, Char cobj) 
		{
			T qi1 = d1.delta(qi.first, cobj);
			TT qi2 = d2.delta(qi.second, cobj);
			pair<T, TT> finalpair(qi1, qi2);
			return finalrepair;
		};
		function<bool(pair<T, TT>)> F = [d1, d2](pair<T, TT> qi) 
		{
			return d1.F(qi.first) || d2.F(qi.second);
		};
		DFA<pair<T1, T2>> finaldfa(Q, q0, delta, F);
		return finaldfa;
	}
	
	template <typename T, typename TT>
	DFA<pair<T, TT> intersectdfa(DFA<T> d1, DFA<TT> d2)
	{
		function<bool(pair<T,TT>)> Q = [d1, d2](pair<T,TT> qi)
		{
			return d1.Q(qi.first) || d2.Q(qi,second);
		}
		pair<T,TT> q0(d1.q0,d2.q0);
		function<pair<T,TT>(pair<T,TT>,Char)> delta = [d1,d2](pair<T,TT> qi, Char cobj)
		{
			T qi1 = d1.delta(qi.first, cobj);
			TT qi2 = d2.delta(qi.second, cobj);
			pair<T, TT> finaldfa(qi1, qi2);
			return finaldfa;
		};
		function<bool(pair<T,TT>)> F = [d1,d2](pair<T,TT> qi)
		{
			return d1.F(qi.first) && d2.F(qi.second);
		};
		DFA<pair<T,TT>> finaldfa(Q, q0, delta, F);
		return finaldfa;
	}
	successString(ns, t1) == false ? pass++ : fail++;
	successString(ns, t2) == false ? pass++ : fail++;
	successString(ns, t3) == false ? pass++ : fail++;
	successString(ns, t4) == false ? pass++ : fail++;
	successString(ns, t5) == false ? pass++ : fail++;
	successString(ns, t6) == false ? pass++ : fail++;
	successString(ns, t7) == false ? pass++ : fail++;
	successString(ns, t8) == false ? pass++ : fail++;
	successString(ns, t9) == false ? pass++ : fail++;
	successString(ns, t10) == false ? pass++ : fail++;
	successString(ns, t11) == false ? pass++ : fail++;
	successString(ns, t12) == false ? pass++ : fail++;
	successString(c1accept, t1) == true ? pass++ : fail++;
	successString(c1accept, t2) == false ? pass++ : fail++;
	successString(c1accept, t3) == false ? pass++ : fail++;
	successString(c1accept, t4) == false ? pass++ : fail++;
	successString(c1accept, t5) == false ? pass++ : fail++;
	successString(c1accept, t6) == false ? pass++ : fail++;
	successString(c1accept, t7) == false ? pass++ : fail++;
	successString(c1accept, t8) == false ? pass++ : fail++;
	successString(c1accept, t9) == false ? pass++ : fail++;
	successString(c1accept, t10) == false ? pass++ : fail++;
	successString(c1accept, t11) == false ? pass++ : fail++;
	successString(c1accept, t12) == false ? pass++ : fail++;
	successString(c2accept, t1) == false ? pass++ : fail++;
	successString(c2accept, t2) == true ? pass++ : fail++;
	successString(c2accept, t3) == false ? pass++ : fail++;
	successString(c2accept, t4) == false ? pass++ : fail++;
	successString(c2accept, t5) == false ? pass++ : fail++;
	successString(c2accept, t6) == false ? pass++ : fail++;
	successString(c2accept, t7) == false ? pass++ : fail++;
	successString(c2accept, t8) == false ? pass++ : fail++;
	successString(c2accept, t9) == false ? pass++ : fail++;
	successString(c2accept, t10) == false ? pass++ : fail++;
	successString(c2accept, t11) == false ? pass++ : fail++;
	successString(c2accept, t12) == false ? pass++ : fail++;
	successString(c3accept, t1) == false ? pass++ : fail++;
	successString(c3accept, t2) == false ? pass++ : fail++;
	successString(c3accept, t3) == true ? pass++ : fail++;
	successString(c3accept, t4) == false ? pass++ : fail++;
	successString(c3accept, t5) == false ? pass++ : fail++;
	successString(c3accept, t6) == false ? pass++ : fail++;
	successString(c3accept, t7) == false ? pass++ : fail++;
	successString(c3accept, t8) == false ? pass++ : fail++;
	successString(c3accept, t9) == false ? pass++ : fail++;
	successString(c3accept, t10) == false ? pass++ : fail++;
	successString(c3accept, t11) == false ? pass++ : fail++;
	successString(c3accept, t12) == false ? pass++ : fail++;
	if(fail >0)
	{
		cout << "Task 10 function had 1 or more failed functions!/n";
	}
	
	return 0;
}

















