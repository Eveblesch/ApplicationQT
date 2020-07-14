#ifndef DEMANDE_EMPRUNT_H
#define DEMANDE_EMPRUNT_H
#include <QWidget>

namespace Ui {
class Demande_emprunt;
}

class Demande_emprunt : public QWidget {
    Q_OBJECT

public:
    explicit Demande_emprunt(QWidget *parent = nullptr);
    ~Demande_emprunt();
    void affichage_demande_emprunt();
//    void affichage_recherche();
//    void affichage_exemplaire(unsigned int idExemplaire);



private slots:
    void affichage_exemplaire(unsigned int idExemplaire);
    void on_button_retour_profil_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();



private:
    Ui::Demande_emprunt *ui;
};
#endif // DEMANDE_EMPRUNT_H
