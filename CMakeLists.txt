cmake_minimum_required(VERSION 4.0)
project(Laboratorio)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Laboratorio
#Libraries
        VectorLib/vettori.h
        VectorLib/vettori.cpp
        #Teoria/Array_multidim.cpp
        #Teoria/Din_Memory.cpp
        #Teoria/Matrici_Dinamiche.cpp
        #Teoria/Liste.cpp
				Teoria/Liste2.cpp
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
)
