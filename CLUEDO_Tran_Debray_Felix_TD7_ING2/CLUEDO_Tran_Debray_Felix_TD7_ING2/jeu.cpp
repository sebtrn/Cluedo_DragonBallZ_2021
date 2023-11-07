#include "header_jeu.h"



int Jeu::menuPrincipal()
{
    int choix = 0;
    int choixFinal = 0;

    ///Chargement de toutes les bitmaps
    BITMAP * buffermenu;
    BITMAP * menu;
    BITMAP * menu1;
    BITMAP * menu2;
    BITMAP * menu3;
    BITMAP * menu4;
    BITMAP * menu5;


    buffermenu= create_bitmap(SCREEN_W, SCREEN_H);

    menu=load_bitmap("images/menu.bmp", NULL);

    ///blindage
    if(!menu)
    {
        allegro_message("Erreur de chargement de l'image du menu");
        allegro_exit();
    }
    menu1 = load_bitmap("images/menu1.bmp", NULL);
    menu2 = load_bitmap("images/menu2.bmp", NULL);
    menu3 = load_bitmap("images/menu3.bmp", NULL);
    menu4 = load_bitmap("images/menu4.bmp", NULL);
    menu5 = load_bitmap("images/menu5.bmp", NULL);

while(choixFinal != 3)
    {
    ///Boucle de gestion du menu (pour s'y déplacer)
    while(choix >= 0)
    {
        blit(menu, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        ///Dans le cas où on est sur la premiere page
        if (choix == 0)
        {
            blit(menu, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///Affichage du menu de selection du nb de joueurs, de l'enregistrement puis lancement de la partie
                choix = -1;
                set_choixMenu(-1);
                //    lancementPartie();
                //menuChoixNbJoueurs();

            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 1;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix = 5;
                rest(200);
            }

        }

        ///Deuxieme page
        else if (choix == 1)
        {
            blit(menu1, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///Reprise de la partie précédente
            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 2;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix--;
                rest(200);
            }

        }

        ///Troisieme page
        else if (choix == 2)
        {
            blit(menu2, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///Affichage des scores
                affichage_Scores();
            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 3;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix--;
                rest(200);
            }

        }

        ///Quatrieme page
        else if (choix == 3)
        {
            blit(menu3, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///Affichage des règles (aides)
                affichage_Aides();
            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 4;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix--;
                rest(200);
            }

        }

        ///cinquieme page
        else if (choix == 4)
        {
            blit(menu4, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///Affichage des paramètres
            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 5;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix--;
                rest(200);
            }

        }

        ///Sixieme page
        else if (choix == 5)
        {
            blit(menu5, buffermenu, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(((617<mouse_x)&&(mouse_x<951))&&((261<mouse_y)&&(mouse_y<393)) && (mouse_b & 1))
            {
                ///On quitte le programme
                return 0;
            }

            else if((((694<mouse_x)&&(mouse_x<945))&&((394<mouse_y)&&(mouse_y<470)) && (mouse_b & 1)) || (key[KEY_DOWN]))
            {
                ///Affichage du menu suivant grace à l'incrementation de choix
                choix = 0;
                rest(200);
            }
            else if(key[KEY_UP])
            {
                choix--;
                rest(200);
            }

        }
        blit(buffermenu,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    ///On sort du menu quand le joueur selectionnne le lancement de la partie


        if((get_choixMenu())== -1)
        {
            menuChoixNbJoueurs();
            menuConnexion();
            initialisation_partie();
            initi_bloc();
            lancement_partie();

            choixFinal = menuFin();

            if(choixFinal == 1)
            {
                initialisation_partie();
                initi_bloc();
                lancement_partie();
                menuPrincipal();

            }
            else if(choixFinal == 2)
            {
                set_choixMenu(0);
                choix = 0;
            }
            else if(choixFinal == 3)
            {
                return 0;
            }
            rest(100);
        }
}

    ///On detruit les bitmaps pour l'allocation (optimise le programme)
    destroy_bitmap(buffermenu);

    destroy_bitmap(menu);
    destroy_bitmap(menu1);
    destroy_bitmap(menu2);
    destroy_bitmap(menu3);
    destroy_bitmap(menu4);
    destroy_bitmap(menu5);

    return 0;

}

void Jeu::set_Nbjoueurs(int nb_joueurs)
{
    m_Nbjoueurs = nb_joueurs; //Setter simple
}

int Jeu::get_Nbjoueurs()const
{
    return m_Nbjoueurs; //getter
}

void Jeu::set_choixMenu(int _choixMenu)
{
    m_choixMenu = _choixMenu; //Setter
}

int Jeu::get_choixMenu()const
{
    return m_choixMenu; //getter
}


void Jeu::menuChoixNbJoueurs()
{
    int choix = 0;

    ///Creation et chargement des bitmaps
    BITMAP * bufferChoix;
    BITMAP * choix0;
    BITMAP * choix1;
    BITMAP * choix2;
    BITMAP * choix3;
    BITMAP * choix4;
    BITMAP * choix5;


    bufferChoix = create_bitmap(SCREEN_W, SCREEN_H);
    choix0= load_bitmap("images/choix.bmp", NULL);
    ///blindage
    if(!choix0)
    {
        allegro_message("Erreur de chargement de l'image du choix du nombre de joueurs");
        allegro_exit();
    }
    choix1= load_bitmap("images/choix1.bmp", NULL);
    choix2= load_bitmap("images/choix2.bmp", NULL);
    choix3= load_bitmap("images/choix3.bmp", NULL);
    choix4= load_bitmap("images/choix4.bmp", NULL);
    choix5= load_bitmap("images/choix5.bmp", NULL);

    ///Parcourt du menu de choix du nb de joueurs
    while(choix == 0)
    {
        blit(choix0, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image standard (curseur qui n'est pas sur un des choix)

        if(((278<mouse_x)&&(mouse_x<395))&&((78<mouse_y)&&(mouse_y<312))) ///Curseur sur le choix de deux joueurs
        {
            if(mouse_b & 1)
            {
                set_Nbjoueurs(2);
                choix = 1;
            }
            else
            {
                blit(choix1, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        else if(((558<mouse_x)&&(mouse_x<735))&&((82<mouse_y)&&(mouse_y<309))) ///Curseur sur le choix de trois joueurs
        {
            if(mouse_b & 1)
            {
                set_Nbjoueurs(3);
                choix = 1;
            }
            else
            {
                blit(choix2, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        else if(((846<mouse_x)&&(mouse_x<1072))&&((89<mouse_y)&&(mouse_y<314))) ///Curseur sur le choix de quatre joueurs
        {
            if(mouse_b & 1)
            {
                set_Nbjoueurs(4);
                choix = 1;
            }
            else
            {
                blit(choix3, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        else if(((317<mouse_x)&&(mouse_x<561))&&((339<mouse_y)&&(mouse_y<642))) ///Curseur sur le choix de cinq joueurs
        {
            if(mouse_b & 1)
            {
                set_Nbjoueurs(5);
                choix = 1;
            }
            else
            {
                blit(choix4, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        else if(((706<mouse_x)&&(mouse_x<937))&&((361<mouse_y)&&(mouse_y<621))) ///Curseur sur le choix de six joueurs
        {
            if(mouse_b & 1)
            {
                set_Nbjoueurs(6);
                choix = 1;
            }
            else
            {
                blit(choix5, bufferChoix, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        blit(bufferChoix,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    }

    ///Destruction des bitmaps(memoire)
    destroy_bitmap(bufferChoix);
    destroy_bitmap(choix0);
    destroy_bitmap(choix1);
    destroy_bitmap(choix2);
    destroy_bitmap(choix3);
    destroy_bitmap(choix4);
    destroy_bitmap(choix5);
}


void Jeu::menuConnexion()
{
    int nbJoueurs = 0;

///   FONT *police;
/// police = load_font("theboldfont.pcx", NULL, NULL);

    ///Chargement et creation des bitmaps
    BITMAP * bufferConnexion;
    BITMAP * connexion;
    BITMAP * connexion1;
    BITMAP * connexion2;



    bufferConnexion = create_bitmap(SCREEN_W, SCREEN_H);

    ///Blindage
    connexion = load_bitmap("images/connexion.bmp", NULL);
    if(!connexion)
    {
        allegro_message("Erreur de chargement de l'image de connexion aux identifiants");
        allegro_exit();
    }
    connexion1 = load_bitmap("images/connexion1.bmp", NULL);
    connexion2 = load_bitmap("images/connexion2.bmp", NULL);


    ///On va pouvoir creer le bon nb de joueur
    while (nbJoueurs < (get_Nbjoueurs()))
    {
        blit(connexion, bufferConnexion, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image standard (curseur qui n'est pas sur un des choix)

        if(((184<mouse_x)&&(mouse_x<611))&&((289<mouse_y)&&(mouse_y<429))) ///Curseur sur nouveau joueur
        {
            if(mouse_b & 1)
            {
                nbJoueurs++;
                rest(100);
                nouveauJoueur(); ///appel du s-p de creation d'un nv joueur
            }
            else
            {
                blit(connexion1, bufferConnexion, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        else if(((699<mouse_x)&&(mouse_x<1126))&&((289<mouse_y)&&(mouse_y<429))) ///Curseur sur connexion
        {
            if(mouse_b & 1)
            {
                nbJoueurs++;
                rest(100);

                ancienJoueur(); ///appel du s-p de recherche de profil d'un ancien joueur
            }
            else
            {
                blit(connexion2, bufferConnexion, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
            }
        }
        blit(bufferConnexion, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    }
    ///Destruction des bitmaps
    destroy_bitmap(bufferConnexion);
    destroy_bitmap(connexion);
    destroy_bitmap(connexion1);
    destroy_bitmap(connexion2);

}


void Jeu::ajout_joueur(Joueur J)
{
    /// m_joueurs est le vecteur de joueurs contenu en private dans le main
    m_joueurs.push_back(J);
}


void Jeu::set_choixPion(int choix)
{
    m_choixPions[choix]=0; //setter
}

int Jeu::get_choixPion(int choix)const
{
    return m_choixPions[choix]; //getter
}


void Jeu::nouveauJoueur()
{

    ///Creation et chargement des bitmaps
    BITMAP * bufferSaisie;
    BITMAP * saisiePseudo;
    BITMAP * mauvaiseSaisie;


///   FONT *police;
///   police = load_font("theboldfont.ttf", NULL, NULL);

    std::string Nom;
    int touche;
    char caractereSaisi = 'c';
    int nb=0;

    /*
        FONT *police;
        police = load_font("police.pcx", NULL, NULL);
    */
    bufferSaisie = create_bitmap(SCREEN_W, SCREEN_H);
    saisiePseudo = load_bitmap("images/RentrerPseudo.bmp", NULL);
    ///Blindage
    if(!saisiePseudo)
    {
        allegro_message("Erreur de chargement de l'image de saisie des identifiants");
        allegro_exit();
    }
    mauvaiseSaisie = load_bitmap("images/MauvaisPseudo.bmp", NULL);


    blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

    blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

//       blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

    //      blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

    //    textprintf_ex(screen, font, 698, 322,makecol(0,0,0), -1, "OKKK");

    while(keypressed())
    {
        ///Tres important
        ///Ici on remet à zéro la saisie des touches en mémoires
        touche = readkey();
        caractereSaisi = (char)touche;
    }

    ///Boucle de saisi tant qu'on appuie pas sur la touche entrée
    while(caractereSaisi != '\r' || nb>=0)
    {
        caractereSaisi = 'c';
        if(keypressed())
        {
            touche = readkey(); ///On recupere la touche

            caractereSaisi = (char)touche;

            Nom += caractereSaisi; /// On complete le nom
            nb++;

            if(caractereSaisi != '^' && caractereSaisi != '\r')
            {
                textprintf_ex(screen, font, 719+(nb*10), 354,makecol(0,0,0), -1, "%c", caractereSaisi); ///On affiche la saisie petit a petit
            }
            if(caractereSaisi == '\r')
            {
                nb = -1;
            }
        }

        if(nb>=12)
        {
            ///Blindage
            ///On remet à zero si on depasse 12 caracteres
            ///On affiche une image qui previent que la saisie etait incorrecte
            int test = 0;
            nb=0;
            Nom = "";
            blit(mauvaiseSaisie, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image d'erreur de saisi
            blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///On l'applique sur l'ecran

            while(test == 0)
            {
                if((mouse_b & 1) || (key[KEY_ENTER]))
                {
                    test = 1;
                    while(keypressed())
                    {
                        touche = readkey();
                        caractereSaisi = (char)touche;
                    }
                }
            }

            blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

            blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie
        }
    }

    Nom.pop_back(); ///On retire le ^ dû à la touche entrée

    Joueur J(Nom);

    J.set_pion(choix_pion()); ///On appelle le s p de choix du pion

    ajout_joueur(J); ///On ajoute el joueur

    ///Destruction des bitmaps
    destroy_bitmap(bufferSaisie);
    destroy_bitmap(saisiePseudo);
    destroy_bitmap(mauvaiseSaisie);

}


void Jeu::ancienJoueur()
{

    ///Creation des bitmaps
    BITMAP * bufferSaisie;
    BITMAP * saisiePseudo;
    BITMAP * mauvaiseSaisie;


//    BITMAP * pion;

    std::string Nom;
    int touche;
    char caractereSaisi;
    int nb=0;
    int test2 = 0;
    int verif = 0;


    /*
        FONT *police;
        police = load_font("police.pcx", NULL, NULL);
    */

    bufferSaisie = create_bitmap(SCREEN_W, SCREEN_H);
    saisiePseudo = load_bitmap("images/RentrerPseudo.bmp", NULL);
    ///Blindage
    if(!saisiePseudo)
    {
        allegro_message("Erreur de chargement de l'image de saisie des identifiants");
        allegro_exit();
    }
    mauvaiseSaisie = load_bitmap("images/MauvaisPseudo.bmp", NULL);

    ///Tant que le joueur n'a pas saisi un nom correct
    while(test2 ==0)
    {
        blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

        blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

//       blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

        //      blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

        //    textprintf_ex(screen, font, 698, 322,makecol(0,0,0), -1, "OKKK");


        while(keypressed())
        {
            touche = readkey(); ///Remise a zero des saisies de touches precedentes
            caractereSaisi = (char)touche;
        }
        while(caractereSaisi != '\r' || nb >=0) ///blindage
        {
            caractereSaisi = 'c';
            if(keypressed())
            {
                touche = readkey(); ///Lecture

                caractereSaisi = (char)touche;

                if(caractereSaisi != '$')
                {
                    Nom += caractereSaisi; ///Ajout
                    nb++;
                }

                if(caractereSaisi != '^' && caractereSaisi != '\r' && caractereSaisi != '$')
                {
                    textprintf_ex(screen, font, 719+(nb*10), 354,makecol(0,0,0), -1, "%c", caractereSaisi); ///affichage
                }
                if(caractereSaisi == '\r')
                {
                    nb = -1;
                }

            }

            if(nb>=12) ///Blindage
            {

                int test = 0;

                Nom = "";
                blit(mauvaiseSaisie, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image d'erreur de saisi
                blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///IOn l'applique sur l'ecran

                while(test == 0)
                {
                    if((mouse_b & 1)||(key[KEY_ENTER]))
                    {
                        test = 1;
                    }
                }

                blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

                blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie
                while(keypressed())
                {
                    touche = readkey();
                    caractereSaisi = (char)touche;
                }
                nb=0;
            }

        }

        Nom.pop_back(); /// On retire le ^ à la fin
        verif = retour_Joueur(Nom); /// On retourne le nom du joueur

        if(verif == 1)
        {
            test2 = 1;
            Joueur J(Nom);
            //     pion = load_bitmap("images/m2.bmp", NULL);
            J.set_score(recup_score(J.get_nom())); ///On recupere le score du joueur
            J.set_pion(choix_pion()); ///On lui definit un pion

            ajout_joueur(J); ///ajout du joueur au vecteur
        }
        else
        {

            int test = 0;

            Nom = "";
            verif = 0;
            caractereSaisi = '$';

            blit(mauvaiseSaisie, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image d'erreur de saisi
            blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///IOn l'applique sur l'ecran

            while(test == 0)
            {
                if(mouse_b & 1)
                {
                    test = 1;
                }
            }

            blit(saisiePseudo, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie

            blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H); ///Image de saisie
        }


    }

    destroy_bitmap(bufferSaisie);
    destroy_bitmap(saisiePseudo);
    destroy_bitmap(mauvaiseSaisie);

//    destroy_bitmap(pion);

}

BITMAP * Jeu::choix_pion()
{

    ///Chargement et creation des bitmaps
    BITMAP * bufferSaisie;

    BITMAP * perso1;
    BITMAP * perso2;
    BITMAP * perso3;
    BITMAP * perso4;
    BITMAP * perso5;
    BITMAP * perso6;
    BITMAP * perso7;
    BITMAP * perso8;

    BITMAP * blindagePerso;

    BITMAP * pion;

//   BITMAP * gohan;

    int choix = 0;

    bufferSaisie = create_bitmap(SCREEN_W, SCREEN_H);

//   gohan = load_bitmap("persos/gohan1.bmp", NULL);

    perso1 = load_bitmap("persos/perso1.bmp", NULL);
    perso2 = load_bitmap("persos/perso2.bmp", NULL);
    perso3 = load_bitmap("persos/perso3.bmp", NULL);
    perso4 = load_bitmap("persos/perso4.bmp", NULL);
    perso5 = load_bitmap("persos/perso5.bmp", NULL);
    perso6 = load_bitmap("persos/perso6.bmp", NULL);
    perso7 = load_bitmap("persos/perso7.bmp", NULL);
    perso8 = load_bitmap("persos/perso8.bmp", NULL);
    blindagePerso = load_bitmap("persos/blindage_perso.bmp", NULL);

    ///tant que le joueur n'effectue pas un choix correct
    while(choix >= 0)
    {
        blit(perso1, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        ///premier choix
        if(choix==0)
        {
            blit(perso1, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H); //Goku

            if(key[KEY_RIGHT]) ///Touche droite pour valider
            {
                if(get_choixPion(0) != 0)
                {
                    pion = load_bitmap("persos/goku.bmp", NULL);
                    choix = -1;
                    set_choixPion(0);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris

                    while(!key[KEY_ENTER])
                    {
                        blit(blindagePerso, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                        blit(bufferSaisie, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
                    }
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 7;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 1;
                rest(200);
            }
        }
        ///Second choix
        else if(choix==1)
        {
            blit(perso2, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(1) != 0)
                {
                    pion = load_bitmap("persos/vegeta.bmp", NULL);
                    choix = -1;
                    set_choixPion(1);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris

                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 0;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 2;
                rest(200);
            }
        }
        else if(choix==2)
        {
            blit(perso3, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(2) != 0)
                {
                    pion = load_bitmap("persos/gohan.bmp", NULL);
                    choix = -1;
                    set_choixPion(2);
                    rest(200);
                    return pion;
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 1;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 3;
                rest(200);
            }
        }
        else if(choix==3)
        {
            blit(perso4, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(3) != 0)
                {
                    pion = load_bitmap("persos/trunks.bmp.bmp", NULL);
                    choix = -1;
                    set_choixPion(3);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 2;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 4;
                rest(200);
            }
        }
        else if(choix==4)
        {
            blit(perso5, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(4) != 0)
                {
                    pion = load_bitmap("persos/piccolo.bmp", NULL);
                    choix = -1;
                    set_choixPion(4);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 3;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 5;
                rest(200);
            }
        }
        else if(choix==5)
        {
            blit(perso6, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(5) != 0)
                {
                    pion = load_bitmap("persos/janemba.bmp", NULL);
                    choix = -1;
                    set_choixPion(5);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 4;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 6;
                rest(200);
            }
        }
        else if(choix==6)
        {
            blit(perso7, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(6) != 0)
                {
                    pion = load_bitmap("persos/frieza.bmp", NULL);
                    choix = -1;
                    set_choixPion(6);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 5;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 7;
                rest(200);
            }
        }
        else if(choix==7)
        {
            blit(perso8, bufferSaisie, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                if(get_choixPion(7) != 0)
                {
                    pion = load_bitmap("persos/broly.bmp", NULL);
                    choix = -1;
                    set_choixPion(7);
                    rest(200);
                }
                else
                {
                    std::cout<<"Pion deja selectionne"<<std::endl;
                    ///Affichage de la page d'erreur de choix du perso car il est deja pris
                }
                rest(100);
            }
            else if(key[KEY_UP])
            {
                choix = 6;
                rest(200);
            }
            else if(key[KEY_DOWN])
            {
                choix = 1;
                rest(200);
            }
        }

        blit(bufferSaisie, screen, 0,0,0,0, SCREEN_W, SCREEN_H);

    }


    destroy_bitmap(perso1);
    destroy_bitmap(perso2);
    destroy_bitmap(perso3);
    destroy_bitmap(perso4);
    destroy_bitmap(perso5);
    destroy_bitmap(perso6);
    destroy_bitmap(perso7);
    destroy_bitmap(perso8);

    destroy_bitmap(blindagePerso);

    destroy_bitmap(bufferSaisie);

    return pion;

}

void Jeu::initialisation_partie()
{
    srand(time(NULL));
    int i=0;
    int j=0;

    std::vector<Carte*> new_maintest;
    std::vector<Carte*> distrib;

    std::vector<Joueur> provi;


    provi = get_joueurs();

    for(i=0; i< get_Nbjoueurs(); i++)
    {
        provi[i].set_score(provi[i].get_score() + 1);

        provi[i].set_maintest(new_maintest);

        provi[i].set_x(48);
        provi[i].set_y(301);

        provi[i].set_elimine(false);
    }

    set_joueurs(provi);

    sauvegarde_Joueurs(m_joueurs);
    set_victoire(false);

    ///chargement des cartes avec fichiers et initialisation

    set_vecttest(lecture_fichier_carte());
    distrib=get_vecttest();
    ///distribution
    random_shuffle(distrib.begin(),distrib.end());

    for (auto elem:distrib)
    {
        new_maintest=m_joueurs[j%(get_Nbjoueurs())].get_maintest();       ///on distribue equitablement le reste
        if(elem->get_nom()!= get_solu_a()->get_nom() && elem->get_nom()!= get_solu_s()->get_nom() && elem->get_nom()!= get_solu_l()->get_nom() )
        {
            new_maintest.push_back(elem);
            m_joueurs[j%(get_Nbjoueurs())].set_maintest(new_maintest);
            j++;
        }
    }
    std::cout<<std::endl<<"la solution arme :"<<get_solu_a()->get_nom()<<", lieu :"<<get_solu_l()->get_nom()<<", suspect :"<<get_solu_s()->get_nom()<<std::endl;
}


void Jeu::set_vecttest(std::vector<Carte*> c)
{
    m_cartestest2=c;
}

std::vector<Carte*> Jeu:: lecture_fichier_carte()
{
    std::vector<Carte*> test;
    char nombit[50];
    BITMAP* bmp;
    srand(time(NULL));

    /*Arme ahypo;
    Suspect shypo;
    Lieu lhypo;*/

    /*std::vector<Arme> probl_pta;
    std::vector<Suspect> probl_pts;
    std::vector<Lieu> probl_ptl;*/
    Carte nouv_carte;
    Arme nouv_arme;
    Suspect nouv_s;
    Lieu nouv_l;
    bool aj_arme=false,aj_sus=false,aj_lieu=false; ///modifiant une etape pour l'ajout des bitmap
    int testarme=0,testsus=0,testlieu=0;

    int i=1,k=0;

    probl_pta.clear();
    probl_ptl.clear();
    probl_pts.clear();


    std::ifstream sr("Cartes.txt");
    if(sr)
    {
        std::string ligne;
        while(getline(sr,ligne))
        {
            if(ligne=="arme")
            {
                aj_arme=true;
                testarme++;
            }
            else if(ligne=="lieu")
            {
                aj_lieu=true;
                testlieu++;
            }
            else if(ligne=="suspect")
            {
                aj_sus=true;
                testsus++;
            }

            else if(aj_arme==true)
            {
                std::cout<<i<<" :"<<ligne<<std::endl;
                nouv_arme.set_nom(ligne);
                sprintf(nombit,"images/armes/%s.bmp",ligne.c_str());
                bmp=load_bitmap(nombit,NULL);
                nouv_arme.set_image(bmp);
                probl_pta.push_back(nouv_arme);
                aj_arme=false;
                i++;
            }

            else if(aj_lieu==true)
            {
                std::cout<<i<<" :"<<ligne<<std::endl;
                nouv_l.set_nom(ligne);
                sprintf(nombit,"images/lieux/%s.bmp",ligne.c_str());
                bmp=load_bitmap(nombit,NULL);
                nouv_l.set_image(bmp);
                probl_ptl.push_back(nouv_l);
                aj_lieu=false;
                i++;
            }

            else if(aj_sus==true)
            {
                std::cout<<i<<" :"<<ligne<<std::endl;
                nouv_s.set_nom(ligne);
                sprintf(nombit,"images/suspects/%s.bmp",ligne.c_str());
                bmp=load_bitmap(nombit,NULL);
                nouv_s.set_image(bmp);
                probl_pts.push_back(nouv_s);
                aj_sus=false;
                i++;
            }
            else
            {
                std::cout<<"Fichier corrompu"<<std::endl;
            }

            /*cout<<i<<" :"<<ligne<<endl;
            nouv_arme.set_nom(ligne);
            probl_pta.push_back(nouv_arme);
            //test.push_back(&probl_pta[i]);
            i++;*/
        }
        for(int i=0; i<(int)probl_pta.size(); i++)
        {
            //std::cout<<std::endl<<"On ajoute : ";
            //probl_pta[i].display(1,1);
            test.push_back(&probl_pta[i]);
            //std::cout<<" on a bien ";
            //test[k]->display(1,1);
            k++;
        }
        for(int i=0; i<(int)probl_ptl.size(); i++)
        {
            //std::cout<<std::endl<<"On ajoute : ";
            //probl_ptl[i].display(1,1);
            test.push_back(&probl_ptl[i]);
            //std::cout<<" on a bien ";
            //test[k]->display(1,1);
            k++;
        }
        for(int i=0; i<(int)probl_pts.size(); i++)
        {
            //std::cout<<std::endl<<"On ajoute : ";
            //probl_pts[i].display(1,1);
            test.push_back(&probl_pts[i]);
            //std::cout<<" on a bien ";
            //test[k]->display(1,1);
            k++;
        }
        set_solu_a(&probl_pta[rand()%6]);
        set_solu_s(&probl_pts[rand()%6]);
        set_solu_l(&probl_ptl[rand()%9]);
    }
    else
    {
        std::cout<<"erreur ouverture de fichier";
    }

    std::cout<<std::endl<<"nombre d'armes :"<<testarme<<", nombres de lieu :"<<testlieu<<", nombres de suspects :"<<testsus;
    return test;
    //m_cartestest2=test;
}

void Jeu::initi_bloc()
{
    std::vector<std::vector<int>> provi((int)get_vecttest().size(),std::vector<int>(get_Nbjoueurs()));
    std::vector<std::vector<int>> test;
    std::vector<Joueur> temp;
    Bloc_notes bprovi;
    ///------------------------------
    BITMAP* bmpv;
    BITMAP* bmpf;           ///ajout
    BITMAP* bmpi;
    ///------------------------------

    std::cout<<"ini bloc notes"<<std::endl;
    bmpv=load_bitmap("images/vrai.bmp",NULL);
    bmpi=load_bitmap("images/incertain.bmp",NULL);
    bmpf=load_bitmap("images/faux.bmp",NULL);

    for (int i=0; i<(int)get_joueurs().size(); i++)
    {
        temp=get_joueurs();
        std::cout<<"Pour : "<<temp[i].get_nom()<<std::endl;
        std::cout<<"taille de l'image incertain :"<<bmpi->w<<std::endl;
        bprovi.set_vrai(bmpv);
        bprovi.set_faux(bmpf);
        bprovi.set_incertain(bmpi);
        bprovi.set_bloc(provi);
        std::cout<<"taille de l'image dans bprovi :"<<bprovi.get_incertain()->w<<std::endl;
        temp[i].set_bloco(bprovi);
        std::cout<<"taille de l'image :"<<temp[i].get_bloco().get_incertain()->w<<std::endl;
        set_joueurs(temp);
    }

    std::cout<<"taille de l'image :"<<get_joueurs()[0].get_bloco().get_incertain()->w<<std::endl;
    std::cout<<"fin ini bloc notes"<<std::endl;
}

std::vector<Joueur> Jeu::get_joueurs()const
{
    return m_joueurs;
}

void Jeu::lancement_partie()
{
    srand(time(NULL)); ///Initialisation de l aleatoire
    BITMAP * page;
    BITMAP * Jeu;
    BITMAP * passagetour;
    BITMAP * defaite;


    Jeu = load_bitmap("images/plateau_v6.bmp",NULL);
    passagetour = load_bitmap("images/tour.bmp",NULL);
    defaite = load_bitmap("images/defaite.bmp",NULL);

    if(!Jeu)
    {
        allegro_message("Erreur de chargement de l'image du Jeu");
        allegro_exit();
    }


    page=create_bitmap(1280,720);

    int i=0,m=0;
    int verif = 0;
///   const char * c;
    int nb_pas=0;
    int touche;
    int choix = 2;

    int verifAlea = 0;
    int Alea = 0;
    int cptelimine=0;
    bool accusa=false;

    std::vector<Salle> tabsalle;
    Salle plateauj("plateau",20);
    Salle frieza("Vaisseau freezer",20);
    Salle namek("Namek",20);
    Salle kaoi("Planete kaio",20);
    Salle terresa("Terre sacree",20);
    Salle enfer("enfer",20);
    Salle beerus("Planete beerus",20);
    Salle salledtmp("Salle du temps",20);
    Salle vege("Planete Vegeta",20);
    Salle kame("Kame house",20);

    tabsalle.push_back(plateauj);
    tabsalle.push_back(vege);
    tabsalle.push_back(namek);
    tabsalle.push_back(kaoi);
    tabsalle.push_back(salledtmp);
    tabsalle.push_back(beerus);
    tabsalle.push_back(terresa);
    tabsalle.push_back(enfer);
    tabsalle.push_back(kame);
    tabsalle.push_back(frieza);

    std::vector<std::vector<int>> test;
    std::vector<Joueur> provi;
    Bloc_notes bprovi;

    ///Boucle de parcourt des joueurs
    while(!key[KEY_ESC] && get_victoire()==false && cptelimine!=get_Nbjoueurs())
    {
        cptelimine=0;
        nb_pas = rand()%(6 - 1 + 1) + 1;

        provi=get_joueurs();

        provi[m%(get_Nbjoueurs())].set_nbPas(nb_pas);
        set_joueurs(provi);

        while (!key[KEY_SPACE])
        {
            provi = get_joueurs();
            clear_bitmap(page);

            blit(Jeu, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            ///toujours modifier les vecteurs provisoires pour les set

            bprovi=provi[m%(get_Nbjoueurs())].get_bloco();
            bprovi.modi_bloc((int)get_vecttest().size(),get_Nbjoueurs());
            provi[m%(get_Nbjoueurs())].set_bloco(bprovi);
            set_joueurs(provi);


            if((key[KEY_H])&& (verifPosition(get_joueurs()[m%(get_Nbjoueurs())]) != 0))
            {
                verif = 1;
            }
            else
            {
                verif = 0;
            }

            if((mouse_b&1) && (mouse_x<787 && mouse_x>720)&&(mouse_y>100 && mouse_y<230))
            {
                accusa=true;
            }


            ///affichage

            //std::cout<<"tour numero :"<<m+1<<", tour de :"<<get_joueurs()[m%(get_Nbjoueurs())].get_nom()<<std::endl;
            //c = get_joueurs()[m%(get_Nbjoueurs())].get_nom().c_str();
            //textprintf_ex(page,font,700,600,makecol(255,255,255),-1,c);
            i=0;
            for(const auto& elem:get_vecttest())
            {
                affi_glo(*elem,850,31*i+40,page);        ///deplacer les coordonnées dans le code plutot qu'ici
                i++;
            }

            provi[m%(get_Nbjoueurs())].get_bloco().affi_bloc(page,(int)get_vecttest().size(),get_Nbjoueurs());

            //get_joueurs()[m%(get_Nbjoueurs())].affi_main(page);
            //get_joueurs()[m%(get_Nbjoueurs())].get_bloco().affi_bloc(page,(int)get_vecttest().size(),get_Nbjoueurs());

            if((get_joueurs()[m%(get_Nbjoueurs())].get_nbPas() == 0) || ( (verif==1) && (verifPosition(get_joueurs()[m%(get_Nbjoueurs())]) != 0)) || (choix ==1))
            {
               /// std::cout<<"Plus de pas ou a deja fait une hypothese"<<std::endl;
            }
            else
            {
                ///1 vers le haut et la droite
                ///2 vers le bas et la gauche
                if(keypressed())
                {
                    if(key[KEY_UP])
                    {
                        ///On verifie ou est le joueur
                        verifAlea = (provi[m%(get_Nbjoueurs())].set_posy(1));
                        provi[m%(get_Nbjoueurs())].set_nbPas((provi[m%(get_Nbjoueurs())].get_nbPas()) - verifAlea);
                        ///Si le joueur peut bouger
                        if(verifAlea == 1)
                        {
                            Pion pion2;
                            pion2 = provi[m%(get_Nbjoueurs())].get_pion();
                            if(pion2.casemystere() == 1) ///Si le joueur est sur une case mystere
                            {
                                Alea = rand()%(6 - (-6)) - 6;

                                Alea = (provi[m%(get_Nbjoueurs())].get_nbPas()) + Alea;

                                if(Alea <= 0)
                                {
                                    Alea = 0;
                                }

                                provi[m%(get_Nbjoueurs())].set_nbPas(Alea);

                            }
                        }
                        rest(200);
                    }
                    ///Les principes sont les memes pour chaque type de déplacements
                    else if(key[KEY_DOWN])
                    {
                        verifAlea = (provi[m%(get_Nbjoueurs())].set_posy(2));
                        provi[m%(get_Nbjoueurs())].set_nbPas((provi[m%(get_Nbjoueurs())].get_nbPas()) - verifAlea);
                        if(verifAlea == 1)
                        {
                            Pion pion2;
                            pion2 = provi[m%(get_Nbjoueurs())].get_pion();
                            if(pion2.casemystere() == 1)
                            {
                                Alea = rand()%(6 - (-6)) - 6;

                                Alea = (provi[m%(get_Nbjoueurs())].get_nbPas()) + Alea;

                                if(Alea <= 0)
                                {
                                    Alea = 0;
                                }

                                provi[m%(get_Nbjoueurs())].set_nbPas(Alea);

                            }
                        }
                        rest(200);
                    }
                    ///Les principes sont les memes pour chaque type de déplacements
                    else if(key[KEY_RIGHT])
                    {
                        verifAlea = (provi[m%(get_Nbjoueurs())].set_posx(1));
                        provi[m%(get_Nbjoueurs())].set_nbPas((provi[m%(get_Nbjoueurs())].get_nbPas()) - verifAlea);
                        if(verifAlea == 1)
                        {
                            Pion pion2;
                            pion2 = provi[m%(get_Nbjoueurs())].get_pion();
                            if(pion2.casemystere() == 1)
                            {
                                Alea = rand()%(6 - (-6)) - 6;

                                Alea = (provi[m%(get_Nbjoueurs())].get_nbPas()) + Alea;

                                if(Alea <= 0)
                                {
                                    Alea = 0;
                                }

                                provi[m%(get_Nbjoueurs())].set_nbPas(Alea);

                            }
                        }
                        rest(200);
                    }
                    ///Les principes sont les memes pour chaque type de déplacements
                    else if(key[KEY_LEFT])
                    {
                        verifAlea = (provi[m%(get_Nbjoueurs())].set_posx(2));
                        provi[m%(get_Nbjoueurs())].set_nbPas((provi[m%(get_Nbjoueurs())].get_nbPas()) - verifAlea);
                        if(verifAlea == 1)
                        {
                            Pion pion2;
                            pion2 = provi[m%(get_Nbjoueurs())].get_pion();
                            if(pion2.casemystere() == 1)
                            {
                                Alea = rand()%(6 - (-6)) - 6;

                                Alea = (provi[m%(get_Nbjoueurs())].get_nbPas()) + Alea;

                                if(Alea <= 0)
                                {
                                    Alea = 0;
                                }

                                provi[m%(get_Nbjoueurs())].set_nbPas(Alea);

                            }
                        }
                        rest(200);
                    }
                }
            }

            draw_sprite(page, get_joueurs()[m%(get_Nbjoueurs())].get_Pion(), get_joueurs()[m%(get_Nbjoueurs())].get_posx(), get_joueurs()[m%(get_Nbjoueurs())].get_posy());
            provi[m%(get_Nbjoueurs())].set_salle(tabsalle[verifPosition(provi[m%(get_Nbjoueurs())])]);
            provi[m%(get_Nbjoueurs())].affi_main(page);
            set_joueurs(provi);

            ///Demande si on veut faire une hypothèse => Il faut etre dans une salle
            if((verifPosition(get_joueurs()[m%(get_Nbjoueurs())]) != 0)&&(verif == 1))
            {
                while(keypressed())
                {
                    touche = readkey();
                    std::cout<<"Suppression de la saisie : "<<touche<<std::endl;
                }

                while(choix == 2)
                {
                    if(keypressed())
                    {
                        if(key[KEY_RIGHT])
                        {
                            choix = 2;
                        }
                        if(key[KEY_LEFT])
                        {
                            choix = 1;
                        }
                        std::cout<<"choix effectué"<<std::endl;
                    }
                }
                ///On demande au joueur son hypothèse


            }
            if(choix == 1 && get_etapehypo()!=10)
            {
                ///Saisie de l'hypothèse
                hypothese(page, m);
            }
            if(accusa && get_etapeaccu()!=6)
            {
                accusation(page,m);
            }



///            set_joueurs(provi);


            blit(page,screen,0,0,0,0,1280,720);
        }

        ///Demande si on veut faire une Accusation !!




        do
        {
            if(get_joueurs()[m%(get_Nbjoueurs())].get_elimine()==true)
                cptelimine++;
            m++;
        }
        while(get_joueurs()[m%(get_Nbjoueurs())].get_elimine()==true && cptelimine!=get_Nbjoueurs());

        if(cptelimine==get_Nbjoueurs())
        {
            while(!key[KEY_ENTER]/*&& get_victoire()==false*/)
            {
                ///une bitmap où on dit tt les jours sont elimines
                std::cout<<"tout les joueurs sont elimines"<<std::endl;
                blit(defaite,screen,0,0,0,0,1280,720);
            }
        }

        rest(200);
        while(!key[KEY_ENTER] && get_victoire()==false && cptelimine!=get_Nbjoueurs())
        {
            ///une bitmap où on dit d'appuyer sur entrée
            blit(passagetour,screen,0,0,0,0,1280,720);
        }

        choix=2;
        set_etathypo(-1);
        set_etataccu(-1);
        set_cpt(0);
        accusa=false;
    }

    ///libération de la mémoire

    destroy_bitmap(Jeu);

}

int Jeu::verifPosition(Joueur j)const
{
    int m_posx, m_posy;

    ///On recupere les positions de x et y
    m_posx = j.get_posx();
    m_posy = j.get_posy();

    if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 51)&&(m_posy >= 1))
    {
        //Si le joueur est sur la planète vegeta
        return 1;
    }
    else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 51)&&(m_posy >= 1))
    {
        //Si le joueur est sur la planète namek
        return 2;
    }
    else if((m_posx <= 598)&&(m_posx > 548)&&(m_posy <= 51)&&(m_posy >= 1))
    {
        //Si le joueur est sur la planète kaio
        return 3;
    }
    else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 301)&&(m_posy >= 201))
    {
        //Si le joueur est dans la salle du Temps
        return 4;
    }
    else if((m_posx <= 648)&&(m_posx >= 498)&&(m_posy <= 401)&&(m_posy >= 251))
    {
        //Si le joueur est sur la planète Beerus
        return 5;
    }
    else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 501)&&(m_posy >= 401))
    {
        //Si le joueur est sur la Terre sacrée des Kais
        return 6;
    }
    else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 651)&&(m_posy >= 601))
    {
        //Si le joueur est en enfer
        return 7;
    }
    else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 651)&&(m_posy >= 601))
    {
        //Si le joueur est sur la kame house
        return 8;
    }
    else if((m_posx <= 598)&&(m_posx >= 548)&&(m_posy <= 651)&&(m_posy >= 601))
    {
        //Si le joueur est dans le vaisseau de freezer
        return 9;
    }
    else
    {
        return 0;
    }
}

void Jeu::affi_glo(Carte& c,int x,int y, BITMAP* Buffer)
{
    ///de l'affichage allegro
    c.display(x,y,Buffer);
}

void Jeu::set_joueurs(std::vector<Joueur> j)
{
    m_joueurs=j;
}


void Jeu::sauvegarde_Joueurs(std::vector<Joueur> vect_joueurs)
{

    ///On sauvegarde le joueur dans un fichier à son nom
    std::string nomFichier;
    for (auto elem:vect_joueurs)
    {
        nomFichier = "sauvegardes/";
        nomFichier += elem.get_nom();
        nomFichier += ".txt";

        std::ofstream monFlux(nomFichier.c_str());

        if(monFlux)
        {
            ///On y stocke le nom du joueur et son score
            monFlux << elem.get_nom()<<std::endl;
            monFlux << elem.get_score()<<std::endl;
        }
        else
        {
            std::cout<<"Erreur de chargement du fichier"<<std::endl;
        }

    }
}

int Jeu::retour_Joueur(std::string nom_J)const
{
    std::string nomFichier;
    nomFichier = "sauvegardes/";
    nomFichier += nom_J;
    nomFichier += ".txt";
    std::string temp;

    std::ifstream fichier(nomFichier);

    ///On recupere un joueur grace au pseudo rentre
    if(fichier)
    {
        getline(fichier, temp); ///On recupere le nom

        if(temp == nom_J) ///blindage
        {
            std::cout<< nom_J << std::endl; ///On affiche le nom
            fichier.close();
            return 1; ///Le fichier existe bien
        }
        else
        {
            std::cout<< "Erreur de lecture du fichier" << std::endl;
            fichier.close();
            return 0; ///Le fichier n'existe pas
        }

    }
    else
    {
        ///Fichier introuvable
        std::cout<< "Le joueur est un nouveau joueur" << std::endl;
        fichier.close();
        return 0;
    }
}

int Jeu::recup_score(std::string _Nom)const
{
    ///On cherche le bon fichier correspondant au joueur
    std::string nomFichier;
    nomFichier = "sauvegardes/";
    nomFichier += _Nom;
    nomFichier += ".txt";
    std::string temp;
    int score;

    std::ifstream fichier(nomFichier);
    if(fichier) ///Si on le trouve
    {
        fichier >> temp;
        fichier >> score;
        std::cout<<score<<std::endl; ///On recupere le pseudo et le score

        fichier.close();
        return score; ///on retourne le score à l'appelant

    }
    else
    {
        ///Fichier introuvable
        std::cout<< "Le joueur est un nouveau joueur" << std::endl;
        fichier.close();
        return 0; ///Si pas de profil => nouveau donc score à 0
    }
}


std::vector<Carte*> Jeu::get_vecttest()const
{
    return m_cartestest2;
}


int Jeu::menuFin()
{
    int choix = 0;

    BITMAP * buffermenufin;
    BITMAP * menufin;
    BITMAP * menu1fin;
    BITMAP * menu2fin;
    BITMAP * menu3fin;

    buffermenufin = create_bitmap(SCREEN_W, SCREEN_H);

    menufin = load_bitmap("images/fin/menufin0.bmp", NULL);
    if(!menufin)
    {
        allegro_message("Erreur de chargement de l'image du menu");
        allegro_exit();
    }

    menu1fin = load_bitmap("images/fin/menufin1.bmp", NULL);
    menu2fin = load_bitmap("images/fin/menufin2.bmp", NULL);
    menu3fin = load_bitmap("images/fin/menufin3.bmp", NULL);

    while (choix == 0)
    {
        ///std::cout<<"rentre dans la boucle"<<std::endl;
        ///La souris est placée sur rejouer
        if(((394<mouse_x)&&(mouse_x<886))&&((84<mouse_y)&&(mouse_y<228)))
        {
            blit(menu1fin, buffermenufin, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(mouse_b & 1)
            {
                choix = 1;
                return choix;
            }
        }
        ///La souris est sur menu
        else if(((395<mouse_x)&&(mouse_x<885))&&((296<mouse_y)&&(mouse_y<438)))
        {
            blit(menu2fin, buffermenufin, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(mouse_b & 1)
            {
                choix = 2;
                return choix;
            }
        }
        ///La souris est sur quitter
        else if(((394<mouse_x)&&(mouse_x<885))&&((506<mouse_y)&&(mouse_y<650)))
        {
            blit(menu3fin, buffermenufin, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(mouse_b & 1)
            {
                choix = 3;
                return choix;
            }
        }
        else
        {
            blit(menufin, buffermenufin, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        }

        blit(buffermenufin, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    destroy_bitmap(buffermenufin);
    destroy_bitmap(menufin);
    destroy_bitmap(menu1fin);
    destroy_bitmap(menu2fin);
    destroy_bitmap(menu3fin);
    return choix;

}



///GETTERS ET SETTERS BASIQUES

void Jeu::hypothese(BITMAP *page,int m)
{
    std::vector<Joueur> provi=get_joueurs();
    BITMAP * fond = load_bitmap("images/verif.bmp", NULL);
    BITMAP * kinto;
    BITMAP * choix_hypo;
    BITMAP * aucune_carte;
    BITMAP * resultat;
    BITMAP * imagea = load_bitmap("images/verif.bmp", NULL);
    BITMAP * images = load_bitmap("images/verif.bmp", NULL);
    BITMAP * imagel = load_bitmap("images/verif.bmp", NULL);
    BITMAP * imageaffi= load_bitmap("images/verif.bmp", NULL);
    kinto=load_bitmap("images/hypothese/kinto.bmp",NULL);
    choix_hypo=load_bitmap("images/hypothese/choix_hypo.bmp",NULL);
    resultat=load_bitmap("images/hypothese/resultat_hypo.bmp",NULL);
    aucune_carte=load_bitmap("images/hypothese/aucune_carte.bmp",NULL);
    char nomimage[50];
    char nomimagea[50];
    char nomimages[50];
    char nomimagel[50];
    char nomimageaffi[50];
    int i=m+1;

    ///--------------------etape de l'arme-------------

    ///------------selection du lieu avec la position
        //if((verifPosition(get_joueurs()[m%(get_Nbjoueurs())]))==1)
    if(get_etapehypo()==-1)
    {
   //     std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        provi[m%(get_Nbjoueurs())].set_lhypotest(get_vecttest()[5+verifPosition(get_joueurs()[m%(get_Nbjoueurs())])]);
 //       std::cout<<"lieu sélectionée : "<<provi[m%(get_Nbjoueurs())].get_lhypo()->get_nom()<<std::endl;
        set_etathypo(0);
        set_joueurs(provi);
    }

    else if(get_etapehypo()==0)
    {
  //      std::cout<<"etape :"<<get_etapehypo()<<std::endl;

        /*///------------selection du lieu avec la position
        //if((verifPosition(get_joueurs()[m%(get_Nbjoueurs())]))==1)
        provi[m%(get_Nbjoueurs())].set_lhypotest(get_vecttest()[5+verifPosition(get_joueurs()[m%(get_Nbjoueurs())])]);

        std::cout<<"lieu sélectionée"<<std::endl;*/

        for(int i=0;i<(int)6/*get_nbarme()*/;i++)
        {
            if((mouse_b&1) && (mouse_x<917 && mouse_x>850)&&(mouse_y>31*i+40 && mouse_y<31*i+67))
            {
   //             std::cout<<"arme sélectionée"<<std::endl;
                provi[m%(get_Nbjoueurs())].set_ahypotest(get_vecttest()[i]);
                set_joueurs(provi);
                set_etathypo(1);
            }
        }
    }

    ///--------------------etape du suspect-------------
    else if(get_etapehypo()==1)
    {
   //     std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        for(int i=15;i<21;i++)
        {
            if((mouse_b&1) && (mouse_x<917 && mouse_x>850)&&(mouse_y>31*i+40 && mouse_y<31*i+67))
            {
    //            std::cout<<"lieu sélectionée"<<std::endl;
                provi[m%(get_Nbjoueurs())].set_shypotest(get_vecttest()[i]);
                set_joueurs(provi);
                set_etathypo(2);
            }
        }
    }

    ///-----------------etape du bouton confirme--------
    else if(get_etapehypo()==2)
    {
  //      std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        if((mouse_b&1) && (mouse_x<668 && mouse_x>535)&&(mouse_y>661 && mouse_y<704))
            {
     //           std::cout<<"hypothese confirmer"<<std::endl;
                set_etathypo(3);
            }
    }

    ///--------------etape de la comparaison------------

    else if(get_etapehypo()==3)
    {
        provi=get_joueurs();
  //      std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        do      ///Tester la version do while au lieu de while
        {
    //        std::cout<<"tour du joueur" <<m%(get_Nbjoueurs())<<"on cherche dans la main du joueur :"<<i%(get_Nbjoueurs())<<std::endl;
    //        std::cout<<"arme a chercher : "<<provi[m%(get_Nbjoueurs())].get_ahypo()->get_nom()<< " suspect a chercher : "<<provi[m%(get_Nbjoueurs())].get_shypo()->get_nom() << " lieu a chercher : "<<provi[m%(get_Nbjoueurs())].get_lhypo()->get_nom() <<std::endl;
            //int i=m+1;
            ///on verifie la main d'un joueur
            for(auto elem2:get_joueurs()[i%(get_Nbjoueurs())].get_maintest())
            {
                ///on verifie s'il a l'arme
                if(elem2->get_nom()==get_joueurs()[m%(get_Nbjoueurs())].get_ahypo()->get_nom())
                {
 //                   provi[m%(get_Nbjoueurs())].set_abon(provi[m%(get_Nbjoueurs())].get_ahypo());
                    provi[m%(get_Nbjoueurs())].set_avalide(true);
                }
                ///on verifie s'il a le suspect
                if(elem2->get_nom()==get_joueurs()[m%(get_Nbjoueurs())].get_shypo()->get_nom())
                {
      //              provi[m%(get_Nbjoueurs())].set_sbon(provi[m%(get_Nbjoueurs())].get_shypo());
                    provi[m%(get_Nbjoueurs())].set_svalide(true);
                }
                ///on verifie s'il a le lieu
                if(elem2->get_nom()==get_joueurs()[m%(get_Nbjoueurs())].get_lhypo()->get_nom())
                {
      //              provi[m%(get_Nbjoueurs())].set_lbon(provi[m%(get_Nbjoueurs())].get_lhypo());
                    provi[m%(get_Nbjoueurs())].set_lvalide(true);
                }
            }
            ///si le joueur n'a qu'une carte on la place dans à afficher et on va à l'etape afficher, on sort aussi de la boucle
            if(provi[m%(get_Nbjoueurs())].get_avalide()==true && provi[m%(get_Nbjoueurs())].get_lvalide()==false && provi[m%(get_Nbjoueurs())].get_svalide()==false )
            {
                provi[m%(get_Nbjoueurs())].set_a_affi(provi[m%(get_Nbjoueurs())].get_ahypo());
                set_etathypo(8);
                set_joueurs(provi);
            }
            else if(provi[m%(get_Nbjoueurs())].get_avalide()==false && provi[m%(get_Nbjoueurs())].get_lvalide()==true && provi[m%(get_Nbjoueurs())].get_svalide()==false)
            {
                provi[m%(get_Nbjoueurs())].set_a_affi(provi[m%(get_Nbjoueurs())].get_lhypo());
                set_etathypo(8);
                set_joueurs(provi);
            }
            else if(provi[m%(get_Nbjoueurs())].get_avalide()==false && provi[m%(get_Nbjoueurs())].get_lvalide()==false && provi[m%(get_Nbjoueurs())].get_svalide()==true)
            {
                provi[m%(get_Nbjoueurs())].set_a_affi(provi[m%(get_Nbjoueurs())].get_shypo());
                set_etathypo(8);
                set_joueurs(provi);
            }
            else if(provi[m%(get_Nbjoueurs())].get_avalide()==false && provi[m%(get_Nbjoueurs())].get_lvalide()==false && provi[m%(get_Nbjoueurs())].get_svalide()==false)
            {
                i++; ///on trouve rien on passe au joueur suivant
            }
            else
            {
                set_etathypo(4); ///on a au moins deux true on lance la transition pour le choix
                set_joueurs(provi);
            }

            ///si au bout du parcours on a rien on passse à l'affichage aucune carte
            if(i%(get_Nbjoueurs())==m%(get_Nbjoueurs()) && (provi[m%(get_Nbjoueurs())].get_avalide()==false && provi[m%(get_Nbjoueurs())].get_lvalide()==false && provi[m%(get_Nbjoueurs())].get_svalide()==false))
            {
                set_etathypo(9);
                set_joueurs(provi);
            }
            //set_joueurs(provi);
        }while(provi[m%(get_Nbjoueurs())].get_avalide()==false && provi[m%(get_Nbjoueurs())].get_lvalide()==false && provi[m%(get_Nbjoueurs())].get_svalide()==false && i%(get_Nbjoueurs())!=m%(get_Nbjoueurs()));
   //     std::cout<<"arme : "<<provi[m%(get_Nbjoueurs())].get_avalide() << " suspect : "<<provi[m%(get_Nbjoueurs())].get_svalide() << " lieu : "<<provi[m%(get_Nbjoueurs())].get_lvalide() <<std::endl;
    }

    ///--------------etape de la transition-------------

    else if(get_etapehypo()==4)
    {
   //     std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        if(get_cpt()<2500)
        {
            draw_sprite(page,kinto,1280-get_cpt(),0);
            set_cpt(get_cpt()+75);
        }
        else if(get_cpt()>=2500)
            set_etathypo(5);
    }


    if(get_etapehypo()==5)
    {
   //     std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        draw_sprite(page,kinto,1280-get_cpt(),0);
        if(key[KEY_ENTER])
        {
            ///attendre qu'on passe l'ordi
  //          std::cout<<"appui sur entree"<<std::endl;
            set_etathypo(6);
        }
    }

    ///sortie de entrée ( agrandir l'image et remettre un truc similaire à la fin )
    else if(get_etapehypo()==6)
    {
   //     std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        if(get_cpt()<3880)
        {
            draw_sprite(page,kinto,1280-get_cpt(),0);
            set_cpt(get_cpt()+75);
        }
        else if(get_cpt()>=3880)
            set_etathypo(7);
    }

    ///preparation carte xxl

    if(get_etapehypo()>-1)
    {
        sprintf(nomimage,"images/hypothese/h_%s.bmp",provi[m%(get_Nbjoueurs())].get_lhypo()->get_nom().c_str());
        sprintf(nomimagel,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_lhypo()->get_nom().c_str());
        fond=load_bitmap(nomimage,NULL);
        if(!fond)
        {
            allegro_message("Erreur de chargement de l'image du fond");
            allegro_exit();
        }
        imagel=load_bitmap(nomimagel,NULL);
        if(!imagel)
        {
            allegro_message("Erreur de chargement de l'image du lieu");
            allegro_exit();
        }
        if(get_etapehypo()>0)
        {
            sprintf(nomimagea,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_ahypo()->get_nom().c_str());
            imagea=load_bitmap(nomimagea,NULL);
            if(!imagea)
            {
                allegro_message("Erreur de chargement de l'image de l'arme");
                allegro_exit();
            }
            if(get_etapehypo()>1)
            {
                sprintf(nomimages,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_shypo()->get_nom().c_str());
                images=load_bitmap(nomimages,NULL);
                if(!images)
                {
                    allegro_message("Erreur de chargement de l'image du lieu");
                    allegro_exit();
                }
            }
        }
    }

    ///selection des cartes par le joueur si necessaire

    if(get_etapehypo()==7)
    {
        provi=get_joueurs();
  //      std::cout<<"etape :"<<get_etapehypo()<<std::endl;
  //      std::cout<<"arme : "<<provi[m%(get_Nbjoueurs())].get_avalide() << " suspect : "<<provi[m%(get_Nbjoueurs())].get_svalide() << " lieu : "<<provi[m%(get_Nbjoueurs())].get_lvalide() <<std::endl;
 //       std::cout<<"entre :";
        if(provi[m%(get_Nbjoueurs())].get_avalide()==true)
        {
    //        std::cout<<" arme,";
            //get_joueurs()[m%(get_Nbjoueurs())].get_ahypo()->display(865,275,choix_hypo);
            draw_sprite(choix_hypo,imagea,128,489);
        }
        if(provi[m%(get_Nbjoueurs())].get_lvalide()==true)
        {
    //        std::cout<<" lieu,";
            //get_joueurs()[m%(get_Nbjoueurs())].get_lhypo()->display(110,275,choix_hypo);
            draw_sprite(choix_hypo,imagel,128,85);
        }
         if(provi[m%(get_Nbjoueurs())].get_svalide()==true)
        {
   //         std::cout<<" suspect";
            //get_joueurs()[m%(get_Nbjoueurs())].get_shypo()->display(490,275,choix_hypo);
            draw_sprite(choix_hypo,images,128,286);
        }
  //      std::cout<<std::endl;

        if((mouse_b&1) && (mouse_x<495 && mouse_x>128)&&(mouse_y>77 && mouse_y<237) && (provi[m%(get_Nbjoueurs())].get_lvalide()==true))
        {
            provi[m%(get_Nbjoueurs())].set_a_affi(get_joueurs()[m%(get_Nbjoueurs())].get_lhypo());
   //         std::cout<<"la carte choisi est : "<<provi[m%(get_Nbjoueurs())].get_a_affi()->get_nom()<<std::endl;
            set_etathypo(11);
        }

        else if((mouse_b&1) && (mouse_x<495 && mouse_x>128)&&(mouse_y>280 && mouse_y<440) && (provi[m%(get_Nbjoueurs())].get_svalide()==true))
        {
            provi[m%(get_Nbjoueurs())].set_a_affi(get_joueurs()[m%(get_Nbjoueurs())].get_shypo());
 //           std::cout<<"la carte choisi est : "<<provi[m%(get_Nbjoueurs())].get_a_affi()->get_nom()<<std::endl;
            set_etathypo(11);
        }

        else if((mouse_b&1) && (mouse_x<495 && mouse_x>128)&&(mouse_y>482 && mouse_y<642) && (provi[m%(get_Nbjoueurs())].get_avalide()==true))
        {
            provi[m%(get_Nbjoueurs())].set_a_affi(get_joueurs()[m%(get_Nbjoueurs())].get_ahypo());
 //           std::cout<<"la carte choisi est : "<<provi[m%(get_Nbjoueurs())].get_a_affi()->get_nom()<<std::endl;
            set_etathypo(11);
        }
        set_joueurs(provi);
        draw_sprite(kinto,choix_hypo,2600,0);
        draw_sprite(page,kinto,1280-get_cpt(),0);
    }

    ///-----------------transition---------------------- (peut-etre pas necessaire)

    else if(get_etapehypo()==11)
    {
    //    std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        if(provi[m%(get_Nbjoueurs())].get_avalide()==true)
        {
            //get_joueurs()[m%(get_Nbjoueurs())].get_ahypo()->display(865,275,choix_hypo);
            draw_sprite(choix_hypo,imagea,128,489);
        }
        if(provi[m%(get_Nbjoueurs())].get_lvalide()==true)
        {
            //get_joueurs()[m%(get_Nbjoueurs())].get_lhypo()->display(110,275,choix_hypo);
            draw_sprite(choix_hypo,imagel,128,85);
        }
         if(provi[m%(get_Nbjoueurs())].get_svalide()==true)
        {
            //get_joueurs()[m%(get_Nbjoueurs())].get_shypo()->display(490,275,choix_hypo);
            draw_sprite(choix_hypo,images,128,286);
        }
        if(get_cpt()<6800)
        {
            draw_sprite(kinto,choix_hypo,2600,0);
            draw_sprite(page,kinto,1280-get_cpt(),0);
            set_cpt(get_cpt()+75);
        }
        else if(get_cpt()>=6800)
            set_etathypo(8);
    }

    ///affichage de la carte montré

    /*else*/ if(get_etapehypo()==8)  ///probleme pour afficher la carte
    {
        provi=get_joueurs();
  //      std::cout<<"etape :"<<get_etapehypo()<<std::endl;
 //       std::cout<<"la carte choisi est : "<<provi[m%(get_Nbjoueurs())].get_a_affi()->get_nom()<<std::endl;
        sprintf(nomimageaffi,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_a_affi()->get_nom().c_str());
        imageaffi=load_bitmap(nomimageaffi,NULL);
        //provi/*get_joueurs()*/[m%(get_Nbjoueurs())].get_a_affi()->display(100,240,resultat); ///afficher la carte montré
        draw_sprite(resultat,imageaffi,60,240);
        draw_sprite(page,resultat,222,33);
        if(key[KEY_ENTER])
        {
            ///attendre qu'on valide fin de l'hypothèse
   //         std::cout<<"appui sur entree"<<std::endl;
            set_etathypo(10);
        }
    }
    ///--------------affichage si aucune carte----------

    else if(get_etapehypo()==9)
    {
    //    std::cout<<"etape :"<<get_etapehypo()<<std::endl;
        //display une image pour dire qu'il y a aucune carte à afficher
        draw_sprite(page,aucune_carte,222,33);
        if(key[KEY_ENTER])
        {
            ///attendre qu'on valide fin de l'hypothèse
    //        std::cout<<"appui sur entree"<<std::endl;
            set_etathypo(10);
        }
    }

   ///-----------on resest----------------------------
    else if(get_etapehypo()==10)
    {
        ///pas forcement necessaire à voir
    }

    ///--------------etape de l'affichage---------------

    if(get_etapehypo()<3)
    {
        if(get_etapehypo()>-1)
        {
            //sprintf(nomimage,"images/hypothese/h_%s.bmp","vaisseau_freezer");
            /*sprintf(nomimage,"images/hypothese/h_%s.bmp",provi[m%(get_Nbjoueurs())].get_lhypo()->get_nom().c_str());
            fond=load_bitmap(nomimage,NULL);
            if(!fond)
            {
                allegro_message("Erreur de chargement de l'image du fond");
                allegro_exit();
            }*/
   //         std::cout<<"affi lieu"<<std::endl;
            //get_joueurs()[m%(get_Nbjoueurs())].get_lhypo()->display(409,76,fond);
            draw_sprite(fond,imagel,415,83);
  //          std::cout<<"affi lieu effectué"<<std::endl;
            if(get_etapehypo()>0)
            {
  //              std::cout<<"affi arme"<<std::endl;
                //get_joueurs()[m%(get_Nbjoueurs())].get_ahypo()->display(409,280,fond);  ///changer l'ordre dans l'image de hypo
                draw_sprite(fond,imagea,415,287);
   //             std::cout<<"affi arme effectue"<<std::endl;

                if(get_etapehypo()>1)
                {
    //                std::cout<<"affi suspect"<<std::endl;
                    //provi[m%(get_Nbjoueurs())].get_shypo()->display(409,484,fond);
                    draw_sprite(fond,images,415,491);
    //                std::cout<<"affi suspect effectue"<<std::endl;
                }
            }
            //draw_sprite(page,fond,0,0);
        }
        draw_sprite(page,fond,0,0);
    }


    destroy_bitmap(kinto);
    destroy_bitmap(resultat);
    destroy_bitmap(choix_hypo);
    destroy_bitmap(aucune_carte);

    if(get_etapehypo()>-1)
    {
        destroy_bitmap(fond);
        destroy_bitmap(imagel);
        if(get_etapehypo()>0)
        {
            destroy_bitmap(imagea);
            if(get_etapehypo()>1)
            {
                destroy_bitmap(images);
                if(get_etapehypo()==8)
                {
                    destroy_bitmap(imageaffi);
                }
            }
        }
    }
}


void Jeu::accusation(BITMAP *page,int m)
{
    std::vector<Joueur> provi=get_joueurs();
    BITMAP * fond = load_bitmap("images/verif.bmp", NULL);
    BITMAP * vrai;
    BITMAP * faux;
    BITMAP * imagea_a = load_bitmap("images/verif.bmp", NULL);
    BITMAP * images_a = load_bitmap("images/verif.bmp", NULL);
    BITMAP * imagel_a = load_bitmap("images/verif.bmp", NULL);
    fond=load_bitmap("images/accusation/accusation.bmp",NULL);
    vrai=load_bitmap("images/accusation/vrai.bmp",NULL);
    faux=load_bitmap("images/accusation/faux.bmp",NULL);
    char nomimagea[50];
    char nomimages[50];
    char nomimagel[50];

    if(get_etapeaccu()==-1)
    {
     //   std::cout<<"etape :"<<get_etapehypo()<<std::endl;

        for(int i=6;i<(int)15/*get_nblieu()*/;i++)
        {
            if((mouse_b&1) && (mouse_x<917 && mouse_x>850)&&(mouse_y>31*i+40 && mouse_y<31*i+67)) ///cahnger l'intervalle
            {
                std::cout<<"lieu sélectionée"<<std::endl;
                provi[m%(get_Nbjoueurs())].set_l_accutest(get_vecttest()[i]);
                set_joueurs(provi);
                set_etataccu(0);
            }
        }
    }
    else if(get_etapeaccu()==0)
    {
      //  std::cout<<"etape :"<<get_etapeaccu()<<std::endl;
        for(int i=0;i<(int)6/*get_nbarme()*/;i++)
        {
            if((mouse_b&1) && (mouse_x<917 && mouse_x>850)&&(mouse_y>31*i+40 && mouse_y<31*i+67))
            {
                std::cout<<"arme sélectionée"<<std::endl;
                provi[m%(get_Nbjoueurs())].set_a_accutest(get_vecttest()[i]);
                set_joueurs(provi);
                set_etataccu(1);
            }
        }
    }

    ///--------------------etape du suspect-------------
    else if(get_etapeaccu()==1)
    {
     //   std::cout<<"etape :"<<get_etapeaccu()<<std::endl;
        for(int i=15;i<21;i++)
        {
            if((mouse_b&1) && (mouse_x<917 && mouse_x>850)&&(mouse_y>31*i+40 && mouse_y<31*i+67))
            {
                std::cout<<"suspect sélectionée"<<std::endl;
                provi[m%(get_Nbjoueurs())].set_s_accutest(get_vecttest()[i]);
                set_joueurs(provi);
                set_etataccu(2);
            }
        }
    }

    ///-----------------etape du bouton confirme--------
    else if(get_etapeaccu()==2)
    {
   //     std::cout<<"etape :"<<get_etapeaccu()<<std::endl;
        if((mouse_b&1) && (mouse_x<668 && mouse_x>535)&&(mouse_y>661 && mouse_y<704))
            {
                std::cout<<"hypothese confirmer"<<std::endl;
                set_etataccu(3);
            }
    }

    ///------------------------comparaison---------------
    else if(get_etapeaccu()==3)
    {
        if(get_joueurs()[m%(get_Nbjoueurs())].get_a_accu()->get_nom()== get_solu_a()->get_nom())
            provi[m%(get_Nbjoueurs())].set_avalide_accu(true);
            else
                provi[m%(get_Nbjoueurs())].set_avalide_accu(false);

        if(get_joueurs()[m%(get_Nbjoueurs())].get_l_accu()->get_nom()== get_solu_l()->get_nom())
            provi[m%(get_Nbjoueurs())].set_lvalide_accu(true);
            else
               provi[m%(get_Nbjoueurs())].set_lvalide_accu(false);

        if(get_joueurs()[m%(get_Nbjoueurs())].get_s_accu()->get_nom()== get_solu_s()->get_nom())
            provi[m%(get_Nbjoueurs())].set_svalide_accu(true);
            else
                provi[m%(get_Nbjoueurs())].set_svalide_accu(false);

        if(provi[m%(get_Nbjoueurs())].get_avalide_accu() ==false || provi[m%(get_Nbjoueurs())].get_lvalide_accu() ==false || provi[m%(get_Nbjoueurs())].get_svalide_accu() ==false)
        {
            provi[m%(get_Nbjoueurs())].set_elimine(true);
            set_etataccu(5);
            set_victoire(false);
        }
        else
        {
            set_etataccu(4);
            set_victoire(true);
        }
        set_joueurs(provi);
    }

    ///----------------affichage final-------------------

    else if(get_etapeaccu()==4)
    {
     //   std::cout<<"etape :"<<get_etapeaccu()<<std::endl;
        //display une image pour dire qu'il y a aucune carte à afficher
        draw_sprite(page,vrai,222,33);
        if(key[KEY_ENTER])
        {
            ///attendre qu'on valide fin de l'hypothèse
       //     std::cout<<"appui sur entree"<<std::endl;
            set_etataccu(6);
        }
    }

    else if(get_etapeaccu()==5)
    {
     //   std::cout<<"etape :"<<get_etapeaccu()<<std::endl;
        draw_sprite(page,faux,0,0);
        if(key[KEY_ENTER])
        {
            ///attendre qu'on valide fin de l'hypothèse
     //       std::cout<<"appui sur entree"<<std::endl;
            set_etataccu(6);
        }
    }

    if(get_etapeaccu()>-1)
    {
        sprintf(nomimagel,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_l_accu()->get_nom().c_str());
        imagel_a=load_bitmap(nomimagel,NULL);
        if(get_etapeaccu()>0)
        {
            sprintf(nomimagea,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_a_accu()->get_nom().c_str());
            imagea_a=load_bitmap(nomimagea,NULL);
            if(get_etapeaccu()>1)
            {
                sprintf(nomimages,"images/cartes_xxl/%s.bmp",provi[m%(get_Nbjoueurs())].get_s_accu()->get_nom().c_str());
                images_a=load_bitmap(nomimages,NULL);
            }
        }
    }

    ///affiche au fur et à mesure de la saisie
    if(get_etapeaccu()<3)
    {
        provi=get_joueurs();
        if(get_etapeaccu()>-1)
        {
            std::cout<<"affi lieu"<<std::endl;
            //get_joueurs()[m%(get_Nbjoueurs())].get_l_accu()->display(409,76,fond);
            draw_sprite(fond,imagel_a,415,83);
            std::cout<<"affi arme lieu"<<std::endl;
            if(get_etapeaccu()>0)
            {
                std::cout<<"affi arme"<<std::endl;
                //get_joueurs()[m%(get_Nbjoueurs())].get_a_accu()->display(409,280,fond);  ///changer l'ordre dans l'image de hypo
                draw_sprite(fond,imagea_a,415,287);
                std::cout<<"affi arme effectue"<<std::endl;

                if(get_etapeaccu()>1)
                {
                    std::cout<<"affi suspect"<<std::endl;
                    //provi[m%(get_Nbjoueurs())].get_s_accu()->display(409,484,fond);
                    draw_sprite(fond,images_a,415,491);
                    std::cout<<"affi suspect effectue"<<std::endl;
                }
            }
        }

        draw_sprite(page,fond,0,0);
    }
    destroy_bitmap(fond);
    destroy_bitmap(vrai);
    destroy_bitmap(faux);

    if(get_etapehypo()>-1)
    {

        destroy_bitmap(imagel_a);
        if(get_etapehypo()>0)
        {
            destroy_bitmap(imagea_a);
            if(get_etapehypo()>1)
            {
                destroy_bitmap(images_a);
            }
        }
    }
}

void Jeu::set_cpt(int m)
{
    m_cpt=m;
}
int Jeu::get_cpt()
{
    return m_cpt;
}


int Jeu::get_etapehypo()const
{
    return m_etape_hypo;
}
void Jeu::set_etathypo(int val)
{
    m_etape_hypo=val;
}

void Jeu::set_cpta(int m)
{
    m_cpta=m;
}
int Jeu::get_cpta()
{
    return m_cpta;
}


int Jeu::get_etapeaccu()const
{
    return m_etape_accu;
}
void Jeu::set_etataccu(int val)
{
    m_etape_accu=val;
}

void Jeu::set_solu_a(Carte * c)
{
    m_solu_a=c;
}
void Jeu::set_solu_l(Carte * c)
{
    m_solu_l=c;
}
void Jeu::set_solu_s(Carte * c)
{
    m_solu_s=c;
}

Carte * Jeu::get_solu_a()
{
    return m_solu_a;
}
Carte * Jeu::get_solu_s()
{
    return m_solu_s;
}
Carte * Jeu::get_solu_l()
{
    return m_solu_l;
}

void Jeu::set_victoire(bool b)
{
    m_victoire=b;
}
bool Jeu::get_victoire()
{
    return m_victoire;
}


///Programmes d'affichages liées aux choix dans le menu

void Jeu::affichage_Aides()
{
    ///Creation et recuperation des bitmaps
    BITMAP * buffer;

    BITMAP * aide1;
    BITMAP * aide2;
    BITMAP * aide3;
    BITMAP * aide4;
    BITMAP * aide5;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);

    aide1 = load_bitmap("AIDE/aide1.bmp", NULL);
    aide2 = load_bitmap("AIDE/aide2.bmp", NULL);
    aide3 = load_bitmap("AIDE/aide3.bmp", NULL);
    aide4 = load_bitmap("AIDE/aide4.bmp", NULL);
    aide5 = load_bitmap("AIDE/aide5.bmp", NULL);


    int choix = 1;

    ///Le joueur doit appuyer sur entree pour sortir

    while(!key[KEY_ENTER])
    {
        ///On va afficher les differentes pages
        ///On peut se deplacer entre les pages avec les fleches gauche et droite
        if(choix==1)
        {
            blit(aide1, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                choix = 2;
                rest(100);
            }

        }
        else if(choix==2)
        {
            blit(aide2, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                choix = 3;
                rest(100);
            }
            else if(key[KEY_LEFT])
            {
                choix = 1;
                rest(100);
            }

        }
        else if(choix==3)
        {
            blit(aide3, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                choix = 4;
                rest(100);
            }
            else if(key[KEY_LEFT])
            {
                choix = 2;
                rest(100);
            }

        }
        else if(choix==4)
        {
            blit(aide4, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_RIGHT])
            {
                choix = 5;
                rest(100);
            }
            else if(key[KEY_LEFT])
            {
                choix = 3;
                rest(100);
            }

        }
        else if(choix==5)
        {
            blit(aide5, buffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

            if(key[KEY_LEFT])
            {
                choix = 4;
                rest(100);
            }

        }
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    ///Destruction des bitmaps (gestion de la memoire)
    destroy_bitmap(aide1);
    destroy_bitmap(aide2);
    destroy_bitmap(aide3);
    destroy_bitmap(aide4);
    destroy_bitmap(aide5);

    destroy_bitmap(buffer);

}


void Jeu::affichage_Scores()
{
    std::string Nom;

    int score = 0;

    std::cout<<"Veuillez saisir le nom du joueur que vous recherchez :" << std::endl;

    std::cin>>Nom;

    score = recup_score(Nom);

    std::cout<<"score :" << score <<std::endl;

            if(score <= 5)
            {
                std::cout<<"Niveau : debutant"<<std::endl;
            }
            else if(score <= 10)
            {
                std::cout<<"Niveau : intermediaire"<<std::endl;
            }
            else if(score <= 20)
            {
                std::cout<<"Niveau : confirme"<<std::endl;
            }
            else
            {
                std::cout<<"Niveau : EXPERT"<<std::endl;
            }

}

void Jeu::animation()
{
    int nbimages = 145;

    BITMAP * anim[nbimages];

    BITMAP * buffer;

    buffer = create_bitmap(SCREEN_W, SCREEN_H);
    char nom[50];

    for(int i=0; i< nbimages; i++)
    {
        sprintf(nom, "images/animation/%d.bmp", i);


        anim[i] = load_bitmap(nom, NULL);

        blit(anim[i], buffer, 0 , 0, 0, 0, SCREEN_W, SCREEN_H);
        blit(buffer, screen, 0 , 0, 0, 0, SCREEN_W, SCREEN_H);

        rest(28);
        destroy_bitmap(anim[i]);
    }

}
