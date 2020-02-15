// ==============================================================
// File generated on Wed Feb 12 16:31:24 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xsnake_output.h"

extern XSnake_output_Config XSnake_output_ConfigTable[];

XSnake_output_Config *XSnake_output_LookupConfig(u16 DeviceId) {
	XSnake_output_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSNAKE_OUTPUT_NUM_INSTANCES; Index++) {
		if (XSnake_output_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSnake_output_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSnake_output_Initialize(XSnake_output *InstancePtr, u16 DeviceId) {
	XSnake_output_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSnake_output_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSnake_output_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

