#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    liste_champ()
{
//    MainWindow::showMaximized();
    ui->setupUi(this);

    accueil = new Accueil;
    setCentralWidget(accueil);

    profil = new Profil(this);
    profil->setHidden(true);
    bdd();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::display_accueil(){
    accueil = new Accueil;
    setCentralWidget(accueil);
}

void MainWindow::display_connexion(){
    connexion = new Connexion;
    setCentralWidget(connexion);
    connexion->affichageChamps();
}

void MainWindow::display_inscription(){
    inscription = new Inscription;
    setCentralWidget(inscription);
    inscription->affichageChamps();
}

void MainWindow::display_localisation(){
    localisation = new Localisation;
    setCentralWidget(localisation);
    localisation->affichage_localisation();
}


void MainWindow::display_profil(QStringList champ){
    for(int i=0;i<champ.length();i++)
    {
        liste_champ.append(champ[i]);
//        std::cout <<liste_champ[i].toStdString()<<std::endl;
    }

    profil = new Profil;
    profil->listeProfil=liste_champ;
    setCentralWidget(profil);
    profil->affichage_infos();
}

void MainWindow::display_profil2(){

    profil = new Profil;
    profil->listeProfil=liste_champ;
    setCentralWidget(profil);
    profil->affichage_infos();
}


void MainWindow::display_modif_infos(){
    modif_infos = new Modif_infos;
    setCentralWidget(modif_infos);
    modif_infos->affichageChamps();
}


void MainWindow::display_bibliotheque()
{
    bibliotheque = new Bibliotheque;
    setCentralWidget(bibliotheque);
    bibliotheque->affichage_bibliotheque();
}

void MainWindow::display_emprunt()
{
    emprunt = new Emprunt;
    setCentralWidget(emprunt);
    emprunt->affichage_emprunt();
}

void MainWindow::display_reservation()
{
    reservation = new Reservation;
    setCentralWidget(reservation);
    reservation->affichage_reservation();
}

void MainWindow::display_recherche()
{
    recherche = new Recherche;
    setCentralWidget(recherche);
    recherche->affichage_recherche();
}

void MainWindow::display_demande_emprunt()
{
    demande_emprunt = new Demande_emprunt;
    setCentralWidget(demande_emprunt);
    demande_emprunt->affichage_demande_emprunt();
}

void MainWindow::display_choix_type()
{
    choix_type = new Choix_type;
    setCentralWidget(choix_type);
    choix_type->affichage_choix_type();
}

void MainWindow::display_ajout_oeuvre_existante()
{
    oeuvre_existante = new Ajout_oeuvre_existante;
    setCentralWidget(oeuvre_existante);
    oeuvre_existante->affichage_ajout_oeuvre_existante();
}

void MainWindow::display_ajout_nouvelle_oeuvre()
{
    nouvelle_oeuvre = new Ajout_nouvelle_oeuvre;
    setCentralWidget(nouvelle_oeuvre);
    nouvelle_oeuvre->affichage_nouvelle_oeuvre();
}


void MainWindow::bdd()
{

    QSqlDatabase maBase;
    maBase = QSqlDatabase::addDatabase("QMYSQL");
    maBase.setHostName("osr-mysql.unistra.fr");
    maBase.setDatabaseName("eblesch"); // Nom de la base
    maBase.setUserName("eblesch"); // Nom utilisateur
    maBase.setPassword("chouette");

    if(maBase.open())
    {
      std::cout << "BDD Fonctionne" << std::endl;
    }
    else
    {
      std::cout << "BDD Fonctionne PAS" << std::endl;

    }
}




