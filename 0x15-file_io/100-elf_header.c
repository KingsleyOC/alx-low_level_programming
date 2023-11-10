#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define ERROR_EXIT_CODE 98
/**
 * display_error_and_exit_ code 98
 */

void display_error_and_exit(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(ERROR_EXIT_CODE);
}

void display_elf_magic(const unsigned char *e_ident)
{
	const char *magic = "ELF Header:";

	printf("%s\n  Magic:   ", magic);
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

void display_elf_class(const unsigned char e_ident[EI_NIDENT])
{
	printf("  Class:                            %s\n",
			e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
}

void display_elf_data(const unsigned char e_ident[EI_NIDENT])
{
	printf("  Data:                             %s\n", e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" :
			(e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big-endian" : "Invalid"));
}

void display_elf_version(const unsigned char e_ident[EI_NIDENT])
{
		printf("  Version:                          %d (current)\n", e_ident[EI_VERSION]);
}

void display_elf_osabi(const unsigned char e_ident[EI_NIDENT])
{
	printf("  OS/ABI:                           ");
	switch (e_ident[EI_OSABI])
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
			printf("UNIX - ARM\n");
			break;
		default:
			printf("UNIX - unknown\n");
			break;
		}
}

void display_elf_abi_version(const unsigned char e_ident[EI_NIDENT])
{
	printf("  ABI Version:                      %d\n", e_ident[EI_ABIVERSION]);
}

void display_elf_type(Elf64_Half e_type)
{
	printf("  Type:                             ");
	switch (e_type)
	{
			case ET_NONE:
				printf("NONE (Unknown type)\n");
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
				printf("Unknown\n");
				break;
		}
}

void display_elf_entry(Elf64_Addr e_entry)
{
	printf("  Entry point address:               0x%lx\n", (unsigned long)e_entry);
}

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		display_error_and_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		isplay_error_and_exit("Cannot open file");

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)
			display_error_and_exit("Cannot read ELF header");

			if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
			display_error_and_exit("Not an ELF file");

			display_elf_magic(elf_header.e_ident);
			display_elf_class(elf_header.e_ident);
			display_elf_data(elf_header.e_ident);
			display_elf_version(elf_header.e_ident);
			display_elf_osabi(elf_header.e_ident);
			display_elf_abi_version(elf_header.e_ident);
			display_elf_type(elf_header.e_type);
			display_elf_entry(elf_header.e_entry);

			close(fd);
			return (0);
}
