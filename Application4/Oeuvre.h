#ifndef OEUVRE_H
#define OEUVRE_H
#include <QString>

class Oeuvre
{
public:
    Oeuvre(int idOeuvre, int idAuteur, int idEditeur, int idType, int idGenre, QString titre, QString ISBN,  int annee,  QString couverture, QString langue);
    int idOeuvre;
    int idAuteur;
    int idEditeur;
    int idType;
    int idGenre;
    QString titre;
    QString ISBN;
    int annee;
    QString couverture;
    QString langue;

    void getinfo_oeuvre();
    int getidOeuvre() const;
    int getidAuteur() const;
    int getidEditeur() const;
    int getidType() const;
    int getidGenre() const;
    QString getTitre() const;
    QString getISBN() const;
    int getAnnee() const;
    QString getCouverture() const;
    QString getLangue() const;
    void create();


};

#endif // OEUVRE_H

