#ifndef AJOUT_NOUVELLE_OEUVRE_H
#define AJOUT_NOUVELLE_OEUVRE_H
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

namespace Ui {
class Ajout_nouvelle_oeuvre;
}

class Ajout_nouvelle_oeuvre : public QWidget {
    Q_OBJECT

public:
    explicit Ajout_nouvelle_oeuvre(QWidget *parent = nullptr);
    ~Ajout_nouvelle_oeuvre();
    void affichage_nouvelle_oeuvre();


private slots:
    void AjoutPressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();




private:
    Ui::Ajout_nouvelle_oeuvre *ui;
    QList<QLineEdit*> liste_lineEdit;
    QList<QComboBox*> liste_ComboBox;

};
#endif // AJOUT_NOUVELLE_OEUVRE_H
