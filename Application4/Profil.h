#ifndef PROFIL_H
#define PROFIL_H
#include <QWidget>
#include <QLabel>

namespace Ui {
class Profil;
}

class Profil : public QWidget {
    Q_OBJECT

public:
    explicit Profil(QWidget *parent = nullptr);
    ~Profil();
    QStringList listeProfil;

    void affichage_infos();




private:
    Ui::Profil *ui;

private slots :
    void button_localisation_pressed();
    void buttonModifInfos_pressed();
    void buttonDemandeEmprunt_pressed();
    void button_afficher_bibliotheque_pressed();
    void button_emprunt_pressed();
    void button_reservation_pressed();
    void on_button_icones_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();





};
#endif // PROFIL_H
