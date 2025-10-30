MEMORY {
    rom     (rx)    : ORIGIN = 0x00000000, LENGTH = 0x40000
    ram     (rwx)   : ORIGIN = 0x20000000, LENGTH = 0x4000
}

STACK_SIZE = 0x2000;

SECTIONS {
    .text :
    {
        KEEP(*(.vectors .vectors.*))
        *(.text.*)
        *(.rodata.*)
        _etext = .;
    } > rom

    .bss (NOLOAD):
    {
        _sbss = .;
        *(.bss .bss.*)
        *(COMMON)
        _ebss = .;
    } > ram

    .data :
    {
        _sdata = .;
        *(.data*);
        _edata = .;
    } > ram AT > rom

    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _sstack = .;
        . = . + STACK_SIZE;
        . = ALIGN(8);
        _estack = .;
    } > ram

    . = ALIGN(4);
    _end = .;
}