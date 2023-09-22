#include "Entity.h" 

Entity::Entity()
{
	//default set all entities to double type 
	entity_type = '0'; 
	entity_operator = '0'; 
	entity_double = 0; 
	precedence = 0; 
}

Entity::Entity(char ty, char op, double ent_double, int prec)
{
	entity_type = ty;
	entity_operator = op;
	entity_double = ent_double;
	precedence = prec; 
}

char Entity::get_entity_type()
{
	return entity_type; 
}

char Entity::get_entity_operator()
{
	return entity_operator; 
}

double Entity:: get_entity_double()
{
	return entity_double; 
}

void Entity::set_entity_type(char target)
{
	entity_type = target;
}

void Entity::set_entity_operator(char target)
{
	entity_operator = target; 
}

void Entity :: set_entity_double(double target)
{
	entity_double = target;
}

int Entity::get_entity_precedence()
{
	return precedence; 
}