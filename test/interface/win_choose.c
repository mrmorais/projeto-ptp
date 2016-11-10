#include <ncurses.h>
#include "window.h"

WINDOW *win_choose() {
  WINDOW *lw = create_newwin();
  int x = 6; int y = 36;
  wmove(lw, x, y);
  wprintw(lw, "______           _                        _         ________  ________ "); wmove(lw, x+1, y);
  wprintw(lw, "| ___ \\         | |                      | |       |_   _|  \\/  |  _  \\"); wmove(lw, x+2, y);
  wprintw(lw, "| |_/ /_   _  __| | ___  __ _  __ _    __| | ___     | | | .  . | | | |"); wmove(lw, x+3, y);
  wprintw(lw, "| ___ \\ | | |/ _` |/ _ \\/ _` |/ _` |  / _` |/ _ \\    | | | |\\/| | | | |"); wmove(lw, x+4, y);
  wprintw(lw, "| |_/ / |_| | (_| |  __/ (_| | (_| | | (_| | (_) |  _| |_| |  | | |/ / "); wmove(lw, x+5, y);
  wprintw(lw, "\\____/ \\__,_|\\__,_|\\___|\\__, |\\__,_|  \\__,_|\\___/   \\___/\\_|  |_/___/  "); wmove(lw, x+6, y);
  wprintw(lw, "                         __/ |                                         "); wmove(lw, x+7, y);
  wprintw(lw, "                        |___/                                          "); move(0, 0);


  wrefresh(lw);

  return lw;
}
