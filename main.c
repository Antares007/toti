#include <stdio.h>
#include <sys/mman.h>

#include <assert.h>
#include <string.h>
void writeTextToFile(const char *filename, const char *text) {}
#include <stdlib.h>
// Function to compile 'cword.c' code, write to 'cword.bin', and read into
// memory
long cword(void *o, const char *cword_text) {
  // Open 'cword.c' file in write mode
  FILE *file = fopen("cword.c", "w");
  assert(file != NULL); // Ensure file is opened successfully
  // Get length of 'cword_text'
  size_t length = strlen(cword_text);
  // Write 'cword_text' to 'cword.c' file
  size_t bytes_written = fwrite(cword_text, sizeof(char), length, file);
  fclose(file);                    // Close 'cword.c' file
  assert(length == bytes_written); // Check if all bytes are written

  // Compile 'cword.c' code to binary
  assert(
      // Compile command
      system(
          "gcc -std=gnu17 -Wall -O3 -c cword.c -o cword.o  -ffreestanding "
          "-fno-stack-clash-protection -fno-stack-protector"
          "&&"
          // Link command
          "ld -T rainbow.ld cword.o -o cword.elf"
          "&&"
          // Object copy command
          "objcopy -O binary -j .text.* -j .text -j .data cword.elf cword.bin"
          "&&"
          // Remove intermediate files
          "rm cword.o cword.elf") ==
      0); // Ensure successful compilation and linking

  // Open 'cword.bin' file in read mode
  file = fopen("cword.bin", "rb");
  assert(file != NULL);     // Ensure file is opened successfully
  fseek(file, 0, SEEK_END); // Move file pointer to end
  // Get size of 'cword.bin' file
  long size = ftell(file);
  // Adjust size to skip header and other data
  size -= 16 + 4 * 16;
  assert(0 < size);          // Ensure file size is valid
  fseek(file, 16, SEEK_SET); // Move file pointer to skip header
  // Read 'cword.bin' file into memory
  assert(fread(o, sizeof(char), size, file) ==
         size); // Ensure all bytes are read
  fclose(file); // Close 'cword.bin' file
  return size;  // Return size of file read into memory
}
#include"aword.h"
#include<unistd.h>
int main(int argc, const char **argv) {
  void **o = mmap((void *)0x0000070700000000, 0x10000,
                 PROT_READ | PROT_WRITE | PROT_EXEC,
                 MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, 0, 0);
  long a = 0;
  long b = 0x1000;
  long s = b;
  long t = s;
  s += cword(((char*)o) + s, "#include\"aw.h\"\n"
                    "G(Olive  ) { P(\"1 \\n\"), o[--b] = Lime,  Yellow(t,a,b,o,s); }"
                    "G(Lime   ) { P(\"1 \\n\"), o[--b] = Olive, Green (t,a,b,o,s); }"
                    "G(Fuchsia) { P(\"1 \\n\"),                 Olive(t,a,b,o,s); }"
                    "G(Maroon ) { }"
                    "G(Navy   ) { }");
  s += cword(((char*)o) + s, "#include\"aw.h\"\n"
                    "G(Olive  ) { P(\"2 \\n\"), Yellow(t,a,b,o,s); }"
                    "G(Lime   ) { P(\"2 \\n\"), Green (t,a,b,o,s); }"
                    "G(Fuchsia) { P(\"2 \\n\"), Purple(t,a,b,o,s); }"
                    "G(Maroon ) { P(\"2 \\n\"), Red   (t,a,b,o,s); }"
                    "G(Navy   ) { P(\"2 \\n\"), Blue  (t,a,b,o,s); }");
  s += cword(((char*)o) + s, "#include\"aw.h\"\n"
                    "G(Olive  ) { P(\"3 \\n\"), Yellow(t,a,b,o,s); }"
                    "G(Lime   ) { P(\"3 \\n\"), Green (t,a,b,o,s); }"
                    "G(Fuchsia) { P(\"3 \\n\"), Purple(t,a,b,o,s); }"
                    "G(Maroon ) { P(\"3 \\n\"), Red   (t,a,b,o,s); }"
                    "G(Navy   ) { P(\"3 \\n\"), Blue  (t,a,b,o,s); }");
  s += cword(((char*)o) + s, "#include\"aw.h\"\n"
                    "G(Olive  ) { P(\"4 \\n\"), Yellow(t,a,b,o,s); }"
                    "G(Lime   ) { P(\"4 \\n\"), Green (t,a,b,o,s); }"
                    "G(Fuchsia) { P(\"4 \\n\"), Purple(t,a,b,o,s); }"
                    "G(Maroon ) { P(\"4 \\n\"), Red   (t,a,b,o,s); }"
                    "G(Navy   ) { P(\"4 \\n\"), Blue  (t,a,b,o,s); }");
  s += cword(((char*)o) + s, "#include\"aw.h\"\n"
                    "G(Olive  ) { P(\"5 \\n\"), ((n_t)o[b])(t,a,b+1,o,s); }"
                    "G(Lime   ) { P(\"5 \\n\"), ((n_t)o[b])(t,a,b+1,o,s); }"
                    "G(Fuchsia) { P(\"5 \\n\"), Purple(t,a,b,o,s); }"
                    "G(Maroon ) { }"
                    "G(Navy   ) { }");
  printf("%p %ld\n", o, s);
  o[a++] = printf;
  o[a++] = usleep;
  ((n_t)(((char*)o) + (s-16)))(b,a,t,o,s);
}
