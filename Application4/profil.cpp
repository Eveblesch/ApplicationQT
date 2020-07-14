#include "ui_profil.h"
#include "mainwindow.h"

Profil::Profil(QWidget *parent) :
    QWidget(parent),
    listeProfil(),
    ui(new Ui::Profil)
{
    ui->setupUi(this);
}

Profil::~Profil()
{
    delete ui;
}

void Profil::affichage_infos()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE prenom=:PRENOM");
    query.bindValue(":PRENOM", "Eve");
    query.exec();

    while (query.next()) {
        QString affichage_login = query.value(3).toString();
        QLabel *label_login = new QLabel;
        label_login->setObjectName("label_profil");
        ui->gridLayout_infos->addWidget(label_login);
        label_login->setText("Login : "+affichage_login);
//        std::cout << pageName.toStdString() << std::endl;

        QString affichage_nom = query.value(1).toString();
        QLabel *label_nom = new QLabel;
        label_nom->setObjectName("label_profil");
        ui->gridLayout_infos->addWidget(label_nom);
        label_nom->setText("Nom : " + affichage_nom);

        QString affichage_prenom = query.value(2).toString();
        QLabel *label_prenom = new QLabel;
        label_prenom->setObjectName("label_profil");
        ui->gridLayout_infos->addWidget(label_prenom);
        label_prenom->setText("Prénom : " + affichage_prenom);


        QString affichage_email = query.value(5).toString();
        QLabel *label_email = new QLabel;
        label_email->setObjectName("label_profil");
        ui->gridLayout_infos->addWidget(label_email);
        label_email->setText("Email : " + affichage_email);


        QSqlQuery queryInfosLoc;
        queryInfosLoc.prepare("SELECT codePostal, ville FROM Localisation WHERE idLocalisation=:idLoc");
        queryInfosLoc.bindValue(":idLoc", query.value(6).toString());
        queryInfosLoc.exec();
        while (queryInfosLoc.next())
        {
            QLabel *label_idLoc = new QLabel;
            label_idLoc->setObjectName("label_profil");
            ui->gridLayout_infos->addWidget(label_idLoc);
            label_idLoc->setText("Localisation : " +queryInfosLoc.value(0).toString() + " - " + queryInfosLoc.value(1).toString());
        }


    }

    QPushButton* button_localisation = new QPushButton;
    button_localisation->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(button_localisation);
    button_localisation->setText("Localisation");
    connect(button_localisation,SIGNAL(pressed()),this,SLOT(button_localisation_pressed()));

    QPushButton* buttonModifierInfo = new QPushButton;
    buttonModifierInfo->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(buttonModifierInfo);
    buttonModifierInfo->setText("Modifier mes informations");
    connect(buttonModifierInfo,SIGNAL(pressed()),this,SLOT(buttonModifInfos_pressed()));


    QPushButton* button_afficher_bibliotheque = new QPushButton;
    button_afficher_bibliotheque->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(button_afficher_bibliotheque);
    button_afficher_bibliotheque->setText("Afficher ma bibliothèque");
    connect(button_afficher_bibliotheque,SIGNAL(pressed()),this,SLOT(button_afficher_bibliotheque_pressed()));

    QPushButton* button_emprunts = new QPushButton;
    button_emprunts->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(button_emprunts);
    button_emprunts->setText("Mes emprunts");
    connect(button_emprunts,SIGNAL(pressed()),this,SLOT(button_emprunt_pressed()));

    QPushButton* button_reservations = new QPushButton;
    button_reservations->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(button_reservations);
    button_reservations->setText("Mes réservations");
    connect(button_reservations,SIGNAL(pressed()),this,SLOT(button_reservation_pressed()));


    QPushButton* button_demande_emprunt = new QPushButton;
    button_demande_emprunt->setObjectName("bouton_profil");
    ui->gridLayout_element->addWidget(button_demande_emprunt);
    button_demande_emprunt->setText("Demandes emprunts");
    connect(button_demande_emprunt,SIGNAL(pressed()),this,SLOT(buttonDemandeEmprunt_pressed()));


}

void Profil::button_localisation_pressed()
{
       //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_localisation();
    }
}

void Profil::button_afficher_bibliotheque_pressed()
{
    //this->setHidden(true);
     MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
     if (mv!= nullptr){
         mv->display_bibliotheque();
     }
}

void Profil::buttonModifInfos_pressed()
{
    //this->setHidden(true);
     MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
     if (mv!= nullptr){
         mv->display_modif_infos();
     }
}

void Profil::buttonDemandeEmprunt_pressed()
{
    //this->setHidden(true);
     MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
     if (mv!= nullptr){
         mv->display_demande_emprunt();
     }
}

void Profil::button_emprunt_pressed()
{
    //this->setHidden(true);
     MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
     if (mv!= nullptr){
         mv->display_emprunt();
     }
}

void Profil::button_reservation_pressed()
{
    //this->setHidden(true);
     MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
     if (mv!= nullptr){
         mv->display_reservation();
     }
}

void Profil::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}

void Profil::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Profil::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}
