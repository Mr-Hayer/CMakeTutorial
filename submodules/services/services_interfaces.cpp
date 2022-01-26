#include <iostream>
#include "services_interfaces.h"

/*CServiceIp*/
CServiceIp::CServiceIp() noexcept
{
    // ctor
}

void CALLTYPE CServiceIp::ServiceInfo()
{
    std::cout<<"I Support IP Services\n";
}

#ifdef RAW_INTERFACE_SERVICES
void CALLTYPE CServiceIp::ServiceInfoR()
{
    std::cout<<"I Support raw IP Services\n";
}
#endif