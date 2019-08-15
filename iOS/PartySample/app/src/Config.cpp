//--------------------------------------------------------------------------------------
// Config.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "Config.h"

const char* c_pfTitleId = "";
extern const int c_selectListCount = 4;

static int c_selectedIndex = 0;

// List for selection in the UI:
static const char* c_selectListNames[] = {
    "ios_user_1",
    "ios_user_2",
    "ios_user_3",
    "ios_user_4"
};

int
Config::GetNameListLength()
{
    return c_selectListCount;
}

const char**
Config::GetNameList()
{
    return c_selectListNames;
}

int
Config::GetSelectedNameIndex()
{
    return c_selectedIndex;
}

void
Config::SetSelectedNameIndex(
    int index
    )
{
    c_selectedIndex = index;
}

const char*
Config::GetSelectedName()
{
    if ((c_selectedIndex < 0)
        || (c_selectedIndex >= c_selectListCount))
        return "";
    return c_selectListNames[c_selectedIndex];
}
