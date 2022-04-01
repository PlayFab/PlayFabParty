#include "pch.h"

#ifdef _WIN32
void
DebugLogWin(
    const char* format,
    ...
    )
{
    char buffer[2048]{};
    va_list args;
    va_start(args, format);
    vsprintf_s(buffer, _countof(buffer), format, args);
    va_end(args);

    OutputDebugStringA(buffer);
}
#endif // _WIN32
