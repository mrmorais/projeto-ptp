#include <ncurses.h> //Incluiremos a biblioteca ao nosso sistema
#include <stdio.h>
#include <stdlib.h>

void sair (void);  //Esta função fará com que o programa seja fechado

int main(void)
{
    initscr();   /*Esta função  inicializa a ncurses. Para todos os programas
                   devemos sempre inicializar a ncurses e depois finalizar, como
                  veremos adiante. */

    start_color(); //Esta função torna possível o uso das cores

//Abaixo estamos definindo os pares de cores que serão utilizados no programa
    init_pair(1,COLOR_WHITE,COLOR_BLUE); //Texto(Branco) | Fundo(Azul)
    init_pair(2,COLOR_BLUE,COLOR_WHITE); //Texto(Azul) | Fundo(Branco)
    init_pair(3,COLOR_RED,COLOR_WHITE);  //Texto(Vermelho) | Fundo(Branco)

    bkgd(COLOR_PAIR(1));  /*Aqui nós definiremos que a cor de fundo do nosso
                                      programa será azul e a cor dos textos será branca.*/

    attron(COLOR_PAIR(1)); /*Estamos alterando o par de cores para 3 em vez
                                          de utilizar o par de cor por omissão(1).*/
    int x = 12, y = 38;
    move(x,y);  //Aqui estamos movendo o cursor para a linha 2 coluna 1.
    printw("______           _                        _         ________  ________ "); move(x+1,y);  //Imprimimos um texto na tela na posição acima.
    printw("| ___ \\         | |                      | |       |_   _|  \\/  |  _  \\"); move(x+2,y);
    printw("| |_/ /_   _  __| | ___  __ _  __ _    __| | ___     | | | .  . | | | |"); move(x+3,y);
    printw("| ___ \\ | | |/ _` |/ _ \\/ _` |/ _` |  / _` |/ _ \\    | | | |\\/| | | | |"); move(x+4,y);
    printw("| |_/ / |_| | (_| |  __/ (_| | (_| | | (_| | (_) |  _| |_| |  | | |/ / "); move(x+5,y);
    printw("\\____/ \\__,_|\\__,_|\\___|\\__, |\\__,_|  \\__,_|\\___/   \\___/\\_|  |_/___/  "); move(x+6,y);
    printw("                         __/ |                                         "); move(x+7,y);
    printw("                        |___/                                          ");move(x+8,y);

    attroff(COLOR_PAIR(3));  /*Estamos alterando o par com a cor por omissão,
                             ou seja, retornando para o par de cor 1. */
    attron(COLOR_PAIR(2));
    //move(3,1);
    //printw("Qualquer tecla para sair."); /*Imprimimos um texto na tela na
    attroff(COLOR_PAIR(2));
    refresh();    //Atualiza a tela
    getch();      //Fica esperando que o usuário aperte alguma tecla

    sair();    // Sai do programa
}

void sair()
{
    endwin(); /*Sempre que finalizarmos um programa com a biblioteca curses,
                     devemos executar este comando.*/
    //exit(0);
}
