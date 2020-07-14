#include "Utilisateur.h"
#include "mainwindow.h"

Utilisateur::Utilisateur(int idUtilisateur, QString nom,QString prenom,QString login, QString mdp, QString email, int idLoc):
  idUtilisateur(idUtilisateur),
  nom(nom),
  prenom(prenom),
  login(login),
  mdp(mdp),
  email(email),
  idLocalisation(idLoc)
{}

void Utilisateur::getinfo_utilisateur()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE idUtilisateur=:idUtilisateur OR login=:login");
    query.bindValue(":idUtilisateur", this->getidUtilisateur());
    query.bindValue(":login", this->getLogin());
    query.exec();

    while (query.next()) {
        this->idUtilisateur = query.value(0).toInt();
        this->nom = query.value(1).toString();
        this->prenom = query.value(2).toString();
        this->login = query.value(3).toString();
        this->mdp=query.value(4).toString();
        this->email=query.value(5).toString();
        this->idLocalisation = query.value(6).toInt();
    }
}

int Utilisateur::getidUtilisateur() const
{
    return idUtilisateur;
}

QString Utilisateur::getNom() const
{
    return nom;
}

QString Utilisateur::getPrenom() const
{
    return prenom;
}

QString Utilisateur::getLogin() const
{
    return login;
}

QString Utilisateur::getMdp() const
{
    return mdp;
}

QString Utilisateur::getEmail() const
{
    return email;
}

int Utilisateur::getidLoc() const
{
    return idLocalisation;
}

int Utilisateur::updateLogin(QString Qlogin)
{
    QSqlQuery query_unique;
    query_unique.prepare("SELECT COUNT(*) FROM User WHERE login=:myLogin");
    query_unique.bindValue(":myLogin", Qlogin);
    query_unique.exec();

     while (query_unique.next()) {
         if(query_unique.value(0).toInt()==0){
             QSqlQuery query_updateLogin;
             query_updateLogin.prepare("UPDATE User SET login=:myLogin WHERE idUtilisateur=5");
             query_updateLogin.bindValue(":myLogin", Qlogin);
             query_updateLogin.exec();
             return 0;
          }

         else{
            return 1;
         }
     }

     return 1;

}

int Utilisateur::updateEmail(QString Qemail)
{
    QSqlQuery query_unique;
    query_unique.prepare("SELECT COUNT(*) FROM User WHERE email=:myEmail");
    query_unique.bindValue(":myEmail", Qemail);
    query_unique.exec();

     while (query_unique.next()) {
         if(query_unique.value(0).toInt()==0){
             QSqlQuery query_updateEmail;
             query_updateEmail.prepare("UPDATE User SET email=:myEmail WHERE idUtilisateur=5");
             query_updateEmail.bindValue(":myEmail", Qemail);
             query_updateEmail.exec();
             return 0;
          }

         else{
            return 1;
         }
     }
     return 1;
}

int Utilisateur::updateMdp(QString mdp1, QString mdp2, QString mdp3)
{
    if(mdp1!=mdp2)
        return 1;

    QSqlQuery query_verif_mdp;
    query_verif_mdp.prepare("SELECT COUNT(*) FROM User WHERE mdp=:myMdp AND idUtilisateur=5");
    query_verif_mdp.bindValue(":myMdp", mdp3);
    query_verif_mdp.exec();
    while (query_verif_mdp.next()) {
        if(query_verif_mdp.value(0).toInt()==0){
            return 1;
        }
        else
        {
            QSqlQuery query_updatemdp;
            query_updatemdp.prepare("UPDATE User SET mdp=:myMdp WHERE idUtilisateur=5");
            query_updatemdp.bindValue(":myMdp", mdp3);
//            query_updatemdp.exec();
            return 0;
        }
    }

}
void Utilisateur::create()
{
    QSqlQuery query;
    query.prepare("INSERT INTO User(nom, prenom, login, mdp, email, idLocalisation) VALUES (:nom, :prenom, :login, :mdp, :email, :idLoc)");
    query.bindValue(":nom", this->getNom());
    query.bindValue(":prenom", this->getPrenom());
    query.bindValue(":login", this->getLogin());
    query.bindValue(":mdp", this->getMdp());
    query.bindValue(":email", this->getEmail());
    query.bindValue(":idLoc", this->getidLoc());

    query.exec();
}
