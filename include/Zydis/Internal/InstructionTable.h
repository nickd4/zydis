/***************************************************************************************************

  Zyan Disassembler Engine (Zydis)

  Original Author : Florian Bernd

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef ZYDIS_INSTRUCTIONTABLE_H
#define ZYDIS_INSTRUCTIONTABLE_H

#include <stdint.h>
#include <Zydis/Defines.h>
#include <Zydis/Mnemonic.h>
#include <Zydis/InstructionInfo.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================================== */
/* Enums and types                                                                                */
/* ============================================================================================== */

/* ---------------------------------------------------------------------------------------------- */
/* Instruction table                                                                              */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisInstructionTableNode datatype.
 */
typedef void* ZydisInstructionTableNode;

/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisInstructionTableNodeType datatype.
 */
typedef uint8_t ZydisInstructionTableNodeType;

/**
 * @brief   Values that represent zydis instruction table node types.
 */
enum ZydisInstructionTableNodeTypes
{
    ZYDIS_NODETYPE_INVALID                  = 0x00,
    /**
     * @brief   Reference to an instruction-definition with 0 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_0OP           = 0x01,
    /**
     * @brief   Reference to an instruction-definition with 1 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_1OP           = 0x02,
    /**
     * @brief   Reference to an instruction-definition with 2 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_2OP           = 0x03,
    /**
     * @brief   Reference to an instruction-definition with 3 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_3OP           = 0x04,
    /**
     * @brief   Reference to an instruction-definition with 4 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_4OP           = 0x05,
    /**
     * @brief   Reference to an instruction-definition with 5 operands.
     */
    ZYDIS_NODETYPE_DEFINITION_5OP           = 0x06,
    /**
     * @brief   Reference to an opcode filter.
     */
    ZYDIS_NODETYPE_FILTER_OPCODE            = 0x07,
    /**
     * @brief   Reference to an vex-map filter.
     */
    ZYDIS_NODETYPE_FILTER_VEX               = 0x08,
    /**
     * @brief   Reference to an xop-map filter.
     */
    ZYDIS_NODETYPE_FILTER_XOP               = 0x09,
    /**
     * @brief   Reference to an instruction-mode filter.
     */
    ZYDIS_NODETYPE_FILTER_MODE              = 0x0A,
    /**
     * @brief   Reference to a mandatory-prefix filter.
     */
    ZYDIS_NODETYPE_FILTER_MANDATORYPREFIX   = 0x0B,
    /**
     * @brief   Reference to a modrm.mod filter.
     */
    ZYDIS_NODETYPE_FILTER_MODRMMOD          = 0x0C,
    /**
     * @brief   Reference to a modrm.reg filter.
     */                                                                                      
    ZYDIS_NODETYPE_FILTER_MODRMREG          = 0x0D,
    /**
     * @brief   Reference to a modrm.rm filter.
     */
    ZYDIS_NODETYPE_FILTER_MODRMRM           = 0x0E,  
    /**
     * @brief   Reference to an operand-size filter.
     */
    ZYDIS_NODETYPE_FILTER_OPERANDSIZE       = 0x0F,
    /**
     * @brief   Reference to an address-size filter.
     */
    ZYDIS_NODETYPE_FILTER_ADDRESSSIZE       = 0x10,
    /**
     * @brief   Reference to an rex/vex/evex.w filter.
     */
    ZYDIS_NODETYPE_FILTER_REXW              = 0x11,
    /**
     * @brief   Reference to an vex/evex.l filter.
     */
    ZYDIS_NODETYPE_FILTER_VEXL              = 0x12,
    /**
     * @brief   Reference to an evex.l' filter.
     */
    ZYDIS_NODETYPE_FILTER_EVEXL2            = 0x13,
    /**
     * @brief   Reference to an evex.b filter.
     */
    ZYDIS_NODETYPE_FILTER_EVEXB             = 0x14
};

/**
 * @brief   Defines the @c ZydisInstructionTableNodeValue datatype.
 */
typedef uint16_t ZydisInstructionTableNodeValue;

/* ---------------------------------------------------------------------------------------------- */
/* Operand definition                                                                             */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisSemanticOperandType datatype.
 */
typedef uint8_t ZydisSemanticOperandType;

/**
 * @brief   Values that represent semantic operand types.
 */
enum ZydisSemanticOperandTypes
{
    ZYDIS_SEM_OPERAND_TYPE_UNUSED,
    ZYDIS_SEM_OPERAND_TYPE_GPR8,
    ZYDIS_SEM_OPERAND_TYPE_GPR16,
    ZYDIS_SEM_OPERAND_TYPE_GPR32,
    ZYDIS_SEM_OPERAND_TYPE_GPR64,
    ZYDIS_SEM_OPERAND_TYPE_FPR,
    ZYDIS_SEM_OPERAND_TYPE_VR64,
    ZYDIS_SEM_OPERAND_TYPE_VR128,
    ZYDIS_SEM_OPERAND_TYPE_VR256,
    ZYDIS_SEM_OPERAND_TYPE_VR512,
    ZYDIS_SEM_OPERAND_TYPE_TR,
    ZYDIS_SEM_OPERAND_TYPE_CR,
    ZYDIS_SEM_OPERAND_TYPE_DR,
    ZYDIS_SEM_OPERAND_TYPE_SREG,
    ZYDIS_SEM_OPERAND_TYPE_MSKR,
    ZYDIS_SEM_OPERAND_TYPE_BNDR,
    ZYDIS_SEM_OPERAND_TYPE_MEM,
    ZYDIS_SEM_OPERAND_TYPE_MEM8,
    ZYDIS_SEM_OPERAND_TYPE_MEM16,
    ZYDIS_SEM_OPERAND_TYPE_MEM32,
    ZYDIS_SEM_OPERAND_TYPE_MEM64,
    ZYDIS_SEM_OPERAND_TYPE_MEM80,
    ZYDIS_SEM_OPERAND_TYPE_MEM128,
    ZYDIS_SEM_OPERAND_TYPE_MEM256,
    ZYDIS_SEM_OPERAND_TYPE_MEM512,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_BCST2,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_BCST4,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_BCST8,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_BCST16,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_BCST2,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_BCST4,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_BCST8,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_BCST16,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_VSIBX,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_VSIBY,
    ZYDIS_SEM_OPERAND_TYPE_MEM32_VSIBZ,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_VSIBX,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_VSIBY,
    ZYDIS_SEM_OPERAND_TYPE_MEM64_VSIBZ,
    ZYDIS_SEM_OPERAND_TYPE_M1616,
    ZYDIS_SEM_OPERAND_TYPE_M1632,
    ZYDIS_SEM_OPERAND_TYPE_M1664,
    ZYDIS_SEM_OPERAND_TYPE_MEM112,
    ZYDIS_SEM_OPERAND_TYPE_MEM224,
    ZYDIS_SEM_OPERAND_TYPE_IMM8,
    ZYDIS_SEM_OPERAND_TYPE_IMM16,
    ZYDIS_SEM_OPERAND_TYPE_IMM32,
    ZYDIS_SEM_OPERAND_TYPE_IMM64,
    ZYDIS_SEM_OPERAND_TYPE_IMM8U,
    ZYDIS_SEM_OPERAND_TYPE_REL8,
    ZYDIS_SEM_OPERAND_TYPE_REL16,
    ZYDIS_SEM_OPERAND_TYPE_REL32,
    ZYDIS_SEM_OPERAND_TYPE_REL64,
    ZYDIS_SEM_OPERAND_TYPE_PTR1616,
    ZYDIS_SEM_OPERAND_TYPE_PTR1632,
    ZYDIS_SEM_OPERAND_TYPE_PTR1664,
    ZYDIS_SEM_OPERAND_TYPE_MOFFS16,
    ZYDIS_SEM_OPERAND_TYPE_MOFFS32,
    ZYDIS_SEM_OPERAND_TYPE_MOFFS64,
    ZYDIS_SEM_OPERAND_TYPE_SRCIDX8,
    ZYDIS_SEM_OPERAND_TYPE_SRCIDX16,
    ZYDIS_SEM_OPERAND_TYPE_SRCIDX32,
    ZYDIS_SEM_OPERAND_TYPE_SRCIDX64,
    ZYDIS_SEM_OPERAND_TYPE_DSTIDX8,
    ZYDIS_SEM_OPERAND_TYPE_DSTIDX16,
    ZYDIS_SEM_OPERAND_TYPE_DSTIDX32,
    ZYDIS_SEM_OPERAND_TYPE_DSTIDX64,
    ZYDIS_SEM_OPERAND_TYPE_FIXED1,
    ZYDIS_SEM_OPERAND_TYPE_AL,
    ZYDIS_SEM_OPERAND_TYPE_CL,
    ZYDIS_SEM_OPERAND_TYPE_AX,
    ZYDIS_SEM_OPERAND_TYPE_DX,
    ZYDIS_SEM_OPERAND_TYPE_EAX,
    ZYDIS_SEM_OPERAND_TYPE_RAX,
    ZYDIS_SEM_OPERAND_TYPE_ES,
    ZYDIS_SEM_OPERAND_TYPE_CS,
    ZYDIS_SEM_OPERAND_TYPE_SS,
    ZYDIS_SEM_OPERAND_TYPE_DS,
    ZYDIS_SEM_OPERAND_TYPE_GS,
    ZYDIS_SEM_OPERAND_TYPE_FS,
    ZYDIS_SEM_OPERAND_TYPE_ST0
};

/**
 * @brief   Defines the @c ZydisOperandDefinition struct.
 */
typedef struct ZydisOperandDefinition_
{
    /**
     * @brief   The semantic operand type.
     */
    ZydisSemanticOperandType type;
    /**
     * @brief   The operand encoding.
     */
    ZydisOperandEncoding encoding;
    /**
     * @brief   The operand access-mode.
     */
    ZydisOperandAccess access;
} ZydisOperandDefinition;

/* ---------------------------------------------------------------------------------------------- */
/* Instruction definition                                                                         */
/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisEvexBFunctionality datatype .
 */
typedef uint8_t ZydisEvexBFunctionality;

/**
 * @brief   Values that represent zydis evex.b-functionalities.
 */
enum ZydisEvexBFunctionalities
{
    ZYDIS_EVEXB_FUNCTIONALITY_NONE,
    ZYDIS_EVEXB_FUNCTIONALITY_BC,
    ZYDIS_EVEXB_FUNCTIONALITY_RC,
    ZYDIS_EVEXB_FUNCTIONALITY_SAE
};

/**
 * @brief   Defines the @c ZydisInstructionDefinition struct.
 */
typedef struct ZydisInstructionDefinition_
{
    /**
     * @brief   The instruction mnemonic.
     */
    ZydisInstructionMnemonic mnemonic;
    /**
     * @brief   The number of used operands.
     */
    uint8_t operandCount;
    /**
     * @brief   The operand-definitions.
     */
    ZydisOperandDefinition operands[5];
    /**
     * @brief   The evex.b functionality.
     */
    ZydisEvexBFunctionality evexBFunctionality;

    bool hasEvexAAA;
    bool hasEvexZ;
} ZydisInstructionDefinition;

/* ---------------------------------------------------------------------------------------------- */

/* ============================================================================================== */
/* Functions                                                                                      */
/* ============================================================================================== */

/**
 * @brief   Returns the type of the specified instruction table node.
 *
 * @param   node    The node.
 *                  
 * @return  The type of the specified instruction table node.
 */
ZYDIS_NO_EXPORT ZydisInstructionTableNodeType ZydisInstructionTableGetNodeType(
    const ZydisInstructionTableNode node);

/**
 * @brief   Returns the value of the specified instruction table node.
 *
 * @param   node    The node.
 *                  
 * @return  The value of the specified instruction table node.
 */
ZYDIS_NO_EXPORT ZydisInstructionTableNodeValue ZydisInstructionTableGetNodeValue(
    const ZydisInstructionTableNode* node);

/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Returns the root node of the instruction table.
 *
 * @return  The root node of the instruction table.
 */
ZYDIS_NO_EXPORT ZydisInstructionTableNode ZydisInstructionTableGetRootNode();

/**
 * @brief   Returns the child node of @c parent specified by @c index.
 *
 * @param   parent  The parent node.
 * @param   index   The index of the child node to retrieve.
 *                  
 * @return  The specified child node.
 */
ZYDIS_NO_EXPORT ZydisInstructionTableNode ZydisInstructionTableGetChildNode(
    const ZydisInstructionTableNode parent, uint16_t index);

/**
 * @brief   Returns the instruction definition that is linked to the given @c node.
 *
 * @param   node    The instruction definition node.
 *                  
 * @return  Pointer to the instruction definition.
 */
ZYDIS_NO_EXPORT ZydisInstructionDefinition ZydisInstructionDefinitionByNode(
    const ZydisInstructionTableNode node);

/* ============================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ZYDIS_INSTRUCTIONTABLE_H */