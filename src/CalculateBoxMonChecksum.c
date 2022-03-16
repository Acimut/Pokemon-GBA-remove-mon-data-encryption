#include "header.h"

//0803e3e8 l 00000092 CalculateBoxMonChecksum
//static 
u16 CalculateBoxMonChecksum_new(struct BoxPokemon *boxMon)
{
    u16 checksum = 0;
    union PokemonSubstruct *substruct0 = GetSubstruct_new(boxMon, 0);
    union PokemonSubstruct *substruct1 = GetSubstruct_new(boxMon, 1);
    union PokemonSubstruct *substruct2 = GetSubstruct_new(boxMon, 2);
    union PokemonSubstruct *substruct3 = GetSubstruct_new(boxMon, 3);
    s32 i;

    for (i = 0; i < 6; i++)
        checksum += substruct0->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct1->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct2->raw[i];

    for (i = 0; i < 6; i++)
        checksum += substruct3->raw[i];

    return checksum;
}

