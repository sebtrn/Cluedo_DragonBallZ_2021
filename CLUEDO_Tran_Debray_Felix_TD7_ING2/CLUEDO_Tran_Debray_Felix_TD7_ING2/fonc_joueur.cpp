#include "header_joueur.h"

Joueur::Joueur(){}

Joueur::~Joueur(){}

Joueur::Joueur(std::string _nom)
       :m_nom(_nom){}

BITMAP * Joueur::get_Pion()const
{
    return m_pion.get_Pion();
}

Salle Joueur::get_salle()const
{
    return m_salle;
}
void Joueur::set_salle(Salle b)
{
    m_salle=b;
}

bool Joueur::get_elimine()const ///voir si le joueur joue encore
{
    return m_elimine;
}

void Joueur::set_elimine(bool b) ///On definit si le joueur est éliminé ou non
{
    m_elimine=b;
}

int Joueur::get_posx()const
{
    return m_pion.get_posx(); ///On utilise les coordonnées de son pion
}

int Joueur::get_posy()const
{
    return m_pion.get_posy(); ///On utilise les coordonnées de son pion
}

int Joueur::set_posx(int val)
{
    return m_pion.set_posx(val); ///On modifie les coordonnées de son pion
}

int Joueur::set_posy(int val)
{
    return m_pion.set_posy(val); ///On modifie les coordonnées de son pion
}

int Joueur::get_nbPas()const
{
    return m_nombrePas; ///On recupère le nombre de pas restants du joueur
}


void Joueur::set_nbPas(int _nombrePas)
{
    m_nombrePas = _nombrePas; ///On definit le nb de pas restants du joueur
}

void Joueur::set_pion(BITMAP * _Perso)
{
    m_pion.set_Pion(_Perso); ///On recupere puis envoie la bitmap du joueur
}

std::vector<Carte> Joueur::get_main()const
{
    return m_main; ///On retourne la main du joueur
}
void Joueur::set_main(std::vector<Carte> m)
{
    m_main=m; ///On définit la main du joueur
}

std::vector<Carte*> Joueur::get_maintest()const
{
    return m_maintest;
}
void Joueur::set_maintest(std::vector<Carte*> m)
{
    m_maintest=m;
}

void Joueur::ajout_main(Carte c)
{
    m_main.push_back(c); ///On ajoute une carte dans le vecteur main du joueur
}

std::string Joueur::get_nom()const
{
    return m_nom; ///On recupere le nom du joueur
}

void Joueur::affi_main(BITMAP* page)
{
    int i=0;
    BITMAP * fond;
    BITMAP * goku;

    const char * g;
    char nbpas[10];
    g = get_nom().c_str();
    sprintf(nbpas,"pas : %d",get_nbPas());

    ///On charge l'image d'affichage de la main

    fond=load_bitmap("images/bullemain.bmp",NULL);
    goku=load_bitmap("images/gokukameha.bmp",NULL);

    ///Si le curseur est sur le radar on affiche la main du joueur, son pseudo et son nb de pas restants
    if((mouse_x>740 && mouse_x<800) && (mouse_y>620 && mouse_y<680))
    {
        if(get_cptanim()!=fond->w)
        {
            //stretch_sprite(page,fond,60,580,fond->w-(fond->w/get_cptanim()),fond->h-(fond->h/get_cptanim()*5));
            ///La fenetre s'ouvre progressivement sur l'ecran
            if(get_cptanim()>fond->w-70)
            {
                ///On affiche les cartes et les infos ici
                for(auto elem:get_maintest())
                {
                    affi_glo1(*elem,80*i+100,50,fond);
                    i++;
                }
                textprintf_ex(fond,font,30,25,makecol(0,0,0),-1,g);
                textprintf_ex(fond,font,30,45,makecol(0,0,0),-1,nbpas);
                textprintf_ex(fond,font,30,35,makecol(0,0,0),-1,get_salle().get_nom().c_str());
            }
            stretch_sprite(goku,fond,120,105,fond->w-(fond->w-get_cptanim()),fond->h/*-(fond->h-(get_cptanim()*5))*/);
            set_cptanim(get_cptanim()+40);
            //rest(1);
        }
        else if(get_cptanim()==fond->w)
        {
            textprintf_ex(fond,font,30,25,makecol(0,0,0),-1,g);
            textprintf_ex(fond,font,30,45,makecol(0,0,0),-1,nbpas);
            textprintf_ex(fond,font,30,35,makecol(0,0,0),-1,get_salle().get_nom().c_str());
            for(auto elem:get_maintest())
            {
                affi_glo1(*elem,80*i+100,50,fond);
                i++;
            }
            draw_sprite(goku,fond,120,105);
        }
        draw_sprite(page,goku,-40,510);
    }
    else
    {
        set_cptanim(40);
    }
    //delete g;
    destroy_bitmap(fond);
    destroy_bitmap(goku);
}

void Joueur::affi_glo1(Carte& c,int x,int y, BITMAP* Buffer)
{
    ///de l'affichage allegro
    c.display(x,y,Buffer);
}

Bloc_notes Joueur::get_bloco()
{
    return m_bloc;
}
void Joueur::set_bloco(Bloc_notes b)
{
    m_bloc=b;
}

void Joueur::set_x(int val)
{
    m_pion.set_x(val);
}

void Joueur::set_y(int val)
{
    m_pion.set_y(val);
}

void Joueur::set_cptanim(int m)
{
    m_cpt_anim=m;
}
int Joueur::get_cptanim()
{
    return m_cpt_anim;
}

void Joueur::hypothese(BITMAP *page)
{
    BITMAP * fond;
    ///On affiche l'image de saisie de l'hypothèse
    fond=load_bitmap("images/hypothese.bmp",NULL);
    draw_sprite(page,fond,222,33);
}

///
///
///Pour le reste il s'agit simplement de setter et de getter ne nécessitant pas de commentaires particuliers
///
///

int Joueur::get_etapehypo()const
{
    return m_etape_hypo;
}
void Joueur::set_etathypo(int val)
{
    m_etape_hypo=val;
}


void Joueur::set_score(int _score)
{
    m_score = _score;
}

int Joueur::get_score()
{
    return m_score;
}

Pion Joueur::get_pion()const
{
    return m_pion;
}

Carte *  Joueur::get_ahypo()const
{
    return m_ahypo;
}
Carte *  Joueur::get_shypo()const
{
    return m_shypo;
}
Carte *  Joueur::get_lhypo()const
{
    return m_lhypo;
}


Carte *  Joueur::get_a_affi()const
{
    return m_a_affi;
}

void Joueur::set_shypotest(Carte * c)
{
    m_shypo=c;
}

void Joueur::set_ahypotest(Carte * c)
{
    m_ahypo=c;
}

void Joueur::set_lhypotest(Carte * c)
{
    m_lhypo=c;
}

void Joueur::set_a_affi(Carte * c)
{
    m_a_affi=c;
}



bool Joueur::get_avalide()
{
    return m_avalide;
}
bool Joueur::get_svalide()
{
    return m_svalide;
}
bool Joueur::get_lvalide()
{
    return m_lvalide;
}

void Joueur::set_avalide(bool b)
{
    m_avalide=b;
}
void Joueur::set_svalide(bool b)
{
    m_svalide=b;
}
void Joueur::set_lvalide(bool b)
{
    m_lvalide=b;
}

Carte * Joueur::get_a_accu()const
{
    return m_a_accu;
}
Carte * Joueur::get_s_accu()const
{
    return m_s_accu;
}
Carte * Joueur::get_l_accu()const
{
    return m_l_accu;
}
void Joueur::set_a_accutest(Carte * c)
{
    m_a_accu=c;
}
void Joueur::set_s_accutest(Carte * c)
{
    m_s_accu=c;
}
void Joueur::set_l_accutest(Carte * c)
{
    m_l_accu=c;
}

bool Joueur::get_avalide_accu()
{
    return m_avalide_accu;
}
bool Joueur::get_svalide_accu()
{
    return m_svalide_accu;
}
bool Joueur::get_lvalide_accu()
{
    return m_lvalide_accu;
}
void Joueur::set_avalide_accu(bool b)
{
    m_avalide_accu=b;
}
void Joueur::set_svalide_accu(bool b)
{
    m_svalide_accu=b;
}
void Joueur::set_lvalide_accu(bool b)
{
    m_lvalide_accu=b;
}
