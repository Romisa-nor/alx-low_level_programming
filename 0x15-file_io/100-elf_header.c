#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(98);
}

void check_elf(unsigned char *e_ident) {
    // Check if the given file is an ELF file
    for (int i = 0; i < EI_NIDENT; i++) {
        if (e_ident[i] != ELFMAG[i]) {
            print_error("Not an ELF file");
        }
    }
}

void print_elf_info(Elf64_Ehdr *header) {
    // Print the magic numbers
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    // Print the ELF class (32-bit or 64-bit)
    printf("  Class:                             ");
    if (header->e_ident[EI_CLASS] == ELFCLASS32) {
        printf("ELF32\n");
    } else if (header->e_ident[EI_CLASS] == ELFCLASS64) {
        printf("ELF64\n");
    } else {
        printf("<unknown: %x>\n", header->e_ident[EI_CLASS]);
    }

    // Print the data format (little endian or big endian)
    printf("  Data:                              ");
    if (header->e_ident[EI_DATA] == ELFDATA2LSB) {
        printf("2's complement, little endian\n");
    } else if (header->e_ident[EI_DATA] == ELFDATA2MSB) {
        printf("2's complement, big endian\n");
    } else {
        printf("<unknown: %x>\n", header->e_ident[EI_DATA]);
    }

    // Print the ELF version
    printf("  Version:                           %d", header->e_ident[EI_VERSION]);
    if (header->e_ident[EI_VERSION] == EV_CURRENT) {
        printf(" (current)\n");
    } else {
        printf("\n");
    }

    // Print the OS/ABI information
    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI]) {
        case ELFOSABI_NONE:
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
            printf("<unknown: %x>\n", header->e_ident[EI_OSABI]);
    }

    // Print the ABI Version
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    // Print the ELF Type
    printf("  Type:                              ");
    switch (header->e_type) {
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
            printf("<unknown: %x>\n", header->e_type);
    }

    // Print the Entry Point Address
    printf("  Entry point address:               %#lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: elf_header elf_filename");
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        print_error("Can't read file");
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read == -1 || bytes_read != sizeof(Elf64_Ehdr)) {
        print_error("No such file");
    }

    check_elf(header.e_ident);

    printf("ELF Header:\n");
    print_elf_info(&header);

    close(fd);
    return 0;
}
