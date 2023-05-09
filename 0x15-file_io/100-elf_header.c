#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *ident);
void print_magic(unsigned char *ident);
void print_class(unsigned char *ident);
void print_data(unsigned char *ident);
void print_version(unsigned char *ident);
void print_abi(unsigned char *ident);
void print_osabi(unsigned char *ident);
void print_type(unsigned int type, unsigned char *ident);
void print_entry(unsigned long int entry, unsigned char *ident);
void close_elf(int fd);

/**
 * check_elf - Checks if a file is an ELF file.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *ident)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (ident[i] != 127 &&
            ident[i] != 'E' &&
            ident[i] != 'L' &&
            ident[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *ident)
{
    int i;
    printf(" Magic: ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x", ident[i]);
        if (i == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * print_class - Prints the class of an ELF header.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *ident)
{
    printf(" Class: ");
    switch (ident[EI_CLASS])
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
        printf("<unknown: %x>\n", ident[EI_CLASS]);
    }
}

/**
 * print_data - Prints the data of an ELF header.
 * @ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *ident)
{
    printf(" Data: ");
    switch (ident[EI_DATA])
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
        printf("<unknown: %x>\n", ident[EI_CLASS]);
    }
}

/**
 * print_version - Prints the version of an ELF header.
 * @ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *ident)
{
    printf(" Version: %d", ident[EI_VERSION]);
    switch (ident[EI_VERSION])
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
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
    printf(" OS/ABI: ");

    switch (e_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    default:
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
    }
}
/**
 * print_abi_version - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version: %d\n", e_ident[EI_ABIVERSION]);
}
/**

print_elf_type - Prints the type of an ELF header.

@type: The ELF type to print.

@ident: A pointer to an array containing the ELF identification information.
*/
void print_elf_type(unsigned int type, unsigned char *ident)
{
if (ident[EI_DATA] == ELFDATA2MSB)
type >>= 8;

printf(" ELF Type: ");

switch (type)
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
printf("<Unknown type: %x>\n", type);
}
}
/**
 * print_entry_point - Prints the entry point address of an ELF header.
 * @entry_point: The address of the entry point.
 * @elf_class: A pointer to an array containing the ELF class.
 */
void print_entry_point(unsigned long int entry_point, unsigned char *elf_class)
{
	printf("Entry Point Address: ");

	if (elf_class[EI_DATA] == ELFDATA2MSB)
	{
		entry_point = ((entry_point << 8) & 0xFF00FF00) |
			  ((entry_point >> 8) & 0xFF00FF);
		entry_point = (entry_point << 16) | (entry_point >> 16);
	}

	if (elf_class[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry_point);

	else
		printf("%#lx\n", entry_point);
}
/**
 * close_file - Closes a file by file descriptor.
 * @fd: The file descriptor of the file to close.
 *
 * Description: If the file cannot be closed, print an error message to stderr and exit with code 98.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Could not close file descriptor %d\n", fd);
		exit(98);
	}
}
/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 1 on failure.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 1.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}

	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (1);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		return (1);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		return (1);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}

