
#include <inttypes.h> /* uint32_t, PRIu32 */
#include <stdio.h> /* printf */

void CRC32_MakeTable(uint32_t crcTable[256], uint32_t POLYNOMIAL)
{
    uint32_t WIDTH = 8 * sizeof(uint32_t);
    uint32_t TOPBIT = 1 << (WIDTH - 1);
    uint32_t remainder;
    // Compute the remainder of each possible dividend
    for (int dividend = 0; dividend < 256; ++dividend)
    {
        // Start with the dividend followed by zeros
        remainder = dividend << (WIDTH - 8);

        // Perform modulo-2 division, a bit at a time
        for (unsigned long bit = 8; bit > 0; --bit)
        {
            // Try to divide the current data bit
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
        crcTable[dividend] = remainder;
    }
}

void CRC32_PrintTable(uint32_t crcTable[256], const char *indentation)
{
    printf("%s", indentation);
    for (int i = 0; i < 256; i++)
    {
        if (i%4 == 0 && i>0)
			printf("\n%s", indentation);
		printf("0x%08"PRIX32"U", crcTable[i]);
        if(i < 255)
		    printf(", ");
    }
}

void CRC32_PrintTableHeader(uint32_t crcTable[256])
{
    printf("#include <stdint.h> /* uint32_t */\n");
    printf("\n");
    printf("#ifndef CRC32_C\n");
    printf("extern uint32_t CRC32_Table[256];\n");
    printf("#else /* CRC32_C */\n");
    printf("uint32_t CRC32_Table[256] = \n");
    printf("{\n");
    CRC32_PrintTable(crcTable, "    ");
    printf("\n");
    printf("};\n");
    printf("#endif /* CRC32_C */\n");
}

int main(int argc, char *argv[])
{
	uint32_t crcTable[256];
	uint32_t POLYNOMIAL = 0x04c11db7;
    CRC32_MakeTable(crcTable, POLYNOMIAL);
	CRC32_PrintTableHeader(crcTable);
    return 0;
}
