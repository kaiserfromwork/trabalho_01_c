#include "image.h"
#include <stdlib.h>


int main(){
  const char *nome_arq = "./docs/hollow_silk.ppm";
  
  ImagemPPM img = ler_imagem(nome_arq);

  free(img.dados);
  
}
