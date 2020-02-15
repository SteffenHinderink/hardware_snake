// ==============================================================
// File generated on Wed Feb 12 16:31:24 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// AXILiteS
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x400 ~
// 0x7ff : Memory 'field_V' (256 * 32b)
//         Word n : bit [31:0] - field_V[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSNAKE_OUTPUT_AXILITES_ADDR_AP_CTRL      0x000
#define XSNAKE_OUTPUT_AXILITES_ADDR_GIE          0x004
#define XSNAKE_OUTPUT_AXILITES_ADDR_IER          0x008
#define XSNAKE_OUTPUT_AXILITES_ADDR_ISR          0x00c
#define XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_BASE 0x400
#define XSNAKE_OUTPUT_AXILITES_ADDR_FIELD_V_HIGH 0x7ff
#define XSNAKE_OUTPUT_AXILITES_WIDTH_FIELD_V     32
#define XSNAKE_OUTPUT_AXILITES_DEPTH_FIELD_V     256

