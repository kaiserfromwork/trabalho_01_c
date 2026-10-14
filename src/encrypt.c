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

void reverter_confusao(ImagemPPM img) {
  unsigned char *ptr = img.dados;
  int total_pixels = img.largura * img.altura;
  
  unsigned char fib_prev = 1;
  unsigned char fib_curr = 1;

  for(int i = 0; i < total_pixels; i++){
    reverter_fib(&fib_prev, &fib_curr, &ptr[0]);
    reverter_fib(&fib_prev, &fib_curr, &ptr[1]);
    reverter_fib(&fib_prev, &fib_curr, &ptr[2]);
    ptr+=3;
  }
  printf("IMAGEM Reveretida!!");

}


void reverter_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte){
  *cor_byte = (*cor_byte - *fib_curr + 256) % 256;

  unsigned char next = (*fib_prev + *fib_curr);
  *fib_prev = *fib_curr;
  *fib_curr = next;
}
// FAZER DIFUSAO MAIS UNICA AUTORAL ******************************************
void aplicar_difusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  int total_pixels = img.largura * img.altura * 3;

  unsigned char prev_byte = 0;
  for(int i = 0; i < total_pixels; i++){
    ptr[i] = (ptr[i] + prev_byte) % 256;
    prev_byte = ptr[i];
  }
}

void reverter_difusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  int total_pixels = img.largura * img.altura * 3;

  unsigned char prev_byte = 0;
  for (int i = 0; i < total_pixels; i++) {
    // Guardar o byte atual para pode usar na proxima iteracao
    unsigned char byte_cifrado = ptr[i];
    ptr[i] = (ptr[i]- prev_byte + 256) % 256;

    prev_byte = byte_cifrado;
  }
}
