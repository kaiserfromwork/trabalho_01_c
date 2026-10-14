#ifndef CRYPT_H
#define CRYPT_H

void aplicar_confusao(ImagemPPM img);
void reverter_confusao(ImagemPPM img);
void aplicar_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte);
void reverter_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte);
void aplicar_difusao(ImagemPPM img);

#endif
