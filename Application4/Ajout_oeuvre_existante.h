#ifndef AJOUT_OEUVRE_EXISTANTE_H
#define AJOUT_OEUVRE_EXISTANTE_H
#include <QWidget>
#include <QComboBox>

namespace Ui {
class Ajout_oeuvre_existante;
}

class Ajout_oeuvre_existante : public QWidget {
    Q_OBJECT

public:
    explicit Ajout_oeuvre_existante(QWidget *parent = nullptr);
    ~Ajout_oeuvre_existante();
    void affichage_ajout_oeuvre_existante();



private slots:
    void ajouterPressed();

    void on_button_retour_pressed();
    void buttonSuite_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();



private:
    Ui::Ajout_oeuvre_existante *ui;
    QList<QComboBox*> liste;

};

#endif // AJOUT_OEUVRE_EXISTANTE_H
