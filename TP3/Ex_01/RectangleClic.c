#include <MLV/MLV_all.h>

#define RED 1
#define BLUE 2

int main() {
  int c = RED;
  int x,y;
  int clique = 0;
  MLV_create_window("rectangle","shapes",1080,720);
 

  MLV_draw_filled_rectangle(5,5,1070,710, MLV_COLOR_RED);
  MLV_actualise_window();
  MLV_wait_mouse(&x,&y);

  while (clique != 1) {
    if (c == RED) {
      MLV_clear_window(MLV_COLOR_BLACK);
      MLV_draw_filled_rectangle(5,5,1070,710, MLV_COLOR_BLUE);
      MLV_actualise_window();
      MLV_wait_mouse(&x,&y);
      c = BLUE;
    }  else {
      MLV_clear_window(MLV_COLOR_BLACK);
      MLV_draw_filled_rectangle(5,5,1070,710, MLV_COLOR_RED);
      MLV_actualise_window();
      MLV_wait_mouse(&x,&y);
      c = RED;
    }
  }
}
