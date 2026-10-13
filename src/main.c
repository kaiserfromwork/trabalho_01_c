#include "image.h"
#include <stdlib.h>


int main(){
  const char *nome_arq = "./docs/hollow_silk.ppm";
  
  ImagemPPM img = ler_imagem(nome_arq);
  salvar_imagemPPM("./img.ppm", img);
  free(img.dados);
  
}
