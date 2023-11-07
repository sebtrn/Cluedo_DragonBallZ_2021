#ifndef HEADER_JOUEUR_H_INCLUDED
#define HEADER_JOUEUR_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>

#include "header_pion.h"
#include "header_cartes.h"
#include "header_blocnote.h"
#include "header_salles.h"

class Joueur
{
private:
    std::string m_nom;
    Pion m_pion;
    std::vector<Carte> m_main;
    std::vector<Carte*> m_maintest;
    bool m_elimine=false;
    Bloc_notes m_bloc;
    int m_nombrePas;
    int m_cpt_anim;
    int m_etape_hypo;
    int m_score = 0;

    Salle m_salle;

    ///C'est un test
    ///Les differents types de piece dans lesquels il peut etre

       Carte * m_ahypo;
    Carte * m_shypo;
    Carte * m_lhypo;        ///à mettre à null et free à la fin

    Carte * m_abon;
    Carte * m_sbon;
    Carte * m_lbon;

    Carte * m_a_affi;

    bool m_avalide=false;
    bool m_svalide=false;
    bool m_lvalide=false;

    Carte * m_a_accu;
    Carte * m_s_accu;
    Carte * m_l_accu;
    bool m_avalide_accu=false;
    bool m_svalide_accu=false;
    bool m_lvalide_accu=false;

    /*
    Maison m_Maison;
    Planete m_Planete;
    Vaisseau m_Vaisseau;
    */


public:
    Joueur();
    ~Joueur();
    Joueur(std::string _nom);
    Pion get_pion()const;   ///voir la position actuelle
    bool get_elimine()const; ///voir si le joueur joue encore
    void set_elimine(bool b);    ///elimine un joueur s'il se trompe
    std::vector<Carte> get_main()const;
    void set_main(std::vector<Carte> m);
    std::string get_nom()const;

    void set_x(int val);
    void set_y(int val);

    int get_posx()const;
    int set_posx(int val);
    int get_posy()const;
    int set_posy(int val);
    int get_etapehypo()const;
    void set_etathypo(int val);
    void set_score(int _score);
    int get_score();

    Salle get_salle()const;
    void set_salle(Salle b);

    std::vector<Carte*> get_maintest()const;
    void set_maintest(std::vector<Carte*> m);
    Bloc_notes get_bloco();
    void set_bloco(Bloc_notes b);

    BITMAP * get_Pion()const;

    void set_pion(BITMAP * _Perso);

    int get_nbPas()const;
    void set_nbPas(int _nombrePas);

    int get_cptanim();
    void set_cptanim(int m);

    void ajout_main(Carte c); ///à enlever
    void hypothese(BITMAP *page);
    int accusation(Lieu l,Arme a,Suspect s);   ///si bon coupe le while de la methode jeu dans le jeu sinon elimine le joueur
    void deplacer();
    void affi_main(BITMAP* page);
    void choix_pion(); ///ajouter qqchose pour empecher un pion d'etre choisi deux fois
    void affi_glo1(Carte& c,int x,int y, BITMAP* Buffer); ///provisoirement dans les deux


    Carte * get_ahypo()const;
    Carte * get_shypo()const;
    Carte * get_lhypo()const;
    void set_ahypotest(Carte * c);
    void set_shypotest(Carte * c);
    void set_lhypotest(Carte * c);

    bool get_avalide();
    bool get_svalide();
    bool get_lvalide();
    void set_avalide(bool b);
    void set_svalide(bool b);
    void set_lvalide(bool b);

    Carte * get_a_affi()const;
    void set_a_affi(Carte * c);



    Carte * get_a_accu()const;
    Carte * get_s_accu()const;
    Carte * get_l_accu()const;
    void set_a_accutest(Carte * c);
    void set_s_accutest(Carte * c);
    void set_l_accutest(Carte * c);

    bool get_avalide_accu();
    bool get_svalide_accu();
    bool get_lvalide_accu();
    void set_avalide_accu(bool b);
    void set_svalide_accu(bool b);
    void set_lvalide_accu(bool b);
};





#endif // HEADER_JOUEUR_H_INCLUDED
