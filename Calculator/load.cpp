#include "load.h" 

//



load::load()
{
	current_answer = 0; 
	Console calculator;
	calc_algorithm engine; 
	//keep calculator running *note, find way to terminate upon user input 
	while (1 == 1)
	{
		calculator.Display_Operation();
		engine.post_fix_calculation(calculator.Process_Operation());
		calculator.Display_Answer(engine.get_numeric_answer());
	}
}