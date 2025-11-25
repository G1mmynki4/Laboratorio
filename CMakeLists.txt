cmake_minimum_required(VERSION 4.0)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laboratorio
        #Libraries
        VectorLib/vettori.h
        VectorLib/vettori.cpp
        "Teoria/lib_vett.h"
        "Teoria/lib_vett.cpp"
        "Teoria/Classi/Classe pila.h"

        #Lab 9
        "Lab9/Lab9 Include/iscrizione.h"
        "Lab9/Lab9 Include/iscrizione.cpp"
        "Lab9/Lab9 Include/class_iscrizione.cpp"
        "Lab9/Lab9 Include/class_iscrizione.h"


        #Programs
        "Teoria/Classi/Classe n complessi.cpp"
        Teoria/Classi/Costruttori.cpp
        #"Teoria/Classi/Classe pila.cpp"
        #"Teoria/Classi/ptr_this.cpp"
        #Teoria/funzioni_inline.cpp
	    #Teoria/Array_multidim.cpp
        #Teoria/Din_Memory.cpp
        #Teoria/Matrici_Dinamiche.cpp
        #Teoria/Liste.cpp
        #Teoria/Liste2.cpp
        #"Teoria/Unità di compilazione.cpp"
        #"Teoria/alg_ord.cpp"

        #"Lab4/Riferimenti.cpp"
        #"Lab4/Puntatori 1.cpp"
        #"Lab4/Puntatori 2.cpp"
        #"Lab4/Puntatori 3.cpp"
        #"Lab4/Funzione con valori di ritorno multipli.cpp"

        #"Lab6/Somma pari di vettori 6.1.cpp"
        #"Lab6/Concatena vettori 6.2.cpp"
        #"Lab6/Stringa Palindroma 6.3.cpp"
        #"Lab6/Ruota Vettore6.3.cpp"

        #"Lab8/Union.cpp"
        #"Lab8/Cristian/main.cpp"
        #"Lab8/Uso debuger 1 8.1.cpp"

        #"Lab9/Gestione iscrizioni 9.1.cpp"
        #"Lab9/Gestione iscrizione classe 9.1.cpp"


)
