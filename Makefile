# Define source directories
KERNEL_SRC_DIR = src/imp/kernel
X86_64_SRC_DIR = src/imp/x86_64
SYSCALL_SRC_DIR = src/syscalls

# Find all source files
KERNEL_C_SRC = $(wildcard $(KERNEL_SRC_DIR)/*.c)
X86_64_C_SRC = $(wildcard $(X86_64_SRC_DIR)/*.c)
X86_64_ASM_SRC = $(wildcard $(X86_64_SRC_DIR)/*.asm)
SYSCALL_SRC = $(wildcard $(SYSCALL_SRC_DIR)/*.c)

# Define object file directories
KERNEL_OBJ_DIR = build/kernel
X86_64_OBJ_DIR = build/x86_64
SYSCALL_OBJ_DIR = build/syscalls

# Generate object file lists
KERNEL_OBJ = $(patsubst $(KERNEL_SRC_DIR)/%.c,$(KERNEL_OBJ_DIR)/%.o,$(KERNEL_C_SRC))
X86_64_C_OBJ = $(patsubst $(X86_64_SRC_DIR)/%.c,$(X86_64_OBJ_DIR)/%.o,$(X86_64_C_SRC))
X86_64_ASM_OBJ = $(patsubst $(X86_64_SRC_DIR)/%.asm,$(X86_64_OBJ_DIR)/%.o,$(X86_64_ASM_SRC))
SYSCALL_OBJ = $(patsubst $(SYSCALL_SRC_DIR)/%.c,$(SYSCALL_OBJ_DIR)/%.o,$(SYSCALL_SRC))

# Define compiler and linker
CC = x86_64-elf-gcc
LD = x86_64-elf-ld

# Compiler flags
CFLAGS = -g -ffreestanding -I src

# Linker flags
LDFLAGS = -n -T targets/x86_64/linker.ld

# Define target files
KERNEL_BIN = dist/x86_64/kernel.bin
KERNEL_ISO = dist/x86_64/kernel.iso

.PHONY: all build-x86_64

all: build-x86_64

build-x86_64: $(KERNEL_BIN)

$(KERNEL_OBJ_DIR)/%.o: $(KERNEL_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(X86_64_OBJ_DIR)/%.o: $(X86_64_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(X86_64_OBJ_DIR)/%.o: $(X86_64_SRC_DIR)/%.asm
	@mkdir -p $(@D)
	nasm -f elf64 $< -o $@

$(SYSCALL_OBJ_DIR)/%.o: $(SYSCALL_SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL_BIN): $(KERNEL_OBJ) $(X86_64_C_OBJ) $(X86_64_ASM_OBJ) $(SYSCALL_OBJ)
	@mkdir -p $(@D)
	$(LD) $(LDFLAGS) -o $@ $^
	cp $(KERNEL_BIN) targets/x86_64/iso/boot/kernel.bin
	grub-mkrescue /usr/lib/grub/i386-pc -o $(KERNEL_ISO) targets/x86_64/iso

clean:
	rm -rf $(KERNEL_OBJ_DIR) $(X86_64_OBJ_DIR) $(SYSCALL_OBJ_DIR) $(KERNEL_BIN) $(KERNEL_ISO)
