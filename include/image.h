#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
  int largura;
  int altura;
  int max_valor;
  unsigned char *dados;

} ImagemPPM;

ImagemPPM ler_imagem(const char *nome_arq);
void salvar_imagemPPM(const char *nome_arq, ImagemPPM img);


#endif
