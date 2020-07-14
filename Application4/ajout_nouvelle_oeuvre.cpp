#include "ui_ajout_nouvelle_oeuvre.h"
#include "mainwindow.h"

Ajout_nouvelle_oeuvre::Ajout_nouvelle_oeuvre(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ajout_nouvelle_oeuvre),
    liste_lineEdit(),
    liste_ComboBox()
{
    ui->setupUi(this);
}

Ajout_nouvelle_oeuvre::~Ajout_nouvelle_oeuvre()
{
    delete ui;
}


void Ajout_nouvelle_oeuvre::affichage_nouvelle_oeuvre()
{
    QLabel *label_h1 = new QLabel;
    label_h1->setObjectName("label_h1");
    label_h1->setText("Création d'oeuvre");
    ui->gridLayout_titre->addWidget(label_h1);

    QLineEdit * saisie;
    saisie=new QLineEdit(QString("Titre"));
    saisie->setObjectName("titre");
    liste_lineEdit.push_back(saisie);
    ui->gridLayout_nouvelle_oeuvre->addWidget(saisie);

    QComboBox *listeAuteur = new QComboBox;
    listeAuteur->addItem("Auteur");

    QSqlQuery queryAuteur;
    queryAuteur.prepare("SELECT * FROM Auteur WHERE idType=1");
    queryAuteur.exec();

    while (queryAuteur.next())
    {
        listeAuteur->addItem(queryAuteur.value(1).toString() + " " + queryAuteur.value(2).toString());
    }
    liste_ComboBox.push_back(listeAuteur);
    ui->gridLayout_nouvelle_oeuvre->addWidget(listeAuteur);


    QComboBox *listeEditeur = new QComboBox;
    listeEditeur->addItem("Edition");

    QSqlQuery queryEditeur;
    queryEditeur.prepare("SELECT * FROM Editeur");
    queryEditeur.exec();

    while (queryEditeur.next())
    {
        listeEditeur->addItem(queryEditeur.value(1).toString());
    }
    liste_ComboBox.push_back(listeEditeur);
    ui->gridLayout_nouvelle_oeuvre->addWidget(listeEditeur);

    QComboBox *listeGenre = new QComboBox;
    listeGenre->addItem("Genre");

    QSqlQuery queryGenre;
    queryGenre.prepare("SELECT * FROM Genre");
    queryGenre.exec();

    while (queryGenre.next())
    {
        listeGenre->addItem(queryGenre.value(1).toString());
    }
    liste_ComboBox.push_back(listeGenre);
    ui->gridLayout_nouvelle_oeuvre->addWidget(listeGenre);

    saisie=new QLineEdit(QString("Date de publication"));
    saisie->setObjectName("date");
    liste_lineEdit.push_back(saisie);
    ui->gridLayout_nouvelle_oeuvre->addWidget(saisie);

    saisie=new QLineEdit(QString("ISBN"));
    saisie->setObjectName("isbn");
    liste_lineEdit.push_back(saisie);
    ui->gridLayout_nouvelle_oeuvre->addWidget(saisie);

    QComboBox *listeLangue = new QComboBox;
    listeLangue->addItem("Langue");
    listeLangue->addItem("Français");
    listeLangue->addItem("Anglais");
    listeLangue->addItem("Espagnol");
    listeLangue->addItem("Allemand");
    listeLangue->addItem("Autre");
    liste_ComboBox.push_back(listeLangue);

    ui->gridLayout_nouvelle_oeuvre->addWidget(listeLangue);

    saisie=new QLineEdit(QString("Adresse de couverture"));
    saisie->setObjectName("couverture");
    liste_lineEdit.push_back(saisie);
    ui->gridLayout_nouvelle_oeuvre->addWidget(saisie);


    QPushButton* button_ajouter = new QPushButton;
    button_ajouter->setObjectName("bouton_validation");
    ui->gridLayout_nouvelle_oeuvre->addWidget(button_ajouter);
    button_ajouter->setText("Ajouter");
    connect(button_ajouter,SIGNAL(pressed()),this,SLOT(AjoutPressed()));


}

void Ajout_nouvelle_oeuvre::AjoutPressed()
{
    Utilisateur *user = new Utilisateur(5, "","","","","",-1);
    user->getinfo_utilisateur();


    QString titre = liste_lineEdit[0]->text();
    QString date = liste_lineEdit[1]->text();
    int date2 = date.toInt();
    QString ISBN = liste_lineEdit[2]->text();
    QString couverture = liste_lineEdit[3]->text();

//    std::cout << titre.toStdString() << std::endl;
//    std::cout << date.toStdString() << std::endl;
//    std::cout << "hey "<< date2 << std::endl;

//    std::cout << ISBN.toStdString() << std::endl;
//    std::cout << couverture.toStdString() << std::endl;

    QString auteur = liste_ComboBox[0]->currentText();
    QString nomAuteur = auteur.split(" ").at(0);
    QString PrenomAuteur = auteur.split(" ").at(1);


    Auteur *auteur2 = new Auteur(-1,nomAuteur,PrenomAuteur,-1);
    auteur2->getInfo_auteur();
    int id = auteur2->getidAuteur();
//    std::cout << "AUTEUR " << auteur.toStdString() << std::endl;
//    std::cout << "nom " << nomAuteur.toStdString() << std::endl;
//    std::cout << "prenom " << PrenomAuteur.toStdString() << std::endl;

//    std::cout << "id auteur " << id << std::endl;

//    for(int i=0;i<liste_ComboBox.size();i++)
//    {
//        std::cout <<liste_ComboBox[i]->currentText().toStdString()<<std::endl;
//    }
//    std::cout <<liste_ComboBox[1]->currentText().toStdString()<<std::endl;

//    QString edition = liste_ComboBox[1]->currentText();
//    std::cout<< "ed 2" <<liste_ComboBox[1]->currentText().toStdString() << std::endl;

//    std::cout<< "ed " << edition.toStdString()<< std::endl;
//    QSqlQuery query_idEdition;
//    query_idEdition.prepare("SELECT idEditeur FROM Editeur WHERE nom=:nom");
//    query_idEdition.bindValue(":nom", edition);
//    query_idEdition.exec();

//    while (query_idEdition.next())
//    {
//        int idEdition = query_idEdition.value(0).toInt();
//        std::cout << "id "<<idEdition << std::endl;

//    }

//    QString genre = liste_ComboBox[2]->currentText();

//    QSqlQuery query_idGenre;
//    query_idGenre.prepare("SELECT idGenre FROM Genre WHERE intitule=:intitule");
//    query_idGenre.bindValue(":intitule", genre);
//    query_idGenre.exec();

//    while (query_idGenre.next())
//    {
//        int idGenre = query_idGenre.value(0).toInt();
//    }

    QString langue = liste_ComboBox[3]->currentText();

//    std::cout << auteur.toStdString() << std::endl;
//    std::cout << edition.toStdString() << std::endl;
//    std::cout << genre.toStdString() << std::endl;
//    std::cout << langue.toStdString() << std::endl;

//    Oeuvre *oeuvre = new Oeuvre(-1,auteur2->getidAuteur(),idEdition,1,idGenre,titre,ISBN,date2,couverture,langue);
//    oeuvre->create();

//    Exemplaire *exemplaire = new Exemplaire(-1, user->getidUtilisateur(),query_rechercheidOeuvre.value(0).toInt(),1,21);
//    exemplaire->create();

}

void Ajout_nouvelle_oeuvre::on_button_icones_2_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_choix_type();
    }
}

void Ajout_nouvelle_oeuvre::on_button_icones_4_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_profil2();
    }
}

void Ajout_nouvelle_oeuvre::on_button_icones_pressed()
{
    MainWindow* mv = dynamic_cast<MainWindow*>(this->parent());
    if (mv!= nullptr){
        mv->display_recherche();
    }
}
