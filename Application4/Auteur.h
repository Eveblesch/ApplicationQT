#ifndef AUTEUR_H
#define AUTEUR_H
#include <QString>

class Auteur
{
public:
    Auteur(int idAuteur, QString nom, QString prenom, int idType);
    int idAuteur;
    QString nom;
    QString prenom;
    int idType;

    int getidAuteur() const;
    QString getNom() const;
    QString getPrenom() const;
    int getidType() const;

    void create();
    void getInfo_auteur();
};

#endif // AUTEUR_H
