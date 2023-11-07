#include "header_pion.h"

Pion::Pion() {}

Pion::~Pion() {}

void Pion::set_Pion(BITMAP * Pion)
{
    m_image = Pion;
}

BITMAP * Pion::get_Pion()const
{
    return m_image;
}

int Pion::get_posx()const
{
    return m_posx;
}

int Pion::get_posy()const
{
    return m_posy;
}

int Pion::get_depx()const
{
    return m_depx;
}

int Pion::get_depy()const
{
    return m_depy;
}


///Selon le int val reçu on sait la direction dans laquelle veut aller le joueur
int Pion::set_posx(int val)
{
    if(val==1) ///vers la droite si val==1
    {
        ///On va tester toutes les coordonnées des limites de la map et des salles
        ///Si le joueur est dans une salle on vérifie s'il y a une porte dans cette direction
        if(m_posx > 598)
        {
            std::cout<<"Le pion ne peut plus aller a droite"<<std::endl;
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète vegeta
            m_posx = 198;
            m_posy = 1;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète namek
            m_posx = 398;
            m_posy = 1;
        }
        else if((m_posx <= 598)&&(m_posx > 548)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète kaio
            return 0;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 301)&&(m_posy >= 201))
        {
            //Si le joueur est dans la salle du Temps
            m_posx = 398;
            m_posy = 251;
        }
        else if((m_posx <= 98)&&(m_posx >= 48)&&(m_posy <= 351)&&(m_posy >= 301))
        {
            //Si le joueur est au spawn chez Bulma
            m_posx = 148;
            m_posy = 301;
        }
        else if((m_posx <= 648)&&(m_posx >= 498)&&(m_posy <= 401)&&(m_posy >= 251))
        {
            //Si le joueur est sur la planète Beerus
            return 0;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 501)&&(m_posy >= 401))
        {
            //Si le joueur est sur la Terre sacrée des Kais
            m_posx = 398;
            m_posy = 451;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est en enfer
            m_posx = 198;
            m_posy = 651;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est sur la kame house
            m_posx = 398;
            m_posy = 651;
        }
        else if((m_posx <= 598)&&(m_posx >= 548)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est dans le vaisseau de freezer
            return 0;
        }
        else
        {
            ///Ici, dans le cas où le joueur n'est pas dans une piece
            ///On blinde pour qu'il ne puisse rentrer que par les portes
            if(m_posy == 1)
            {
                //Il s'agit de blindage assez classiques en utilisant les coordonnées du pion
                if((m_posx >48) || (m_posx< 248))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 51)
            {
                if((m_posx==48) || (m_posx==248) || (m_posx==498))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 201)
            {
                if((m_posx==198))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 251)
            {
                if((m_posx==448))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 301)
            {
                if((m_posx==198))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 351)
            {
                if((m_posx==448))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 401)
            {
                if((m_posx==198) || (m_posx==448))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 501)
            {
                if((m_posx==198))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 601)
            {
                if((m_posx ==48) || (m_posx== 248) || (m_posx==498))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else if(m_posy == 651)
            {
                if((m_posx ==48) || (m_posx== 248))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx + get_depx();
                }
            }
            else
            {
                m_posx = m_posx + get_depx();
            }
        }

    }

    else if(val==2) ///vers la gauche
    {
        ///On va tester toutes les coordonnées des limites de la map et des salles
        ///Si le joueur est dans une salle on vérifie s'il y a une porte dans cette direction
        if(m_posx < 98)
        {
            std::cout<<"Le pion ne peut plus aller a gauche"<<std::endl;
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète vegeta
            return 0;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète namek
            return 0;
        }
        else if((m_posx <= 598)&&(m_posx > 548)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète kaio
            m_posx = 498;
            m_posy = 1;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 301)&&(m_posy >= 201))
        {
            //Si le joueur est dans la salle du Temps
            m_posx = 198;
            m_posy = 251;
        }
        else if((m_posx <= 98)&&(m_posx >= 48)&&(m_posy <= 351)&&(m_posy >= 301))
        {
            //Si le joueur est au spawn chez Bulma
            return 0;
        }
        else if((m_posx <= 648)&&(m_posx >= 498)&&(m_posy <= 401)&&(m_posy >= 251))
        {
            //Si le joueur est sur la planète Beerus
            m_posx = 448;
            m_posy = 301;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 501)&&(m_posy >= 401))
        {
            //Si le joueur est sur la Terre sacrée des Kais
            m_posx = 198;
            m_posy = 451;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est en enfer
            return 0;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est sur la kame house
            return 0;
        }
        else if((m_posx <= 598)&&(m_posx >= 548)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est dans le vaisseau de freezer
            m_posx = 498;
            m_posy = 651;
        }
        else
        {
            ///Dans le cas où le joueur n'est pas dans une pièce
            ///Il ne pourra rentrer que par les portes
            ///Blindage par utilisation des coordonées
            if(m_posy == 1)
            {
                if((m_posx ==648))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy == 51)
            {
                if((m_posx == 648)||(m_posx == 398)|| (m_posx == 198))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy==201)
            {
                if((m_posx == 398))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy==351)
            {
                if((m_posx == 398) || (m_posx==148))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy==401 || m_posy==501)
            {
                if((m_posx == 398))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy==601)
            {
                if((m_posx == 398) || (m_posx==198) || (m_posx==648))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else if(m_posy==651)
            {
                if((m_posx == 648))
                {
                    return 0;
                }
                else
                {
                    m_posx = m_posx - get_depx();
                }
            }
            else
            {
                m_posx = m_posx - get_depx();
            }
        }

    }
    return 1;
}

///Ici, on va suivre le meme principe que pour les deplacements latéraux


int Pion::set_posy(int val)
{
    ///On va tester toutes les coordonnées des limites de la map et des salles
    ///Si le joueur est dans une salle on vérifie s'il y a une porte dans cette direction
    if(val==1) ///vers le haut
    {
        if(m_posy < 51)
        {
            std::cout<<"Le pion ne peut plus aller vers le haut"<<std::endl;
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète vegeta
            m_posx = 598;
            m_posy = 651;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète namek
            return 0;
        }
        else if((m_posx <= 598)&&(m_posx > 548)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète kaio
            return 0;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 301)&&(m_posy >= 201))
        {
            //Si le joueur est dans la salle du Temps
            m_posx = 298;
            m_posy = 151;
        }
        else if((m_posx <= 98)&&(m_posx >= 48)&&(m_posy <= 351)&&(m_posy >= 301))
        {
            //Si le joueur est au spawn chez Bulma
            m_posx = 48;
            m_posy = 251;
        }
        else if((m_posx <= 648)&&(m_posx >= 498)&&(m_posy <= 401)&&(m_posy >= 251))
        {
            //Si le joueur est sur la planète Beerus
            m_posx = 548;
            m_posy = 201;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 501)&&(m_posy >= 401))
        {
            //Si le joueur est sur la Terre sacrée des Kais
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est en enfer
            m_posx = 98;
            m_posy = 551;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est sur la kame house
            m_posx = 298;
            m_posy = 551;
        }
        else if((m_posx <= 598)&&(m_posx >= 548)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est dans le vaisseau de freezer
            m_posx = 548;
            m_posy = 551;
        }
        else
        {
            if(m_posy == 101)
            {
                if((m_posx == 98) || (m_posx == 298) || (m_posx == 548))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy - get_depy();
                }
            }
            else if(m_posy == 351)
            {
                if((m_posx == 248) || (m_posx == 348))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy - get_depy();
                }
            }
            else if(m_posy == 401)
            {
                if((m_posx == 98))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy - get_depy();
                }
            }
            else if(m_posy == 451)
            {
                if((m_posx == 498) || (m_posx == 548) || (m_posx == 648))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy - get_depy();
                }
            }
            else if(m_posy == 551)
            {
                if((m_posx == 248) || (m_posx == 298) || (m_posx == 348))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy - get_depy();
                }
            }
            else
            {
                m_posy = m_posy - get_depy();
            }

        }

    }
    ///On va tester toutes les coordonnées des limites de la map et des salles
    ///Si le joueur est dans une salle on vérifie s'il y a une porte dans cette direction
    else if(val==2) ///vers le bas
    {
        if(m_posy > 601)
        {
            std::cout<<"Le pion ne peut plus aller vers le bas"<<std::endl;
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète vegeta
            m_posx = 148;
            m_posy = 101;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète namek
            m_posx = 348;
            m_posy = 101;
        }
        else if((m_posx <= 598)&&(m_posx > 548)&&(m_posy <= 51)&&(m_posy >= 1))
        {
            //Si le joueur est sur la planète kaio
            m_posx = 598;
            m_posy = 101;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 301)&&(m_posy >= 201))
        {
            //Si le joueur est dans la salle du Temps
            m_posx = 298;
            m_posy = 351;
        }
        else if((m_posx <= 98)&&(m_posx >= 48)&&(m_posy <= 351)&&(m_posy >= 301))
        {
            //Si le joueur est au spawn chez Bulma
            m_posx = 48;
            m_posy = 401;
        }
        else if((m_posx <= 648)&&(m_posx >= 498)&&(m_posy <= 401)&&(m_posy >= 251))
        {
            //Si le joueur est sur la planète Beerus
            m_posx = 598;
            m_posy = 451;
        }
        else if((m_posx <= 348)&&(m_posx >= 248)&&(m_posy <= 501)&&(m_posy >= 401))
        {
            //Si le joueur est sur la Terre sacrée des Kais
            return 0;
        }
        else if((m_posx <= 148)&&(m_posx >= 98)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est en enfer
            m_posx = 648;
            m_posy = 251;
        }
        else if((m_posx <= 348)&&(m_posx >= 298)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est sur la kame house
            return 0;
        }
        else if((m_posx <= 598)&&(m_posx >= 548)&&(m_posy <= 651)&&(m_posy >= 601))
        {
            //Si le joueur est dans le vaisseau de freezer
            return 0;
        }
        else
        {
            if(m_posy == 151)
            {
                if((m_posx == 248) || (m_posx == 348))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy + get_depy();
                }
            }
            else if(m_posy == 201)
            {
                if((m_posx==498) || (m_posx==598) || (m_posx==648))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy + get_depy();
                }
            }
            else if(m_posy == 251)
            {
                if((m_posx==98))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy + get_depy();
                }
            }
            else if(m_posy == 351)
            {
                if((m_posx == 248) || (m_posx == 298) || (m_posx == 348))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy + get_depy();
                }
            }
            else if(m_posy == 551)
            {
                if((m_posx == 148) || (m_posx == 348) || (m_posx == 598))
                {
                    return 0;
                }
                else
                {
                    m_posy = m_posy + get_depy();
                }
            }
            else
            {
                m_posy = m_posy + get_depy();
            }

        }

    }
    return 1;
}


void Pion::set_x(int val)
{
    m_posx = val;
}

void Pion::set_y(int val)
{
    m_posy = val;
}

///On va ici verifier si le joueur est dans une case mystere ou pas
int Pion::casemystere()
{
    ///On compare les positions du pion à celle des cases
    ///Si le pion est sur une case mystere on retourne 1
    if((m_posx==98) && (m_posy==151))
    {
        return 1;
    }
    else if((m_posx==398) && (m_posy==151))
    {
        return 1;
    }
    else if((m_posx==148) && (m_posy==501))
    {
        return 1;
    }
    else if((m_posx==448) && (m_posy==551))
    {
        return 1;
    }
    else if((m_posx==598) && (m_posy==501))
    {
        return 1;
    }
    else if((m_posx==648) && (m_posy==101))
    {
        return 1;
    }
    ///Sinon, on retourne 0
    else
    {
        return 0;
    }
}
