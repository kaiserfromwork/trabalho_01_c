#include <stdio.h>
#include <stdlib.h>
#include "image.h"

/*
 * Le uma imgaem PPM (P6) do arquivo especificado
 *
 * ImagemPPM e' struct usado para salvar dados da imagem no formato .ppm
 * contem altura, largura, max_valor (255) e dados dos pixels
 * */
ImagemPPM ler_imagem(const char *nome_arq){
  FILE *arq;

  ImagemPPM img;

  if((arq = fopen(nome_arq, "rb")) == NULL){
    perror("Error");
    exit(EXIT_FAILURE);
  } else {
    printf("Arquivo Lido!");
  }

  char formato[3];
  fscanf(arq, "%2s", formato);
  // Verificando formato, para poder buscar valores de altura, largura da imagem
  printf("\nFormato = %c \n", formato[0]);
  printf("Formato = %c \n", formato[1]);
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
  
  // Ler cabecalho da imagem
  //Formato do comeco do arquivo PPM, e' preciso manter esse formato especifico para .ppm P6
  fscanf(arq, "%d %d %d", &img.largura, &img.altura, &img.max_valor);
  fgetc(arq);

  // Verificar leitura do pixels
  int total_pixels = img.altura * img.largura * 3;
  img.dados = (unsigned char *) malloc(total_pixels);

  size_t lidos = fread(img.dados, sizeof(unsigned char), total_pixels, arq);
  if (lidos != total_pixels) {
    fprintf(stderr, "Error ao ler matriz de pixels\n");
    exit(EXIT_FAILURE);
  }
  else {
    printf("Pixels: %d", total_pixels);
  }
  
  fclose(arq);
  return img;
}

/*
 * Salva imagem PPM usando arquivo espeficicado
 * */
void salvar_imagemPPM(const char *nome_arq, ImagemPPM img){
  FILE *arq = fopen(nome_arq, "wb");
  if (!arq) {
    perror("Erro ao salver arquivo!");
    exit(EXIT_FAILURE);
  }
  //Formato do comeco do arquivo PPM, e' preciso manter esse formato especifico para .ppm P6
  fprintf(arq, "P6\n%d %d\n%d\n", img.largura, img.altura, img.max_valor);
  int total_pixels = img.largura * img.altura * 3;
  fwrite(img.dados, sizeof(unsigned char), total_pixels, arq);
  printf("\nImagem Salva!");
  fclose(arq);


}


