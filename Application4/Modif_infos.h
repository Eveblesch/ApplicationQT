#ifndef MODIF_INFOS_H
#define MODIF_INFOS_H
#include <QWidget>
#include <QLineEdit>
namespace Ui {
class Modif_infos;
}

class Modif_infos : public QWidget {
    Q_OBJECT

public:
    explicit Modif_infos(QWidget *parent = nullptr);
    ~Modif_infos();
    void affichageChamps();


private slots:
    void login_pressed();
    void email_pressed();
    void mdp_pressed();
    void on_button_retour_profil_pressed();
    void on_button_icones_2_pressed();
    void on_button_icones_4_pressed();
    void on_button_icones_pressed();



private:
    Ui::Modif_infos *ui;
    QList<QLineEdit*> liste;
};

#endif // MODIF_INFOS_H
