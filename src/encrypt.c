#include "image.h"
#include "encrypt.h"
#include <stdio.h>

void aplicar_confusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  int total_pixels = img.largura * img.altura;
  
  unsigned char fib_prev = 1;
  unsigned char fib_curr = 1;

  for(int i = 0; i < total_pixels; i++){
    aplicar_fib(&fib_prev, &fib_curr, &ptr[0]);
    aplicar_fib(&fib_prev, &fib_curr, &ptr[1]);
    aplicar_fib(&fib_prev, &fib_curr, &ptr[2]);
    ptr+=3;
  }
  printf("IMAGEM CONFUSA!!");


}

void aplicar_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte){
  *cor_byte = (*cor_byte + *fib_curr) % 256;

  unsigned char next = (*fib_prev + *fib_curr);
  *fib_prev = *fib_curr;
  *fib_curr = next;
  
}

