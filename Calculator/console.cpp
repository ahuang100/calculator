#include "console.h" 

Console::Console()
{
	operation_sequence = ""; 
}

void Console::Display_Operation()
{
	cout << "Calculator 1.0.0. Please review the readme for operational usage. Enter desired operation" << endl;
}

queue<Entity> Console::Process_Operation()
{
	getline(cin, operation_sequence);

	//clearing whitespaces
	operation_sequence.erase(remove_if(operation_sequence.begin(), operation_sequence.end(), isspace), operation_sequence.end()); //using cctype library function, remove all spaces 
	//get string length after clear
	int op_length = operation_sequence.length();

	//classify numbers and operators 

	queue<Entity> current_infix_exp;
	string number; 
	int i = 0;

	//tokenize
	while(i < op_length)
	{
		//while current char is digit, process digit chars until operator is reached or when we hit last char 
			while ((operation_sequence[i] >= 48 && operation_sequence[i] <= 57) && (i != op_length - 1))
			{
				//updating number string 
				number += operation_sequence[i];
				//move to next char
				i++;
			}
			//if on last char, process last char to see if it is a digit or an operator 
			if (i == op_length - 1)
			{
				//if last char is a digit, append to current number string and terminate
				if (isdigit(operation_sequence[i]))
				{
					number += operation_sequence[i];
					double final = stod(number); 
					current_infix_exp.push(Entity('0', 'i', final, 0));
					//break out of processing 
					break; 
				}
				//else, terminate current number string and push last operator 
				else
				{
					if (number != "") //edge case, make sure we are not pushing "" number
					{
						double final = stod(number);
						//pushing current number
						current_infix_exp.push(Entity('0', 'i', final, 0));
					}
					//pushing last operator
					if (operation_sequence[i] == '*' || operation_sequence[i] == '/')
						current_infix_exp.push(Entity('1', operation_sequence[i], 0, 2));
					else if(operation_sequence[i] == '+' || operation_sequence[i] == '-')
						current_infix_exp.push(Entity('1', operation_sequence[i], 0, 1));
					else //parantheses 
						current_infix_exp.push(Entity('1', operation_sequence[i], 0, 0));
					//break out of processing 
					break; 
				}
			}
			//if not on last char, process current finished number and move to next char (edge case: make sure we are not pushing "" number) 
			else
			{
				if (number != "")
				{
					double final = stod(number);
					//push into queue 
					current_infix_exp.push(Entity('0', 'i', final, 0));
					//clear number
					number = "";
				}
			}

			//while chars are operators and end is not reached, process 
			while ((!isdigit(operation_sequence[i])) && (i != op_length - 1))
			{
				//pushing operator
				if (operation_sequence[i] == '*' || operation_sequence[i] == '/')
					current_infix_exp.push(Entity('1', operation_sequence[i], 0, 2));
				else if (operation_sequence[i] == '+' || operation_sequence[i] == '-')
					current_infix_exp.push(Entity('1', operation_sequence[i], 0, 1));
				else //parantheses 
					current_infix_exp.push(Entity('1', operation_sequence[i], 0, 0));
				//move to next char 
				i++; 
			}

	}

	//*OMIT debug tokenizer
	//queue<Entity> debug = current_infix_exp;
	//while (debug.size() != 0)
	//{
	//	if (debug.front().get_entity_type() == '0')
	//	{
	//		cout << debug.front().get_entity_double() << " ";
	//		debug.pop();
	//	}
	//	else
	//	{
	//		cout << debug.front().get_entity_operator() << " ";
	//		debug.pop();
	//	}
	//}
	
	queue<Entity> postfix_exp; 
	stack<Entity> operator_stack; 

    //preprocess into operators/operand stack (assumes that input has correct notation) follows PEMDAS behavior 
	while(current_infix_exp.size() != 0)
	{
		//attach operand into postfix_exp if digit 
		if (current_infix_exp.front().get_entity_type() == '0')
		{
			postfix_exp.push(current_infix_exp.front()); 
			current_infix_exp.pop();
		}
		else if (current_infix_exp.front().get_entity_operator() == '(')
		{
			operator_stack.push(current_infix_exp.front());
			current_infix_exp.pop(); 
		}
		else if (current_infix_exp.front().get_entity_operator() == ')')
		{
			//remove the ')'
			current_infix_exp.pop(); 
			//pop until '(' is reached 
			while (operator_stack.top().get_entity_operator() != '(')
			{
				postfix_exp.push(operator_stack.top()); 
				operator_stack.pop(); 
			}
			//pop '(' 
			operator_stack.pop(); 
		}
		//operators and precedence 
		else
		{
			//if operator stack is empty or if top of stack is (
			if ((operator_stack.size() == 0) || (operator_stack.top().get_entity_operator() == '('))
			{
				operator_stack.push(current_infix_exp.front());
				current_infix_exp.pop();
			}
			else if (current_infix_exp.front().get_entity_precedence() > operator_stack.top().get_entity_precedence())
			{
				operator_stack.push(current_infix_exp.front());
				current_infix_exp.pop(); 
			}
			else
			{
				postfix_exp.push(operator_stack.top()); 
				operator_stack.pop(); 
			}
		}
	}
	
	while (operator_stack.size() != 0)
	{
		postfix_exp.push(operator_stack.top()); 
		operator_stack.pop(); 
	}

	return postfix_exp; 
}



void Console::Display_Answer(double numeric_answer)
{
	cout << "Answer: " << numeric_answer << endl; 
}
