#include "header_cartes.h"

using namespace std;

Carte::Carte(){}

Carte::~Carte(){}

Carte::Carte(string _nom) ///rajouter les bitmaps
      :m_nom(_nom){}

void Carte::set_nom(string _nom)
{
    m_nom=_nom;
}

std::string Carte::get_nom()
{
    return m_nom;
}

void Carte::display(int x,int y, BITMAP* Buffer)
{
    cout<<"considere comme une simple carte, bug passage parametre"<<endl;
    cout<<"carte : "<<m_nom<<endl;
}

BITMAP * Carte::get_image()
{
    return m_image;
}
void Carte::set_image(BITMAP * i)
{
    m_image=i;
}


///L'affichage Allegro est fait grâce au polymorphisme
///Ce polymorphisme régit la couleur encadrant les cartes



Lieu::Lieu(){}
Lieu::~Lieu(){}
Lieu::Lieu(string _nom)
     :Carte(_nom){}

void Lieu::display(int x,int y, BITMAP* Buffer)
{
    ///de l'affichage allegro
    BITMAP * contour=load_bitmap("images/contour/lieu.bmp",NULL);
    draw_sprite(get_image(),contour,0,0);
    blit(get_image(), Buffer, 0, 0, x, y, get_image()->w,get_image()->h);
}

Suspect::Suspect(){}
Suspect::~Suspect(){}
Suspect::Suspect(string _nom)
     :Carte(_nom){}

void Suspect::display(int x,int y, BITMAP* Buffer)
{
    ///de l'affichage allegro
    //cout<<"suspect : "<<m_nom<<endl;
    BITMAP * contour=load_bitmap("images/contour/suspect.bmp",NULL);
    draw_sprite(get_image(),contour,0,0);
    blit(get_image(), Buffer, 0, 0, x, y, get_image()->w,get_image()->h);
}

Arme::Arme(){}
Arme::~Arme(){}
Arme::Arme(string _nom)
     :Carte(_nom){}

void Arme::display(int x,int y, BITMAP* Buffer)
{
    ///de l'affichage allegro
    //cout<<"arme : "<<m_nom<<endl;
    BITMAP * contour=load_bitmap("images/contour/arme.bmp",NULL);
    draw_sprite(get_image(),contour,0,0);
    blit(get_image(), Buffer, 0, 0, x, y, get_image()->w,get_image()->h);
}
