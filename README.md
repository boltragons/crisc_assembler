# CASM (CRISC Assembler)

## A simple assembler made for the CRISC-1 8-bit CPU to help in the learning of different computer science subjects.

This Assembler was designed for the [CRISC-1](https://github.com/boltragons/crisc_cpu/tree/main) CPU, to translate an assembly code file to binary instructions to use in the Logisim while simulating the CPU.

To assemble just type the command below, where the input file must have .asm extension and the output file can be omitted (is the same as the input, but without the extension, by default).

```
./casm input.asm [output]
```

Currenctly the assembler is very simple, only translating the instructions to binary. In the future it will be upgraded to allow sophiscated branches and support a data segment.

Example assembly codes are provided in [examples/](https://github.com/boltragons/crisc_assembler/blob/main/examples) folder along with its binary outputs.
