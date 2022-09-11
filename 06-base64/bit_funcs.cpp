#include "bit_funcs.h"
#include <cstdint>

#define readbit(byte,add) (((byte)&(add)) ? 1 : 0)
#define SetBit(Register,Bit)		( Register|=(Bit))
#define ClrBit(Register,Bit)		( Register&=(~(Bit)))
#define CplBit(Register,Bit)		( Register^=(Bit))
#define sbi(port,bit)				(port |=  (1<<(bit)))
#define cbi(port,bit)				(port &= ~(1<<(bit)))
#define rbi(port,bit)				(port & (1<<(bit)))

bool get_bit(uint8_t *data, uint16_t bitoffset)
{
	return ( (1 << (bitoffset & 7)) & data[bitoffset >> 3] ) ? 1 : 0 ; // X&7 is X%8 , X>>3 is X/8
}

uint8_t get_bits(uint8_t* data, uint16_t bitOffset, uint8_t numBits)
{
    uint8_t bits = 0;
	if ( numBits == 0 )
		return 0;
    for (uint16_t currentbit = bitOffset + (numBits-1) ; currentbit >= bitOffset; currentbit--)
    {
    	bits = bits << 1;
    	bits = bits | get_bit(data, currentbit);
		if( currentbit == 0 )
			break;
    }
    return bits;
}
void bitcpy(uint8_t* source,uint16_t sourceOffset,uint8_t* dest, uint16_t destOffset, uint16_t noBits)
{
	for (uint16_t i = 0 ; i < noBits ; i++)
	{
		if ( get_bit(source, i + sourceOffset) )
			sbi(dest[(destOffset+i)>>3],(i+destOffset)&7);
		else
			cbi(dest[(destOffset+i)>>3],(i+destOffset)&7);
	}

}
// this function copy "noBits" bits from " LSB of source " to " bitOffset Bit of dest "
void put_bits(uint8_t source,uint8_t noBits,uint8_t *dest,uint16_t bitOffset)
{
	for (uint8_t i = 0 ; i < noBits ; i++)
	{
		if ( get_bit(&source, i) )
			sbi(dest[(bitOffset+i)>>3],(i+bitOffset)&7);
		else
			cbi(dest[(bitOffset+i)>>3],(i+bitOffset)&7);
	}
}

void bit_memset(uint8_t *array,uint16_t bitOffset,uint16_t len,bool value)
{
	for (uint8_t i = 0 ; i < len ; i++)
	{
		if ( value )
			sbi(array[(bitOffset+i)>>3],(i+bitOffset)&7);
		else
			cbi(array[(bitOffset+i)>>3],(i+bitOffset)&7);
	}
}

uint16_t CheckForZeroBitsInBuff(uint8_t *buff,uint16_t Bitlen)
{
 uint16_t NoCmpltByte=0,i,NoZeros=0;
 uint8_t NoBitsInLastByte=0;
 NoCmpltByte=Bitlen/8;
 NoBitsInLastByte=Bitlen%8;
 for (i=0;i<NoCmpltByte;i++) NoZeros+=CountZeroBitsInByte(buff[i],8);
NoZeros+= CountZeroBitsInByte(buff[i],NoBitsInLastByte);
return NoZeros;
}

uint8_t CountZeroBitsInByte(uint8_t Byte,uint8_t BitsInByte)
{
 uint8_t NoZeros=0,i;
 for (i=0;i<BitsInByte;i++)
 {
    if ( ((1<<i)&Byte) == 0 ) NoZeros++;
 }
 return NoZeros;
}

uint16_t CheckForSetBitsInBuff(uint8_t *buff,uint16_t Bitlen)
{
 uint16_t NoCmpltByte=0,i,No=0;
 uint8_t NoBitsInLastByte=0;
 NoCmpltByte=Bitlen/8;
 NoBitsInLastByte=Bitlen%8;
 for (i=0;i<NoCmpltByte;i++) No +=CountSetBitsInByte(buff[i],8);
No+= CountSetBitsInByte(buff[i],NoBitsInLastByte);
return No;
}

uint8_t CountSetBitsInByte(uint8_t Byte,uint8_t BitsInByte)
{
 uint8_t no=0,i;
 for (i=0;i<BitsInByte;i++)
 {
    if ( ((1<<i)&Byte) ) no++;
 }
 return no;
}

bool EventCheckBitInByte(uint8_t refByte,uint8_t refBit,uint8_t *tempByte,uint8_t tempBit,uint8_t ev4one,uint8_t ev4zero,uint8_t *EventCode)
{
	if( (readbit(refByte,refBit)) != (readbit((*tempByte),tempBit)) )
   	{
    	CplBit((*tempByte),tempBit);
        if (refByte&refBit) (*EventCode)=ev4one;
     	else (*EventCode)=ev4zero;
   		return true;
   	}
    return false;
}

uint8_t MergeSubniblesToByte(uint8_t subnible_3, uint8_t subnible_2, uint8_t subnible_1, uint8_t subnible_0)
{
   // declare local variables
   uint8_t data;

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
uint16_t MergeBytesToWord(uint8_t highByte, uint8_t lowByte)
{
   // declare local variables
   uint16_t data;

   // get high byte
   data = highByte;
   // shift left
   data <<= 8;
   // merge low byte
   data |= lowByte;

   // return word
   return data;
}
