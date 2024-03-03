// Copyright (c) 2024 CASM
// All rights reserved

// Load array size from first memory position:
XOR R0, R0
LD R3, R0
XOR R2, R2

// Accumulate array elements from second position onwards:
INC R0	
LD R1, R0	
ADD R2, R1
LI R1, B	
DEC R3	
BZ R1	
LI R1, 3
B R1

// Save the sum in memory after the array:
XOR R0, R0
LD R3, R0	
INC R3	
ST R3, R2	
HALT
