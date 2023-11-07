#include "header_jeu.h"

void Jeu::initialisation_allegro()
{
    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(desktop_color_depth());
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1280,720,0,0))!=0)
    {
        allegro_message("Probleme initialisation mode graphique\n ");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    show_mouse(screen);
}

///////////////////////////////

