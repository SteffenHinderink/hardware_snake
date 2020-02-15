// ==============================================================
// File generated on Wed Feb 12 16:31:24 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XSNAKE_OUTPUT_H
#define XSNAKE_OUTPUT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsnake_output_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XSnake_output_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XSnake_output;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSnake_output_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSnake_output_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSnake_output_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSnake_output_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XSnake_output_Initialize(XSnake_output *InstancePtr, u16 DeviceId);
XSnake_output_Config* XSnake_output_LookupConfig(u16 DeviceId);
int XSnake_output_CfgInitialize(XSnake_output *InstancePtr, XSnake_output_Config *ConfigPtr);
#else
int XSnake_output_Initialize(XSnake_output *InstancePtr, const char* InstanceName);
int XSnake_output_Release(XSnake_output *InstancePtr);
#endif

void XSnake_output_Start(XSnake_output *InstancePtr);
u32 XSnake_output_IsDone(XSnake_output *InstancePtr);
u32 XSnake_output_IsIdle(XSnake_output *InstancePtr);
u32 XSnake_output_IsReady(XSnake_output *InstancePtr);
void XSnake_output_EnableAutoRestart(XSnake_output *InstancePtr);
void XSnake_output_DisableAutoRestart(XSnake_output *InstancePtr);

u32 XSnake_output_Get_field_V_BaseAddress(XSnake_output *InstancePtr);
u32 XSnake_output_Get_field_V_HighAddress(XSnake_output *InstancePtr);
u32 XSnake_output_Get_field_V_TotalBytes(XSnake_output *InstancePtr);
u32 XSnake_output_Get_field_V_BitWidth(XSnake_output *InstancePtr);
u32 XSnake_output_Get_field_V_Depth(XSnake_output *InstancePtr);
u32 XSnake_output_Write_field_V_Words(XSnake_output *InstancePtr, int offset, int *data, int length);
u32 XSnake_output_Read_field_V_Words(XSnake_output *InstancePtr, int offset, int *data, int length);
u32 XSnake_output_Write_field_V_Bytes(XSnake_output *InstancePtr, int offset, char *data, int length);
u32 XSnake_output_Read_field_V_Bytes(XSnake_output *InstancePtr, int offset, char *data, int length);

void XSnake_output_InterruptGlobalEnable(XSnake_output *InstancePtr);
void XSnake_output_InterruptGlobalDisable(XSnake_output *InstancePtr);
void XSnake_output_InterruptEnable(XSnake_output *InstancePtr, u32 Mask);
void XSnake_output_InterruptDisable(XSnake_output *InstancePtr, u32 Mask);
void XSnake_output_InterruptClear(XSnake_output *InstancePtr, u32 Mask);
u32 XSnake_output_InterruptGetEnabled(XSnake_output *InstancePtr);
u32 XSnake_output_InterruptGetStatus(XSnake_output *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
