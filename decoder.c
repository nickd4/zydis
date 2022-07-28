#include <stdio.h>
#include <inttypes.h>
#include <Zydis/Zydis.h>

int main()
{
    ZyanU8 data[8];

    // Initialize decoder context
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_REAL_16, ZYDIS_STACK_WIDTH_16);

    // Initialize formatter. Only required when you actually plan to do instruction
    // formatting ("disassembling"), like we do here
    ZydisFormatter formatter;
    ZydisFormatterInit(&formatter, ZYDIS_FORMATTER_STYLE_INTEL);

    // Loop over the instructions in our buffer.
    ZyanU64 runtime_address = 0;
    ZydisDecodedInstruction instruction;
    ZydisDecodedOperand operands[ZYDIS_MAX_OPERAND_COUNT_VISIBLE];

    printf("byte addressing modes\n");
    for (int i = 0; i < 4; ++i) {
      printf("mod %d\n", i);
      for (int j = 0; j < 8; ++j) {
        data[0] = 0x00;
        data[1] = j | (i << 6);
        data[2] = 0x34;
        data[3] = 0x56;
        data[4] = 0x78;
        data[5] = 0x9a;
        data[6] = 0xbc;
        data[7] = 0xde;

        ZydisDecoderDecodeFull(&decoder, data, sizeof(data),
            &instruction, operands, ZYDIS_MAX_OPERAND_COUNT_VISIBLE, 
            ZYDIS_DFLAG_VISIBLE_OPERANDS_ONLY);
        // Print current instruction pointer.
        //printf("%016" PRIX64 "  ", runtime_address);

        // Format & print the binary instruction structure to human readable format
        char buffer[256];
        ZydisFormatterFormatInstruction(&formatter, &instruction, operands,
            instruction.operand_count_visible, buffer, sizeof(buffer), runtime_address,
            ZYAN_NULL);
        puts(buffer);
      }
      printf("\n");
    }
    printf("\n");

    printf("word addressing modes\n");
    for (int i = 0; i < 4; ++i) {
      printf("mod %d\n", i);
      for (int j = 0; j < 8; ++j) {
        data[0] = 0x01;
        data[1] = j | (i << 6);
        data[2] = 0x34;
        data[3] = 0x56;
        data[4] = 0x78;
        data[5] = 0x9a;
        data[6] = 0xbc;
        data[7] = 0xde;

        ZydisDecoderDecodeFull(&decoder, data, sizeof(data),
            &instruction, operands, ZYDIS_MAX_OPERAND_COUNT_VISIBLE, 
            ZYDIS_DFLAG_VISIBLE_OPERANDS_ONLY);
        // Print current instruction pointer.
        //printf("%016" PRIX64 "  ", runtime_address);

        // Format & print the binary instruction structure to human readable format
        char buffer[256];
        ZydisFormatterFormatInstruction(&formatter, &instruction, operands,
            instruction.operand_count_visible, buffer, sizeof(buffer), runtime_address,
            ZYAN_NULL);
        puts(buffer);
      }
      printf("\n");
    }
    printf("\n");

    printf("opcodes\n");
    for (int i = 0; i < 0x100; ++i) {
      printf("opcode %02x\n", i);
      for (int j = 0; j < 8; ++j) {
        data[0] = i;
        data[1] = 2 | (j << 3);
        data[2] = 0x34;
        data[3] = 0x56;
        data[4] = 0x78;
        data[5] = 0x9a;
        data[6] = 0xbc;
        data[7] = 0xde;

        ZydisDecoderDecodeFull(&decoder, data, sizeof(data),
            &instruction, operands, ZYDIS_MAX_OPERAND_COUNT_VISIBLE, 
            ZYDIS_DFLAG_VISIBLE_OPERANDS_ONLY);
        // Print current instruction pointer.
        //printf("%016" PRIX64 "  ", runtime_address);

        // Format & print the binary instruction structure to human readable format
        char buffer[256];
        ZydisFormatterFormatInstruction(&formatter, &instruction, operands,
            instruction.operand_count_visible, buffer, sizeof(buffer), runtime_address,
            ZYAN_NULL);
        puts(buffer);
      }
      printf("\n");
    }
    printf("\n");

    return 0;
}
