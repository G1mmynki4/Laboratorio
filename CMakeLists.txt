cmake_minimum_required(VERSION 4.0)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laboratorio
        #Libraries
        #VectorLib/vettori.h
        #VectorLib/vettori.cpp
        #"FdP/FdP/Teoria/Unità di compilazione/lib_vett.h"
        #"FdP/FdP/Teoria/Unità di compilazione/lib_vett.cpp"
        #"FdP/FdP/Teoria/Classi/Classe complesso.h"

        #FdP/Lab 9
        #"FdP/FdP/Lab 9/FdP/Lab9 Include/iscrizione.h"
        #"FdP/FdP/Lab 9/FdP/Lab9 Include/iscrizione.cpp"
        #"FdP/FdP/Lab 9/FdP/Lab9 Include/class_iscrizione.cpp"
        #"FdP/FdP/Lab 9/FdP/Lab9 Include/class_iscrizione.h"
        #"FdP/FdP/Lab9/Gestione iscrizioni 9.1.cpp"
        #"FdP/FdP/Lab9/Gestione iscrizione classe 9.1.cpp"

        #FdP/Lab 10
        #"FdP/FdP/Lab 10/Cinema 10.1.cpp"
        #"FdP/FdP/Lab 10/FdP/Lab10 Include/Cinema_class.cpp"
        #"FdP/FdP/Lab 10/FdP/Lab10 Include/Cinema_class.h"

        #FdP/Lab 11
        #"FdP/FdP/Lab 11/FdP/Lab11 include/palazzo_class.cpp"
        #"FdP/FdP/Lab 11/FdP/Lab11 include/palazzo_class.h"
        #"FdP/FdP/Lab 11/Palazzo 11.1.cpp"

        #FdP/Lab 12
        #"FdP/Lab 12/PuzzleBobble.cpp"
        #"FdP/Lab 12/Include/compito.cpp"
        #"FdP/Lab 12/Include/compito.h"

        #Appello 1 2026
        #"FdP/ExamTest/1_2026/include/compito.h"
        #"FdP/ExamTest/1_2026/include/compito.cpp"
        #"FdP/ExamTest/1_2026/Exam1.cpp"
        #"FdP/ExamTest/2_2026/include/compito.h"
        #"FdP/ExamTest/2_2026/include/compito.cpp"
        #"FdP/ExamTest/2_2026/Exam2.cpp"

        #Appello 4 2024
        #"FdP/ExamTest/4_2024/include/compito.h"
        #"FdP/ExamTest/4_2024/include/compito.cpp"
        #"FdP/ExamTest/4_2024/Exam4.cpp"

        #Appello 4 2025
        #"FdP/ExamTest/4_2025/include/compito.h"
        #"FdP/ExamTest/4_2025/include/compito.cpp"
        #"FdP/ExamTest/4_2025/Exam4.cpp"

        #Appello 4 2023
        #"FdP/ExamTest/4_2023/include/compito.h"
        #"FdP/ExamTest/4_2023/include/compito.cpp"
        #"FdP/ExamTest/4_2023/Exam3.cpp"

        #Appello 1 2022
        #"FdP/ExamTest/1_2022/include/compito.h"
        #"FdP/ExamTest/1_2022/include/compito.cpp"
        #"FdP/ExamTest/1_2022/Exam1.cpp"

        #Appello 2017
        #"FdP/ExamTest/6_2017/include/compito.h"
        #"FdP/ExamTest/6_2017/include/compito.cpp"
        #"FdP/ExamTest/6_2017/Exam6.cpp"

        #Programs
        #"FdP/Teoria/Classi/Classe n complessi.cpp"
        #"FdP/Teoria/Classi/Costruttori.cpp"
        #"FdP/Teoria/Classi/Funzioni friend.cpp"
        #"FdP/Teoria/Classi/Costruttori di copia.cpp"
        #"FdP/Teoria/Classi/Classe pila.cpp"
        #"FdP/Teoria/Classi/ptr_this.cpp"
        #"FdP/Teoria/Classi/Costanti e ref dentro classi.cpp"
        #"FdP/Teoria/Classi/membri dato statici.cpp"
        #"FdP/Teoria/Classi/Funzioni membro const.cpp"
        #FdP/Teoria/Preprocessori/preprocessore.cpp
        #"FdP/Teoria/Ovverride operatori/Override op unari.cpp"
        #FdP/Teoria/funzioni_inline.cpp
	#FdP/Teoria/Array_multidim.cpp
        #FdP/Teoria/Din_Memory.cpp
        #FdP/Teoria/Matrici_Dinamiche.cpp
        #FdP/Teoria/Liste.cpp
        #FdP/Teoria/Liste2.cpp
        #"FdP/Teoria/Unità di compilazione/Unità di compilazione.cpp"
        #"FdP/Teoria/alg_ord.cpp"
        #"FdP/Teoria/Ovverride operatori/override op.cpp"
        #"FdP/Teoria/Ovverride operatori/operatori di conversione.cpp"
        #"FdP/Teoria/Ovverride operatori/ovverride ostream.cpp"
        #"FdP/Teoria/Funzioni ricorsive.cpp"

        #"FdP/Lab 4/Riferimenti.cpp"
        #"FdP/Lab 4/Puntatori 1.cpp"
        #"FdP/Lab 4/Puntatori 2.cpp"
        #"FdP/Lab 4/Puntatori 3.cpp"
        #"FdP/Lab 4/Funzione con valori di ritorno multipli.cpp"

        #"FdP/Lab 6/Somma pari di vettori 6.1.cpp"
        #"FdP/Lab 6/Concatena vettori 6.2.cpp"
        #"FdP/Lab 6/Stringa Palindroma 6.3.cpp"
        #"FdP/Lab 6/Ruota Vettore6.3.cpp"

        #"FdP/Lab 8/Union.cpp"
        #"FdP/Lab 8/Cristian/main.cpp"
        #"FdP/Lab 8/Uso debuger 1 8.1.cpp"



        #Algoritmi e Strutture Dati
        #"Algoritmi e Strutture Dati/Esercizi Laboratorio/Lab4/Es1/1_ABR_init.cpp"
        "Algoritmi e Strutture Dati/Teoria/Heap Structure/HeapSort.cpp"

)
