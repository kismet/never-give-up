//
// Created by stefy on 17/05/2026.
//

#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H
typedef struct Student {
    string cognome;
    string materia;
    float voti[10]; //i voti presi
    int n_voti; //il numero di voti registrati
    float media;
} Studente_t;
#endif //STUDENT_TYPE_H
