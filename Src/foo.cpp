#include "foo.h"
#include <iostream>

int func1()
{
	return -1;
}

void func2()
{
	std::cout<<__FUNCTION__<<'\n';
}
