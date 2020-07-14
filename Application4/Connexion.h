#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QLineEdit>

namespace Ui {
class Connexion;
}

class Connexion : public QWidget {
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = nullptr);
    ~Connexion();
    void affichageChamps();


private slots:
    void button_connexion_pressed();
    void on_button_retour_pressed();


private:
    Ui::Connexion *ui;
    QList<QLineEdit*> liste;

};

#endif // CONNEXION_H
