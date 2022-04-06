#include <stdio.h>

int sobreposicao(float Rx, float Ry, float Ralt, float Rlarg, float x, float y, float alt, float larg);

int main()
{
    float Rx, Ry, Ralt, Rlarg; //R para o quadrado de Referencia
    float x, y, alt, larg;
    int num_retangulos, i, k;
    int num_sobreposicao, total_sobreposicao = 0;
    float matriz_sobreposicao[100][4];

    printf("QUADRADO DE REFERENCIA:\n");

    printf("INSIRA A COORDENADA X: ");
    scanf("%f", &Rx);
    printf("INSIRA A COORDENADA y: ");
    scanf("%f", &Ry);
    printf("INSIRA A ALTURA: ");
    scanf("%f", &Ralt);
    printf("INSIRA A LARGURA: ");
    scanf("%f", &Rlarg);

    printf("\n\nCOM QUANTOS RETANGULOS VOCE DESEJA TESTAR A SOBREPOSICAO: ");
    scanf("%d", &num_retangulos);

    for (i = 0; i < num_retangulos; i++) {
        printf("\nINSIRA A COORDENADA X DO RETANGULO TESTE %d: ", i + 1);
        scanf("%f", &x);
        printf("INSIRA A COORDENADA Y DO RETANGULO TESTE %d: ", i + 1);
        scanf("%f", &y);
        printf("INSIRA A ALTURA DO RETANGULO TESTE %d: ", i + 1);
        scanf("%f", &alt);
        printf("INSIRA A LARGURA DO RETANGULO TESTE %d: ", i + 1);
        scanf("%f", &larg);

        num_sobreposicao = sobreposicao(Rx, Ry, Ralt, Rlarg, x, y, alt, larg);

        if (num_sobreposicao == 1) {
            matriz_sobreposicao[total_sobreposicao][0] = x;         
            matriz_sobreposicao[total_sobreposicao][1] = y;         
            matriz_sobreposicao[total_sobreposicao][2] = alt;       
            matriz_sobreposicao[total_sobreposicao][3] = larg;      
            total_sobreposicao++;                                   
        }
        
    }
    if (total_sobreposicao > 0) {
        printf("\nSOBREPOSICOES:\n");
        printf("TOTAL DE SOBREPOSICAO = %d\n", total_sobreposicao);
        for (i = 0; i < total_sobreposicao; i++) {
            printf("x = %.2f, y = %.2f, alt = %.2f, larg = %.2f\n", matriz_sobreposicao[i][0], matriz_sobreposicao[i][1], matriz_sobreposicao[i][2], matriz_sobreposicao[i][3]);
        }
    } else {
        printf("\nTOTAL DE SOBREPOSICAO = %d\n", total_sobreposicao);
    }

    return 0;
}

int sobreposicao(float Rx, float Ry, float Ralt, float Rlarg, float x, float y, float alt, float larg) {

    if (x + larg > Rx && y + alt > Ry) {
        if (x < Rx + Rlarg && y < Ry + Ralt) {
            return 1;
        }
    }
    return 0;
}
