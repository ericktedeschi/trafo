/* Programa: trafo
** Arquivo: trafo.c
** Descricao: Programa para realizar calculos para a confeccao de
**            Transformadores de pequena e media potencia.
** Autor: Erick Belluci Tedeschi 06/2001
*/
#include <stdio.h>
#include <ncurses.h>
#include <math.h>

void tela();
void num();

main()
{
 float a = 0, vs = 0, w = 0, vp = 0;
 int ps = 0;
 float wp = 0;
 float area = 0;
 float esppri = 0, espiravolt = 0, espsec = 0;
 float fiop = 0, fios = 0;
 char opcao;
 // Inicia Curses
 initscr();
 cbreak();
 clear();
 scrollok(stdscr, TRUE);
 idlok(stdscr, TRUE);
 echo();
 attrset(A_BOLD);
 box(stdscr, 0, 0);
 start_color();
 init_pair(2, COLOR_YELLOW, COLOR_BLACK);
 attrset(COLOR_PAIR(2) | A_BOLD);
 
 mvprintw(2, 17, "00000000  00000    00000   0000000   00000 ");
 mvprintw(3, 17, "   00     00  00  00   00  00       00   00");
 mvprintw(4, 17, "   00     00000   00   00  00000    00   00");
 mvprintw(5, 17, "   00     00  00  0000000  00       00   00");
 mvprintw(6, 17, "   00     00  00  00   00  00        00000 ");

 init_pair(1, COLOR_BLUE, COLOR_GREEN);
 attrset(COLOR_PAIR(1));
 mvprintw(10, 12, "                                                      ");
 mvprintw(11, 12, "    Cálculo de Transformadores de Pequena Potência    ");  
 mvprintw(12, 12, "                         2001                         ");
 mvprintw(13, 12, "                                                      ");
 attrset(A_NORMAL);
 mvprintw(17, 21, " Created by - Erick Belluci Tedeschi "); attrset(A_BOLD);
 mvprintw(18, 21, "   E-mail: erickbt86@yahoo.com.br    ");
 beep();

 getch();
 clear();
 inicio:
 attrset(A_BOLD);
 box(stdscr, 0, 0);
 mvprintw(1, 2, "Transformador v.1.0");
 attrset(A_BLINK);
 mvprintw(5, 37, "http://utenti.lycos.it/simplix");
 init_pair(4, COLOR_YELLOW, COLOR_BLUE);
 attrset(COLOR_PAIR(4) | A_BOLD);
 mvprintw(3, 2, "                         ");
 mvprintw(4, 2, "                         ");
 mvprintw(5, 2, "                         ");
 mvprintw(6, 2, "                         ");
 mvprintw(7, 2, "                         ");
 mvprintw(4, 4, "Volts primário: "); scanw("%f", &vp);
 beep();
 mvprintw(5, 4, "Volts Secundário: "); scanw("%f", &vs);
 beep();
 mvprintw(6, 4, "Ampéres: "); scanw("%f", &a);
 beep();
 w = vs * a; tela();
  
 init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
 attrset(COLOR_PAIR(3) | A_BOLD);
 mvprintw(11, 4, "1 - Watts Secundário: %5.2f", w);
 if(w == 1.5) ps = 50;
 if(w > 1.5 && w < 2.1) ps = 53;
 if(w == 2.1) ps = 55;
 if(w > 2.1 && w < 2.8) ps = 57;
 if(w == 2.8) ps = 60;
 if(w > 2.8 && w < 4.4) ps = 63;
 if(w == 4.4) ps = 65;
 if(w > 4.4 && w < 6.0) ps = 67;
 if(w == 6.0) ps = 70;
 if(w > 6.0 && w < 13) ps = 73;
 if(w == 13) ps = 75;
 if(w > 13 && w < 20) ps = 77;
 if(w == 20) ps = 80;
 if(w > 20 && w < 55) ps = 83;
 if(w == 55) ps = 85;
 if(w > 55 && w < 250) ps = 87;
 if(w == 250) ps = 90;
 if(w > 250 && w < 500) ps = 92;
 if(w == 500) ps = 93;
 if(w > 500 && w < 1000) ps = 94;
 if(w == 1000) ps = 95;
 if(w > 1000) ps = 97;
 wp = (w / ps) * 100;

 mvprintw(12, 4, "2 - Watts primário - %3.2f  /  Rendimento - %d%", wp, ps);
 area = (sqrt( wp ) / 0.7);
 mvprintw(13, 4, "3 - Área do Núcleo: %5.2f Centímetros^2", area);
 esppri = ((vp / area) * 37.5);
 mvprintw(14, 4, "4 - Espiras do Primério: %5.2f", esppri);
 espiravolt = (esppri / vp);
 mvprintw(15, 4, "5 - Relação Espiravolt: %5.2f", espiravolt);
 espsec = (vs * espiravolt);
 mvprintw(16, 4, "6 - Espiras Secundário: %5.2f", espsec);
 fiop = (wp / vp);
 fios = (w /vs);
 mvprintw(17, 4, "7 - Corrente do Primério em Ampéres: %5.2f ", fiop); 
 mvprintw(18, 4, "8                        Secundário: %5.2f ", fios);
 num();
 opcao:
 attrset(A_BOLD);
 mvprintw(22, 2, "Deseja fazer outro cálculo? (S/N) ");
 switch ( getch() )
 {
  case 'S':
  case 's':
  {
   goto inicio;
   break;
  }
  case 'N':
  case 'n':
  {
   goto fim;
   break;
  }
  default: goto opcao; break;
 }
 fim:
 clear();
 refresh();
 endwin();
 return 0;
}

void tela()
{
 init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
 attrset(COLOR_PAIR(1));
 mvprintw(10, 2, "                                                           ");
 mvprintw(11, 2, "  							     ");
 mvprintw(12, 2, "							     ");
 mvprintw(13, 2, "						             ");
 mvprintw(14, 2, "							     ");
 mvprintw(15, 2, "							     ");
 mvprintw(16, 2, "							     ");
 mvprintw(17, 2, "							     ");
 mvprintw(18, 2, "							     ");
 mvprintw(19, 2, "							     ");

 attrset(A_NORMAL);
}

void num()
{
 int x, y = 10;
 init_pair(1, COLOR_GREEN, COLOR_YELLOW);
 attrset(COLOR_PAIR(1));
 for(x = 1; x < 9; x++)
 {
  y++;
  mvprintw(y, 4, "%d", x);
 }
}
