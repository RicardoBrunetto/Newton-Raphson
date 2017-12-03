/*
███╗   ██╗███████╗██╗    ██╗████████╗ ██████╗ ███╗   ██╗      ██████╗  █████╗ ██████╗ ██╗  ██╗███████╗ ██████╗ ███╗   ██╗
████╗  ██║██╔════╝██║    ██║╚══██╔══╝██╔═══██╗████╗  ██║      ██╔══██╗██╔══██╗██╔══██╗██║  ██║██╔════╝██╔═══██╗████╗  ██║
██╔██╗ ██║█████╗  ██║ █╗ ██║   ██║   ██║   ██║██╔██╗ ██║█████╗██████╔╝███████║██████╔╝███████║███████╗██║   ██║██╔██╗ ██║
██║╚██╗██║██╔══╝  ██║███╗██║   ██║   ██║   ██║██║╚██╗██║╚════╝██╔══██╗██╔══██║██╔═══╝ ██╔══██║╚════██║██║   ██║██║╚██╗██║
██║ ╚████║███████╗╚███╔███╔╝   ██║   ╚██████╔╝██║ ╚████║      ██║  ██║██║  ██║██║     ██║  ██║███████║╚██████╔╝██║ ╚████║
╚═╝  ╚═══╝╚══════╝ ╚══╝╚══╝    ╚═╝    ╚═════╝ ╚═╝  ╚═══╝      ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝

██████╗  █████╗ ██╗███████╗     ██████╗ ██╗   ██╗ █████╗ ██████╗ ██████╗  █████╗ ██████╗  █████╗
██╔══██╗██╔══██╗██║╚══███╔╝    ██╔═══██╗██║   ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗
██████╔╝███████║██║  ███╔╝     ██║   ██║██║   ██║███████║██║  ██║██████╔╝███████║██║  ██║███████║
██╔══██╗██╔══██║██║ ███╔╝      ██║▄▄ ██║██║   ██║██╔══██║██║  ██║██╔══██╗██╔══██║██║  ██║██╔══██║
██║  ██║██║  ██║██║███████╗    ╚██████╔╝╚██████╔╝██║  ██║██████╔╝██║  ██║██║  ██║██████╔╝██║  ██║
╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚══════╝     ╚══▀▀═╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝

Ricardo Henrique Brunetto [RA94182]
NOV/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-20

void doubleToIeee(double valor, int *sinal, int *expoente, double *mantissa){
  *expoente = floor(log2(valor));
  if(valor < 0){
    valor = valor*(-1);
    *sinal = 1;
  }else{
    *sinal = 0;
  }
  *mantissa = valor/(pow(2, *expoente)) - 1.0;
}

double ieeeToDouble(double mantissa, int expoente, int sinal){
  return (mantissa * pow(-1, sinal) * pow(2, expoente));
}


double raiz_quadrada (double mantissa, int * expoente){
  int isImpar = 0, k=1;
  if(*expoente & 1){
    isImpar = 1;
    *expoente = *expoente - 1;
  }
  *expoente = (*expoente)*(0.5);
  double xk_1 = mantissa * 0.5 + 1.0;
  mantissa += 1.0;
  double xk = 0, aux;
  printf("\n\nExpoente: %d\n", *expoente);
  do{
    xk = xk_1;
    xk_1 = xk - (((xk*xk - mantissa)/xk)*0.5);
    printf("#%d\t[xk]: %.20lf\t[xk+1]: %.20lf\n", k++, xk, xk_1);
  }while((fabs(xk_1 - xk) > EPSILON));
  if(isImpar) return (xk_1 * 1.41421356237309504880168872420969807); /*1.41421356237309504880168872420969807 = sqrt(2)*/
  return xk_1;
}

int main(){
  printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
  printf("\t|N|E|W|T|O|N|-|R|A|P|H|S|O|N|\n");
  printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
  printf("\t|R|A|I|Z|   |Q|U|A|D|R|A|D|A|\n");
  printf("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");

  double k;
  printf("Digite um valor para calcular a raiz [DIGITE 0 PARA SAIR]: ");
  scanf("%lf", &k);
  while(k!=0){
    double mant; int ex, sinal;
    doubleToIeee(k, &sinal, &ex, &mant);
    double raiz = raiz_quadrada(mant, &ex);
    printf("\nRAIZ CONVERGIDA: %.20lf\t", raiz);
    printf("VALOR DECIMAL: %.20lf\n", ieeeToDouble(raiz, ex, sinal));
    printf("\n\nDigite um valor para calcular a raiz [DIGITE 0 PARA SAIR]: ");
    scanf("%lf", &k);
  }
}
