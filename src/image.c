#include <stdio.h>
#include <stdlib.h>
#include "image.h"

Imagem ler_imagem(const char *nome_arq){
  FILE *arq;

  // Inicializando struct para testes
  Imagem img = {0, 0, 0, NULL};

  if((arq = fopen(nome_arq, "rb")) == NULL){
    perror("Error!"); 
    exit(1);
  } else {
    printf("Arquivo Lido!");
  }
  return img;
}



