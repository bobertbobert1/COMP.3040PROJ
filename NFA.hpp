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
	private:
	
	
}