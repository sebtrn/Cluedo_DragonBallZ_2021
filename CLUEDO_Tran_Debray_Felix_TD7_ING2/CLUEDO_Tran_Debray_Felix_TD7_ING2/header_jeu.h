#ifndef HEADER_JEU_H_INCLUDED
#define HEADER_JEU_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>


#include "header_cartes.h"

#include "header_joueur.h"



class Jeu
{
private :
    ///Ici on ajoutera un vecteur de joueurs pour les afficher
    ///On aura besoin de leurs pions(coordonnees), pseudos ect...
    ///Egalement d'autres infos dont on aura besoin
    int m_Nbjoueurs;
    int m_choixMenu;

    int m_choixPions[8]={1,1,1,1,1,1,1,1};

    std::vector<Arme> probl_pta;
    std::vector<Suspect> probl_pts;
    std::vector<Lieu> probl_ptl;

    std::vector<Joueur> m_joueurs;
    std::vector<Carte> m_cartestest;
    std::vector<Carte*> m_cartestest2;   ///si on fait le bonus où les cartes etc sont stockés dans un fichier on les stockes ici avant de les redistribué
    std::stack<Carte> m_cartes;
    //std::map<string,string> m_motdepasse; ///si le mot de passe est bon on parcours un fichier avec les comptes
    /// et quand les identifiants correspondent on met les infos du joueur dans le vecteur


    Carte * m_solu_l;
    Carte * m_solu_s;
    Carte * m_solu_a;

    int m_etape_hypo=-1;
    int m_etape_accu=-1;
    int m_cpt;
    int m_cpta;

    bool m_victoire = false;

    /*Carte m_solu_l;
    Carte m_solu_s;
    Carte m_solu_a;*/

    ///les bitmaps dont on a peut etre besoin jsp trop comment ça interagit avec les objets

    /*BITMAP * m_plateau;
    BITMAP * test1;
    BITMAP * test2;*/

    ///les trucs dont on a besoins pour allegro genre si on clics etc (je crois pas que y en avait)




public:
    Jeu() {}
    ~Jeu() {}

    int get_Nbjoueurs()const;
    int get_choixMenu()const;
    int get_choixPion(int choix)const;

    int menuFin();

    void set_choixPion(int choix);
    void initialisation_allegro();
    int menuPrincipal();
    void set_Nbjoueurs(int nb_joueurs);
    void set_choixMenu(int _choixMenu);
    void menuChoixNbJoueurs();
    void menuConnexion();
    void affichage_Aides();
    void affichage_Scores();
    ///void lancementPartie();

    ///void affichagePlateau();
    ///On aura besoin dans l'affichage du plateau du vecteur de joueurs
    ///Et également d'autres infos (ex : numero de Tour...)

    ///Elements de sauvegarde
    void sauvegarde_Joueurs(std::vector<Joueur> vect_joueurs);

    int retour_Joueur(std::string nom_J)const;
    int recup_score(std::string nom_J)const;


    ///


    ///--------
    Joueur recherche_compte(); ///si on trouve pas de compte on appelle ajout compte pour en faire un nouveau compte dans la base de données et aussi le retourner

    std::vector<Carte*> lecture_fichier_carte();
    std::vector<Carte*> get_vecttest()const;

    void set_vecttest(std::vector<Carte*> c);
    void ajout_joueur(Joueur j);
    void nouveauJoueur();
    void ancienJoueur();
    void initialisation_partie();
    void lancement_partie();
    BITMAP * choix_pion();




    ///Pas encore verifiee
    std::vector<Joueur> get_joueurs()const;
    void set_joueurs(std::vector<Joueur> j);
    void affi_glo(Carte& c,int x,int y, BITMAP* Buffer);  ///une methode de jeu et/ou joeur
    void affi_gloprovi(/*std::vector<Carte*>& test on obtient avec le getter normalement*/int x,int y);  ///une methode jeu
    void initi_bloc();

    ///Pas encore implémentées
    void animation();
    void affichage();
    void Jouer();
    void ecran_victoire(Joueur gagnant);
    int verifPosition(Joueur j)const;
    void sauvegarde();
    void reprise();
    void menu();
    void ajout_compte();
    void fin_de_partie(); ///tout les trucs de bonus niveau de compte etc, rechercher comment on modifie les données d'un fichier

    void hypothese(BITMAP *page,int m);
    int get_etapehypo()const;
    void set_etathypo(int val);
    int get_cpt();
    void set_cpt(int m);

    ///accusation

    void accusation(BITMAP *page,int m);
    int get_etapeaccu()const;
    void set_etataccu(int val);
    int get_cpta();
    void set_cpta(int m);
    void set_solu_a(Carte * c);
    void set_solu_l(Carte * c);
    void set_solu_s(Carte * c);
    Carte * get_solu_a();
    Carte * get_solu_s();
    Carte * get_solu_l();
    void set_victoire(bool b);
    bool get_victoire();


    ///rajouter les methodes pour creer les comptes les stocker les assigner à u joueur etc

};


#endif // HEADER_JEU_H_INCLUDED
