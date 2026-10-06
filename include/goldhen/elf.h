/*
 * elf.h - the ELF64 subset the loader needs.
 *
 * The loader validates the embedded payload, measures its image, copies its
 * PT_LOAD segments into kernel memory and applies R_X86_64_RELATIVE
 * relocations.  These are the standard Elf64 structures it walks.
 *
 * Practical note, verified against the shipped payload: the embedded payload
 * ELF has no relocation sections at all in its section header table (only
 * .rodata, .interp, .dynsym, .dynstr, .gnu.hash, .eh_frame, .data, .dynamic,
 * .comment and .shstrtab besides the code).  Its .dynsym holds only the null
 * symbol.  Every kernel symbol is therefore resolved at run time by
 * map_functions() rather than by the dynamic linker, and the relocation pass in
 * elf_load() finds nothing to do.  The code is kept because it is part of the
 * original loader and runs on every load.
 */
#ifndef GOLDHEN_ELF_H
#define GOLDHEN_ELF_H

#include <goldhen/types.h>

/* ---- identification ---------------------------------------------------- */
#define EI_NIDENT 16
#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

#define ELFCLASS64 2
#define ELFDATA2LSB 1
#define EM_X86_64 62
#define ET_DYN 3
#define EV_CURRENT 1

typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

/* ---- program headers --------------------------------------------------- */
#define PT_NULL 0
#define PT_LOAD 1
#define PT_DYNAMIC 2
#define PT_INTERP 3
#define PF_X 1
#define PF_W 2
#define PF_R 4

typedef struct {
    uint32_t p_type;
    uint32_t p_flags;
    uint64_t p_offset;
    uint64_t p_vaddr;
    uint64_t p_paddr;
    uint64_t p_filesz;
    uint64_t p_memsz;
    uint64_t p_align;
} Elf64_Phdr;

/* ---- section headers --------------------------------------------------- */
#define SHT_NULL 0
#define SHT_PROGBITS 1
#define SHT_SYMTAB 2
#define SHT_STRTAB 3
#define SHT_RELA 4
#define SHT_HASH 5
#define SHT_DYNAMIC 6
#define SHT_NOBITS 8
#define SHT_REL 9
#define SHF_WRITE 0x1
#define SHF_ALLOC 0x2
#define SHF_EXECINSTR 0x4

typedef struct {
    uint32_t sh_name;
    uint32_t sh_type;
    uint64_t sh_flags;
    uint64_t sh_addr;
    uint64_t sh_offset;
    uint64_t sh_size;
    uint32_t sh_link;
    uint32_t sh_info;
    uint64_t sh_addralign;
    uint64_t sh_entsize;
} Elf64_Shdr;

/* ---- relocations ------------------------------------------------------- */
#define R_X86_64_NONE 0
#define R_X86_64_64 1
#define R_X86_64_RELATIVE 8

#define ELF64_R_SYM(info) ((info) >> 32)
#define ELF64_R_TYPE(info) ((uint32_t)(info))
#define ELF64_R_INFO(sym, type) (((uint64_t)(sym) << 32) | (uint32_t)(type))

typedef struct {
    uint64_t r_offset;
    uint64_t r_info;
} Elf64_Rel;

typedef struct {
    uint64_t r_offset;
    uint64_t r_info;
    int64_t r_addend;
} Elf64_Rela;

/* ---- dynamic linking --------------------------------------------------- */
#define DT_NULL 0
#define DT_NEEDED 1
#define DT_STRTAB 5
#define DT_SYMTAB 6
#define DT_RELA 7
#define DT_RELASZ 8
#define DT_REL 17
#define DT_RELSZ 18

typedef struct {
    int64_t d_tag;
    union {
        uint64_t d_val;
        uint64_t d_ptr;
    } d_un;
} Elf64_Dyn;

typedef struct {
    uint32_t st_name;
    unsigned char st_info;
    unsigned char st_other;
    uint16_t st_shndx;
    uint64_t st_value;
    uint64_t st_size;
} Elf64_Sym;

#endif /* GOLDHEN_ELF_H */
