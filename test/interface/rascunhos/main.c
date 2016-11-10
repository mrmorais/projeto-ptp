#include <stdlib.h>
#include <ncurses.h>

int main() {
  int ch;
  initscr(); //Start ncurses
  raw(); //Line buffering disabled
  keypad(stdscr, TRUE);
  noecho(); //Don't echo()

  printw("Type any character\n");

  ch = getch();

  if(ch == KEY_F(1))
    printw("F1 Key pressed");
  else
  {
    printw("The pressed key is ");
    attron(A_BOLD);
    printw("%c", ch);
    attroff(A_BOLD);
  }
  refresh();
  getch();
  endwin();
  return 0;
}
