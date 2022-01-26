
#include <iostream>

#include "foo.h"
#include "dbgUtils.h"

#include "services_interfaces.h"

int main()
{
	std::cout<<"Hello world!\n";
	std::cout<<"Calling func1 from foo.h: "<<func1()<<'\n';
	func2();
	auto message = formatMsg("formatted message %d %s", 12, "user message");
	printMsg(message.c_str());

	CServiceIp ipservice;
	ipservice.ServiceInfo();

	#ifdef RAW_INTERFACE_SERVICES
	ipservice.ServiceInfoR();
	#endif

	return 0;
}
