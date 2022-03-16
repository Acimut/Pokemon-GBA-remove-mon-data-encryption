__aeabi_idiv     = 0x081e3b68|1;
__aeabi_idivmod  = 0x081e3b68|1;
__aeabi_uidiv    = 0x081e3b68|1;
__aeabi_uidivmod = 0x081e3b68|1;
__divsi3  = 0x081e4018|1;
__udivsi3 = 0x081e460c|1;
__umodsi3 = 0x081e4684|1;
memcpy    = 0x081e5e78|1;
memset    = 0x081e5ed8|1;
strcmp    = 0x081e5f2c|1;
strcpy    = 0x081e5f88|1;
memmove   = 0x081e8e60|1;

/* CreateBoxMon */
/*gBaseStats const struct BaseStats -> usar un puntuero*/
gBaseStatsPtr       = 0x080001BC;
ZeroBoxMonData      = 0x0803d97c|1;
gSaveBlock2Ptr      = 0x0300500c;/*IWRAM*/
GetSpeciesName      = 0x08040fd0|1;
Random              = 0x08044ec8|1;
gExperienceTables   = 0x08253ae4;/*const u32*/
gGameLanguage       = 0x081e9f11;/*const u8*/
gGameVersion        = 0x081e9f10;/*const u8*/
GetCurrentRegionMapSectionId = 0x08056260|1;
GiveBoxMonInitialMoveset     = 0x0803e9e0|1;/*static*/

/*CalculateBoxMonChecksum*/
/*GetSubstruct*/

/*GetBoxMonData*/
gText_BadEgg        = 0x083fe868;/*const u8*/
gText_EggNickname   = 0x08415a62;/*const u8*/
StringCopy          = 0x08008d84|1;
StringLength        = 0x08008e08|1;
gBitTable           = 0x0825e45c;/*const u32*/

/*SetBoxMonData*/

CreateBoxMon            = 0x0803dac4|1;
CalculateBoxMonChecksum = 0x0803e3e8|1;
GetSubstruct            = 0x0803f940|1;
GetBoxMonData           = 0x0803fd44|1;
SetBoxMonData           = 0x080404d0|1;

