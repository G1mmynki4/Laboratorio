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

        #Programs
				#"Teoria/classi.cpp"
				Teoria/ptr_this.cpp
	Teoria/funzioni_inline.cpp
	#Teoria/Array_multidim.cpp
        #Teoria/Din_Memory.cpp
        #Teoria/Matrici_Dinamiche.cpp
        #Teoria/Liste.cpp
        #Teoria/Liste2.cpp
        #"Teoria/Unità di compilazione.cpp"

        #"Lab4/Riferimenti.cpp"
        #"Lab4/Puntatori 1.cpp"
        #"Lab4/Puntatori 2.cpp"
        #"Lab4/Puntatori 3.cpp"
        #"Lab4/Funzione con valori di ritorno multipli.cpp"
        #"Teoria/alg_ord.cpp"
        #"Lab6/Somma pari di vettori 6.1.cpp"
        #"Lab6/Concatena vettori 6.2.cpp"
        #"Lab6/Stringa Palindroma 6.3.cpp"
        #"Lab6/Ruota Vettore6.3.cpp"
        #"Lab8/Union.cpp"
        #"Lab8/Cristian/main.cpp"
        #"Lab8/Uso debuger 1 8.1.cpp"
)
