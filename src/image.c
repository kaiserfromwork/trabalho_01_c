#include <stdio.h>
#include <stdlib.h>
#include "image.h"

Imagem ler_imagem(const char *nome_arq){
  FILE *arq;

  // Inicializando struct para testes
  Imagem img = {0, 0, 0, NULL};

  if((arq = fopen(nome_arq, "rb")) == NULL){
    perror("Error");
    exit(1);
  } else {
    printf("Arquivo Lido!");
  }

  char formato[3];
  fscanf(arq, "%2s", formato);
  if (formato[0] != 'P' || formato[1] != '6'){
    fprintf(stderr, "Formato invalido (deve ser P6 binario!\n");
    fclose(arq);
    exit(EXIT_FAILURE);
  }

  char ch = fgetc(arq);
  while (ch == '#'){
    while (fgetc(arq) != '\n')
      ch = fgetc(arq);
  }
  ungetc(ch, arq);
  
  // Ler cabecalho
  fscanf(arq, "%d %d %d", &img.largura, &img.altura, &img.max_valor);
  fgetc(arq);

  // Verificar leitura do pixels
  int total_pixels = img.altura * img.largura * 3;
  img.dados = (unsigned char *) malloc(total_pixels);

  size_t lidos = fread(img.dados, sizeof(unsigned char), total_pixels, arq);
  if (lidos != total_pixels) {
    fprintf(stderr, "Error ao ler matriz de pixels\n");
  }
  
  fclose(arq);
  return img;
}



