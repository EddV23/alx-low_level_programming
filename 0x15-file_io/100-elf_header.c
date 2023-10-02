#include "main.h"

/**
 * display_elf_magic - Display the ELF magic number
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_magic(Elf64_Ehdr *elf_header)
{
	int i;

	printf("ELF Header:\n  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%c", elf_header->e_ident[i], (i == EI_NIDENT - 1) ? '\n' : ' ');
}

/**
 * display_elf_class - Display the ELF class
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_class(Elf64_Ehdr *elf_header)
{
	printf("  Class:                             ");

	switch (elf_header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
	}
}

/**
 * display_elf_data - Display the ELF data encoding
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_data(Elf64_Ehdr *elf_header)
{
	printf("  Data:                              ");

	switch (elf_header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
	}
}

/**
 * display_elf_version - Display the ELF version
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_version(Elf64_Ehdr *elf_header)
{
	printf("  Version:                           %d (current)\n",
	       elf_header->e_ident[EI_VERSION]);
}

/**
 * display_elf_osabi - Display the ELF OS/ABI
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_osabi(Elf64_Ehdr *elf_header)
{
	printf("  OS/ABI:                            ");

	switch (elf_header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_MODESTO:
		printf("UNIX - MODESTO\n");
		break;
	case ELFOSABI_OPENBSD:
		printf("UNIX - OpenBSD\n");
		break;
	default:
		printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
	}
}

/**
 * display_elf_abi_version - Display the ELF ABI version
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_abi_version(Elf64_Ehdr *elf_header)
{
	printf("  ABI Version:                       %d\n",
	       elf_header->e_ident[EI_ABIVERSION]);
}

/**
 * display_elf_type - Display the ELF type
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_type(Elf64_Ehdr *elf_header)
{
	printf("  Type:                              ");
	switch (elf_header->e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: 0x%x>\n", elf_header->e_type);
	}
}

/**
 * display_elf_entry_point - Display the ELF entry point address
 * @elf_header: Pointer to the ELF header structure
 */
void display_elf_entry_point(Elf64_Ehdr *elf_header)
{
	printf("  Entry point address:               0x%lx\n",
	       (unsigned long)elf_header->e_entry);
}

/**
 * main - Entry point, display ELF header information
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	display_elf_magic(&elf_header);
	display_elf_class(&elf_header);
	display_elf_data(&elf_header);
	display_elf_version(&elf_header);
	display_elf_osabi(&elf_header);
	display_elf_abi_version(&elf_header);
	display_elf_type(&elf_header);
	display_elf_entry_point(&elf_header);

	close(fd);
	return (0);
}
