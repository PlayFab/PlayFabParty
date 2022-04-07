#include "pch.h"

static std::mutex g_logQueueMutex;
_Guarded_by_(g_logQueueMutex) static std::vector<AppLogEntry> g_logQueue;

void
QueueLog(
    const std::string& system,
    const std::string& message
    )
{
    std::lock_guard<std::mutex> g_logLock(g_logQueueMutex);
    g_logQueue.emplace_back(AppLogEntry{system, message});
}

void
QueueLog(
    const std::string& system,
    const char* messageFormat,
    ...
    )
{
    va_list args;
    va_start(args, messageFormat);
    char messageBuffer[2048];
    vsnprintf_s(messageBuffer, _countof(messageBuffer), messageFormat, args);
    va_end(args);

    std::lock_guard<std::mutex> g_logLock(g_logQueueMutex);
    g_logQueue.emplace_back(AppLogEntry{system, messageBuffer});
}

std::vector<AppLogEntry>
DrainLogQueue()
{
    std::lock_guard<std::mutex> g_logLock(g_logQueueMutex);

    std::vector<AppLogEntry> logs;
    if (!g_logQueue.empty())
    {
        // Reserve and swap so that we quickly drain the log queue into a lock free buffer and replace it with a new
        // vector which is already sized to hold at least as many messages.
        logs.reserve(g_logQueue.size());
        std::swap(logs, g_logQueue);
    }

    return logs;
}
