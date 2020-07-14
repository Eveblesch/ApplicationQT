#include "ui_emprunt.h"
#include "mainwindow.h"

Emprunt::Emprunt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Emprunt)
{
    ui->setupUi(this);
}

Emprunt::~Emprunt()
{
    delete ui;
}

void Emprunt::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Emprunt::getImage(QNetworkReply* reply)
{
    QLabel *label_image = new QLabel;
    label_image->setGeometry(0, 0, 400, 400);
    int l = label_image->width();
    int h = label_image->height();

    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    label_image->setPixmap(pixmap.scaled(l,h,Qt::KeepAspectRatio));
    ui->gridLayout_emprunt->addWidget(label_image);

}


void Emprunt::affichage_exemplaire(unsigned int idExemplaire)
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
                ui->gridLayout_emprunt->addWidget(label_titre);
                label_titre->setText(affichage_titre);

                QPushButton* bouton_couverture= new QPushButton;
                QPixmap pixmap("https://images-na.ssl-images-amazon.com/images/I/61nZqhftUPL.jpg");
                QIcon ButtonIcon(pixmap);
                bouton_couverture->setIcon(ButtonIcon);
                bouton_couverture->setIconSize(pixmap.rect().size());
                bouton_couverture->setObjectName("couverture");
                ui->gridLayout_emprunt->addWidget(bouton_couverture);
//                connect(button_afficher_bibliotheque,SIGNAL(pressed()),this,SLOT(on_button_afficher_bibliotheque_pressed()));


//                QNetworkAccessManager* manager = new QNetworkAccessManager();
//                connect(manager, &QNetworkAccessManager::finished, this,&Emprunt::getImage);
//                QNetworkRequest request;
//                request.setUrl(QUrl("https://images-na.ssl-images-amazon.com/images/I/61nZqhftUPL.jpg"));
//                manager->get(request);




//                QString affichage_couverture = query_infos.value(8).toString();
//                QLabel *label_couverture = new QLabel;
//                label_couverture->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_couverture);
//                label_couverture->setText(affichage_couverture);

                Auteur *auteur = new Auteur(query_infos.value(1).toInt(), "","",-1);
                auteur->getInfo_auteur();

                QString nom = auteur->getNom();
                QString prenom = auteur->getPrenom();
                QString total = nom + " " + prenom;
                QLabel *label_auteur = new QLabel;
                label_auteur->setObjectName("label_profil");
                ui->gridLayout_emprunt->addWidget(label_auteur);
                label_auteur->setText(total);


                QString affichage_annee = query_infos.value(7).toString();
                QLabel *label_annee = new QLabel;
                label_annee->setObjectName("label_profil");
                ui->gridLayout_emprunt->addWidget(label_annee);
                label_annee->setText(affichage_annee);
        }

    }
}



void Emprunt::affichage_emprunt()
{
    QLabel *label_emprunt = new QLabel;
    label_emprunt->setObjectName("label_h1");
    label_emprunt->setText("Mes emprunts");
    ui->gridLayout_titre->addWidget(label_emprunt);

    QSqlQuery queryidEx;
    queryidEx.prepare("SELECT idExemplaire FROM Emprunt WHERE accepte=1");
    queryidEx.exec();


    while (queryidEx.next())
    {
        affichage_exemplaire(queryidEx.value(0).toInt());
    }
}



void Emprunt::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Emprunt::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Emprunt::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}

