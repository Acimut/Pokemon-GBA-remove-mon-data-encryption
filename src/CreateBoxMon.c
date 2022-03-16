#include "header.h"

//0803dac4 g 000002d4 CreateBoxMon
void CreateBoxMon_new(struct BoxPokemon *boxMon, u16 species, u8 level, u8 fixedIV, u8 hasFixedPersonality, u32 fixedPersonality, u8 otIdType, u32 fixedOtId)
{
    u8 speciesName[POKEMON_NAME_LENGTH + 1];
    u32 personality;
    u32 value;
    //u16 checksum;

    ZeroBoxMonData(boxMon);

    if (hasFixedPersonality)
        personality = fixedPersonality;
    else
        personality = Random32();

    SetBoxMonData_new(boxMon, MON_DATA_PERSONALITY, &personality);

    //Determine original trainer ID
    if (otIdType == OT_ID_RANDOM_NO_SHINY) //Pokemon cannot be shiny
    {
        u32 shinyValue;
        do
        {
            value = Random32();
            shinyValue = HIHALF(value) ^ LOHALF(value) ^ HIHALF(personality) ^ LOHALF(personality);
        } while (shinyValue < SHINY_ODDS);
    }
    else if (otIdType == OT_ID_PRESET) //Pokemon has a preset OT ID
    {
        value = fixedOtId;
    }
    else //Player is the OT
    {
        value = gSaveBlock2Ptr->playerTrainerId[0]
              | (gSaveBlock2Ptr->playerTrainerId[1] << 8)
              | (gSaveBlock2Ptr->playerTrainerId[2] << 16)
              | (gSaveBlock2Ptr->playerTrainerId[3] << 24);
    }

    SetBoxMonData_new(boxMon, MON_DATA_OT_ID, &value);

    //checksum = CalculateBoxMonChecksum(boxMon);
    //SetBoxMonData_new(boxMon, MON_DATA_CHECKSUM, &checksum);
    //EncryptBoxMon(boxMon);
    GetSpeciesName(speciesName, species);
    SetBoxMonData_new(boxMon, MON_DATA_NICKNAME, speciesName);
    SetBoxMonData_new(boxMon, MON_DATA_LANGUAGE, &gGameLanguage);
    SetBoxMonData_new(boxMon, MON_DATA_OT_NAME, gSaveBlock2Ptr->playerName);
    SetBoxMonData_new(boxMon, MON_DATA_SPECIES, &species);
    SetBoxMonData_new(boxMon, MON_DATA_EXP, &gExperienceTables[gBaseStatsPtr[species].growthRate][level]);
    SetBoxMonData_new(boxMon, MON_DATA_FRIENDSHIP, &gBaseStatsPtr[species].friendship);
    value = GetCurrentRegionMapSectionId();
    SetBoxMonData_new(boxMon, MON_DATA_MET_LOCATION, &value);
    SetBoxMonData_new(boxMon, MON_DATA_MET_LEVEL, &level);
    SetBoxMonData_new(boxMon, MON_DATA_MET_GAME, &gGameVersion);
    value = ITEM_POKE_BALL;
    SetBoxMonData_new(boxMon, MON_DATA_POKEBALL, &value);
    SetBoxMonData_new(boxMon, MON_DATA_OT_GENDER, &gSaveBlock2Ptr->playerGender);

    if (fixedIV < 32)
    {
        SetBoxMonData_new(boxMon, MON_DATA_HP_IV, &fixedIV);
        SetBoxMonData_new(boxMon, MON_DATA_ATK_IV, &fixedIV);
        SetBoxMonData_new(boxMon, MON_DATA_DEF_IV, &fixedIV);
        SetBoxMonData_new(boxMon, MON_DATA_SPEED_IV, &fixedIV);
        SetBoxMonData_new(boxMon, MON_DATA_SPATK_IV, &fixedIV);
        SetBoxMonData_new(boxMon, MON_DATA_SPDEF_IV, &fixedIV);
    }
    else
    {
        u32 iv;
        value = Random();

        iv = value & 0x1F;
        SetBoxMonData_new(boxMon, MON_DATA_HP_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData_new(boxMon, MON_DATA_ATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData_new(boxMon, MON_DATA_DEF_IV, &iv);

        value = Random();

        iv = value & 0x1F;
        SetBoxMonData_new(boxMon, MON_DATA_SPEED_IV, &iv);
        iv = (value & 0x3E0) >> 5;
        SetBoxMonData_new(boxMon, MON_DATA_SPATK_IV, &iv);
        iv = (value & 0x7C00) >> 10;
        SetBoxMonData_new(boxMon, MON_DATA_SPDEF_IV, &iv);
    }

    if (gBaseStatsPtr[species].abilities[1])
    {
        value = personality & 1;
        SetBoxMonData_new(boxMon, MON_DATA_ABILITY_NUM, &value);
    }

    GiveBoxMonInitialMoveset(boxMon);
}

