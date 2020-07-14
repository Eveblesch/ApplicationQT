#include "ui_accueil.h"
#include "mainwindow.h"


Accueil::Accueil(QWidget *parent) :
    QWidget(parent),

    ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}


void Accueil::on_button_inscription_pressed()
{
//    this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){

        mv->display_inscription();
    }

}

void Accueil::on_button_connexion_pressed()
{
//    this->setHidden(true);
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){

        mv->display_connexion();
    }
}



void Accueil::message()
{
    std::cout<<"ok"<<std::endl;
}
