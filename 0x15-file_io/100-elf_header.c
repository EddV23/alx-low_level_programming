#include "main.h"

/**
 * check_elf - Checks if the file is an ELF file
 * @elf_ident: Pointer to the ELF header structure
 *
 */
void check_elf(unsigned char *elf_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (elf_ident[i] != 127 &&
		    elf_ident[i] != 'E' &&
		    elf_ident[i] != 'L' &&
		    elf_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_elf_magic - Display the ELF magic number
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_magic(unsigned char *elf_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", elf_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_elf_class - Display the ELF class
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_class(unsigned char *elf_ident)
{
	printf("  Class:                             ");

	switch (elf_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * display_elf_data - Display the ELF data encoding
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_data(unsigned char *elf_ident)
{
	printf("  Data:                              ");

	switch (elf_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
	}
}

/**
 * display_elf_version - Display the ELF version
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_version(unsigned char *elf_ident)
{
	printf("  Version:                           %d",
	       elf_ident[EI_VERSION]);

	switch (elf_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * display_elf_osabi - Display the ELF OS/ABI
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_osabi(unsigned char *elf_ident)
{
	printf("  OS/ABI:                            ");

	switch (elf_ident[EI_OSABI])
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
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
	}
}

/**
 * display_elf_abi_version - Display the ELF ABI version
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_abi_version(unsigned char *elf_ident)
{
	printf("  ABI Version:                       %d\n",
	       elf_ident[EI_ABIVERSION]);
}

/**
 * display_elf_type - Display the ELF type
 * @elf_type: The ELF type
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_type(unsigned int elf_type, unsigned char *elf_ident)
{
	if (elf_ident[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/**
 * display_elf_entry_point - Display the ELF entry point address
 * @elf_entry: The entry point address
 * @elf_ident: Pointer to the ELF header structure
 */
void display_elf_entry_point(unsigned long int elf_entry, unsigned char *elf_ident)
{
	printf("  Entry point address:               ");

	if (elf_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
			((elf_entry >> 8) & 0xFF00FF);
		elf_entry = (elf_entry << 16) | (elf_entry >> 16);
	}

	if (elf_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry);

	else
		printf("%#lx\n", elf_entry);
}

/**
 * close_elf_file - Closes an ELF file
 * @elf: File descriptor of the ELF file
 *
 */
void close_elf_file(int elf_close)
{
	if (close(elf_close) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_close);
		exit(98);
	}
}

/**
 * main - Entry point, display ELF header information
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int __attribute__((__unused__)) ac, char **av)
{
	int fd, rd;
	Elf64_Ehdr *elf_header;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close_elf_file(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	rd = read(fd, elf_header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(elf_header);
		close_elf_file(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}

	check_elf(elf_header->e_ident);
	printf("ELF Header:\n");
	display_elf_magic(elf_header->e_ident);
	display_elf_class(elf_header->e_ident);
	display_elf_data(elf_header->e_ident);
	display_elf_version(elf_header->e_ident);
	display_elf_osabi(elf_header->e_ident);
	display_elf_abi_version(elf_header->e_ident);
	display_elf_type(elf_header->e_type, elf_header->e_ident);
	display_elf_entry_point(elf_header->e_entry, elf_header->e_ident);

	free(elf_header);
	close_elf_file(fd);
	return (0);
}
