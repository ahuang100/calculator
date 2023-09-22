#ifndef ENTITY
#define ENTITY 

#include<queue> 
#include<string> 


using namespace std; 

class Entity
{
public:
	Entity();
	Entity(char ty, char op, double ent_double, int prec);
	char get_entity_type();
	char get_entity_operator();
	double get_entity_double();
	int get_entity_precedence(); 
	void set_entity_type(char target);
	void set_entity_operator(char target);
	void set_entity_double(double target);

private:
	//entity_type will have special characters to designate typeof operator/operand, char 0 = double, char 1 = operator 
	char entity_type;
	char entity_operator;
	double entity_double;
	//2 will be mult/divide prec, 1 will be add/subtract prec
	int precedence; 
};



#endif ENTITY 