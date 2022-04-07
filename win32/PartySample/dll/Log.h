#pragma once

struct AppLogEntry
{
    std::string system;
    std::string message;
};

void
QueueLog(
    const std::string& system,
    const std::string& message
    );

void
QueueLog(
    const std::string& system,
    const char* messageFormat,
    ...
    );

std::vector<AppLogEntry>
DrainLogQueue();
