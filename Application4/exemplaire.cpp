#include "Exemplaire.h"
#include "mainwindow.h"

Exemplaire::Exemplaire(unsigned int idExemplaire, unsigned int idUtilisateur, unsigned int idOeuvre,bool disponible, unsigned int dureeReservation):
    idExemplaire(idExemplaire),
    idUtilisateur(idUtilisateur),
    idOeuvre(idOeuvre),
    disponible(disponible),
    dureeReservation(dureeReservation)

{}

void Exemplaire::getinfo_exemplaire()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Exemplaire WHERE idExemplaire=:idExemplaire");
    query.bindValue(":idExemplaire", this->getidExemplaire());
    query.exec();

    while (query.next()) {

        this->idExemplaire = query.value(0).toInt();
        this->idUtilisateur = query.value(1).toInt();
        this->idOeuvre = query.value(2).toInt();
        this->disponible=query.value(3).toInt();
        this->dureeReservation=query.value(4).toInt();

    }
}
int Exemplaire::getidExemplaire() const
{
    return idExemplaire;
}

int Exemplaire::getidUtilisateur() const
{
    return idUtilisateur;
}


int Exemplaire::getidOeuvre() const
{
    return idOeuvre;
}

int Exemplaire::getDisponible() const
{
    return disponible;
}

int Exemplaire::getDureeReservation() const
{
    return dureeReservation;
}



void Exemplaire::create()
{
    std::cout << "crée" <<std::endl;
    QSqlQuery query;
    query.prepare("INSERT INTO Exemplaire(idUtilisateur, idOeuvre, disponible,DureeReservation) VALUES (:idUtilisateur, :idOeuvre, :disponible,:DureeReservation)");
    query.bindValue(":idUtilisateur", this->getidUtilisateur());
    query.bindValue(":idOeuvre", this->getidOeuvre());
    query.bindValue(":disponible", this->getDisponible());
    query.bindValue(":DureeReservation", this->getDureeReservation());

    query.exec();
}
