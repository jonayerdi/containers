
#ifndef _CRC32_H_
#define _CRC32_H_

#include <stdint.h> /* uint8_t, uint32_t */
#include <stddef.h> /* size_t */

#include "crc32_table.h"

#define CRC32_Init() ((uint32_t)0xFFFFFFFFU)
#define CRC32_Next(crc, byte) (((crc)>>8U) ^ CRC32_Table[((crc)^byte) & 0xFFU])
#define CRC32_End(crc) ((crc) ^ ((uint32_t)0xFFFFFFFFU))

uint32_t CRC32_Compute(void *data, size_t size);

#endif /* _CRC32_H_ */
