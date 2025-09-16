#include <stdio.h>
#include <unistd.h> // This header declares sbrk() on Linux/Unix

int main() {
    void *initial_break = sbrk(0);
    
    printf("Initial program break is at address: %p\n", initial_break);

    void *new_block_start = sbrk(1);

    if (new_block_start == (void *)-1) {
        perror("sbrk failed");
        return 1;
    }

    printf("Successfully allocated 1 byte.\n");
    printf("The start of our new block is at: %p\n", new_block_start);

    void *new_break = sbrk(0);
    printf("New program break is now at address: %p\n", new_break);

    return 0;
}
