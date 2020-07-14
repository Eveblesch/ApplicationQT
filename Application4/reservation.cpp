#include "ui_reservation.h"
#include "mainwindow.h"

Reservation::Reservation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reservation)
{
    ui->setupUi(this);
}

Reservation::~Reservation()
{
    delete ui;
}


void Reservation::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}


void Reservation::affichage_exemplaire(unsigned int idExemplaire)
{
    QSqlQuery queryidOeuvre;
    queryidOeuvre.prepare("SELECT idOeuvre, disponible FROM Exemplaire WHERE idExemplaire=:idExemplaire");
    queryidOeuvre.bindValue(":idExemplaire", idExemplaire);
    queryidOeuvre.exec();


    while (queryidOeuvre.next())
    {
        QSqlQuery query_infos;
        query_infos.prepare("SELECT * FROM Oeuvre WHERE idOeuvre=:idOeuvre");
        query_infos.bindValue(":idOeuvre", queryidOeuvre.value(0).toString());
        query_infos.exec();

        while (query_infos.next()) {

                QString affichage_titre = query_infos.value(5).toString();
                QLabel *label_titre = new QLabel;
                label_titre->setObjectName("label_gras");
                ui->gridLayout_Reservation->addWidget(label_titre);
                label_titre->setText(affichage_titre);

                QPushButton* bouton_couverture= new QPushButton;
                QPixmap pixmap("https://images-na.ssl-images-amazon.com/images/I/61nZqhftUPL.jpg");
                QIcon ButtonIcon(pixmap);
                bouton_couverture->setIcon(ButtonIcon);
                bouton_couverture->setIconSize(pixmap.rect().size());
                bouton_couverture->setObjectName("couverture");

                ui->gridLayout_Reservation->addWidget(bouton_couverture);
//                connect(button_afficher_bibliotheque,SIGNAL(pressed()),this,SLOT(on_button_afficher_bibliotheque_pressed()));



//                QString affichage_couverture = query_infos.value(8).toString();
//                QLabel *label_couverture = new QLabel;
//                label_couverture->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_couverture);
//                label_couverture->setText(affichage_couverture);

                Auteur *auteur = new Auteur(query_infos.value(1).toInt(), NULL,NULL,NULL);
                auteur->getInfo_auteur();

                QString nom = auteur->getNom();
                QString prenom = auteur->getPrenom();
                QString total = nom + " " + prenom;
                QLabel *label_auteur = new QLabel;
                label_auteur->setObjectName("label_profil");
                ui->gridLayout_Reservation->addWidget(label_auteur);
                label_auteur->setText(total);


                QString affichage_annee = query_infos.value(7).toString();
                QLabel *label_annee = new QLabel;
                label_annee->setObjectName("label_profil");
                ui->gridLayout_Reservation->addWidget(label_annee);
                label_annee->setText(affichage_annee);
        }

    }
}



void Reservation::affichage_reservation()
{
    QLabel *label_res = new QLabel;
    label_res->setObjectName("label_h1");
    label_res->setText("Mes reservations");
    ui->gridLayout_titre->addWidget(label_res);

    QSqlQuery query_unique;
    query_unique.prepare("SELECT COUNT(*) FROM Reservation WHERE idUtilisateur=5");
//    query_unique.bindValue(":myLogin", Qlogin);
    query_unique.exec();

     while (query_unique.next()) {
         std::cout << "count " << query_unique.value(0).toInt() << std::endl;
         if(query_unique.value(0).toInt()==0){
             QLabel *label_msg = new QLabel;
             label_msg->setObjectName("label_profil");
             label_msg->setText("Vous n'avez aucune réservation.");
             ui->gridLayout_titre->addWidget(label_msg);
         }
     }

    QSqlQuery queryidEx;
    queryidEx.prepare("SELECT idExemplaire FROM Reservation WHERE idUtilisateur=5");
    queryidEx.exec();


    while (queryidEx.next())
    {
        affichage_exemplaire(queryidEx.value(0).toInt());
    }
}

void Reservation::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Reservation::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Reservation::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
