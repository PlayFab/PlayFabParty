#include <stdint.h>
#include <stdio.h>

#include <PartyTypes.h>
#include <Party_c.h>

int
__cdecl
wmain()
{
    PartyError error;
    PARTY_HANDLE partyHandle;
    if (PARTY_FAILED(error = PartyInitialize("DummyId", &partyHandle)))
    {
        printf("Party instance failed to initialize! (err=0x%08x)\n", error);
        return error;
    }

    printf("Initialized Party instance. handle=0x%p\n", partyHandle);

    if (PARTY_FAILED(error = PartyCleanup(partyHandle)))
    {
        printf("Party instance failed to cleanup! (err=0x%08x)\n", error);
        return error;
    }

    puts("Cleaned up Party instance.");
    return error;
}
