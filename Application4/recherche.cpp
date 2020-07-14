
#include "ui_recherche.h"
#include "mainwindow.h"

Recherche::Recherche(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Recherche),
    liste()
{
    ui->setupUi(this);
}

Recherche::~Recherche()
{
    delete ui;
}

void Recherche::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while((item = layout->takeAt(0)))
    {
        if (item->layout()!=nullptr)
        {
            clearLayout(item->layout());
            delete item->layout();
        }
        if (item->widget()!=nullptr)
        {
           delete item->widget();
        }
        delete item;
    }
}

void Recherche::on_button_recherche_pressed()
{
    clearLayout(ui->gridLayout_recherche);
    rechercher();

}

void Recherche::rechercher()
{

    liste.push_back(ui->lineEditRecherche);
    QString recherche = liste[0]->text();
    std::cout << "Recherche : " <<  recherche.toStdString()<< std::endl;

    int index = ui->comboBoxChoix->currentIndex();
//    std::cout << "index " << index << std::endl;
    int type = index+1;
        std::cout << "Type : " << type << std::endl;

    //RECHERCHE D'OEUVRES
    if(type>=1 && type <=3)
    {

        QSqlQuery queryidOeuvre;
        queryidOeuvre.prepare("SELECT idOeuvre, titre, couverture FROM Oeuvre WHERE titre LIKE :titre1 AND idType=:idType1");
        queryidOeuvre.bindValue(":titre1", recherche);
        queryidOeuvre.bindValue(":idType1", type);
        queryidOeuvre.exec();

        while (queryidOeuvre.next())
        {
            std::cout << "idOeuvre : " <<queryidOeuvre.value(0).toInt() << std::endl;


            QSqlQuery queryidEx;
            queryidEx.prepare("SELECT idExemplaire, idOeuvre, disponible FROM Exemplaire WHERE idOeuvre=:idOeuvre1");
            queryidEx.bindValue(":idOeuvre1", queryidOeuvre.value(0).toInt());
            queryidEx.exec();
            while (queryidEx.next())
            {
                std::cout << "idEx : " <<queryidEx.value(0).toInt() << std::endl;

                affichage_exemplaire(queryidEx.value(0).toInt());

            }
        }
    }

    //RECHERCHE UTILISATEUR
    if(type==4)
    {
//        QSqlQuery query_unique;
//        query_unique.prepare("SELECT COUNT(*) AS nbre FROM User WHERE login LIKE :login1");
//        query_unique.bindValue(':login1',recherche);
//        query_unique.exec();
//        std::cout << "HEYY : " <<  recherche.toStdString()<< std::endl;

//        while (query_unique.next()) {
//            std::cout << "count " << query_unique.value(0).toInt() << std::endl;
//            if(query_unique.value(0).toInt()==0){
//                QLabel *label_msg = new QLabel;
//                label_msg->setObjectName("label_profil");
//                QString msg = "Il y a " + query_unique.value(0).toInt();
//                // + " résultat(s) pour votre recherche '" + recherche.toStdString() + "'."
//                label_msg->setText(msg);
//                ui->gridLayout_recherche->addWidget(label_msg);
//            }
//        }


        QSqlQuery queryidUtilisateur;
        queryidUtilisateur.prepare("SELECT * FROM User WHERE login LIKE :login1");
        queryidUtilisateur.bindValue(":login1", recherche);
        queryidUtilisateur.exec();

        while (queryidUtilisateur.next())
        {
            QString login = queryidUtilisateur.value(3).toString();

            QLabel *label_login = new QLabel;
            label_login->setObjectName("label_profil");
            label_login->setText(login);
            ui->gridLayout_recherche->addWidget(label_login);

        }
    }


    //RECHERCHE AUTEUR
    if(type==5)
    {
        QSqlQuery queryidAuteur;
        queryidAuteur.prepare("SELECT * FROM Auteur WHERE nom LIKE :recherche OR prenom LIKE :recherche");
        queryidAuteur.bindValue(":recherche", recherche);
        queryidAuteur.exec();

        while (queryidAuteur.next())
        {
            QString auteur = queryidAuteur.value(1).toString() + " "+ queryidAuteur.value(2).toString();
            QLabel *label_auteur = new QLabel;
            label_auteur->setObjectName("label_profil");
            label_auteur->setText(auteur);
            ui->gridLayout_recherche->addWidget(label_auteur);

        }
    }

    //RECHERCHE LOCALISATION
    if(type==6)
    {
        QSqlQuery queryidLoc;
        queryidLoc.prepare("SELECT * FROM Localisation WHERE codePostal LIKE :recherche OR ville LIKE :recherche");
        queryidLoc.bindValue(":recherche", recherche);
        queryidLoc.exec();

        while (queryidLoc.next())
        {
            QString localisation = queryidLoc.value(1).toString() + " "+ queryidLoc.value(2).toString();
            QLabel *label_loc = new QLabel;
            label_loc->setObjectName("label_profil");
            label_loc->setText(localisation);
            ui->gridLayout_recherche->addWidget(label_loc);
        }
    }
}

void Recherche::affichage_exemplaire(unsigned int idExemplaire)
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
                ui->gridLayout_recherche->addWidget(label_titre);
                label_titre->setText(affichage_titre);

                QPushButton* bouton_couverture= new QPushButton;
                QPixmap pixmap("https://images-na.ssl-images-amazon.com/images/I/61nZqhftUPL.jpg");
                QIcon ButtonIcon(pixmap);
                bouton_couverture->setIcon(ButtonIcon);
                bouton_couverture->setIconSize(pixmap.rect().size());
                bouton_couverture->setObjectName("couverture");

                ui->gridLayout_recherche->addWidget(bouton_couverture);
//                connect(button_afficher_bibliotheque,SIGNAL(pressed()),this,SLOT(on_button_afficher_bibliotheque_pressed()));



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
                ui->gridLayout_recherche->addWidget(label_auteur);
                label_auteur->setText(total);


                QString affichage_annee = query_infos.value(7).toString();
                QLabel *label_annee = new QLabel;
                label_annee->setObjectName("label_profil");
                ui->gridLayout_recherche->addWidget(label_annee);
                label_annee->setText(affichage_annee);
        }

    }
}

void Recherche::affichage_recherche()
{


}

void Recherche::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}
void Recherche::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Recherche::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
