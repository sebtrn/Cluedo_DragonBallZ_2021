#include "header_jeu.h"

using namespace std;

int main()
{
    Jeu Jeu1;
    Jeu1.initialisation_allegro();
    Jeu1.animation();
    Jeu1.menuPrincipal();


    allegro_exit();
    return 0;
}END_OF_MAIN();
