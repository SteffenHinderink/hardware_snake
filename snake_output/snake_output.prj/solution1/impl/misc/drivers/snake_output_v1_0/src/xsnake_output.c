// ==============================================================
// File generated on Wed Feb 12 16:31:24 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xsnake_output.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSnake_output_CfgInitialize(XSnake_output *InstancePtr, XSnake_output_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSnake_output_Start(XSnake_output *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL) & 0x80;
    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSnake_output_IsDone(XSnake_output *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSnake_output_IsIdle(XSnake_output *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSnake_output_IsReady(XSnake_output *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSnake_output_EnableAutoRestart(XSnake_output *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XSnake_output_DisableAutoRestart(XSnake_output *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XSnake_output_Get_field_V_BaseAddress(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE);
}

u32 XSnake_output_Get_field_V_HighAddress(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH);
}

u32 XSnake_output_Get_field_V_TotalBytes(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH - XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + 1);
}

u32 XSnake_output_Get_field_V_BitWidth(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSNAKE_OUTPUT_AXILITES_WIDTH_FIELD_V;
}

u32 XSnake_output_Get_field_V_Depth(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSNAKE_OUTPUT_AXILITES_DEPTH_FIELD_V;
}

u32 XSnake_output_Write_field_V_Words(XSnake_output *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH - XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XSnake_output_Read_field_V_Words(XSnake_output *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH - XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + (offset + i)*4);
    }
    return length;
}

u32 XSnake_output_Write_field_V_Bytes(XSnake_output *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH - XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XSnake_output_Read_field_V_Bytes(XSnake_output *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH - XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Axilites_BaseAddress + XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE + offset + i);
    }
    return length;
}

void XSnake_output_InterruptGlobalEnable(XSnake_output *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_GIE, 1);
}

void XSnake_output_InterruptGlobalDisable(XSnake_output *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_GIE, 0);
}

void XSnake_output_InterruptEnable(XSnake_output *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_IER);
    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_IER, Register | Mask);
}

void XSnake_output_InterruptDisable(XSnake_output *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_IER);
    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_IER, Register & (~Mask));
}

void XSnake_output_InterruptClear(XSnake_output *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnake_output_WriteReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_ISR, Mask);
}

u32 XSnake_output_InterruptGetEnabled(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_IER);
}

u32 XSnake_output_InterruptGetStatus(XSnake_output *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnake_output_ReadReg(InstancePtr->Axilites_BaseAddress, XSNAKE_OUTPUT_AXILITES_ADDR_ISR);
}

