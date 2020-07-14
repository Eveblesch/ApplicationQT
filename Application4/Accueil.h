#ifndef ACCUEIL_H
#define ACCUEIL_H
#include <QWidget>
#include <QSqlQuery>


namespace Ui {
    class Accueil;
}

class Accueil : public QWidget {
    Q_OBJECT

public:
    explicit Accueil(QWidget *parent = nullptr);
    ~Accueil();
    void message();



private slots:
    void on_button_inscription_pressed();
    void on_button_connexion_pressed();


private:
    Ui::Accueil *ui;
};

#endif // ACCUEIL_H
