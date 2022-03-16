#include "header.h"

//0803f940 l 000002a8 GetSubstruct
//static 
union PokemonSubstruct *GetSubstruct_new(struct BoxPokemon *boxMon, u8 substructType)
{
    union PokemonSubstruct *substruct = boxMon->secure.substructs;
    return &substruct[substructType];
}

