#ifndef HEADER_BLOCNOTE_H_INCLUDED
#define HEADER_BLOCNOTE_H_INCLUDED

#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <allegro.h>


class Bloc_notes
{
    private:
                                                    ///un vecteur où chaque case correspond à une carte et en fonction du chiffre dans la case
        std::vector<std::vector<int>> m_bloc_notes; ///1,2 ou 3 on affiche si le joueur pense que cette carte est bonne ou fausse ou s'il sait pas
                                                    ///et ducoup on change le chiffre, en cliquant sur la carte, ou avec les touches
        BITMAP* m_vrai;
        BITMAP* m_faux;
        BITMAP* m_incertain;
        std::vector<int> prbl_bloc;
        int m_clic=0;
        int m_posclicx;
        int m_posclicy;

    public:
        std::vector<std::vector<int>> get_bloc()const;
        void set_bloc(std::vector<std::vector<int>> b);
        int get_clic();
        void set_clic(int val);
        void affi_bloc(BITMAP* buffer,int nbcartes,int nbjoueurs);
        void modi_bloc(int nbcartes,int nbjoueurs);
        BITMAP * get_faux();
        void set_faux(BITMAP * i);
        BITMAP * get_vrai();
        void set_vrai(BITMAP * i);
        BITMAP * get_incertain();
        void set_incertain(BITMAP * i);
        void set_posclicx(int val);
        int get_posclicx();
        void set_posclicy(int val);
        int get_posclicy();
};


#endif // HEADER_BLOCNOTE_H_INCLUDED
