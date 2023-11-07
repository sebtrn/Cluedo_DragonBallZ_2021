#ifndef HEADER_PION_H_INCLUDED
#define HEADER_PION_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>



class Pion
{
private:
    //BITMAP * animation[5];
    ///ou si on a pas le temps
    BITMAP * m_image;
    std::string m_nom_pion;
    int m_posx = 48;
    int m_posy = 301;

    int m_prex;                      ///pour animation deplacement si on a le temps
    int m_prey;

    int m_depx = 50;
    int m_depy = 50;

public:
    Pion();
    ~Pion();
    int get_posx()const;
    int set_posx(int val);
    int get_posy()const;
    int set_posy(int val);

    void set_x(int val);
    void set_y(int val);

    void set_Pion(BITMAP * Pion);
    BITMAP * get_Pion()const;

    int casemystere();

    int get_depx()const;
    int get_depy()const;

    int get_prex()const;
    void set_prex(int val);
    int get_prey()const;           ///pour animation deplacement si on a le temps
    void set_prey(int val);
    void anim_deplacement();
};

#endif // HEADER_PION_H_INCLUDED
