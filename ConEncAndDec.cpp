#include <stdio.h>
#include <stdint.h>

extern void sha512_encrypt(uint64_t* plaintext, uint64_t* ciphertext); // Assembly function for SHA-512 encryption
extern void sha512_decrypt(uint64_t* ciphertext, uint64_t* plaintext); // Assembly function for SHA-512 decryption

int main() {
    uint64_t plaintext[8] = {0x0123456789abcdef, 0xfedcba9876543210, 0x13579bdf2468ace0, 0x0eca8642df9b7531,
                              0xf0e1d2c3b4a59687, 0x87654321abcdef09, 0xdeadbeefbadc0ffee, 0x0123456789abcdef};
    uint64_t ciphertext[8] = {0}; // Stores the result of encryption
    uint64_t decrypted[8] = {0}; // Stores the result of decryption

    printf("Plaintext: ");
    for (int i = 0; i < 8; i++) {
        printf("%016lx ", plaintext[i]);
    }

    sha512_encrypt(plaintext, ciphertext); // Call the SHA-512 encryption function

    printf("\nCiphertext: ");
    for (int i = 0; i < 8; i++) {
        printf("%016lx ", ciphertext[i]);
    }

    sha512_decrypt(ciphertext, decrypted); // Call the SHA-512 decryption function

    printf("\nDecrypted text: ");
    for (int i = 0; i < 8; i++) {
        printf("%016lx ", decrypted[i]);
    }

    return 0;
}
