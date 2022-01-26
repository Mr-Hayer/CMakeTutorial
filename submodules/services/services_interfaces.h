#ifndef _SERVICES_INTERFACES_H_
#define _SERVICES_INTERFACES_H_

#include "services_platformdef.h"
#include <stdint.h>

struct IServices
{
    virtual void CALLTYPE ServiceInfo() = 0;
};

#ifdef RAW_INTERFACE_SERVICES
struct IRawServices
{
    virtual void CALLTYPE ServiceInfoR() = 0;
};
#endif

class CServiceIp : public IServices
#ifdef RAW_INTERFACE_SERVICES
, public IRawServices
#endif
{
    public:
    CServiceIp() noexcept;

    /*IServices*/
    virtual void CALLTYPE ServiceInfo() override;

    /*IRawServices*/
    #ifdef RAW_INTERFACE_SERVICES
    virtual void CALLTYPE ServiceInfoR() override;
    #endif

    private:
    unsigned char m_Address[4] = {0,0,0,0};
};

#endif