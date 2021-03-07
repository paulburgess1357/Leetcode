#include <iostream>
#include <string>
#include "./ArrayProblems/VerifyingAnAlienDictionary.hpp"

int main(){

	std::string order{ "hlabcdefgijkmnopqrstuvwxyz" };
	std::vector<std::string> words{ "hello","leetcode" };

	Solution run_solution;
	run_solution.isAlienSorted(words, order);
	
}