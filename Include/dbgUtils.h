#ifndef _DBGUTILS_H_
#define _DBGUTILS_H_

#include <string>
#include <cassert>
// dbg services

template<size_t MaxSize=255, typename ... Args>
std::string formatMsg(const char* fmt, Args&&... args)
{
    char *Buffer = new char[MaxSize]();
    assert(Buffer);

    std::sprintf(Buffer,fmt,args...);
    std::string retval(Buffer);
    delete[] Buffer;
    return retval;
}

void printMsg(const char* message);

#endif