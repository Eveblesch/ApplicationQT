#ifndef EMPRUNT_H
#define EMPRUNT_H
#include <QWidget>
#include <QNetworkReply>

namespace Ui {
class Emprunt;
}

class Emprunt : public QWidget {
    Q_OBJECT

public:
    explicit Emprunt(QWidget *parent = nullptr);
    ~Emprunt();
    void affichage_emprunt();


private slots:
    void on_button_retour_profil_pressed();
    void getImage(QNetworkReply*);

    void affichage_exemplaire(unsigned int idExemplaire);
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();




private:
    Ui::Emprunt *ui;
};


#endif // EMPRUNT_H
