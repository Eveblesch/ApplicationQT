#ifndef RECHERCHE_H
#define RECHERCHE_H
#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Recherche;
}

class Recherche : public QWidget {
    Q_OBJECT

public:
    explicit Recherche(QWidget *parent = nullptr);
    ~Recherche();
    void affichage_recherche();
    void rechercher();
    void affichage_exemplaire(unsigned int idExemplaire);



private slots:
    void clearLayout(QLayout *layout);
    void on_button_recherche_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();



private:
    Ui::Recherche *ui;
    QList<QLineEdit*> liste;
};

#endif // RECHERCHE_H
