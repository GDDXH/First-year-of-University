#include "c_basis.h"

void C_basis::inputWhen(string w)
{
	when = w;
}

void C_basis::inputWhere(string w)
{
	where = w;
}
string C_basis::getName()const
{
	return name;
}
void C_basis::inputName(string n)
{
	name = n;
}