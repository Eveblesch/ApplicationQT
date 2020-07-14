#include "ui_choix_type.h"
#include "mainwindow.h"

Choix_type::Choix_type(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Choix_type)
{
    ui->setupUi(this);
}

Choix_type::~Choix_type()
{
    delete ui;
}

void Choix_type::on_button_validation_pressed()
{
//    QString entree = ui->lineEditRecherche->text();
//    std::cout << entree.toStdString()<<std::endl;
//    return entree;

    QString text = ui->comboBox->currentText();
//    std::cout <<text.toStdString()<<std::endl;

    int index = ui->comboBox->currentIndex();
//    std::cout << index << std::endl;

    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_ajout_oeuvre_existante();
    }
}


void Choix_type::affichage_choix_type()
{

//    QString recherche = on_button_recherche_pressed();
//    std::cout << "recherche2 " << recherche.toStdString()<<std::endl;


}


void Choix_type::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Choix_type::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Choix_type::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
