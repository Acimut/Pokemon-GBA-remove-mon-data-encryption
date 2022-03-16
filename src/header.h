#define IS_POKEMON_C



#include "global.h"
#include "gflib.h"
#include "random.h"
#include "util.h"
#include "overworld.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/moves.h"
#include "constants/songs.h"


//#include "strings.h"
extern const u8 gText_EggNickname[];
extern const u8 gText_BadEgg[];

//puntero a gBaseStats.
extern const struct BaseStats *gBaseStatsPtr;

void CreateBoxMon_new(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId);
u16 CalculateBoxMonChecksum_new(struct BoxPokemon *boxMon);
union PokemonSubstruct *GetSubstruct_new(struct BoxPokemon *boxMon, u8 substructType);//static
void SetBoxMonData_new(struct BoxPokemon *boxMon, s32 field, const void *dataArg);
u32 GetBoxMonData_new(struct BoxPokemon *boxMon, s32 field, u8 *data);


/*static*/
extern void GiveBoxMonInitialMoveset(struct BoxPokemon *boxMon);

