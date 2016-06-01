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
    Regra regras[46];
    unsigned char i;

    for (i=0;i<46;i++) {
    regras[i].conjEntrada = (unsigned char*) malloc(4*sizeof(unsigned char));
    regras[i].conjSaida = (unsigned char*)   malloc(1*sizeof(unsigned char));
    }


    // Variavel healthBot
    var[0].min = 0.000000;
    var[0].max = 100.000000;
    var[0].numConjuntos = 3;
    var[0].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[0].conj[0].tipo = CONJ_T;
    var[0].conj[0].a = 0.000000;
    var[0].conj[0].b = 0.000000;
    var[0].conj[0].c = 25.000000;
    var[0].conj[0].d = 50.000000;
    // Conjunto triangulo Me
    var[0].conj[1].tipo = CONJ_T;
    var[0].conj[1].a = 25.000000;
    var[0].conj[1].b = 50.000000;
    var[0].conj[1].c = 50.000000;
    var[0].conj[1].d = 75.000000;
    // Conjunto trapezio Hi
    var[0].conj[2].tipo = CONJ_T;
    var[0].conj[2].a = 50.000000;
    var[0].conj[2].b = 75.000000;
    var[0].conj[2].c = 100.000000;
    var[0].conj[2].d = 100.000000;

    // Variavel ammoBot
    var[1].min = 0.000000;
    var[1].max = 30.000000;
    var[1].numConjuntos = 3;
    var[1].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[1].conj[0].tipo = CONJ_T;
    var[1].conj[0].a = 0.000000;
    var[1].conj[0].b = 0.000000;
    var[1].conj[0].c = 7.500000;
    var[1].conj[0].d = 15.000000;
    // Conjunto triangulo Me
    var[1].conj[1].tipo = CONJ_T;
    var[1].conj[1].a = 7.500000;
    var[1].conj[1].b = 15.000000;
    var[1].conj[1].c = 15.000000;
    var[1].conj[1].d = 22.500000;
    // Conjunto trapezio Hi
    var[1].conj[2].tipo = CONJ_T;
    var[1].conj[2].a = 15.000000;
    var[1].conj[2].b = 22.500000;
    var[1].conj[2].c = 30.000000;
    var[1].conj[2].d = 30.000000;

    // Variavel healthEnemy
    var[2].min = 0.000000;
    var[2].max = 100.000000;
    var[2].numConjuntos = 3;
    var[2].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[2].conj[0].tipo = CONJ_T;
    var[2].conj[0].a = 0.000000;
    var[2].conj[0].b = 0.000000;
    var[2].conj[0].c = 25.000000;
    var[2].conj[0].d = 50.000000;
    // Conjunto triangulo Me
    var[2].conj[1].tipo = CONJ_T;
    var[2].conj[1].a = 25.000000;
    var[2].conj[1].b = 50.000000;
    var[2].conj[1].c = 50.000000;
    var[2].conj[1].d = 75.000000;
    // Conjunto trapezio Hi
    var[2].conj[2].tipo = CONJ_T;
    var[2].conj[2].a = 50.000000;
    var[2].conj[2].b = 75.000000;
    var[2].conj[2].c = 100.000000;
    var[2].conj[2].d = 100.000000;

    // Variavel ammoEnemy
    var[3].min = 0.000000;
    var[3].max = 30.000000;
    var[3].numConjuntos = 3;
    var[3].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[3].conj[0].tipo = CONJ_T;
    var[3].conj[0].a = 0.000000;
    var[3].conj[0].b = 0.000000;
    var[3].conj[0].c = 7.500000;
    var[3].conj[0].d = 15.000000;
    // Conjunto triangulo Me
    var[3].conj[1].tipo = CONJ_T;
    var[3].conj[1].a = 7.500000;
    var[3].conj[1].b = 15.000000;
    var[3].conj[1].c = 15.000000;
    var[3].conj[1].d = 22.500000;
    // Conjunto trapezio Hi
    var[3].conj[2].tipo = CONJ_T;
    var[3].conj[2].a = 15.000000;
    var[3].conj[2].b = 22.500000;
    var[3].conj[2].c = 30.000000;
    var[3].conj[2].d = 30.000000;

    // Variavel courage
    var[4].min = 0.000000;
    var[4].max = 1.000000;
    var[4].numConjuntos = 3;
    var[4].conj = (Conjunto *) malloc(3*sizeof(Conjunto));
    // Conjunto trapezio Lo
    var[4].conj[0].tipo = CONJ_T;
    var[4].conj[0].a = 0.000000;
    var[4].conj[0].b = 0.000000;
    var[4].conj[0].c = 0.250000;
    var[4].conj[0].d = 0.500000;
    // Conjunto triangulo Me
    var[4].conj[1].tipo = CONJ_T;
    var[4].conj[1].a = 0.250000;
    var[4].conj[1].b = 0.500000;
    var[4].conj[1].c = 0.500000;
    var[4].conj[1].d = 0.750000;
    // Conjunto trapezio Hi
    var[4].conj[2].tipo = CONJ_T;
    var[4].conj[2].a = 0.500000;
    var[4].conj[2].b = 0.750000;
    var[4].conj[2].c = 1.000000;
    var[4].conj[2].d = 1.000000;

    // Regras
    regras[0].conjEntrada[0] = 0;
    regras[0].conjEntrada[1] = 1;
    regras[0].conjEntrada[2] = 0;
    regras[0].conjEntrada[3] = 0;
    regras[0].conjSaida[0] = 1;
    regras[1].conjEntrada[0] = 1;
    regras[1].conjEntrada[1] = 2;
    regras[1].conjEntrada[2] = 1;
    regras[1].conjEntrada[3] = 1;
    regras[1].conjSaida[0] = 3;
    regras[2].conjEntrada[0] = 1;
    regras[2].conjEntrada[1] = 2;
    regras[2].conjEntrada[2] = 2;
    regras[2].conjEntrada[3] = 1;
    regras[2].conjSaida[0] = 2;
    regras[3].conjEntrada[0] = 1;
    regras[3].conjEntrada[1] = 2;
    regras[3].conjEntrada[2] = 3;
    regras[3].conjEntrada[3] = 1;
    regras[3].conjSaida[0] = 1;
    regras[4].conjEntrada[0] = 1;
    regras[4].conjEntrada[1] = 2;
    regras[4].conjEntrada[2] = 1;
    regras[4].conjEntrada[3] = 2;
    regras[4].conjSaida[0] = 2;
    regras[5].conjEntrada[0] = 1;
    regras[5].conjEntrada[1] = 2;
    regras[5].conjEntrada[2] = 2;
    regras[5].conjEntrada[3] = 2;
    regras[5].conjSaida[0] = 1;
    regras[6].conjEntrada[0] = 1;
    regras[6].conjEntrada[1] = 2;
    regras[6].conjEntrada[2] = 3;
    regras[6].conjEntrada[3] = 2;
    regras[6].conjSaida[0] = 1;
    regras[7].conjEntrada[0] = 1;
    regras[7].conjEntrada[1] = 2;
    regras[7].conjEntrada[2] = 1;
    regras[7].conjEntrada[3] = 3;
    regras[7].conjSaida[0] = 1;
    regras[8].conjEntrada[0] = 1;
    regras[8].conjEntrada[1] = 2;
    regras[8].conjEntrada[2] = 2;
    regras[8].conjEntrada[3] = 3;
    regras[8].conjSaida[0] = 1;
    regras[9].conjEntrada[0] = 1;
    regras[9].conjEntrada[1] = 2;
    regras[9].conjEntrada[2] = 3;
    regras[9].conjEntrada[3] = 3;
    regras[9].conjSaida[0] = 1;
    regras[10].conjEntrada[0] = 1;
    regras[10].conjEntrada[1] = 3;
    regras[10].conjEntrada[2] = 1;
    regras[10].conjEntrada[3] = 1;
    regras[10].conjSaida[0] = 3;
    regras[11].conjEntrada[0] = 1;
    regras[11].conjEntrada[1] = 3;
    regras[11].conjEntrada[2] = 2;
    regras[11].conjEntrada[3] = 1;
    regras[11].conjSaida[0] = 3;
    regras[12].conjEntrada[0] = 1;
    regras[12].conjEntrada[1] = 3;
    regras[12].conjEntrada[2] = 3;
    regras[12].conjEntrada[3] = 1;
    regras[12].conjSaida[0] = 2;
    regras[13].conjEntrada[0] = 1;
    regras[13].conjEntrada[1] = 3;
    regras[13].conjEntrada[2] = 1;
    regras[13].conjEntrada[3] = 2;
    regras[13].conjSaida[0] = 3;
    regras[14].conjEntrada[0] = 1;
    regras[14].conjEntrada[1] = 3;
    regras[14].conjEntrada[2] = 2;
    regras[14].conjEntrada[3] = 2;
    regras[14].conjSaida[0] = 2;
    regras[15].conjEntrada[0] = 1;
    regras[15].conjEntrada[1] = 3;
    regras[15].conjEntrada[2] = 3;
    regras[15].conjEntrada[3] = 2;
    regras[15].conjSaida[0] = 2;
    regras[16].conjEntrada[0] = 1;
    regras[16].conjEntrada[1] = 3;
    regras[16].conjEntrada[2] = 1;
    regras[16].conjEntrada[3] = 3;
    regras[16].conjSaida[0] = 2;
    regras[17].conjEntrada[0] = 1;
    regras[17].conjEntrada[1] = 3;
    regras[17].conjEntrada[2] = 2;
    regras[17].conjEntrada[3] = 3;
    regras[17].conjSaida[0] = 1;
    regras[18].conjEntrada[0] = 1;
    regras[18].conjEntrada[1] = 3;
    regras[18].conjEntrada[2] = 3;
    regras[18].conjEntrada[3] = 3;
    regras[18].conjSaida[0] = 1;
    regras[19].conjEntrada[0] = 2;
    regras[19].conjEntrada[1] = 2;
    regras[19].conjEntrada[2] = 1;
    regras[19].conjEntrada[3] = 1;
    regras[19].conjSaida[0] = 3;
    regras[20].conjEntrada[0] = 2;
    regras[20].conjEntrada[1] = 2;
    regras[20].conjEntrada[2] = 2;
    regras[20].conjEntrada[3] = 1;
    regras[20].conjSaida[0] = 3;
    regras[21].conjEntrada[0] = 2;
    regras[21].conjEntrada[1] = 2;
    regras[21].conjEntrada[2] = 3;
    regras[21].conjEntrada[3] = 1;
    regras[21].conjSaida[0] = 3;
    regras[22].conjEntrada[0] = 2;
    regras[22].conjEntrada[1] = 2;
    regras[22].conjEntrada[2] = 1;
    regras[22].conjEntrada[3] = 2;
    regras[22].conjSaida[0] = 3;
    regras[23].conjEntrada[0] = 2;
    regras[23].conjEntrada[1] = 2;
    regras[23].conjEntrada[2] = 2;
    regras[23].conjEntrada[3] = 2;
    regras[23].conjSaida[0] = 2;
    regras[24].conjEntrada[0] = 2;
    regras[24].conjEntrada[1] = 2;
    regras[24].conjEntrada[2] = 3;
    regras[24].conjEntrada[3] = 2;
    regras[24].conjSaida[0] = 1;
    regras[25].conjEntrada[0] = 2;
    regras[25].conjEntrada[1] = 2;
    regras[25].conjEntrada[2] = 1;
    regras[25].conjEntrada[3] = 3;
    regras[25].conjSaida[0] = 3;
    regras[26].conjEntrada[0] = 2;
    regras[26].conjEntrada[1] = 2;
    regras[26].conjEntrada[2] = 2;
    regras[26].conjEntrada[3] = 3;
    regras[26].conjSaida[0] = 1;
    regras[27].conjEntrada[0] = 2;
    regras[27].conjEntrada[1] = 2;
    regras[27].conjEntrada[2] = 3;
    regras[27].conjEntrada[3] = 3;
    regras[27].conjSaida[0] = 1;
    regras[28].conjEntrada[0] = 2;
    regras[28].conjEntrada[1] = 3;
    regras[28].conjEntrada[2] = 1;
    regras[28].conjEntrada[3] = 1;
    regras[28].conjSaida[0] = 3;
    regras[29].conjEntrada[0] = 2;
    regras[29].conjEntrada[1] = 3;
    regras[29].conjEntrada[2] = 2;
    regras[29].conjEntrada[3] = 1;
    regras[29].conjSaida[0] = 3;
    regras[30].conjEntrada[0] = 2;
    regras[30].conjEntrada[1] = 3;
    regras[30].conjEntrada[2] = 3;
    regras[30].conjEntrada[3] = 1;
    regras[30].conjSaida[0] = 3;
    regras[31].conjEntrada[0] = 2;
    regras[31].conjEntrada[1] = 3;
    regras[31].conjEntrada[2] = 1;
    regras[31].conjEntrada[3] = 2;
    regras[31].conjSaida[0] = 3;
    regras[32].conjEntrada[0] = 2;
    regras[32].conjEntrada[1] = 3;
    regras[32].conjEntrada[2] = 2;
    regras[32].conjEntrada[3] = 2;
    regras[32].conjSaida[0] = 3;
    regras[33].conjEntrada[0] = 2;
    regras[33].conjEntrada[1] = 3;
    regras[33].conjEntrada[2] = 3;
    regras[33].conjEntrada[3] = 2;
    regras[33].conjSaida[0] = 2;
    regras[34].conjEntrada[0] = 2;
    regras[34].conjEntrada[1] = 3;
    regras[34].conjEntrada[2] = 1;
    regras[34].conjEntrada[3] = 3;
    regras[34].conjSaida[0] = 3;
    regras[35].conjEntrada[0] = 2;
    regras[35].conjEntrada[1] = 3;
    regras[35].conjEntrada[2] = 2;
    regras[35].conjEntrada[3] = 3;
    regras[35].conjSaida[0] = 2;
    regras[36].conjEntrada[0] = 2;
    regras[36].conjEntrada[1] = 3;
    regras[36].conjEntrada[2] = 3;
    regras[36].conjEntrada[3] = 3;
    regras[36].conjSaida[0] = 1;
    regras[37].conjEntrada[0] = 3;
    regras[37].conjEntrada[1] = 2;
    regras[37].conjEntrada[2] = 1;
    regras[37].conjEntrada[3] = 1;
    regras[37].conjSaida[0] = 3;
    regras[38].conjEntrada[0] = 3;
    regras[38].conjEntrada[1] = 2;
    regras[38].conjEntrada[2] = 2;
    regras[38].conjEntrada[3] = 1;
    regras[38].conjSaida[0] = 3;
    regras[39].conjEntrada[0] = 3;
    regras[39].conjEntrada[1] = 2;
    regras[39].conjEntrada[2] = 3;
    regras[39].conjEntrada[3] = 1;
    regras[39].conjSaida[0] = 3;
    regras[40].conjEntrada[0] = 3;
    regras[40].conjEntrada[1] = 2;
    regras[40].conjEntrada[2] = 1;
    regras[40].conjEntrada[3] = 2;
    regras[40].conjSaida[0] = 3;
    regras[41].conjEntrada[0] = 3;
    regras[41].conjEntrada[1] = 2;
    regras[41].conjEntrada[2] = 2;
    regras[41].conjEntrada[3] = 2;
    regras[41].conjSaida[0] = 3;
    regras[42].conjEntrada[0] = 3;
    regras[42].conjEntrada[1] = 2;
    regras[42].conjEntrada[2] = 3;
    regras[42].conjEntrada[3] = 2;
    regras[42].conjSaida[0] = 2;
    regras[43].conjEntrada[0] = 3;
    regras[43].conjEntrada[1] = 2;
    regras[43].conjEntrada[2] = 1;
    regras[43].conjEntrada[3] = 3;
    regras[43].conjSaida[0] = 3;
    regras[44].conjEntrada[0] = 3;
    regras[44].conjEntrada[1] = 2;
    regras[44].conjEntrada[2] = 2;
    regras[44].conjEntrada[3] = 3;
    regras[44].conjSaida[0] = 2;
    regras[45].conjEntrada[0] = 3;
    regras[45].conjEntrada[1] = 2;
    regras[45].conjEntrada[2] = 3;
    regras[45].conjEntrada[3] = 3;
    regras[45].conjSaida[0] = 2;

    FuzzySystem fuzzy(MAMDANI, ORMETHOD_, ANDMETHOD_À‚‚, 4, 1, 46, var, regras);
    return fuzzy.rodarSistema(x);

}