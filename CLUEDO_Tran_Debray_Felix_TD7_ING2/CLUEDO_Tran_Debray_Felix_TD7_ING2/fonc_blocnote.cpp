#include "header_blocnote.h"

using namespace std;

vector<vector<int>> Bloc_notes::get_bloc()const
{
    //cout<<"getbloc(), normalent 1er:"<<m_bloc_notes[0][0]<<endl;
    return m_bloc_notes;
}

void Bloc_notes::set_bloc(vector<vector<int>> b)
{
    //cout<<"setbloc() normalement 1er : "<<b[0][0]<<endl;
    m_bloc_notes=b;
    //cout<<"verif 1er : "<<m_bloc_notes[0][0]<<endl;
}

void Bloc_notes::affi_bloc(BITMAP* buffer,int nbcartes,int nbjoueurs)
{
    int i=0,j=0;
    BITMAP * indispo;
    indispo=load_bitmap("images/nondispo.bmp",NULL);

    //cout<<"taille de l'image :"<<get_incertain()->w<<endl;
    for(auto elem:get_bloc())
    {
        //cout<<i+1<<"eme carte"<<endl;
        j=0;
        for(auto elem2:elem)
        {
            //cout<<"montre par joueur :"<<j+1<<endl;
            if(elem2==1)
            {
                //cout<<"faux"<<endl;
                draw_sprite(buffer,get_faux(),940+52*j,31*i+40);
            }
            else if(elem2==2)
            {
                //cout<<"vrai"<<endl;
                draw_sprite(buffer,get_vrai(),940+52*j,31*i+40);
            }
            else if(elem2==3)
            {
                //cout<<"incertain"<<endl;
                draw_sprite(buffer,get_incertain(),940+52*j,31*i+40);
            }
            else
            {
                //draw_sprite(buffer,get_incertain(),1040+65*j,34*i+5.5);
                //cout<<"provisoirement l'image pour faux, en vrai ne rien afficher"<<endl;
                //draw_sprite(buffer,get_faux(),1040+65*j,34*i+5.5); ///provisoire ne rien afficher en vrai
            }
            j++;
        }
        i++;
    }
    for(int i=0;i<21;i++)
    {
        for(int j=nbjoueurs;j<6;j++)
        {
            draw_sprite(buffer,indispo,940+52*j,31*i+40);
        }
    }
    destroy_bitmap(indispo);
}
void Bloc_notes::modi_bloc(int nbcartes,int nbjoueurs)
{
    std::vector<std::vector<int>> temp;
     if (mouse_b&1 && get_clic()==0)
    {
        set_clic(1);
        set_posclicx(mouse_x);
        set_posclicy(mouse_y);
        cout<<"clic "<<get_posclicx()<<";"<<get_posclicy()<<endl;
    }
    else if(get_clic()==1 && !mouse_b&1)
    {
        cout<<"modif bloc-notes"<<endl;
        for(int i=0;i<nbcartes;i++)
        {
            for(int j=0;j<nbjoueurs;j++)
            {
                if((mouse_x>940+52*j && mouse_x<970+52*j) && (mouse_y>40+31*i && mouse_y<70+31*i) && (mouse_x==get_posclicx())&&(mouse_y==get_posclicy()))
                {
                    cout<<"modif effectue"<<endl;
                    temp=get_bloc();
                    cout<<"etape 1"<<endl;
                    temp[i][j]++;
                    temp[i][j]=temp[i][j]%4;
                    cout<<"etape 2"<<endl;
                    set_bloc(temp);
                    cout<<"etape 3"<<endl;
                }
            }
        }
        set_clic(0);
    }
}

int Bloc_notes::get_clic()
{
    return m_clic;
}
void Bloc_notes::set_clic(int val)
{
    m_clic=val;
}

BITMAP * Bloc_notes::get_faux()
{
    return m_faux;
}
void Bloc_notes::set_faux(BITMAP * i)
{
    m_faux=i;
}
BITMAP * Bloc_notes::get_vrai()
{
    return m_vrai;
}
void Bloc_notes::set_vrai(BITMAP * i)
{
    m_vrai=i;
}
BITMAP * Bloc_notes::get_incertain()
{
    return m_incertain;
}
void Bloc_notes::set_incertain(BITMAP * i)
{
    m_incertain=i;
}

void Bloc_notes::set_posclicx(int val)
{
    m_posclicx=val;
}

int Bloc_notes::get_posclicx()
{
    return m_posclicx;
}

void Bloc_notes::set_posclicy(int val)
{
    m_posclicy=val;
}

int Bloc_notes::get_posclicy()
{
    return m_posclicy;
}
