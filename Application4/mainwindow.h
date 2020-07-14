#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QTextEdit>

#include "Accueil.h"
#include "Connexion.h"
#include "Inscription.h"
#include "Profil.h"
#include "Modif_infos.h"
#include "Utilisateur.h"
#include "Oeuvre.h"
#include "Exemplaire.h"
#include "Auteur.h"
#include "Localisation.h"
#include "Bibliotheque.h"
#include "Emprunt.h"
#include "Reservation.h"
#include "Recherche.h"
#include "Demande_emprunt.h"
#include "Choix_type.h"
#include "Ajout_oeuvre_existante.h"
#include "Ajout_nouvelle_oeuvre.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void display_accueil();
    void display_profil(QStringList champ);
    void display_inscription();
    void display_connexion();
    void display_localisation();
    void display_modif_infos();
    void display_bibliotheque();
    void display_profil2();
    void display_emprunt();
    void display_reservation();
    void display_recherche();
    void display_demande_emprunt();
    void display_choix_type();
    void display_ajout_oeuvre_existante();
    void display_ajout_nouvelle_oeuvre();





private slots:
    void bdd();


private:
    Ui::MainWindow *ui;

    Accueil *accueil;
    Connexion *connexion;
    Inscription *inscription;
    Profil *profil;
    QString identifiant;
    QStringList liste_champ;
    Localisation *localisation;
    Modif_infos *modif_infos;
    Bibliotheque *bibliotheque;
    Emprunt *emprunt;
    Reservation * reservation;
    Recherche * recherche;
    Demande_emprunt * demande_emprunt;
    Choix_type *choix_type;
    Ajout_oeuvre_existante * oeuvre_existante;
    Ajout_nouvelle_oeuvre * nouvelle_oeuvre;
};

#endif // MAINWINDOW_H
