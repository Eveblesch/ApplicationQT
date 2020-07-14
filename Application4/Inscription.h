#ifndef INSCRIPTION_H
#define INSCRIPTION_H
#include <QWidget>
#include <QLineEdit>
#include <QList>
#include <QPushButton>

namespace Ui {
class Inscription;
}

class Inscription : public QWidget {
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = nullptr);
    ~Inscription();
    void affichageChamps();


private slots:
    void button_inscription_pressed();
    void on_button_retour_pressed();


private:
    Ui::Inscription *ui;
    QList<QLineEdit*> liste;
    QStringList liste_inscription;
};

#endif // INSCRIPTION_H
