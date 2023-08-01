#include <jni.h>
#include <memory>
#include <thread>
#include <errno.h>

#include "PartyPal.h"
#include "Party.h"

#include "NetworkManager.h"
#include "NetworkStateChangeManager.h"
#include "Managers.h"
#include "LanguageOptions.h"

#define RETURN_VOID_IF(expr) \
    do {                     \
        if (expr)            \
        {                    \
            return;          \
        }                    \
    } while (false)          \


#define RETURN_VOID_IF_FALSE(expr) \
    do {                           \
        if (!(expr))               \
        {                          \
            return;                \
        }                          \
    } while (false)                \

#define RETURN_IF(expression, retVal)  \
    do { \
        bool expr = (expression); \
        if (expr) \
        { \
            return (retVal); \
        } \
    } while (false)       \

#ifndef __APPLE__
typedef int errno_t;
#endif

inline errno_t fopen_s(FILE **file, const char *filename, const char *mode)
{
    *file = fopen(filename, mode);
    return *file == nullptr ? errno : 0;
}