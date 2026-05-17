//
// Created by stefy on 17/05/2026.
//

#ifndef STUDENTS_H
#define STUDENTS_H
/**
 * Calcola la media dei voti di s e aggiorna il campo media s
 */
void calcola_media(Studente_t &s);

/**
 * Aggiunge il voto se c'è spazio allo studente s, e altrimenti restituisce false
 */
bool aggiungi_voto(Studente_t &s, float voto);

/**
 * Crea uno studente con cognome c che ha 0 voti, nella materia m
 */
void crea_studente(Studente_t &s, string c, string m);

/**
 * Abbassa l'ultimo voto dello studente s di punti
 */
void penalizza(Studente_t *s, float punti);

/**
 * Restituisce lo studente con la media più alta nell'elenco
 */
Studente* miglior_studente(Studente_t arr[], int dim);
#endif //STUDENTS_H
