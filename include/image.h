#ifndef IMAGE_H
#define IMAGE_H

typedef struct {
  int largura;
  int altura;
  int max_valor;
  char *dados;

} Imagem;

Imagem ler_imagem(const char *arq_name);
void salvar_imagem();


#endif
