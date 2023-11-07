#ifndef HEADER_CARTES_H_INCLUDED
#define HEADER_CARTES_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>

class Carte
{
protected:
    BITMAP * m_image;
    std::string m_nom;
public:
    Carte();
    Carte(std::string _nom);
    void set_nom(std::string _nom);
    BITMAP * get_image();
    void set_image(BITMAP * i);
    virtual~Carte();
    virtual void display(int x,int y, BITMAP* Buffer)/*=0*/;
    std::string get_nom();

    //void display_carte(Carte& c,int x,int y); ///polymorphisme (ou avant) on ajuste la position si c'est une arme un suspect ou un lieu
};

class Lieu: public Carte        ///l'heritage sert pas à grand chose
{
public:
    Lieu();
    ~Lieu();
    Lieu(std::string _nom);
    void display(int x,int y, BITMAP* Buffer);
};

class Suspect: public Carte        ///l'heritage sert pas à grand chose
{
public:
    Suspect();
    ~Suspect();
    Suspect(std::string _nom);
    void display(int x,int y, BITMAP* Buffer);
};

class Arme: public Carte        ///l'heritage sert pas à grand chose
{
public:
    Arme();
    ~Arme();
    Arme(std::string _nom);
    void display(int x,int y, BITMAP* Buffer);
};




#endif // HEADER_CARTES_H_INCLUDED
