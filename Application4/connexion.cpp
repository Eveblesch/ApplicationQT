#include "ui_connexion.h"
#include "mainwindow.h"

Connexion::Connexion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Connexion),
    liste()
{
    ui->setupUi(this);
}

Connexion::~Connexion()
{
    delete ui;
}


void Connexion::button_connexion_pressed()
{
////    this->setHidden(true);
//    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
//    if (mv!= nullptr){
//        mv->display_profil();
//    }
}

void Connexion::on_button_retour_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_accueil();
    }
}



void Connexion::affichageChamps()
{
    QLineEdit * saisie;
    saisie=new QLineEdit(QString("Identifiant"));
    saisie->setObjectName("identifiant");
    liste.push_back(saisie);

    saisie=new QLineEdit(QString("Mot de passe"));
    liste.push_back(saisie);
    saisie->setObjectName("mdp");


    for(int i=0;i<liste.length();i++)
    {
        ui->gridLayout_connexion->addWidget(liste[i]);

    }

    QPushButton* button_connexion = new QPushButton;
    button_connexion->setObjectName("bouton");
    ui->gridLayout_connexion->addWidget(button_connexion);
    button_connexion->setText("Connexion");
//    connect(button_connexion,SIGNAL(pressed()),this,SLOT(on_button_connexion_pressed()));

    QString sortie;
    QCryptographicHash cryptoHashSHA256(QCryptographicHash::Sha256);
    cryptoHashSHA256.addData("mdp");
    sortie = cryptoHashSHA256.result().toHex().data();

    std::cout << sortie.toStdString() <<std::endl;
}
