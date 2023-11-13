#ifndef DEFINES_H
#define DEFINES_H

#ifdef WIN32
    #ifndef WINDOWS
    #define WINDOWS
    #endif
#else
    #ifndef UNIX
    #define UNIX
    #endif
#endif

#endif //DEFINES_H
