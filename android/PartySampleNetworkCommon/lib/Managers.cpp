#include "pch.h"
#include "Managers.h"

using namespace PartySample;

// Define the local storage map for the manager classes to access by templatization.
std::map<const char *, std::shared_ptr<Manager>> Managers::m_managersByType;
