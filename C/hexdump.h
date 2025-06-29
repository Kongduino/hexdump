void hexDump(unsigned char* buf, unsigned int len) {
  // Something similar to the Unix/Linux hexdump -C command
  // Pretty-prints the contents of a buffer, 16 bytes a row
  char alphabet[17] = "0123456789abcdef";
  unsigned int i, index;
  printf("     +------------------------------------------------+ +----------------+\n");
  printf("     |.0 .1 .2 .3 .4 .5 .6 .7 .8 .9 .a .b .c .d .e .f | |      ASCII     |\n");
  for (i = 0; i < len; i += 16) {
    if (i % 128 == 0) printf("     +------------------------------------------------+ +----------------+\n");
    char s[] = "000. |                                                | |                |\n";
    // pre-formated line. We will replace the spaces with text when appropriate.
    unsigned char ix = 6, iy = 57, j;
    for (j = 0; j < 16; j++) {
      if (i + j < len) {
        unsigned char c = buf[i + j];
        // fastest way to convert a byte to its 2-digit hex equivalent
        s[ix++] = alphabet[(c >> 4) & 0x0F];
        s[ix++] = alphabet[c & 0x0F];
        ix++;
        if (c > 31 && c < 128) s[iy++] = c;
        else s[iy++] = '.'; // display ASCII code 0x20-0x7F or a dot.
      }
    }
    index = i / 16;
    // display line number then the text
    sprintf(s, "%03x.", index);
    s[4] = ' ';
    printf("%s", s);
  }
  printf("     +------------------------------------------------+ +----------------+\n");
}
