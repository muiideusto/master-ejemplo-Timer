/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"

#define WAIT_TIME_MS 500 

#define pinBT1 PA_15


InterruptIn bt1(pinBT1);
Timer temporizador;

void botonPulsado();
void botonSoltado();


int main()
{
   
    bt1.rise(botonPulsado);
    bt1.fall(botonSoltado);
    while (true)
    {
        
        thread_sleep_for(WAIT_TIME_MS);
    }
}

void botonPulsado(){
    temporizador.reset();
    temporizador.start();
}

void botonSoltado(){
    int tiempoPulsado_ms=temporizador.read_ms(); //ya no utilizar
    long long tiempoEnMicros=temporizador.elapsed_time().count();
    printf("Tiempo pulsación en ms %d\n",tiempoPulsado_ms);
    printf("Tiempo pulsación en us %lld\n",tiempoEnMicros);
}