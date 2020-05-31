#ifndef DFA_HPP
#define DFA_HPP

#include "String.hpp"
#include "Char.hpp"
#include "Alpha.hpp"
#include <functional>
#include <utility>
#include <vector>

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
		
		bool accepts(Str s)
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
		
		//Goes through the same process as the accepts function but also grabs every state along the way
		vector<pair<State, Char>> acceptsandstates(Str s)
		{
			vector<pair<State, Char>> states;
			int len = s.length();
			State qi = q0;
			int i = 0;
			while(i < len)
			{
				qi = delta(qi, s[i]);
				states.push_back(pair<State  Char>(qi, s[i]));
				i++;
			}
			return states;
		}
	private:
		
};
#endif