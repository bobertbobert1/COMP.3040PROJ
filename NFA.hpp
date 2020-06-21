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

class NFA
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
	
	NFA<State> convert(DFA<State> d)
	{
		return NFA<State>(d.Q, d.q0, d.delta, d.F);
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

template <class State>
class ttree;
	
template <class State>
class ttree
{
	public
	ttree(State s, Char trans, bool status, vector<ttree> kids) : s(s), trans(trans) status(status), kids(kids)();
	
	State s;
	Char trans;
	bool status;
	vector<ttree> kids;	
	
};

template <class State>
ttree<State> forkalg(NFA<State> n, Str s, State qi)
{
	vector<ttree<State>> kids;
	vector<State> epsilon = n.delta(qi, Char(-1));
	for(int i = epsilon.begin(); i != epsilon.end();i++)
	{
		kids.push_back(forkalg(n,s,*i));
	}
	
	if(s.length()!=0)
	{
		Char c = s.front();
		vector<State> next = n.delta(qi,c);
		s.pop_front();
		for(int i=next.begin();i!=next.end();i++)
		{
			kids.push_back(forkalg(n,s,*i));
		}
		return ttree<State>(qi,c,n.F(qi),kids);
		
	}
	return ttree<State>(qi,Char(-1),n.F(qi),kids);
}
	
template<class State>
ttree<State> fork(NFA<State> n, Str s)
{
	return forkalg(n,s,n.q0);
}

template <class State>
bool backtrackalg(NFA<State> n, Str s, State qi)
{
	vector<State> epsilon = n.delta(qi,Char(-1));
	for(int i = epsilon.begin();i!=epsilon.end();i++)
	{
		if(backtrackalg(n,s,*i))
		{
			return true;
		}
	}
	
	int size = s.length();
	if(size>0)
	{
		Char c = s.front();
		vector<State> next = n.delta(qi,c);
		s.pop_front();
		for(int i=next.begin();i!=next.end();i++)
		{
			if(backtrackalg(n,s,*i))
			{
				return true;
			}
		}
	}
	
	if(size<=0)
	{
		return n.F(qi);
	}
	return false;
}

template<class State>
bool backtrack(NFA<State> n, Str s)
{
	return backtrackalg(n,s,n.q0);
}
	
	
	
	
	
	
	
	
	
	
	
	