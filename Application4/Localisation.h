#ifndef LOCALISATION_H
#define LOCALISATION_H
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QFontComboBox>

namespace Ui {
class Localisation;
}

class Localisation : public QWidget {
    Q_OBJECT

public:
    explicit Localisation(QWidget *parent = nullptr);
    ~Localisation();
//    QStringList listeProfil;

//    void affichage_infos();
      void affichage_localisation();



private:
    Ui::Localisation *ui;
    QList<QComboBox*> listeLoc;


private slots :
    void ajoutLocalisation();
    void on_button_retour_profil_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();


};
#endif // LOCALISATION_H
