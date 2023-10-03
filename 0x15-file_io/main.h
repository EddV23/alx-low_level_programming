#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void check_elf(unsigned char *elf_ident);
void display_elf_magic(unsigned char *elf_ident);
void display_elf_class(unsigned char *elf_ident);
void display_elf_data(unsigned char *elf_ident);
void display_elf_version(unsigned char *elf_ident);
void display_elf_osabi(unsigned char *elf_ident);
void display_elf_abi_version(unsigned char *elf_ident);
void display_elf_type(unsigned int elf_type, unsigned char *elf_ident);
void display_elf_entry(unsigned long int elf_entry, unsigned char *elf_ident);
void close_elf_file(int elf_close);

#endif /* MAIN_H */
