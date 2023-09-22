#ifndef CONSOLE
#define CONSOLE

#include <iostream> 
#include <string>
#include <stack> 
#include <queue>
#include <cctype> 
#include <algorithm>

#include "Entity.h" 

using namespace std; 




class Console
{
public: 
	Console(); 
	void Display_Operation(); 
	queue<Entity> Process_Operation(); 
	void Display_Answer(double numeric_answer); 

private: 
	string operation_sequence; 
};








#endif