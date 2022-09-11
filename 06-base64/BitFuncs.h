/*
 * BitFuncs.h
 *
 *  Created on: Jul 5, 2020
 *      Author: maddah
 */

#ifndef BITFUNCS_H_
#define BITFUNCS_H_

#include "BasicTypes.h"

void bit_memset(UINT8 *array,UINT16 bitOffset,UINT16 len,BOOLEAN value);
void put_bits(UINT8 source,UINT8 noBits,UINT8 *dest,UINT16 bitOffset);
void bitcpy(UINT8* source,UINT16 sourceOffset,UINT8* dest, UINT16 destOffset, UINT16 noBits);
UINT8 get_bits(UINT8* data, UINT16 bitOffset, UINT8 numBits);
BOOLEAN get_bit(UINT8 *data, UINT16 bitoffset);
UINT16 CheckForZeroBitsInBuff(UINT8 *buff, UINT16 Bitlen);
UINT8 CountZeroBitsInByte(UINT8 Byte, UINT8 BitsInByte);
UINT16 CheckForSetBitsInBuff(UINT8 *buff, UINT16 Bitlen);
UINT8 CountSetBitsInByte(UINT8 Byte, UINT8 BitsInByte);
BOOLEAN EventCheckBitInByte(UINT8 refByte, UINT8 refBit, UINT8 *tempByte,
		UINT8 tempBit, UINT8 ev4one, UINT8 ev4zero, UINT8 *EventCode);
UINT16 MergeBytesToWord(UINT8 highByte, UINT8 lowByte);
UINT8 MergeSubniblesToByte(UINT8 subnible_3, UINT8 subnible_2, UINT8 subnible_1, UINT8 subnible_0);
#endif /* BITFUNCS_H_ */
