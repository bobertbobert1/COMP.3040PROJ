#ifndef NFA_HPP
#define NFA_HPP

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

class NFA_HPP
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
			
		NFA(std::function<bool(State)> Q, State q0, std::function<State(State, Char)> delta, std::function<bool(State)> F) :Q(Q), q0(q0), delta(delta), F(F) {};	
	
	NFA convert(DFA d)
	{
		return NFA(d.Q, d.q0, d.delta, d.F);
	}
	
	bool oracle(vector<pair<State, Char>> trace)
	{
		if(trace.size()>0)
		{
			for(int i=1; i<trace.size();i++)
			{
				vector<State> stated = delta(trace[i-1].first,trace[i].second);
				typename vector<State>::iterator run;
				run = find(stated.begin(),stated.end(),trace[i].first);
				if(run==stated.end())
				{
					return false;
				}
			}
		}
		return true;
	}
	private:
	
	
}