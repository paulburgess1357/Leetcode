#pragma once
#include <iostream>
#include <vector>

template<typename T>
void print(const std::vector<T>& val){

	std::cout << "[ ";
	for(size_t i = 0; i < val.size(); i++){
		std::cout << val.at(i);
		if(i < val.size() - 1){
			std::cout << ", ";
		} else{
			std::cout << " ]" << std::endl;
		}
		
	}
}