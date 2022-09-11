/*
 * BitFuncs.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: maddah
 */

#include <BitFuncs.h>
#include "GlobalDef.h"

BOOLEAN get_bit(UINT8 *data, UINT16 bitoffset)
{
	return ( (1 << (bitoffset & 7)) & data[bitoffset >> 3] ) ? 1 : 0 ; // X&7 is X%8 , X>>3 is X/8
}

UINT8 get_bits(UINT8* data, UINT16 bitOffset, UINT8 numBits)
{
    UINT8 bits = 0;
	if ( numBits == 0 )
		return 0;
    for (UINT16 currentbit = bitOffset + (numBits-1) ; currentbit >= bitOffset; currentbit--)
    {
    	bits = bits << 1;
    	bits = bits | get_bit(data, currentbit);
		if( currentbit == 0 )
			break;
    }
    return bits;
}
void bitcpy(UINT8* source,UINT16 sourceOffset,UINT8* dest, UINT16 destOffset, UINT16 noBits)
{
	for (UINT16 i = 0 ; i < noBits ; i++)
	{
		if ( get_bit(source, i + sourceOffset) )
			sbi(dest[(destOffset+i)>>3],(i+destOffset)&7);
		else
			cbi(dest[(destOffset+i)>>3],(i+destOffset)&7);
	}

}
// this function copy "noBits" bits from " LSB of source " to " bitOffset Bit of dest "
void put_bits(UINT8 source,UINT8 noBits,UINT8 *dest,UINT16 bitOffset)
{
	for (UINT8 i = 0 ; i < noBits ; i++)
	{
		if ( get_bit(&source, i) )
			sbi(dest[(bitOffset+i)>>3],(i+bitOffset)&7);
		else
			cbi(dest[(bitOffset+i)>>3],(i+bitOffset)&7);
	}
}

void bit_memset(UINT8 *array,UINT16 bitOffset,UINT16 len,BOOLEAN value)
{
	for (UINT8 i = 0 ; i < len ; i++)
	{
		if ( value )
			sbi(array[(bitOffset+i)>>3],(i+bitOffset)&7);
		else
			cbi(array[(bitOffset+i)>>3],(i+bitOffset)&7);
	}
}

UINT16 CheckForZeroBitsInBuff(UINT8 *buff,UINT16 Bitlen)
{
 UINT16 NoCmpltByte=0,i,NoZeros=0;
 UINT8 NoBitsInLastByte=0;
 NoCmpltByte=Bitlen/8;
 NoBitsInLastByte=Bitlen%8;
 for (i=0;i<NoCmpltByte;i++) NoZeros+=CountZeroBitsInByte(buff[i],8);
NoZeros+= CountZeroBitsInByte(buff[i],NoBitsInLastByte);
return NoZeros;
}

UINT8 CountZeroBitsInByte(UINT8 Byte,UINT8 BitsInByte)
{
 UINT8 NoZeros=0,i;
 for (i=0;i<BitsInByte;i++)
 {
    if ( ((1<<i)&Byte) == 0 ) NoZeros++;
 }
 return NoZeros;
}

UINT16 CheckForSetBitsInBuff(UINT8 *buff,UINT16 Bitlen)
{
 UINT16 NoCmpltByte=0,i,No=0;
 UINT8 NoBitsInLastByte=0;
 NoCmpltByte=Bitlen/8;
 NoBitsInLastByte=Bitlen%8;
 for (i=0;i<NoCmpltByte;i++) No +=CountSetBitsInByte(buff[i],8);
No+= CountSetBitsInByte(buff[i],NoBitsInLastByte);
return No;
}

UINT8 CountSetBitsInByte(UINT8 Byte,UINT8 BitsInByte)
{
 UINT8 no=0,i;
 for (i=0;i<BitsInByte;i++)
 {
    if ( ((1<<i)&Byte) ) no++;
 }
 return no;
}

BOOLEAN EventCheckBitInByte(UINT8 refByte,UINT8 refBit,UINT8 *tempByte,UINT8 tempBit,UINT8 ev4one,UINT8 ev4zero,UINT8 *EventCode)
{
	if( (readbit(refByte,refBit)) != (readbit((*tempByte),tempBit)) )
   	{
    	CplBit((*tempByte),tempBit);
        if (refByte&refBit) (*EventCode)=ev4one;
     	else (*EventCode)=ev4zero;
   		return TRUE;
   	}
    return FALSE;
}

UINT8 MergeSubniblesToByte(UINT8 subnible_3, UINT8 subnible_2, UINT8 subnible_1, UINT8 subnible_0)
{
   // declare local variables
   UINT8 data;

   // get subnible_3
   data = subnible_3;
   // shift left
   data <<= 2;
   // merge subnible_2
   data |= subnible_2;
   // shift left
   data <<= 2;
   // merge subnible_1
   data |= subnible_1;
   // shift left
   data <<= 2;
   // merge subnible_0
   data |= subnible_0;

   // return byte
   return data;
}
UINT16 MergeBytesToWord(UINT8 highByte, UINT8 lowByte)
{
   // declare local variables
   UINT16 data;

   // get high byte
   data = highByte;
   // shift left
   data <<= 8;
   // merge low byte
   data |= lowByte;

   // return word
   return data;
}
