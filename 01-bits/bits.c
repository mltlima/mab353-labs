/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Se possível, tentando pensar em qual seria mais
 * eficiente.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utlizou para realizar a tarefa (dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível (como qualquer
 *          código), imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Aluno: Miguel Lima Tavares
 *      DRE: 119161571
 *      Aluno: Vinicius dos Santos Bahia
 *      DRE: 118176565
 *      versão do GCC utilizada: XXXX
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>


/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */
int32_t ehPar(int32_t x) {
    return (x ^ 1) & 1;
}
/* 
    Checando se um número bnário é par ou ímpar:
    - se o LSb de x é 1, x é ímpar (retorna 0);
    - se o LSb de x é 0, x é par (retorna 1);

    A ideia é verificar se o último bit do número x é 1 ou não. 
    Se o último bit for 1, o número é ímpar, caso contrário, é par. 
    Como sabemos, a operação XOR bit a bit de um número qualquer por 1
    incrementa o valor do número em 1 se o número for par, caso contrário, 
    diminui o valor do número em 1 se o valor for ímpar.
        exemplo:
                    0111
                ^   0001
                =   0110
    Como queremos retornar apenas 1 ou 0, após a operação XOR usa-se a 
    operação AND bit a bit com a máscara 1, para persistir apenas o LSb
    e zerar o restante dos bits.
        exemplo:
                    0110
                &   0001
                =   0000
     */

/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */
int32_t mod8(int32_t x) {
    return (x & 7);
}
/**
 * Como 8 e uma potencia de 2 ele e representado por um unico 1 e zeros
 * ao diminuir 1 teremos um numero composto somente por ums.
 * Fazendo um and bit a bit qualquer numero diferente de 1 retona 0
 * assim o numero maximo que pode ser retornado e 7.
 * Ou seja, 2^3 3 bits menos significativos serao
 * preservados e os bits alem do terceiro bit serao forcados a zero
 */

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
int32_t negativo(int32_t x) {
   return ((~x) + 1);
}
/* 
    Para representar um número em sua forma negativa,
    basta representá-lo em complemento a 2, o que consiste
    em aplicar um NOT bit a bit no número, somando-se 1 ao
    final.
     */


/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
    return ~(~x | ~y);
}
/* 
    Em uma operação AND entre dois termos, se um dos termos for zero,
    necessariamente o resultado será zero. Portanto, para implementar
    um AND bit a bit entre X e Y, basta focar em gerar um resultado 
    que obtenha bits iguais nas mesmas posições em que haviam zeros em X e Y.
    Nas posições que não havia zero, deve-se preencher com o bit oposto ao anterior.
    Conseguimos isso aplicando um OR bit a bit entre um ~X e um ~Y.
        Exemplo:
            x        0011
            y        1011
            ~x       1100
            ~y       0100
            ~x|~y    1100

    Agora que se tem todas as posições (relativas às posições de X ou Y em que haviam 0)
    preenchidas com 1 e o restante das posições preenchidas com 0, temos a resposta equivalente
    a um AND bit a bit com cada bit negado. Precisa-se então negar o resultado bit a bit para
    a implementação exata de um &.
            x        0011
            y        1011
            x&y      0011
            ~(~x|~y) 0011
     */

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> !
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
int32_t ehIgual(int32_t x, int32_t y) {
     return (!(x ^ y));
}
/* 
    Dois números serão iguais quando todos os bits entre eles
    forem iguais dadas as mesmas posições.
    Para implementar uma comparação de igualdade entre X e Y, 
    pode-se usar o XOR bit a bit entre X e Y. Assim, o resultado
    obtido será zero apenas se todos os bits comparados forem iguais em
    X e Y nas mesmas posições. Caso contrário, o resultado sempre será
    diferente de zero. 
    Se temos 
        zero quando X e Y são iguais 
        e
        diferente-de-zero quando X e Y forem diferentes
    basta negar todo o resultado, já que queremos justamente o contrário:
        quando iguais, retorna um
        quando diferentes, retorna zero
    Isto é possível, pois o operador ! aplicado a um número diferente de zero,
    retorna zero e quando ! é aplicado a zero, retorna um.
     */

/* Limpa bit n
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 4
 *      Monitor: 3
 *
 *      Retorna o x com o bit n = 0,
 *      n pode variar entre 0 e 31, do LSB ao MSB
 *
 *      Exemplo:
 *          limpaBitN(3, 0) -> 2
 *          limpaBitN(3, 1) -> 1
 */
int32_t limpaBitN(int32_t x, int8_t n) {
    return (x & ~(1 << n));
}
/* 
    A ideia aqui é criar uma máscara totalmente preenchida
    de 1, exceto na posição n, na qual será preenchida com zero.
    Assim, aplicando a operação AND bit a bit de X com a máscara obtida,
    persistiremos todos os bits de X, exceto o da posição n, que sempre será 
    zero (pois um AND com um dos termos em zero sempre resulta em zero).
    Para criar a máscara, basta shiftar o número um à esquerda n vezes e depois
    negar bit a bit o resultado. Assim, teremos inicialmente todos os bits da máscara
    em 0, exceto o da posição n que estará em 1, e após aplicar o ~ todos os bits se
    inverterão.
        exemplo: n = 2
        1       0001
        1<<n    0100
        ~(1<<n) 1011
     */

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    return ((x >> p) & 1);
}
/* 
    O algoritmo usado aqui consiste em shiftar
    x à direita p vezes, para que o bit na posição p
    desejado passe a ser o LSb. Para então retornarmos
    apenas o número correspondente ao bit do LSb, precisamos
    zerar o restante dos bits. A maneira mais prática de fazer
    isso é aplicando um AND com a máscara 00000...0001 (ou simplesmente 1), 
    que preservará apenas o bit de X relativo à posição em que a máscara possui 
    bit = 1, que no caso é o LSb. 
     */

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
int32_t byteEmP(int32_t x, uint8_t p) {
    return ((x >> (p << 3)) & 0xFF);
}
/* 
    Aqui a idéia é parecida com a questão acima de bitEmP.
    Sabendo que 1 Byte = 8 bits, para transladarmos o byte
    na posição p para o LSB (Byte menos significativo), devemos
    shiftar x à direita em múltiplos de 8. No caso, como p assume
    valores possíveis 0 ou 1 ou 2 ou 3, que equivalem às posições
    de cada Byte, sabemos que para levar o Byte de posição p para
    o LSB (Byte menos significativo), devemos shiftar X à direita
    em p*8 vezes.
    A multiplicação de p por 8 pode ser feita com 3 shifts à esquerda 
    de p, já que cada shif à esquerda representa uma multiplicação por 2,
    e 2 elevado a 3 é igual a 8.
    por fim, como queremos retornar apenas o byte desejado (até então nbo LSB),
    devemos aplicar um AND com máscara que zere todos os outros bits que não sejam
    relativos ao primeiro Byte. A máscara para isso seria o binário 0000...0011111111,
    com apenas os oito primeiros bits em 1 e o restante em 0. Isso equivale ao número
    FF em hexadecimal.
     */

/*
 * Seta byte na posição p do inteiro x como y
 *      Permitido:
 *          Operações: << >> | ~ ! &
 *
 *      Número máximo de operações: 7
 *      Monitor: 5
 *
 *      Retorna x com o valor y no byte da posição p
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          setaByteEmP(0x12345678, 0xFF, 0) -> 0x123456FF
 *          setaByteEmP(0x12345678, 0xFF, 1) -> 0x1234FF78
 *          setaByteEmP(0x12345678, 0xFF, 2) -> 0x12FF5678
 *          setaByteEmP(0x12345678, 0xFF, 3) -> 0xFF345678
 *
 */
int32_t setaByteEmP(int32_t x, int32_t y, uint8_t p) {
    return (y<<(p<<3)) | (x & (~(0xff << (p << 3))));
}
/* 
    Para setar um Byte Y em uma posição específica P de um
    número X, será necessário primeiro posicionar o Byte Y na 
    posição em que se quer inserir (P), com o restante dos bits em zero.
    Tendo isso pronto, precisamos zerar todos os bits relativos às posições
    do Byte que se inicia na posição P de X.
    Com os dois resultados prontos, "encaixar" um no outro é possível
    aplicando um OR bit a bit entre os dois resultados. Assim, persistirão
    todos os bits de X, exceto os da posições relativas ao Byte iniciado em P,
    pois estes estarão valendo zero, fazendo com que persista apenas os bits dessas
    posições relativos ao Y.

    As operações para posicionar Y na posição correta inicialmente já foram explicadas
    em exercícios anteriores, como byteEmP.
    As operações para zerar o o Byte em P no número X consistem em criar uma máscara
    com todos os bits em 1, exceto os da posições relativas ao byte em P (que ficarão em 0),
    para então aplicar-se o & com X e obter a mesma sequência de bits de X, exceto o trecho com
    posição relativa aos bits 0 da máscara, pois estes bits valerão 0 necessariamente.
     */

/*
 * Minimo
 *      Permitido:
 *          Operações: << >> | ^ < > ~ ! & -
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna o menor numero entre x e y
 *
 *      Exemplo:
 *          minimo(10, 15) -> 10
 *          minimo(-2, -1) -> -2
 *          minimo(-1, 2) -> -1
 *
 */
int32_t minimo(int32_t x, int32_t y) {
    return (y ^ ((x ^ y) & -(x < y)));
}
/* 
    -(x < y) será 0 se x >= y e será -1 (i.e. um int com todos os bits valendo 1) se x < y.
    Observe que, para todo N:
        (N & -1) = N    
            e    
        (N & 0) = 0
    Então, se (x < y), nós recebemos (y ^ x ^ y), o que é igual a x porque (y ^ y) se cancela. 
    E caso contrário, nós recebemos (y ^ 0), que é y. 
    Então, recebemos x se (x < y) e y se !(x < y), o que é exatamente o que queremos.
     */
     
/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & + ~
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
int32_t negacaoLogica(int32_t x) {
  return (((~x+1)|x)>>31)+1;
}
/**
 * o right shift maximo que podemos dar e 31 bits para nao haver um overflow
 * ao fazer o shift em x e em seu inverso, temos garantido que um desses dois
 * sera negativo e o shift feito o colocara em  0xFFFFFFFF. Entao fazemos o or
 * para obter o numero que queremos negativo e fazemos o complemento a dois 
 * para obter a negacao  
 */

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: limpaBitN");
    teste(limpaBitN(1,0), 0);
    teste(limpaBitN(0b1111,1), 0b1101);
    teste(limpaBitN(15,3), 7);
    teste(limpaBitN(-1,31), 2147483647);
    teste(limpaBitN(-1,0), -2);
    teste(limpaBitN(2147483647, 30), 1073741823);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: setaByteEmP");
    teste(setaByteEmP(0x00, 0xFF, 0), 0x000000FF);
    teste(setaByteEmP(0x00, 0xFF, 1), 0x0000FF00);
    teste(setaByteEmP(0x00, 0xFF, 2), 0x00FF0000);
    teste(setaByteEmP(0x00, 0xFF, 3), 0xFF000000);
    teste(setaByteEmP(0x01234567, 0x33, 2), 0x01334567);
    teste(setaByteEmP(0xdeadbeef, 0x00, 0), 0xdeadbe00);
    teste(setaByteEmP(0xdeadbeef, 0x00, 1), 0xdead00ef);
    puts("");

    puts("Teste: minimo");
    teste(minimo(0,1), 0);
    teste(minimo(0,10), 0);
    teste(minimo(1, 128), 1);
    teste(minimo(-1, 0), -1);
    teste(minimo(-1, -2), -2);
    teste(minimo(2147483647, 2147483646), 2147483646);
    teste(minimo(-2147483648, -2147483647), -2147483648);
    teste(minimo(-2147483648, -1), -2147483648);
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");

}
