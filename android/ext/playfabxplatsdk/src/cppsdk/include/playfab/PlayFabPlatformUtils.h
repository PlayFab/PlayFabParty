#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
// BUMBLELION: Avoid streams for memory leaking issues with CRT
//#include <sstream>

namespace PlayFabInternal
{
#if defined(PLAYFAB_PLATFORM_SWITCH)
    static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#else
    typedef std::chrono::system_clock Clock;
    typedef std::chrono::time_point<Clock> TimePoint;
#endif

    // The primary purpose of these format strings is to communicate to and from the PlayFab server with consistent accuracy across platforms supported by this SDK
    constexpr char TIMESTAMP_READ_FORMAT[] = "%Y-%m-%dT%T";
    constexpr char TIMESTAMP_WRITE_FORMAT[] = "%Y-%m-%dT%H:%M:%S.000Z";
    constexpr int TIMESTAMP_BUFFER_SIZE = 64; // Arbitrary number sufficiently large enough to contain the timestamp strings sent by PlayFab server

    // BUMBLELION: iso8601chartable, iso8601StateTable, and Iso8601StringToSystemTime(...) below are copied from 
    //             existing Iso8601 parser implementations in the OS repo (search "file:iso8601.*"). They are here
    //             so that we can avoid using C++ STL streams for parsing time values returned from the service.
    //             As soon as we use C++ STL streams, we will begin to leak memory post Cleanup() due to performance 
    //             optimizations in the CRT. An analog to Windows' SYSTEMTIME is also typedef'd as PFPU_SYSTEMTIME 
    //             so this can work crossplatform.

    typedef struct _PFPU_SYSTEMTIME {
        uint16_t wYear;
        uint16_t wMonth;
        uint16_t wDayOfWeek;
        uint16_t wDay;
        uint16_t wHour;
        uint16_t wMinute;
        uint16_t wSecond;
        uint16_t wMilliseconds;
    } PFPU_SYSTEMTIME;

    // This code implements a parser & generater for the ISO 8601 date format.

    // This table defines different "types" of characters for use as the columns
    // of the state table
    constexpr unsigned char iso8601chartable[256] =
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0x82, 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };

    // State table
    // 0x80 bit = Error
    // 0x20 = Add character & advance to next field
    // 0x40 = Add character & advance to next field + skip one (for day of week)
    // 0x1f = Mask to determine next state #

    // Columns = input character type: unknown, number, "-", "T", ":", "Z"
    constexpr int STATE_TABLE_COLS = 6;
    constexpr int STATE_TABLE_ROWS = 19;
    constexpr unsigned char iso8601StateTable[STATE_TABLE_ROWS][STATE_TABLE_COLS] =
    {
        { 0x80, 0x01, 0x25, 0x80, 0x80, 0x80 }, // year
        { 0x80, 0x02, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x03, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x24, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x06, 0x05, 0x85, 0x85, 0x05 }, //0x04 month
        { 0x80, 0x06, 0x48, 0x80, 0x80, 0x80 },
        { 0x80, 0x47, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x09, 0x08, 0x88, 0x88, 0x08 }, //0x07 day
        { 0x80, 0x09, 0x8b, 0x2b, 0x8b, 0x80 },
        { 0x80, 0x2a, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x0c, 0x8b, 0x0b, 0x8b, 0x08 }, //0x0a hour
        { 0x80, 0x0c, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x2d, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x0f, 0x8e, 0x8e, 0x0e, 0x08 }, //0x0d min
        { 0x80, 0x0f, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x30, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x12, 0x91, 0x91, 0x11, 0x08 }, //0x10 sec
        { 0x80, 0x12, 0x80, 0x80, 0x80, 0x80 },
        { 0x80, 0x30, 0x80, 0x80, 0x80, 0x80 }
    };

    // Convert a character string formatted as iso8601 into a SYSTEMTIME structure
    // Supports both basic & extended forms of iso8601.
    // isoDate: Input string. It can be null or space terminated.

    inline PFPU_SYSTEMTIME Iso8601StringToSystemTime(const char* pszisoDate)
    {
        PFPU_SYSTEMTIME systemTime;
        memset(&systemTime, 0, sizeof(PFPU_SYSTEMTIME));
        if (NULL == pszisoDate)
        {
            return systemTime;
        }

        // Main state machine loop. Loop until a space or null.
        uint16_t* dateWords = (uint16_t*)&systemTime;
        uint16_t* endWord = dateWords + 7;    // To detect the end of the date
        int state = 0;
        while (*pszisoDate && *pszisoDate != ' ')
        {
            // BUMBLELION: This code was changed from the OS repo source it was taken from;
            // GCC was throwing `-Wchar-subscripts` errors, as the original OS code was attempting
            // to index into an array with just a `char` type. Specifying the signing of the `char`
            // fixes this error.
            // The sign-bit is masked in the following code so the change is safe.
            unsigned char code = iso8601chartable[static_cast<unsigned char>(*pszisoDate)];
            if (code & 0x80)
            {
                code = code & 0x7f;
            }

            if ((code >= STATE_TABLE_COLS) ||
                (state >= STATE_TABLE_ROWS))
            {
                return systemTime;
            }

            if (code == 1)    // The character code 1 is always a number which gets accumulated
            {
                *dateWords = *dateWords * 10 + *pszisoDate - '0';
            }

            unsigned char action = iso8601StateTable[state][code];
            state = action & 0x1f;    // Calculate the next state
            switch (action >> 5)
            {
                case 0x1:
                {
                    dateWords++;
                    break;
                }
                case 0x2:    // Finish piece & advance twice (past day of week)
                {
                    dateWords += 2;
                    break;
                }
            }

            if (dateWords > endWord)    // Prevent an overflow
            {
                return systemTime;
            }
                        
            pszisoDate++;
        }

        return systemTime;
    }

    // Initialize may be required on some platforms
    inline void InitializeClock()
    {
#if defined(PLAYFAB_PLATFORM_SWITCH)
        static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#endif
    }

    // Time type conversions
    inline time_t TimePointToTimeT(const TimePoint& input)
    {
        return Clock::to_time_t(input);
    }

    inline TimePoint TimeTToTimePoint(time_t input)
    {
        return Clock::from_time_t(input);
    }

    inline tm TimeTToUtcTm(time_t input)
    {
        // BUMBLELION: Use memset to zero the struct instead of an initializer list so our (old) Android compilation tools don't break
        tm timeInfo;
        memset(&timeInfo, 0, sizeof(tm));
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        gmtime_s(&input, &timeInfo);
#elif defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
        gmtime_s(&timeInfo, &input);
#else
        gmtime_r(&input, &timeInfo);
#endif
        return timeInfo;
    }

    inline time_t UtcTmToTimeT(tm input)
    {
#if defined(PLAYFAB_PLATFORM_PLAYSTATION)
        return mktime(&input);
#elif defined(PLAYFAB_PLATFORM_WINDOWS) || defined(PLAYFAB_PLATFORM_XBOX)
        return _mkgmtime(&input);
#else
        return timegm(&input);
#endif
    }

    inline tm TimePointToUtcTm(const TimePoint& input)
    {
        return TimeTToUtcTm(Clock::to_time_t(input));
    }

    inline TimePoint UtcTmToTimePoint(const tm& input)
    {
        return TimeTToTimePoint(UtcTmToTimeT(input));
    }

    // Get Time now - Platform dependent granularity (granularity: upto 1 second, accuracy within a few seconds)
    inline TimePoint GetTimePointNow()
    {
        // The conversion is mostly to ensure consistent behavior among all platforms
        return std::chrono::time_point_cast<std::chrono::seconds>(Clock::now());
    }

    inline time_t GetTimeTNow()
    {
        return TimePointToTimeT(GetTimePointNow());
    }

    // Get a tick count that represents now in milliseconds (not useful for absolute time)
    inline Int64 GetMilliTicks()
    {
#if defined(PLAYFAB_PLATFORM_SWITCH)
        static_assert("You must request the Nintendo specific XPlat SDK from PlayFab support.");
#else
        auto msClock = std::chrono::time_point_cast<std::chrono::milliseconds>(Clock::now());
        return msClock.time_since_epoch().count();
#endif
    }

    // Time Serialization
    inline std::string UtcTmToIso8601String(const tm& input)
    {
        char buff[TIMESTAMP_BUFFER_SIZE];
        strftime(buff, TIMESTAMP_BUFFER_SIZE, TIMESTAMP_WRITE_FORMAT, &input);
        return buff;
    }

    // BUMBLELION: Completely rewrite this function to avoid using STL stream functionality because Windows CRT will
    //             leak a locale object by design if we do
    inline tm Iso8601StringToTm(const std::string& utcString)
    {
        PFPU_SYSTEMTIME systemTime = Iso8601StringToSystemTime(utcString.c_str());        

        // BUMBLELION: Use memset to zero the struct instead of an initializer list so our (old) Android compilation tools don't break
        tm timeInfo;
        memset(&timeInfo, 0, sizeof(tm));
        timeInfo.tm_sec = systemTime.wSecond;
        timeInfo.tm_min = systemTime.wMinute;
        timeInfo.tm_hour = systemTime.wHour;
        timeInfo.tm_mday = systemTime.wDay;
        timeInfo.tm_mon = systemTime.wMonth - 1;
        timeInfo.tm_year = systemTime.wYear - 1900;
        timeInfo.tm_wday = systemTime.wDayOfWeek;
        timeInfo.tm_isdst = -1;

        return timeInfo;
    }

    inline std::string TimeTToIso8601String(time_t input)
    {
        return UtcTmToIso8601String(TimeTToUtcTm(input));
    }

    inline time_t Iso8601StringToTimeT(const std::string& input)
    {
        return UtcTmToTimeT(Iso8601StringToTm(input));
    }

    // TODO: Invert this conversion at some point, and serialize the milliseconds as well
    inline std::string TimePointToIso8601String(const TimePoint& input)
    {
        return UtcTmToIso8601String(TimePointToUtcTm(input));
    }

    inline TimePoint Iso8601StringToTimePoint(const std::string& input)
    {
        return UtcTmToTimePoint(Iso8601StringToTm(input));
    }
}
