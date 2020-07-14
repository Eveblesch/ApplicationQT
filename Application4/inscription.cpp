#include "ui_inscription.h"
#include "mainwindow.h"

Inscription::Inscription(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Inscription),
    liste(),
    liste_inscription()
{
    ui->setupUi(this);
}

Inscription::~Inscription()
{
    delete ui;
}


void Inscription::affichageChamps()
{
//    clearWidget();
    QLineEdit * saisie;
    saisie=new QLineEdit(QString("Identifiant"));
    saisie->setObjectName("identifiant");
    liste.push_back(saisie);
    saisie=new QLineEdit(QString("Nom"));
    saisie->setObjectName("nom");
    liste.push_back(saisie);
    saisie=new QLineEdit(QString("Prénom"));
    saisie->setObjectName("prenom");
    liste.push_back(saisie);
    saisie=new QLineEdit(QString("Email"));
    saisie->setObjectName("email");
    liste.push_back(saisie);
    saisie=new QLineEdit(QString("idLoc"));
    liste.push_back(saisie);
    saisie->setObjectName("idLoc");
    saisie=new QLineEdit(QString("Mot de passe"));
    liste.push_back(saisie);
    saisie->setObjectName("mdp");


    for(int i=0;i<liste.length();i++)
    {
        ui->gridLayout_inscription->addWidget(liste[i]);

    }

    QPushButton* button_inscription = new QPushButton;
    button_inscription->setObjectName("bouton");
    ui->gridLayout_inscription->addWidget(button_inscription);
    button_inscription->setText("S'inscrire");
    connect(button_inscription,SIGNAL(pressed()),this,SLOT(button_inscription_pressed()));

}


void Inscription::button_inscription_pressed()
{
    for(int i=0;i<liste.length();i++)
    {
        liste_inscription.append(liste[i]->text());
    }

//    this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil(liste_inscription);

    }

//    QString a = liste[1]->text();
//    std::cout << a.toStdString() << std::endl;

//    QLineEdit* a = liste[1]->objectName();
//     std::cout <<ui->gridLayout_inscription->a->text()<< std::endl;


//    QString a = this->ui->identifiant->text();
//    std::cout << liste[1]->toStdString() << std::endl;
//    ui->gridLayout_inscription->

//    QSqlQuery query;
//    query.prepare("INSERT INTO User(nom,prenom,login,mdp,email,idLocalisation) VALUES(:nom, :prenom,:login,:mdp,:email,:idLocalisation)");
//    query.bindValue(":nom", liste_inscription[1]);
//    query.bindValue(":prenom", liste_inscription[2]);
//    query.bindValue(":login", liste_inscription[0]);
//    query.bindValue(":mdp", liste_inscription[5]);
//    query.bindValue(":email", liste_inscription[3]);
//    query.bindValue(":idLocalisation", liste_inscription[4]);
//    query.exec();

}

void Inscription::on_button_retour_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_accueil();
    }
}

