.gba
.thumb
.open "BPRE.gba","build/rom_BPRE.gba", 0x08000000
//---------------------------------------------------

//0803dac4 g 000002d4 CreateBoxMon
.align 2
.org (CreateBoxMon & 0xFFFFFFFE)
.area 0x2d4, 0xFF
.importobj "build/src/CreateBoxMon_lnk.o"
//.pool
.endarea

//0803e3e8 l 00000092 CalculateBoxMonChecksum
.align 2
.org (CalculateBoxMonChecksum & 0xFFFFFFFE)
.area 0x092, 0xFF
.importobj "build/src/CalculateBoxMonChecksum.o"
//.pool
.endarea

//0803f940 l 000002a8 GetSubstruct
.align 2
.org (GetSubstruct & 0xFFFFFFFE)
.area 0x2a8, 0xFF
.importobj "build/src/GetSubstruct.o"
//.pool
.endarea

//0803fd44 g 00000636 GetBoxMonData
.align 2
.org (GetBoxMonData & 0xFFFFFFFE)
.area 0x636, 0xFF
.importobj "build/src/GetBoxMonData.o"
//.pool
.endarea

//080404d0 g 00000638 SetBoxMonData
.align 2
.org (SetBoxMonData & 0xFFFFFFFE)
.area 0x638, 0xFF
.importobj "build/src/SetBoxMonData.o"
//.pool
.endarea

.close

/*.align 4
.org 0x08FF0000
.importobj "build/linked.o"
.close*/
