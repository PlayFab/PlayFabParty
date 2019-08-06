//--------------------------------------------------------------------------------------
// Config.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#ifndef Config_h
#define Config_h

class Config
{
public:
    static
    int
    GetNameListLength();

    static
    const char**
    GetNameList();

    static
    int
    GetSelectedNameIndex();

    static
    void
    SetSelectedNameIndex(int index);

    static
    const char*
    GetSelectedName();
};
#endif /* Config_h */
