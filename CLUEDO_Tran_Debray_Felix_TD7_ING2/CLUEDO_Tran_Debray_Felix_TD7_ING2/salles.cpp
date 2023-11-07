#include "header_salles.h"

Salle::Salle(){}
Salle::~Salle(){}
Salle::Salle(std::string _Nom, int _taille)
        :m_Nom(_Nom),m_taille(_taille){}

int Salle::get_taille()const{return m_taille;}
std::string Salle::get_nom()const{return m_Nom;}
