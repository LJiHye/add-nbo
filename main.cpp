#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <stdlib.h> // for exit
#include <netinet/in.h> //for ntohl

uint32_t nbo(char *fname) {
    FILE *fd;
    uint32_t n, buf;

    if(!(fd=fopen(fname, "r"))) {
        printf("file open error : \"%s\"\n", fname);
        exit(2);
    }

    fread(&buf, sizeof(uint32_t), 1, fd);
    //p = reinterpret_cast<uint32_t*>(buf);
    n = ntohl(buf);

    fclose(fd);

    return n;
}



int main(int argc, char *argv[]) {
    uint32_t v1, v2;

    if(argc < 3) {
        printf("syntax : %s <file1> <file2>\n", argv[0]);
        printf("sample : %s a.bin c.bin\n", argv[0]);
        exit(1);
    }

    v1 = nbo(argv[1]);
    v2 = nbo(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", v1, v1, v2, v2, v1+v2, v1+v2);

    exit(0);
}
