section .multiboot_head

head_start:

  ; magic number
  dd 0xe85250d6 ; multiboot2

  ; architecture
  dd 0 ; protected mode i386

  ; head length
  dd head_end - head_start

  ; checksum
  dd 0x100000000 - (0xe85250d6 + 0 + (head_end - head_start))

  ; end tag
  dw 0
  dw 0
  dd 8

head_end: