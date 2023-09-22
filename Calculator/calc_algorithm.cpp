#include "calc_algorithm.h"

calc_algorithm::calc_algorithm()
{
	numeric_answer = 0; 
}

void calc_algorithm::post_fix_calculation(queue<Entity> post_fix_exp)
{
	stack<double> operand_stack; 
	double operand_1; 
	double operand_2; 
	double current_answer; 
	char operator_func; 

	while (post_fix_exp.size() != 0)
	{
		//if current queue item is an operand place in operand stack 
		if (post_fix_exp.front().get_entity_type() == '0')
		{
			operand_stack.push(post_fix_exp.front().get_entity_double());
			post_fix_exp.pop(); 
		}
		if (post_fix_exp.size() == 0)
			break; 
		//if current queue item is operator, pop 2 items off stack/ apply operation 
		if (post_fix_exp.front().get_entity_type() == '1' && (operand_stack.size() >= 2))
		{
			operand_1 = operand_stack.top();
			operand_stack.pop(); 
			operand_2 = operand_stack.top(); 
			operand_stack.pop(); 
			//operation 
			operator_func = post_fix_exp.front().get_entity_operator();
			switch (operator_func) {
			case '+': 
				current_answer = operand_2 + operand_1; 
				operand_stack.push(current_answer); 
				break;
			case '-': 
				current_answer = operand_2 - operand_1;
				operand_stack.push(current_answer);
				break;
			case '*': 
				current_answer = operand_2 * operand_1;
				operand_stack.push(current_answer);
				break;
			case '/': 
				current_answer = operand_2 / operand_1;
				operand_stack.push(current_answer);
				break;
			}
			post_fix_exp.pop();
		}
	}
	//update answer
	numeric_answer = operand_stack.top();
}

double calc_algorithm::get_numeric_answer()
{
	return numeric_answer; 
}