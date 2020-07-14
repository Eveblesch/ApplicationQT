#ifndef RESERVATION_H
#define RESERVATION_H
#include <QWidget>

namespace Ui {
class Reservation;
}

class Reservation : public QWidget {
    Q_OBJECT

public:
    explicit Reservation(QWidget *parent = nullptr);
    ~Reservation();
    void affichage_reservation();


private slots:
    void on_button_retour_profil_pressed();
    void affichage_exemplaire(unsigned int idExemplaire);
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();




private:
    Ui::Reservation *ui;
};
#endif // RESERVATION_H
