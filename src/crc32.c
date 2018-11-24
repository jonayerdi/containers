
#define _CRC32_C_
#include "crc32.h"

uint32_t CRC32_Compute(void *data, size_t size)
{
	uint32_t crc = CRC32_Init();
	for(size_t i = 0 ; i < size ; i++)
		crc = CRC32_Next(crc, ((uint8_t *)data)[i]);
	return CRC32_End(crc);
}
