#include "Oeuvre.h"
#include "mainwindow.h"


Oeuvre::Oeuvre(int idOeuvre, int idAuteur, int idEditeur, int idType, int idGenre, QString titre, QString ISBN,  int annee,  QString couverture, QString langue):
    idOeuvre(idOeuvre),
    idAuteur(idAuteur),
    idEditeur(idEditeur),
    idType(idType),
    idGenre(idGenre),
    titre(titre),
    ISBN(ISBN),
    annee(annee),
    couverture(couverture),
    langue(langue)
{}

void Oeuvre::getinfo_oeuvre()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Oeuvre WHERE idOeuvre=:idOeuvre");
    query.bindValue(":idOeuvre", this->getidOeuvre());
    query.exec();

    while (query.next()) {

        this->idOeuvre = query.value(0).toInt();
        this->idAuteur = query.value(1).toInt();
        this->idEditeur = query.value(2).toInt();
        this->idType=query.value(3).toInt();
        this->idGenre=query.value(4).toInt();
        this->titre = query.value(5).toString();
        this->ISBN=query.value(6).toString();
        this->annee=query.value(7).toInt();
        this->couverture=query.value(8).toString();
        this->langue=query.value(9).toString();
    }
}

int Oeuvre::getidOeuvre() const
{
    return idOeuvre;
}

int Oeuvre::getidAuteur() const
{
    return idAuteur;
}

int Oeuvre::getidEditeur() const
{
    return idEditeur;
}

int Oeuvre::getidType() const
{
    return idType;
}

int Oeuvre::getidGenre() const
{
    return idGenre;
}

QString Oeuvre::getTitre() const
{
    return titre;
}

QString Oeuvre::getISBN() const
{
    return ISBN;
}

int Oeuvre::getAnnee() const
{
    return annee;
}

QString Oeuvre::getCouverture() const
{
    return couverture;
}
QString Oeuvre::getLangue() const
{
    return langue;
}



void Oeuvre::create()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Oeuvre(idAuteur, idEditeur, idType, idGenre, titre, ISBN, annee, couverture, langue) VALUES (:idAuteur, :idEditeur, :idType, :idGenre, :titre, :ISBN, :annee, :couverture, :langue)");
    query.bindValue(":idAuteur", this->getidAuteur());
    query.bindValue(":idEditeur", this->getidEditeur());
    query.bindValue(":idType", this->getidType());
    query.bindValue(":idGenre", this->getidGenre());
    query.bindValue(":titre", this->getTitre());
    query.bindValue(":ISBN", this->getISBN());
    query.bindValue(":annee", this->getAnnee());
    query.bindValue(":couverture", this->getCouverture());
    query.bindValue(":langue", this->getLangue());

    query.exec();
}

