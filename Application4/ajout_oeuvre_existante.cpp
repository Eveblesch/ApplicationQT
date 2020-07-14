#include "ui_ajout_oeuvre_existante.h"
#include "mainwindow.h"

Ajout_oeuvre_existante::Ajout_oeuvre_existante(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ajout_oeuvre_existante),
    liste()
{
    ui->setupUi(this);
}

Ajout_oeuvre_existante::~Ajout_oeuvre_existante()
{
    delete ui;
}



void Ajout_oeuvre_existante::affichage_ajout_oeuvre_existante()
{

    QLabel *label_liste = new QLabel;
    label_liste->setObjectName("label_h2");
    label_liste->setText("Regarder si l'élément existe déjà");
    ui->gridLayout_element_existant->addWidget(label_liste);

    QComboBox *listeOeuvre = new QComboBox;
    listeOeuvre->addItem("Chercher");

    QSqlQuery queryOeuvre;
    queryOeuvre.prepare("SELECT * FROM Oeuvre WHERE idType=1");
    queryOeuvre.exec();

    while (queryOeuvre.next())
    {

          listeOeuvre->addItem(queryOeuvre.value(5).toString());

//        QSqlQuery queryAuteur;
//        queryAuteur.prepare("SELECT nom, prenom FROM Auteur WHERE idAuteur=:idAuteur");
//        queryAuteur.bindValue(":idAuteur", queryOeuvre.value(0).toInt());
//        queryAuteur.exec();

//        while (queryAuteur.next())
//        {
//            listeOeuvre->addItem(queryOeuvre.value(5).toString() + " - " + queryAuteur.value(1).toString() + " " + queryAuteur.value(2).toString());

//        }

    }
    liste.push_back(listeOeuvre);
    ui->gridLayout_element_existant->addWidget(listeOeuvre);


    QPushButton* button_ajouter = new QPushButton;
    button_ajouter->setObjectName("bouton_profil");
    ui->gridLayout_element_existant->addWidget(button_ajouter);
    button_ajouter->setText("Ajouter");
    connect(button_ajouter,SIGNAL(pressed()),this,SLOT(ajouterPressed()));



    //SUITE
    QLabel *label_suite = new QLabel;
    label_suite->setObjectName("label_h3");
    label_suite->setText("L'élément n'existe pas ? Ajoutez le");
    ui->gridLayout_element_existant->addWidget(label_suite);

    QPushButton* button_ajouter2 = new QPushButton;
    button_ajouter2->setObjectName("bouton_profil");
    ui->gridLayout_element_existant->addWidget(button_ajouter2);
    button_ajouter2->setText("Ajouter un nouvel élément");
    connect(button_ajouter2,SIGNAL(pressed()),this,SLOT(buttonSuite_pressed()));


}
void Ajout_oeuvre_existante::ajouterPressed()
{
    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();


    QString res = liste[0]->currentText();
    QString titre = res.split("-").at(0);

    QSqlQuery query_rechercheidOeuvre;
    query_rechercheidOeuvre.prepare("SELECT idOeuvre FROM Oeuvre WHERE titre LIKE :titre");
    query_rechercheidOeuvre.bindValue(":titre", titre);
    query_rechercheidOeuvre.exec();

    while (query_rechercheidOeuvre.next())
    {

        Exemplaire *exemplaire = new Exemplaire(-1,user->getidUtilisateur(),query_rechercheidOeuvre.value(0).toInt(),1,21);
        exemplaire->create();

    }

    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_bibliotheque();
    }

}
void Ajout_oeuvre_existante::buttonSuite_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_ajout_nouvelle_oeuvre();
    }
}

void Ajout_oeuvre_existante::on_button_retour_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}


void Ajout_oeuvre_existante::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Ajout_oeuvre_existante::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Ajout_oeuvre_existante::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
