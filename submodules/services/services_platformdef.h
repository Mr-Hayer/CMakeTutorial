#ifndef _SERVICES_PLATFORMDEF_H_
#define _SERVICES_PLATFORMDEF_H_

#if defined(_MSC_VER)
#define CALLTYPE __stdcall
#elif defined(__GNUC__) || defined(__clang__)
#define CALLTYPE
#endif


#endif //_SERVICES_PLATFORMDEF_H_