/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

#include <stdio.h>

int ehPrimo(int n){
    int i;
    int div = 0;

    //Caso especial para n=1, que não é primo
    if (n == 1){
        return 0;
    }

    //Checa se o número é par (com excessão do 2, que é primo)
    if ((n != 2) && (n%2 == 0)) {
        return 0;
    }

    // Checa se existe algum outro divisor
    for(i=3;i<n;i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main() {
    int leitura;
    FILE *arquivo = fopen("arquivo.txt","w");
    while(1){
        scanf("%d",&leitura);
        if(leitura>=0){
            if((ehPrimo(leitura)==0) && (leitura != 0)){
                fprintf(arquivo,"%d\n",leitura);
            }
        }
        else{
            fclose(arquivo);
            break;
        }
    }
    FILE *fp = popen("sort -n -r arquivo.txt","r");
    char ler[30];
    while(fgets(ler,30,fp)!=NULL){
        printf("%s",ler);
    }
    fclose(fp);
    return 0;
}
