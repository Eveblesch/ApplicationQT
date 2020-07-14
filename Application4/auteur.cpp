#include "Auteur.h"
#include "mainwindow.h"


Auteur::Auteur(int idAuteur, QString nom, QString prenom, int idType):
    idAuteur(idAuteur),
    nom(nom),
    prenom(prenom),
    idType(idType)
{}

void Auteur::getInfo_auteur()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Auteur WHERE idAuteur=:idAuteur OR (nom=:nom AND prenom=:prenom)");
    query.bindValue(":idAuteur", this->getidAuteur());
    query.bindValue(":nom", this->getNom());
    query.bindValue(":prenom", this->getPrenom());
    query.exec();

    while (query.next()) {

        this->idAuteur =query.value(0).toInt();
        this->nom = query.value(1).toString();
        this->prenom=query.value(2).toString();
        this->idType=query.value(3).toInt();
    }
}

int Auteur::getidAuteur() const
{
    return idAuteur;
}
QString Auteur::getNom() const
{
    return nom;
}

QString Auteur::getPrenom() const
{
    return prenom;
}

int Auteur::getidType() const
{
    return idType;
}

void Auteur::create()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Auteur(nom,prenom,idType) VALUES (:nom,:prenom, :idType");
    query.bindValue(":nom", this->getNom());
    query.bindValue(":prenom", this->getPrenom());
    query.bindValue(":idType", this->getidType());
    query.exec();
}
