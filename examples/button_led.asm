// Copyright (c) 2024 CASM
// All rights reserved

// Config PORTA of GPIO with P0 as OUTPUT and the remaining as INPUT:
XOR R0, R0
LI R1, 1	
OUT R1	

// IF button is pressed:
LI R0, 2	
IN R2	
AND R2, R0
LI R0, E	
BZ R0	

// THEN turn on the LED:
LI R0, 1	
IN R2	
OR R2, R0 
OUT R2	
LI R0, 3	
B R0

// ELSE turn off the LED:
LI R0, 1	
IN R2	
NOT R0	
AND R2, R0 
LI R0, 1	
OUT R2	
LI R0, 3	
B R0	
