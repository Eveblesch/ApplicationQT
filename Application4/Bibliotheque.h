#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QLabel>

namespace Ui {
class Bibliotheque;
}

class Bibliotheque : public QWidget {
    Q_OBJECT

public:
    explicit Bibliotheque(QWidget *parent = nullptr);
    ~Bibliotheque();
    void affichage_exemplaire(unsigned int idExemplaire);
    void affichage_bibliotheque();


private slots:
    void on_button_retour_profil_pressed();
    void getImage(QNetworkReply*);
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();

private:
    Ui::Bibliotheque *ui;

};
#endif // BIBLIOTHEQUE_H
