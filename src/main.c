#include "image.h"
#include "encrypt.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv){

  const char *nome_arq;
  // **argv permite receber imagem como argumento quando rodar o programa usando cli
  // caso nao espeficado uma imagem pre determinada sera usada.
  if (argc == 2) {
    nome_arq = argv[1];
  } else {
    nome_arq = "./docs/hollow_silk.ppm";
  }
  // struct usado para manipular imagem 
  // ImagemPPM e' struct usado para salvar dados da imagem no formato .ppm
  // contem altura, largura, max_valor (255) e dados dos pixels
  ImagemPPM img = ler_imagem(nome_arq);

  // CONFUSAO
  aplicar_confusao(img);
  salvar_imagemPPM("./img_confusa.ppm", img);

  // DIFUSAO
  aplicar_difusao(img);
  salvar_imagemPPM("./img_difusa.ppm", img);

  // Imagem revertida para original
  reverter_difusao(img);
  reverter_confusao(img);
  salvar_imagemPPM("./img_revertida.ppm", img);

  // Libera memoria usado por malloc() 
  free(img.dados);
  
}
