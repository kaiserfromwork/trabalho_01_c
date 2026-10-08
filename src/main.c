#include "image.h"



int main(){
  const char *nome_arq = "./docs/hollow_silk.jpeg";
  
  Imagem img = ler_imagem(nome_arq);

  free(img.dados)
  
}
