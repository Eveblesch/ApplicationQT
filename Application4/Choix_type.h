#ifndef CHOIX_TYPE_H
#define CHOIX_TYPE_H
#include <QWidget>

namespace Ui {
class Choix_type;
}

class Choix_type : public QWidget {
    Q_OBJECT

public:
    explicit Choix_type(QWidget *parent = nullptr);
    ~Choix_type();
    void affichage_choix_type();



private slots:
    void on_button_validation_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();



private:
    Ui::Choix_type *ui;
};

#endif // CHOIX_TYPE_H
