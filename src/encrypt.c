#include "image.h"
#include "encrypt.h"
#include <stdio.h>
  /**
  * Modifica os valores dos pixels usando ponteiros e uma funcao baseada na sequencia fibonacci
  *
  * ImagemPPM e' um strucut que contem largura, altura, valor_max e dados dos pixels
  */
void aplicar_confusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  // usamos a largura e altura da imagem para percorrer todos os pixels.
  int total_pixels = img.largura * img.altura;
  
  // Se valores inicias forem 0 o primeiro pixel nao sera afetado
  unsigned char fib_prev = 1;
  unsigned char fib_curr = 1;

  for(int i = 0; i < total_pixels; i++){
    aplicar_fib(&fib_prev, &fib_curr, &ptr[0]);
    aplicar_fib(&fib_prev, &fib_curr, &ptr[1]);
    aplicar_fib(&fib_prev, &fib_curr, &ptr[2]);
    ptr+=3;
  }


}
/*
 * Altera o valor dos pixels da imagem usando uma formula baseada na sequencia
 * Fibonacci, usando dois valores. 
 */

void aplicar_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte){
  // unsigned char mantem o numero entre 0 e 255, 
  // fazendo um wrap pro zero quando passa de 255
  *cor_byte = (*cor_byte + *fib_curr);

  unsigned char next = (*fib_prev + *fib_curr);
  *fib_prev = *fib_curr;
  *fib_curr = next;
  //printf("Fib: %d\n", next);
  
}
/*
 * Reverte a alteracao feita nos pixels da imagem usando uma formula baseada na
 * na sequencia Fibonacci.
 * */
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
  printf("Confusao revertida!");

}
/*
 * Reverte as alteracoes feita a imagem usando pointers e uma formula baseada
 * na sequencia Fibonacci.
 */

void reverter_fib(unsigned char *fib_prev, unsigned char *fib_curr, unsigned char *cor_byte){
  *cor_byte = (*cor_byte - *fib_curr);

  unsigned char next = (*fib_prev + *fib_curr);
  *fib_prev = *fib_curr;
  *fib_curr = next;
}
/**
  * Permuta as posicoes, em um bloco de memoria usando poteiros, dos pixels na memoria sem alterar os 
  * seus valores.
  *
  */
void aplicar_difusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  // Como queremos modificar o byte, multiplicamos o resultaado de largura * alatura por 3.
  int total_bytes = img.largura * img.altura * 3;
  
  // <=
  for(int i = 0; i < total_bytes - 20; i+=20){
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

/*
 * Reverte a posicao dos pixels para a posicao original de memoria,
 * sem alterar valores numericos. 
 * */

void reverter_difusao(ImagemPPM img){
  unsigned char *ptr = img.dados;
  int total_bytes = img.largura * img.altura * 3;

  for(int i = 0; i < total_bytes - 20; i+=20){
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
