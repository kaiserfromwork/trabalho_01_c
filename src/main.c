#include "image.h"
#include "encrypt.h"
#include <stdlib.h>


int main(){
  const char *nome_arq = "./docs/hollow_silk.ppm";
  
  ImagemPPM img = ler_imagem(nome_arq);
  aplicar_confusao(img);
  salvar_imagemPPM("./img_confusa.ppm", img);
  //reverter_confusao(img);
  aplicar_difusao(img);
  salvar_imagemPPM("./img_revertida.ppm", img);
  free(img.dados);
  
}
