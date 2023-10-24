/* Entry Point Definition */
ENTRY(start) /* Specify the program entry point */

SECTIONS {
    /* Set the program's initial memory address to 1 megabyte */
    . = 1M;

    /* Boot Section */
    .boot : {
        /* Keep the Multiboot head (if present) in the .boot section */
        KEEP(*(.multiboot_head))
    }

    /* Text Section */
    .text : {
        /* Include all code in the .text section */
        *(.text)
    }
}
