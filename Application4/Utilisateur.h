#ifndef UTILISATEUR_H
#define UTILISATEUR_H
#include <QString>
//#include <string>

class Utilisateur
{
    public:
      Utilisateur(int idUtilisateur,QString nom,QString prenom,QString login, QString mdp, QString email, int idLoc);

      int idUtilisateur;
      QString nom;
      QString prenom;
      QString login;
      QString mdp;
      QString email;
      int idLocalisation;

        void getinfo_utilisateur();
        int getidUtilisateur() const;
        QString getNom() const;
        QString getPrenom() const;
        QString getLogin() const;
        QString getMdp() const;
        QString getEmail() const;
        int getidLoc() const;

        int updateLogin(QString Qlogin);
        int updateEmail(QString Qemail);
        int updateMdp(QString mdp1, QString mdp2, QString mdp3);


        void create();
    };

#endif // UTILISATEUR_H
