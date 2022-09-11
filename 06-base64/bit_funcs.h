#ifndef BITFUNCS_H_
#define BITFUNCS_H_

#include <cstdint>

void bit_memset(uint8_t *array,uint16_t bitOffset,uint16_t len,bool value);
void put_bits(uint8_t source,uint8_t noBits,uint8_t *dest,uint16_t bitOffset);
void bitcpy(uint8_t* source,uint16_t sourceOffset,uint8_t* dest, uint16_t destOffset, uint16_t noBits);
uint8_t get_bits(uint8_t* data, uint16_t bitOffset, uint8_t numBits);
bool get_bit(uint8_t *data, uint16_t bitoffset);
uint16_t CheckForZeroBitsInBuff(uint8_t *buff, uint16_t Bitlen);
uint8_t CountZeroBitsInByte(uint8_t Byte, uint8_t BitsInByte);
uint16_t CheckForSetBitsInBuff(uint8_t *buff, uint16_t Bitlen);
uint8_t CountSetBitsInByte(uint8_t Byte, uint8_t BitsInByte);
bool EventCheckBitInByte(uint8_t refByte, uint8_t refBit, uint8_t *tempByte,
		uint8_t tempBit, uint8_t ev4one, uint8_t ev4zero, uint8_t *EventCode);
uint16_t MergeBytesToWord(uint8_t highByte, uint8_t lowByte);
uint8_t MergeSubniblesToByte(uint8_t subnible_3, uint8_t subnible_2, uint8_t subnible_1, uint8_t subnible_0);
#endif /* BITFUNCS_H_ */
