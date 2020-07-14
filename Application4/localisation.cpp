#include "ui_localisation.h"
#include "mainwindow.h"


Localisation::Localisation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Localisation),
    listeLoc()
{
    ui->setupUi(this);
}

Localisation::~Localisation()
{
    delete ui;
}

void Localisation::affichage_localisation()
{
    QLabel *label_loc = new QLabel;
    label_loc->setObjectName("label_h1");
    label_loc->setText("Localisation");
    ui->gridLayout_titre->addWidget(label_loc);

    QSqlQuery queryUtilisateur;
    queryUtilisateur.prepare("SELECT idUtilisateur FROM User WHERE prenom=:PRENOM");
    queryUtilisateur.bindValue(":PRENOM", "Eve");
    queryUtilisateur.exec();

    QLabel *label_info = new QLabel;
    label_info->setObjectName("label_h3");
    label_info->setText("Liste des villes que vous avez ajoutées");
    ui->gridLayout_localisation->addWidget(label_info);

    while (queryUtilisateur.next()) {

//        std::cout<<queryUtilisateur.value(0).toInt()<<std::endl;

        QSqlQuery queryidLocalisation;
        queryidLocalisation.prepare("SELECT idLocalisation FROM ListeLocalisation WHERE idUtilisateur=:idUtilisateur");
        queryidLocalisation.bindValue(":idUtilisateur", queryUtilisateur.value(0).toInt());
        queryidLocalisation.exec();

        while (queryidLocalisation.next())
        {

            QSqlQuery queryInfosLoc;
            queryInfosLoc.prepare("SELECT codePostal, ville FROM Localisation WHERE idLocalisation=:idLoc");
            queryInfosLoc.bindValue(":idLoc", queryidLocalisation.value(0).toInt());
            queryInfosLoc.exec();
            while (queryInfosLoc.next())
            {
                QLabel *label_localisation = new QLabel;
                label_localisation->setObjectName("label_profil");
                ui->gridLayout_localisation->addWidget(label_localisation);
//                QString s = QString::number(queryidLocalisation.value(0).toInt());
//                QString affichage_nom = query.value(1).toString();
                label_localisation->setText(queryInfosLoc.value(0).toString() + " - " + queryInfosLoc.value(1).toString());
            }


        }

    }

    //PARTIE AJOUT LOCALISATION
    QLabel *label_liste = new QLabel;
    label_liste->setObjectName("label_h2");
    label_liste->setText("Ajouter une localisation");
    ui->gridLayout_ajoutLoc->addWidget(label_liste);

    QComboBox *listeLocalisation = new QComboBox;
    listeLocalisation->addItem("Choix");

    QSqlQuery queryLoc;
    queryLoc.prepare("SELECT codePostal, ville FROM Localisation");
    queryLoc.exec();

    while (queryLoc.next())
    {
        listeLocalisation->addItem(queryLoc.value(0).toString() + " - " + queryLoc.value(1).toString());

    }
    listeLocalisation->setObjectName("ComboLoc");
    ui->gridLayout_ajoutLoc->addWidget(listeLocalisation);
    listeLoc.push_back(listeLocalisation);


    QPushButton* button_ajouter = new QPushButton;
    button_ajouter->setObjectName("bouton_validation");
    ui->gridLayout_ajoutLoc->addWidget(button_ajouter);
    button_ajouter->setText("Ajouter");
    connect(button_ajouter,SIGNAL(pressed()),this,SLOT(ajoutLocalisation()));

}


void Localisation::ajoutLocalisation()
{

    QString res = listeLoc[0]->currentText();
    QString code = res.split(" ").at(0);

    QSqlQuery query_rechercheidLoc;
    query_rechercheidLoc.prepare("SELECT idLocalisation FROM Localisation WHERE codePostal=:code");
    query_rechercheidLoc.bindValue(":code", code);
    query_rechercheidLoc.exec();

    while (query_rechercheidLoc.next())
    {
        QSqlQuery query_count;
        query_count.prepare("SELECT COUNT(*) FROM ListeLocalisation WHERE idUtilisateur=:idUtilisateur AND idLocalisation=:idLocalisation");
        query_count.bindValue(":idUtilisateur", 5);
        query_count.bindValue(":idLocalisation", query_rechercheidLoc.value(0).toInt());
        query_count.exec();
        while (query_count.next()) {
            if(query_count.value(0).toInt()==0)
            {
                QSqlQuery query_ajoutLoc;
                query_ajoutLoc.prepare("INSERT INTO ListeLocalisation(idLocalisation, idUtilisateur) VALUES (:idLocalisation, :idUtilisateur)");
                query_ajoutLoc.bindValue(":idUtilisateur", 5);
                query_ajoutLoc.bindValue(":idLocalisation", query_rechercheidLoc.value(0).toInt());
                query_ajoutLoc.exec();
            }
            std::cout << "count " <<query_count.value(0).toInt()<<std::endl;
        }

    }

    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_localisation();
    }

}

void Localisation::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

//void Localisation::button_localisation_pressed()
//{
//    //this->setHidden(true);
//    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
//    if (mv!= nullptr){
//        mv->display_localisation();
//    }
//}



void Localisation::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Localisation::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Localisation::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
