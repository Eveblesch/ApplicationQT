#include "ui_modif_infos.h"
#include "mainwindow.h"

Modif_infos::Modif_infos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Modif_infos),
    liste()
{
    ui->setupUi(this);
}

Modif_infos::~Modif_infos()
{
    delete ui;
}


void Modif_infos::affichageChamps()
{
    QLabel *label_titre = new QLabel;
    label_titre->setObjectName("label_h1");
    label_titre->setText("Modifications");
    ui->gridLayout_titre->addWidget(label_titre);

    //Login
    QLabel *label_login = new QLabel;
    label_login->setText("Changement du login");
    label_login->setObjectName("label_h3");
    ui->gridLayout_5->addWidget(label_login);


    QLineEdit * login;
    login=new QLineEdit(QString("Nouveau login"));
    login->setObjectName("chg_login");
    ui->gridLayout_5->addWidget(login);
    liste.push_back(login);

    QPushButton* button_login= new QPushButton;
    ui->gridLayout_5->addWidget(button_login);
    button_login->setText("Changer");
    button_login->setObjectName("bouton_profil");
    connect(button_login,SIGNAL(pressed()),this,SLOT(login_pressed()));

    //EMAIL
    QLabel *label_email = new QLabel;
    label_email->setText("Changement de l'adresse email");
    label_email->setObjectName("label_h3");
    ui->gridLayout_5->addWidget(label_email);

    QLineEdit * email;
    email=new QLineEdit(QString("Nouvelle adresse email"));
    email->setObjectName("chg_email");
    ui->gridLayout_5->addWidget(email);
    liste.push_back(email);

    QPushButton* button_email= new QPushButton;
    ui->gridLayout_5->addWidget(button_email);
    button_email->setText("Changer");
    button_email->setObjectName("bouton_profil");

    connect(button_email,SIGNAL(pressed()),this,SLOT(email_pressed()));


    //MDP
    QLabel *label_mdp = new QLabel;
    label_mdp->setText("Changement du mot de passe");
    label_mdp->setObjectName("label_h3");

    ui->gridLayout_5->addWidget(label_mdp);

    QLineEdit * mdp1;
    mdp1=new QLineEdit(QString("Ancien mot de passe"));
    mdp1->setObjectName("chg_mdp1");
    ui->gridLayout_5->addWidget(mdp1);
    liste.push_back(mdp1);

    QLineEdit * mdp2;
    mdp2=new QLineEdit(QString("Nouveau mot de passe"));
    mdp2->setObjectName("chg_mdp2");
    ui->gridLayout_5->addWidget(mdp2);
    liste.push_back(mdp2);


    QLineEdit * mdp3;
    mdp3=new QLineEdit(QString("Retapper votre nouveau mot de passe"));
    mdp3->setObjectName("chg_mdp3");
    ui->gridLayout_5->addWidget(mdp3);
    liste.push_back(mdp3);


    QPushButton* button_mdp= new QPushButton;
    ui->gridLayout_5->addWidget(button_mdp);
    button_mdp->setText("Changer");
    button_mdp->setObjectName("bouton_profil");

    connect(button_mdp,SIGNAL(pressed()),this,SLOT(mdp_pressed()));
}


void Modif_infos::login_pressed()
{
//    std::cout << "text : " <<liste[0]->text().toStdString()<<std::endl;
    QString login = liste[0]->text();

    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();
    int retour = user->updateLogin(login);
    if(retour==0)
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_profil2();
        }
    }
    else
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_modif_infos();
        }
    }
}

void Modif_infos::email_pressed()
{
//    std::cout << "text : " <<liste[1]->text().toStdString()<<std::endl;
    QString email = liste[1]->text();

    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();
    int retour = user->updateEmail(email);
    if(retour==0)
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_profil2();
        }
    }
    else
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_modif_infos();
        }
    }
}

void Modif_infos::mdp_pressed()
{
    QString mdp1 = liste[3]->text();
    QString mdp2 = liste[3]->text();
    QString mdp3 = liste[3]->text();

    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();
    int retour = user->updateMdp(mdp1,mdp2,mdp3);
    if(retour==0)
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_profil2();
        }
    }
    else
    {
        MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
        if (mv!= nullptr){
            mv->display_modif_infos();
        }
    }
}

void Modif_infos::on_button_retour_profil_pressed()
{
    //this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}



void Modif_infos::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Modif_infos::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Modif_infos::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}

