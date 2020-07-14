#ifndef EXEMPLAIRE_H
#define EXEMPLAIRE_H


class Exemplaire
{
    public:
        Exemplaire(unsigned int idExemplaire, unsigned int idUtilisateur, unsigned int idOeuvre,bool disponible, unsigned int dureeReservation);
        unsigned int idExemplaire;
        unsigned int idUtilisateur;
        unsigned int idOeuvre;
        bool disponible;
        unsigned int dureeReservation;

        void getinfo_exemplaire();
        int getidExemplaire() const;
        int getidUtilisateur() const;
        int getidOeuvre() const;
        int getDisponible() const;
        int getDureeReservation() const;
        void create();


};

#endif // EXEMPLAIRE_H
