#include "ui_demande_emprunt.h"
#include "mainwindow.h"

Demande_emprunt::Demande_emprunt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demande_emprunt)
{
    ui->setupUi(this);
}

Demande_emprunt::~Demande_emprunt()
{
    delete ui;
}



void Demande_emprunt::affichage_exemplaire(unsigned int idExemplaire)
{
    std::cout << "ok"<< std::endl;

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
                ui->gridLayout_demandeEmprunt->addWidget(label_titre);
                label_titre->setText(affichage_titre);

                Auteur *auteur = new Auteur(query_infos.value(1).toInt(),"","",-1);
                auteur->getInfo_auteur();

                int type = query_infos.value(3).toInt();
                QLabel *label_type = new QLabel;
                if(type==1)
                    label_type->setText("Livre");
                else if(type==2)
                    label_type->setText("CD");
                else
                     label_type->setText("DVD");

                label_type->setObjectName("label_profil");
                ui->gridLayout_demandeEmprunt->addWidget(label_type);

                QString nom = auteur->getNom();
                QString prenom = auteur->getPrenom();
                QString total = nom + " " + prenom;
                QLabel *label_auteur = new QLabel;
                label_auteur->setObjectName("label_profil");
                ui->gridLayout_demandeEmprunt->addWidget(label_auteur);
                label_auteur->setText(total);


                QString affichage_annee = query_infos.value(7).toString();
                QLabel *label_annee = new QLabel;
                label_annee->setObjectName("label_profil");
                ui->gridLayout_demandeEmprunt->addWidget(label_annee);
                label_annee->setText(affichage_annee);
        }

    }
}
void Demande_emprunt::affichage_demande_emprunt()
{
    //TOP
    QLabel *label_titre = new QLabel;
    label_titre->setObjectName("label_h2");
    label_titre->setText("Demande(s) d'emprunt par les utilisateurs");
    ui->gridLayout_demandeEmprunt->addWidget(label_titre);

    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();
    std::cout << "loc2 " << user->getidLoc()<<std::endl;


    QSqlQuery queryidEx;
    queryidEx.prepare("SELECT idExemplaire, idEmprunt, idUtilisateur FROM Emprunt WHERE accepte=0");
    queryidEx.exec();

    while (queryidEx.next())
    {
        std::cout << "idEx " << queryidEx.value(0).toInt() << std::endl;
        Exemplaire *exemplaire = new Exemplaire(queryidEx.value(0).toInt(), -1,-1,-1,-1);
        exemplaire->create();

        std::cout << "1 " << exemplaire->getidUtilisateur()<<std::endl;
        std::cout << "2 " << user->getidUtilisateur()<<std::endl;
        std::cout << "loc " << user->getidLoc()<<std::endl;

        if(exemplaire->getidUtilisateur()==user->getidUtilisateur())
        {
            std::cout << "yeees" << std::endl;

            Oeuvre *oeuvre = new Oeuvre(exemplaire->getidOeuvre(),-1,-1,-1,-1,"","",-1,"","");
            oeuvre->getinfo_oeuvre();

            Utilisateur *emprunteur = new Utilisateur(queryidEx.value(2).toInt(),"","","","","",-1);
            emprunteur->getinfo_utilisateur();

            affichage_exemplaire(queryidEx.value(0).toInt());
        }
    }


    //BOTTOM
    QLabel *label_titre2 = new QLabel;
    label_titre2->setObjectName("label_h2");
    label_titre2->setText("Mes demandes d'emprunt");
    ui->gridLayout_accepteEmprunt->addWidget(label_titre2);


}
void Demande_emprunt::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}


void Demande_emprunt::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Demande_emprunt::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Demande_emprunt::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
