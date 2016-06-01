// A funcao rodarMeuFis abrigara os dados gerados
// pelo parser e recebera as entradas e a variavel
// que guardara as saidas. Eh apenas um atalho para
// a funcao rodarSistema para guardar as regras do
// FIS, sem ter que adiciona-las a funcao principal
// (main/setup/loop...)

// Nao deve ser alterado!

// Exemplo de uso:
// float entrada[4];
// entrada[0] = 0;
// entrada[1] = 10;
// entrada[2] = 20;
// entrada[3] = 30;
// float *saida = rodarMeuFis(entrada);

#include "FuzzySystem.h"

float* rodarMeuFis(float *x) {

    Variavel var[5];
    Regra regras[29];
    unsigned char i;

    for (i=0;i<29;i++) {
    regras[i].conjEntrada = (unsigned char*) malloc(4*sizeof(unsigned char));
    regras[i].conjSaida = (unsigned char*)   malloc(1*sizeof(unsigned char));
    }


    // Variavel botNum
    var[0].min = 0.000000;
    var[0].max = 8.000000;
    var[0].numConjuntos = 3;
    var[0].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[0].conj[0].tipo = CONJ_T;
    var[0].conj[0].a = 0.000000;
    var[0].conj[0].b = 0.000000;
    var[0].conj[0].c = 2.000000;
    var[0].conj[0].d = 4.000000;
    // Conjunto triangulo Me
    var[0].conj[1].tipo = CONJ_T;
    var[0].conj[1].a = 2.000000;
    var[0].conj[1].b = 4.000000;
    var[0].conj[1].c = 4.000000;
    var[0].conj[1].d = 6.000000;
    // Conjunto trapezio Hi
    var[0].conj[2].tipo = CONJ_T;
    var[0].conj[2].a = 4.000000;
    var[0].conj[2].b = 6.000000;
    var[0].conj[2].c = 8.000000;
    var[0].conj[2].d = 8.000000;

    // Variavel protection
    var[1].min = 0.000000;
    var[1].max = 500.000000;
    var[1].numConjuntos = 3;
    var[1].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[1].conj[0].tipo = CONJ_T;
    var[1].conj[0].a = 0.000000;
    var[1].conj[0].b = 0.000000;
    var[1].conj[0].c = 125.000000;
    var[1].conj[0].d = 250.000000;
    // Conjunto triangulo Me
    var[1].conj[1].tipo = CONJ_T;
    var[1].conj[1].a = 125.000000;
    var[1].conj[1].b = 250.000000;
    var[1].conj[1].c = 250.000000;
    var[1].conj[1].d = 375.000000;
    // Conjunto trapezio Hi
    var[1].conj[2].tipo = CONJ_T;
    var[1].conj[2].a = 250.000000;
    var[1].conj[2].b = 375.000000;
    var[1].conj[2].c = 500.000000;
    var[1].conj[2].d = 500.000000;

    // Variavel playerDist
    var[2].min = 0.000000;
    var[2].max = 80.000000;
    var[2].numConjuntos = 3;
    var[2].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[2].conj[0].tipo = CONJ_T;
    var[2].conj[0].a = 0.000000;
    var[2].conj[0].b = 0.000000;
    var[2].conj[0].c = 20.000000;
    var[2].conj[0].d = 40.000000;
    // Conjunto triangulo Me
    var[2].conj[1].tipo = CONJ_T;
    var[2].conj[1].a = 20.000000;
    var[2].conj[1].b = 40.000000;
    var[2].conj[1].c = 40.000000;
    var[2].conj[1].d = 60.000000;
    // Conjunto trapezio Hi
    var[2].conj[2].tipo = CONJ_T;
    var[2].conj[2].a = 40.000000;
    var[2].conj[2].b = 60.000000;
    var[2].conj[2].c = 80.000000;
    var[2].conj[2].d = 80.000000;

    // Variavel courage
    var[3].min = 0.000000;
    var[3].max = 1.000000;
    var[3].numConjuntos = 3;
    var[3].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[3].conj[0].tipo = CONJ_T;
    var[3].conj[0].a = 0.000000;
    var[3].conj[0].b = 0.000000;
    var[3].conj[0].c = 0.250000;
    var[3].conj[0].d = 0.500000;
    // Conjunto triangulo Me
    var[3].conj[1].tipo = CONJ_T;
    var[3].conj[1].a = 0.250000;
    var[3].conj[1].b = 0.500000;
    var[3].conj[1].c = 0.500000;
    var[3].conj[1].d = 0.750000;
    // Conjunto trapezio Hi
    var[3].conj[2].tipo = CONJ_T;
    var[3].conj[2].a = 0.500000;
    var[3].conj[2].b = 0.750000;
    var[3].conj[2].c = 1.000000;
    var[3].conj[2].d = 1.000000;

    // Variavel style
    var[4].min = 0.000000;
    var[4].max = 1.000000;
    var[4].numConjuntos = 3;
    var[4].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio De
    var[4].conj[0].tipo = CONJ_T;
    var[4].conj[0].a = 0.000000;
    var[4].conj[0].b = 0.000000;
    var[4].conj[0].c = 0.250000;
    var[4].conj[0].d = 0.500000;
    // Conjunto triangulo Ne
    var[4].conj[1].tipo = CONJ_T;
    var[4].conj[1].a = 0.250000;
    var[4].conj[1].b = 0.500000;
    var[4].conj[1].c = 0.500000;
    var[4].conj[1].d = 0.750000;
    // Conjunto trapezio Ag
    var[4].conj[2].tipo = CONJ_T;
    var[4].conj[2].a = 0.500000;
    var[4].conj[2].b = 0.750000;
    var[4].conj[2].c = 1.000000;
    var[4].conj[2].d = 1.000000;

    // Regras
    regras[0].conjEntrada[0] = 0;
    regras[0].conjEntrada[1] = 0;
    regras[0].conjEntrada[2] = 0;
    regras[0].conjEntrada[3] = 1;
    regras[0].conjSaida[0] = 1;
    regras[1].conjEntrada[0] = 0;
    regras[1].conjEntrada[1] = 0;
    regras[1].conjEntrada[2] = 0;
    regras[1].conjEntrada[3] = 3;
    regras[1].conjSaida[0] = 3;
    regras[2].conjEntrada[0] = 1;
    regras[2].conjEntrada[1] = 1;
    regras[2].conjEntrada[2] = 1;
    regras[2].conjEntrada[3] = 2;
    regras[2].conjSaida[0] = 3;
    regras[3].conjEntrada[0] = 1;
    regras[3].conjEntrada[1] = 1;
    regras[3].conjEntrada[2] = 2;
    regras[3].conjEntrada[3] = 2;
    regras[3].conjSaida[0] = 2;
    regras[4].conjEntrada[0] = 1;
    regras[4].conjEntrada[1] = 1;
    regras[4].conjEntrada[2] = 3;
    regras[4].conjEntrada[3] = 2;
    regras[4].conjSaida[0] = 2;
    regras[5].conjEntrada[0] = 2;
    regras[5].conjEntrada[1] = 1;
    regras[5].conjEntrada[2] = 1;
    regras[5].conjEntrada[3] = 2;
    regras[5].conjSaida[0] = 3;
    regras[6].conjEntrada[0] = 2;
    regras[6].conjEntrada[1] = 1;
    regras[6].conjEntrada[2] = 2;
    regras[6].conjEntrada[3] = 2;
    regras[6].conjSaida[0] = 3;
    regras[7].conjEntrada[0] = 2;
    regras[7].conjEntrada[1] = 1;
    regras[7].conjEntrada[2] = 3;
    regras[7].conjEntrada[3] = 2;
    regras[7].conjSaida[0] = 2;
    regras[8].conjEntrada[0] = 3;
    regras[8].conjEntrada[1] = 1;
    regras[8].conjEntrada[2] = 1;
    regras[8].conjEntrada[3] = 2;
    regras[8].conjSaida[0] = 3;
    regras[9].conjEntrada[0] = 3;
    regras[9].conjEntrada[1] = 1;
    regras[9].conjEntrada[2] = 2;
    regras[9].conjEntrada[3] = 2;
    regras[9].conjSaida[0] = 3;
    regras[10].conjEntrada[0] = 3;
    regras[10].conjEntrada[1] = 1;
    regras[10].conjEntrada[2] = 3;
    regras[10].conjEntrada[3] = 2;
    regras[10].conjSaida[0] = 2;
    regras[11].conjEntrada[0] = 1;
    regras[11].conjEntrada[1] = 2;
    regras[11].conjEntrada[2] = 1;
    regras[11].conjEntrada[3] = 2;
    regras[11].conjSaida[0] = 3;
    regras[12].conjEntrada[0] = 1;
    regras[12].conjEntrada[1] = 2;
    regras[12].conjEntrada[2] = 2;
    regras[12].conjEntrada[3] = 2;
    regras[12].conjSaida[0] = 1;
    regras[13].conjEntrada[0] = 1;
    regras[13].conjEntrada[1] = 2;
    regras[13].conjEntrada[2] = 3;
    regras[13].conjEntrada[3] = 2;
    regras[13].conjSaida[0] = 1;
    regras[14].conjEntrada[0] = 2;
    regras[14].conjEntrada[1] = 2;
    regras[14].conjEntrada[2] = 1;
    regras[14].conjEntrada[3] = 2;
    regras[14].conjSaida[0] = 3;
    regras[15].conjEntrada[0] = 2;
    regras[15].conjEntrada[1] = 2;
    regras[15].conjEntrada[2] = 2;
    regras[15].conjEntrada[3] = 2;
    regras[15].conjSaida[0] = 2;
    regras[16].conjEntrada[0] = 2;
    regras[16].conjEntrada[1] = 2;
    regras[16].conjEntrada[2] = 3;
    regras[16].conjEntrada[3] = 2;
    regras[16].conjSaida[0] = 1;
    regras[17].conjEntrada[0] = 3;
    regras[17].conjEntrada[1] = 2;
    regras[17].conjEntrada[2] = 1;
    regras[17].conjEntrada[3] = 2;
    regras[17].conjSaida[0] = 3;
    regras[18].conjEntrada[0] = 3;
    regras[18].conjEntrada[1] = 2;
    regras[18].conjEntrada[2] = 2;
    regras[18].conjEntrada[3] = 2;
    regras[18].conjSaida[0] = 3;
    regras[19].conjEntrada[0] = 3;
    regras[19].conjEntrada[1] = 2;
    regras[19].conjEntrada[2] = 3;
    regras[19].conjEntrada[3] = 2;
    regras[19].conjSaida[0] = 2;
    regras[20].conjEntrada[0] = 1;
    regras[20].conjEntrada[1] = 3;
    regras[20].conjEntrada[2] = 1;
    regras[20].conjEntrada[3] = 2;
    regras[20].conjSaida[0] = 3;
    regras[21].conjEntrada[0] = 1;
    regras[21].conjEntrada[1] = 3;
    regras[21].conjEntrada[2] = 2;
    regras[21].conjEntrada[3] = 2;
    regras[21].conjSaida[0] = 3;
    regras[22].conjEntrada[0] = 1;
    regras[22].conjEntrada[1] = 3;
    regras[22].conjEntrada[2] = 3;
    regras[22].conjEntrada[3] = 2;
    regras[22].conjSaida[0] = 2;
    regras[23].conjEntrada[0] = 2;
    regras[23].conjEntrada[1] = 3;
    regras[23].conjEntrada[2] = 1;
    regras[23].conjEntrada[3] = 2;
    regras[23].conjSaida[0] = 3;
    regras[24].conjEntrada[0] = 2;
    regras[24].conjEntrada[1] = 3;
    regras[24].conjEntrada[2] = 2;
    regras[24].conjEntrada[3] = 2;
    regras[24].conjSaida[0] = 2;
    regras[25].conjEntrada[0] = 2;
    regras[25].conjEntrada[1] = 3;
    regras[25].conjEntrada[2] = 3;
    regras[25].conjEntrada[3] = 2;
    regras[25].conjSaida[0] = 2;
    regras[26].conjEntrada[0] = 3;
    regras[26].conjEntrada[1] = 3;
    regras[26].conjEntrada[2] = 1;
    regras[26].conjEntrada[3] = 2;
    regras[26].conjSaida[0] = 2;
    regras[27].conjEntrada[0] = 3;
    regras[27].conjEntrada[1] = 3;
    regras[27].conjEntrada[2] = 2;
    regras[27].conjEntrada[3] = 2;
    regras[27].conjSaida[0] = 2;
    regras[28].conjEntrada[0] = 3;
    regras[28].conjEntrada[1] = 3;
    regras[28].conjEntrada[2] = 3;
    regras[28].conjEntrada[3] = 2;
    regras[28].conjSaida[0] = 2;

    FuzzySystem fuzzy(MAMDANI, ORMETHOD_, ANDMETHOD_ÀÂï, 4, 1, 29, var, regras);
    return fuzzy.rodarSistema(x);

}