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

  //unsigned char prev_byte = 0;
  for(int i = 0; i < total_pixels - 20; i+=20){
    unsigned char bloco[10];
    for (int k = 0; k < 10; k++){
      bloco[k] = ptr[k+i];
    }
    for (int k = 0; k < 10; k++){
      ptr[k+i] = ptr[k+i+10];
    }
    for (int k = 0; k < 10; k++){
      ptr[10+k+i] = bloco[k];
    }
  }
}



void reverter_difusao(ImagemPPM img){
  //unsigned char *ptr = img.dados;
  int total_pixels = img.largura * img.altura * 3;

  for (int i = 0; i < total_pixels; i++) {
  }
}
