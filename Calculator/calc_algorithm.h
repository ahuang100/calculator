#ifndef CALC_ALGORITHM
#define CALC_ALGORITHM 

#include "Entity.h" 
#include "console.h" 
#include <queue> 
#include <stack> 


using namespace std; 

class calc_algorithm
{
public: 
	calc_algorithm(); 
	void post_fix_calculation(queue<Entity> post_fix_exp); 
	double get_numeric_answer(); 
private: 
	double numeric_answer; 

};






#endif