#ifndef HEADER_SALLES_H_INCLUDED
#define HEADER_SALLES_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>

class Salle
{
private:

protected:
    std::string m_Nom;
    int m_taille;

public:
    Salle();
    Salle(std::string _Nom, int _taille);
    ~Salle();

    int get_taille()const;
    std::string get_nom()const;
};


class Planete : public Salle
{
public:

protected:
    int m_Habitants;
    std::string m_Galaxie;

private:
    Planete();
    Planete(std::string _Nom, int _taille, int _Habitants, std::string _Galaxie);
    ~Planete();

    int get_Habitants()const;
    std::string get_Galaxie()const;
};

class Maison : public Planete
{
    public:
        std::string m_Ville;
        std::string m_Proprietaire;
    private:
        Maison();
        Maison(std::string _Nom, int _taille, int _Habitants, std::string _Galaxie, std::string _Ville, std::string _Proprietaire);
        ~Maison();

        std::string get_Ville()const;
        std::string get_Proprietaire()const;
};

class Vaisseau : public Planete
{
    public:
        std::string m_Proprietaire;
    private:
        Vaisseau();
        Vaisseau(std::string _Nom, int _taille, int _Habitants, std::string _Galaxie, std::string _Proprietaire);
        ~Vaisseau();

        std::string get_Proprietaire()const;

};

#endif // HEADER_SALLES_H_INCLUDED
