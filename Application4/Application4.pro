#-------------------------------------------------
#
# Project created by QtCreator 2020-06-23T20:17:33
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT += network

INCLUDEPATH += /usr/include/mysql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    inscription.cpp \
    profil.cpp \
    modif_infos.cpp \
    utilisateur.cpp \
    oeuvre.cpp \
    exemplaire.cpp \
    auteur.cpp \
    localisation.cpp \
    accueil.cpp\
    bibliotheque.cpp \
    emprunt.cpp \
    reservation.cpp \
    recherche.cpp \
    demande_emprunt.cpp \
    choix_type.cpp \
    ajout_oeuvre_existante.cpp \
    ajout_nouvelle_oeuvre.cpp

HEADERS += \
        mainwindow.h \
    Accueil.h \
    Connexion.h \
    Inscription.h \
    Profil.h \
    Modif_infos.h \
    Utilisateur.h \
    Oeuvre.h \
    Exemplaire.h \
    Auteur.h \
    Localisation.h \
    Bibliotheque.h \
    Emprunt.h \
    Reservation.h \
    Recherche.h \
    Demande_emprunt.h \
    Choix_type.h \
    Ajout_oeuvre_existante.h \
    Ajout_nouvelle_oeuvre.h

FORMS += \
    connexion.ui \
    mainwindow.ui \
    accueil.ui \
    inscription.ui \
    profil.ui \
    modif_infos.ui \
    localisation.ui \
    bibliotheque.ui \
    affichage_oeuvre.ui \
    emprunt.ui \
    reservation.ui \
    recherche.ui \
    demande_emprunt.ui \
    choix_type.ui \
    ajout_oeuvre_existante.ui \
    ajout_nouvelle_oeuvre.ui

RESOURCES += \
    ressources.qrc
