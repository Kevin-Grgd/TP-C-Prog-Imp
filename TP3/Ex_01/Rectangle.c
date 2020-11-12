#include <MLV/MLV_all.h>

int main() {
  MLV_create_window("rectangle","shapes",1080,720);

  MLV_draw_filled_rectangle(5,5,1070,710, MLV_COLOR_RED);
  MLV_actualise_window();
  MLV_wait_seconds(15);
  return 1;
}
