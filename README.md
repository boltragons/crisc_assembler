# CASM (CRISC Assembler) v1.0.0
## A simple assembler made for the CRISC-1 8-bit CPU to translate assembly code to a Logisim-compliant loadable binary map.

<p align="center">
 <a href="#objective">Objective</a> •
 <a href="#manual">Manual</a> • 
 <a href="#language">Language</a> • 
 <a href="#example">Example</a> • 
 <a href="#tools">Tools</a> • 
 <a href="#licence">Licence</a> • 
 <a href="#developer">Developer</a>
</p>

# Objective

This Assembler was designed for the [CRISC-1](https://github.com/boltragons/crisc_cpu/tree/main) CPU, to translate an assembly code file to binary instructions to use in the Logisim while simulating the CPU.

The main objective is to facilitate the learning of Computer Engineering classes, such as "Computer Architecture", "Assembly Language", "Embedded Systems" and "Digital Logic" through the programming for the CRISC-1, using Assembly.

The use of the CRISC-1 computer is interesting in learning computer architectures, but its programming is complicated, mainly due to the use of numeric opcodes for this and manual translation. This project brings a relatively powerful and simple assembler, which will assist in learning through mnemonic instructions.

# Manual

## Compilation

This programm was compiled in a Ubuntu-based Operating System, therefore it will only run in a linux-based kernel. To run in other kernel (such as Windows) you must compile it, since it doesn't use OS-specific API. For this you must have "CMake" and a C++ compiler installed. You can build with CMake or use the following bash script in the root directory (the binary will be put in the root folder):

```
./build.sh
```

## Executing

You must run the assembler with at least one parameter, up to two, in the following fashion:

```
./casm input.asm [output]
```

Where "input.asm" is the file with the CRISC Assembly mnemonics (the extension must be ".asm") and "output" is the optional file where the binary map will be placed (the output file can be omitted, as by default is the same as the input, but without the extension). Done this you can test the program in the Logisim simulator executing the processor.

After assembling load the generated file in the programm memory, and you're good to go!

# Language

The CPU instructions (and the Assembly mnemonics) were made to mirror classic RISC ones. There are 19 instructions, as showed bellow. There are some things worth mentioning:

- There are no procedures or variables in the Assembly code, only instructions an commentaries.
- You can write one line commentaries with "//".
- The variables must be placed directly in the data memory.
- The instructions' and variables' addresses must be calculated manually.
- Since the CRISC-1 only have 256 Bytes for Data and Program, the maximum size of the programm is limited.
- The CRISC-1 also have 16 I/O addresses for peripheral access.

In the table below are the instructions for the CRISC-1 processor:

| Binary Format | Instruction Type | Mnemonic | C Equivalent | Aditional Description |
| :---: | :---: | :---: | :---: | :---: |
| (00000000) | Control | HALT | exit(0) | Halts the program execution. |
| (0)001[SSDD] | ALU Binary | ADD Rd, Rs | Rd = Rd + Rs | - |
| (0)010[SSDD] | ALU Binary | SUB Rd, Rs | Rd = Rd - Rs | - |
| (0)011[SSDD] | ALU Binary | AND Rd, Rs | Rd = Rd & Rs | - |
| (0)100[SSDD] | ALU Binary | OR Rd, Rs | Rd = Rd \| Rs | - |
| (0)101[SSDD] | ALU Binary | XOR Rd, Rs | Rd = Rd ^ Rs | - |
| (0)110[SSDD] | ALU Binary | MUL Rd, Rs | Rd = Rd * Rs | - |
| (0)111[SSDD] | ALU Binary | CMP Rd, Rs | ZF = Rd - Rs | - |
| (1011)00[DD] | ALU Unary | NOT Rd | Rd = ~Rd | - |
| (1011)01[DD] | ALU Unary | NEG Rd | Rd = -Rd | - |
| (1011)10[DD] | ALU Unary | INC Rd | Rd++ | - |
| (1011)11[DD] | ALU Unary | DEC Rd | Rd-- | - |
| (11)XXXX[DD] | Immediate | LI Rd, Imm | Rd = Imm | Loads a 4-bit immediate in Rd |
| (100)0[SSDD] | Memory Access | LD Rd, Rs | Rd = *(Rs) | Loads the value of the Data memory address in Rs to Rd |
| (100)1[SSDD] | Memory Access | ST Rd, Rs | *(Rd) = Rs | Stores the value in Rs in the Data memory address in Rd |
| (10100)0[DD] | Branching | B Rs | PC = Rs | Branch to the address in RS |
| (10100)1[DD] | Branching | BZ Rs | if(ZF) PC = Rs | If the Zero Flag (ZF) is 1 then branch to the address in Rs |
| (10101)0[DD] | I/O Access | IN Rd | Rd = *(R0) | Loads the value of the I/O address in R0 to Rd |
| (10101)1[DD] | I/O Access | OUT Rs | *(R0) = Rs | Stores the value in Rs in the I/O address in R0 |

For more information about the arquitecture and the instructions, see the (CRISC-1 Reference Manual)[https://github.com/boltragons/crisc_cpu/blob/main/docs/CRISC-1%20Reference%20Manual.pdf]. There are a few programs in examples/ folder. Check it out.

# Example

In the examples folder is a program for turning on a LED based in the status of a button. If not using the Assembler the best way to build a code like this is to write it in any readable fashion (like using Assembly symbols per say), and manually translate it to the binary code, like in the example shown below:

config_gpio:
00: XOR R0, R0   ;; (0)101[SSDD] 0b01010000 0x50
01: LI R1, 1     ;; (11)XXXX[DD] 0b11000101 0xC5
02: OUT R1       ;; (10101)1[SS] 0b10101101 0xAD

if:
03: LI R0, 2     ;; (11)XXXX[DD] 0b11001000 0xC8
04: IN R2        ;; (10101)0[DD] 0b10101010 0xAA
05: AND R2, R0   ;; (0)011[SSDD] 0b00110010 0x32
06: LI R0, E     ;; (11)XXXX[DD] 0b11111000 0xF8
07: BZ R0        ;; (10100)1[DD] 0b10100100 0xA4

then:
08: LI R0, 1     ;; (11)XXXX[DD] 0b11000100 0xC4
09: IN R2        ;; (10101)0[DD] 0b10101010 0xAA
0A: OR R2, R0    ;; (0)100[SSDD] 0b01000010 0x42
0B: OUT R2       ;; (10101)1[SS] 0b10101110 0xAE
0C: LI R0, 3     ;; (11)XXXX[DD] 0b11001100 0xCC
0D: B R0         ;; (10100)0[DD] 0b10100000 0xA0

else:
0E: LI R0, 1     ;; (11)XXXX[DD] 0b11000100 0xC4
0F: IN R2        ;; (10101)0[DD] 0b10101010 0xAA
10: NOT R0       ;; (1011)00[DD] 0b10110000 0xD0
11: AND R2, R0   ;; (0)011[SSDD] 0b00110010 0x32
12: LI R0, 1     ;; (11)XXXX[DD] 0b11000100 0xC4
13: OUT R2       ;; (10101)1[SS] 0b10101110 0xAE
14: LI R0, 3     ;; (11)XXXX[DD] 0b11001100 0xCC
15: B R0         ;; (10100)0[DD] 0b10100000 0xA0

Note that the development goes from left to right: first the symbols are written, the addresses are resolved, and then the binary, and the subsequent hexadecimal value for the instruction is obtained from the instructions format. This is highly tedious.

Using a Assembler facilitate the process. Just code the Assembly part and let the Assembler do the rest:

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

Sadly because some limitations of the CRISC-1 the automatic procedures addresses cannot be done (yet), so it have to be manually, but the rest is done automatically by using CASM. 

This program used the PORT A (address 0x0) of the GPIO, which used 3 registers to configure it's pins:

- DATADIR (offset 0x0): Configure the pin as input for 0 and output for 1.
- DATAOUT (offset 0x1): Outputs low output value for 0, and high for 1.
- DATAIN (offset 0x2): Reads 0 for low input value, and 1 for high.

So with the IN and OUT instructions is possible to manage the I/O pins.

# Tools

This program was made with C++17 and CMake.

# Licence

Under the GNU General Public License v3.0.

# Developer

My name is Pedro Botelho, and I'm a Computer Enginnering stundent at Federal University of Ceará, in Brazil.

This program is still in the testing phase. Help in the development, reporting any error to the developer.

For more informations, or to report some error, send an e-mail to pedrobotelho15@alu.ufc.br.
