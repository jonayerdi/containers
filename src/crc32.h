
#ifndef CRC32_H
#define CRC32_H

#include <stdint.h> /* uint8_t, uint32_t */
#include <stddef.h> /* size_t */

#include "CRC32_table.h"

#define CRC32_Init() ((uint32_t)0xFFFFFFFFU)
#define CRC32_Next(crc, byte) (((crc)>>8U) ^ CRC32_Table[((crc)^byte) & 0xFFU])
#define CRC32_End(crc) ((crc) ^ ((uint32_t)0xFFFFFFFFU))

uint32_t CRC32_Compute(void *data, size_t size);

#endif /* CRC32_H */
