#ifndef DFA_HPP
#define DFA_HPP

#include "String.hpp"
#include "Char.hpp"
#include "Alpha.hpp"
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;
template <class State>
class DFA
{
	public:
		
		//Initial state
		State q0;
		//States
		std::function<bool(State)> Q;
		//Transitions
		std::function<State(State, Char)> delta;
		//Accepting states
		std::function<bool(State)> F;
		
		DFA(std::function<bool(State)> Q, State q0, std::function<State(State, Char)> delta, std::function<bool(State)> F) :Q(Q), q0(q0), delta(delta), F(F) {};
		
		bool checks(Str s)
		{
			int len = s.length();
			State qi = q0;
			int i = 0;
			while(i < len)
			{
				qi = delta(qi, s[i]);
			}
			return F(qi);
		}
		Str findstr(Alpha bet)
		{
			Str strong(bet);
			vector<State> passed;
			State qi = q0;
			return searchin(vector<State> passed, State qi, Str strong, Alpha bet);
		}
			
	private:
		Str searchalg(vector <State> passed, State qi, Str strong, Alpha bet)
		{
			typename vector<State>::iterator run;
			run = find(passed.begin(), passed.end(), qi);
			if(run != passed.end())
			{
				strong.pop_back();
				return strong;
			}
			
			else if(F(qi))
			{
				return strong;
			}
			
			else
			{
				passed.push_back(qi);
				Str strong2(bet);
				for(int i=0; i<bet.size(); i++)
				{
					State qnext = delta(qi, bet[i]);
					Str strong3 = strong;
					strong3.add(bet[i]);
					passed.push_back(qi);
					strong2 = searchalg(passed, qnext, strong3, bet);
					if(accepts(strong2))
					{
						break;
					}
				}
				return strong2;
			}
			
		}
};
#endif