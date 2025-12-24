cmake_minimum_required(VERSION 4.0)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laboratorio
        #Libraries
        #VectorLib/vettori.h
        #VectorLib/vettori.cpp
        #"Teoria/Unità di compilazione/lib_vett.h"
        #"Teoria/Unità di compilazione/lib_vett.cpp"
        #"Teoria/Classi/Classe complesso.h"

        #Lab 9
        #"Lab 9/Lab9 Include/iscrizione.h"
        #"Lab 9/Lab9 Include/iscrizione.cpp"
        #"Lab 9/Lab9 Include/class_iscrizione.cpp"
        #"Lab 9/Lab9 Include/class_iscrizione.h"
        #"Lab9/Gestione iscrizioni 9.1.cpp"
        #"Lab9/Gestione iscrizione classe 9.1.cpp"

        #Lab 10
        #"Lab 10/Cinema 10.1.cpp"
        #"Lab 10/Lab10 Include/Cinema_class.cpp"
        #"Lab 10/Lab10 Include/Cinema_class.h"

        #Lab 11
        #"Lab 11/Lab11 include/palazzo_class.cpp"
        #"Lab 11/Lab11 include/palazzo_class.h"
        #"Lab 11/Palazzo 11.1.cpp"

        #Lab 12
        #"Lab 12/PuzzleBobble.cpp"
        #"Lab 12/Include/compito.cpp"
        #"Lab 12/Include/compito.h"

        #Appello 4 2025
        "ExamTest/4_2025/include/compito.h"
        "ExamTest/4_2025/include/compito.cpp"
        "ExamTest/4_2025/Exam4.cpp"

        #Programs
        #"Teoria/Classi/Classe n complessi.cpp"
        #"Teoria/Classi/Costruttori.cpp"
        #"Teoria/Classi/Funzioni friend.cpp"
        #"Teoria/Classi/Costruttori di copia.cpp"
        #"Teoria/Classi/Classe pila.cpp"
        #"Teoria/Classi/ptr_this.cpp"
        #"Teoria/Classi/Costanti e ref dentro classi.cpp"
        #"Teoria/Classi/membri dato statici.cpp"
        #"Teoria/Classi/Funzioni membro const.cpp"
        #Teoria/Preprocessori/preprocessore.cpp
        #"Teoria/Ovverride operatori/Override op unari.cpp"
        #Teoria/funzioni_inline.cpp
	#Teoria/Array_multidim.cpp
        #Teoria/Din_Memory.cpp
        #Teoria/Matrici_Dinamiche.cpp
        #Teoria/Liste.cpp
        #Teoria/Liste2.cpp
        #"Teoria/Unità di compilazione/Unità di compilazione.cpp"
        #"Teoria/alg_ord.cpp"
        #"Teoria/Ovverride operatori/override op.cpp"
        #"Teoria/Ovverride operatori/operatori di conversione.cpp"
        #"Teoria/Ovverride operatori/ovverride ostream.cpp"
        #"Teoria/Funzioni ricorsive.cpp"

        #"Lab 4/Riferimenti.cpp"
        #"Lab 4/Puntatori 1.cpp"
        #"Lab 4/Puntatori 2.cpp"
        #"Lab 4/Puntatori 3.cpp"
        #"Lab 4/Funzione con valori di ritorno multipli.cpp"

        #"Lab 6/Somma pari di vettori 6.1.cpp"
        #"Lab 6/Concatena vettori 6.2.cpp"
        #"Lab 6/Stringa Palindroma 6.3.cpp"
        #"Lab 6/Ruota Vettore6.3.cpp"

        #"Lab 8/Union.cpp"
        #"Lab 8/Cristian/main.cpp"
        #"Lab 8/Uso debuger 1 8.1.cpp"



)
