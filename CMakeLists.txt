cmake_minimum_required(VERSION 3.21)
project(Automate C)

set(CMAKE_C_STANDARD 99)

add_executable(Automate main.c structure.h initialisation.c initialisation.h genererAutomate.c genererAutomate.h
        afficherAutomate.c afficherAutomate.h get_from_txt.c get_from_txt.h determine.c determine.h complet.c complet.h strandard.c strandard.h)


