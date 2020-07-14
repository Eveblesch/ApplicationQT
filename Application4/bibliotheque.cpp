#include "ui_bibliotheque.h"
#include "mainwindow.h"
#include <chrono>
#include <thread>

Bibliotheque::Bibliotheque(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Bibliotheque)
{
    ui->setupUi(this);
}

Bibliotheque::~Bibliotheque()
{
    delete ui;
}


void Bibliotheque::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}


void Bibliotheque::getImage(QNetworkReply* reply)
{
    QLabel *label_image = new QLabel;
    label_image->setGeometry(0, 0, 300, 100);
    int l = label_image->width();
    int h = label_image->height();

    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    label_image->setPixmap(pixmap.scaled(l,h,Qt::KeepAspectRatio));
    ui->gridLayout_affichageOeuvre->addWidget(label_image);

}

void Bibliotheque::affichage_exemplaire(unsigned int idExemplaire)
{
//    std::cout << "idEx "<<idExemplaire<<std::endl;

    QSqlQuery queryidOeuvre;
    queryidOeuvre.prepare("SELECT idOeuvre, disponible FROM Exemplaire WHERE idExemplaire=:idExemplaire");
    queryidOeuvre.bindValue(":idExemplaire", idExemplaire);
    queryidOeuvre.exec();

//    std::cout << " Size "<<queryidOeuvre.size() <<std::endl;

//    int cmt = 0;
//    while (queryidOeuvre.next())
//    {
//        if(queryidOeuvre.size()==1)
//        {
//            cmt++;
//        }
//    }

//    for(int i=0;i<cmt;i++)
//    {
//        std::cout << "heyyyyyyy "<<queryidOeuvre[0].value(3).toInt()<< std::endl;
//    }

    while (queryidOeuvre.next())
    {
        QNetworkAccessManager* manager = new QNetworkAccessManager();
        connect(manager, &QNetworkAccessManager::finished, this,&Bibliotheque::getImage);
        QNetworkRequest request;
        request.setUrl(QUrl("https://images-na.ssl-images-amazon.com/images/I/61nZqhftUPL.jpg"));
        manager->get(request);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

//        std::cout << queryidOeuvre.value(0).toInt() << std::endl;

        QSqlQuery query_infos;
        query_infos.prepare("SELECT * FROM Oeuvre WHERE idOeuvre=:idOeuvre");
        query_infos.bindValue(":idOeuvre", queryidOeuvre.value(0).toString());
        query_infos.exec();


        while (query_infos.next()) {
//            std::cout<<query_infos.value(0)<<std::endl;
//            std::cout << query_infos.value(5).toString() << std::endl;

//                QString affichage_titre = query_infos.value(5).toString();
//                QLabel *label_titre = new QLabel;
//                label_titre->setObjectName("label_gras");
//                ui->gridLayout_affichageOeuvre->addWidget(label_titre);
//                label_titre->setText(affichage_titre);

//                connect(netReply, SIGNAL(finished()), &loop, SLOT(quit()));




//                label_couverture->setPixmap(pixmap);
//                label_couverture->resize(pixmap.size());
//                ui->gridLayout_affichageOeuvre->addWidget(label_couverture);

//                QPushButton* bouton_couverture= new QPushButton;
//                QIcon ButtonIcon(pixmap);
//                bouton_couverture->setIcon(ButtonIcon);
//                bouton_couverture->setIconSize(pixmap.rect().size());
//                bouton_couverture->setObjectName("couverture");

//                ui->gridLayout_affichageOeuvre->addWidget(bouton_couverture);
//                connect(button_afficher_bibliotheque,SIGNAL(pressed()),this,SLOT(on_button_afficher_bibliotheque_pressed()));



//                QString affichage_couverture = query_infos.value(8).toString();
//                QLabel *label_couverture = new QLabel;
//                label_couverture->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_couverture);
//                label_couverture->setText(affichage_couverture);

//                Auteur *auteur = new Auteur(query_infos.value(1).toInt(),"","",-1);
//                auteur->getInfo_auteur();

//                int type = query_infos.value(3).toInt();
//                QLabel *label_type = new QLabel;
//                if(type==1)
//                    label_type->setText("Livre");
//                else if(type==2)
//                    label_type->setText("CD");
//                else
//                     label_type->setText("DVD");

//                label_type->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_type);

//                QString nom = auteur->getNom();
//                QString prenom = auteur->getPrenom();
//                QString total = nom + " " + prenom;
////                std::cout << "nom"<< nom.toStdString() <<std::endl;
////                std::cout <<"id "<<auteur->getidType()<<std::endl;
//                QLabel *label_auteur = new QLabel;
//                label_auteur->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_auteur);
//                label_auteur->setText(total);


//                QString affichage_annee = query_infos.value(7).toString();
//                QLabel *label_annee = new QLabel;
//                label_annee->setObjectName("label_profil");
//                ui->gridLayout_affichageOeuvre->addWidget(label_annee);
//                label_annee->setText(affichage_annee);
        }

    }
}



void Bibliotheque::affichage_bibliotheque()
{

    QLabel *label = new QLabel;
    label->setObjectName("label_h1");
    label->setText("Ma bibliothèque");
    ui->gridLayout_titre->addWidget(label);

    QSqlQuery queryidOeuvre;
    queryidOeuvre.prepare("SELECT idOeuvre, disponible FROM Exemplaire WHERE idUtilisateur=:idUtilisateur");
    queryidOeuvre.bindValue(":idUtilisateur", 5);
    queryidOeuvre.exec();


    while (queryidOeuvre.next())
    {
        affichage_exemplaire(queryidOeuvre.value(0).toInt());
    }
}



void Bibliotheque::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Bibliotheque::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}
void Bibliotheque::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}

