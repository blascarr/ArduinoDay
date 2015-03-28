/* ============================================
SLDlabs library code for Arduino Course Control
Copyright (c) 2015 Adrián Blasco & Pablo Aliaga

Dlabs Hackerspace Zaragoza
===============================================
*/

#include "SLDlabs.h"
#include <Arduino.h>



SLDlabs::SLDlabs()
{
    pinMode(_M11, OUTPUT); 
    pinMode(_M12, OUTPUT); 
    pinMode(_M21, OUTPUT); 
    pinMode(_M22, OUTPUT); 

  	pinMode(_pinLDR1,INPUT);
  	pinMode(_pinLDR2,INPUT);
}
int SLDlabs::valorLDR1()
{
	return(analogRead(_pinLDR1));
}

int SLDlabs::valorLDR2()
{
	return(analogRead(_pinLDR2));
}
bool SLDlabs::sensorLDR1 (int value){
  if (analogRead(_pinLDR1) > value){
    //rueda_dcha(255);
    return true;
  }else{
    //rueda_dcha(0);
    return false;
  }
}

bool SLDlabs::sensorLDR2 (int value){
  if (analogRead(_pinLDR2) > value){
    //rueda_dcha(255);
    return true;
  }else{
    //rueda_dcha(0);
    return false;
  }
}

void SLDlabs::mover (int M11, int M12, int M21, int M22) {
  /*analogWrite(_ControlPins[0],M11);
  analogWrite(_ControlPins[1],M12);
  analogWrite(_ControlPins[2],M21);
  analogWrite(_ControlPins[3],M22);*/
  analogWrite(_M11,M11);
  analogWrite(_M12,M12);
  analogWrite(_M21,M21);
  analogWrite(_M22,M22);
 }
 
void SLDlabs::avanzar () {
  mover(0, 255, 255, 0);
 }
void SLDlabs::retroceder () {
  mover(255, 0, 0, 255);
 }
void SLDlabs::girar_Dcha () {
  mover(255, 0, 255, 0);
 }
void SLDlabs::girar_Izda () {
  mover(0, 255, 0, 255);
 }
void SLDlabs::detener () {
  mover(0, 0, 0, 0);
 }
 
void SLDlabs::avanzar_V (int V) {
  mover(0, V, V, 0);
 }
void SLDlabs::retroceder_V (int V) {
  mover(V, 0, 0, V);
 }
void SLDlabs::girar_Dcha_V (int V) {
  mover(V, 0, V, 0);
 }
 
void SLDlabs::girar_Izda_V (int V) {
  mover(0, V, 0, V);
 }
 
void SLDlabs::rueda_dcha (int V) {
  analogWrite(_M11,0);
  analogWrite(_M12,V);
 }
 
void SLDlabs::rueda_izda (int V) {
  analogWrite(_M21,V);
  analogWrite(_M22,0);
 }
 
 
void SLDlabs::IRDetector (bool IRantes) {
  _IRdespues=IRantes;
  bool IRaux=false;
  int contador=0;
  while (IRantes == _IRdespues) {
    _IRdespues=sensorLDR1 (_umbral);
    if (IRantes != _IRdespues) {
      IRaux=_IRdespues;
      for (contador = 0; contador <= 100; contador++) {
        IRaux=sensorLDR1 (_umbral);
        if ((IRaux != _IRdespues) || (contador >= 100)) {
          break;
         }
        //Serial.println(contador);
      }
      if (contador >= 100) {
        detener ();
        break;
       }else {
        _IRdespues=!_IRdespues;
       }
     }
   }
 }
 
void SLDlabs::avanzarcasilla () {
  avance();
  avance();
  retroceso();
  if (_orientacion == "N") {
    _pos_num=_pos_num + 1;
   }else if (_orientacion == "S") {
    _pos_num=_pos_num - 1;
   }else if (_orientacion == "E") {
    _pos_letra=_pos_letra + 1;
   }else if (_orientacion == "W") {
    _pos_letra=_pos_letra - 1;
   }
 }
 
void SLDlabs::giro_dcha90 (int timeDelay) {
  girar_Dcha ();
  delay(timeDelay);
  detener ();
  if (_orientacion == "N") {
    _orientacion="E";
   }else if (_orientacion == "S") {
    _orientacion="W";
   }else if (_orientacion == "E") {
    _orientacion="S";
   }else if (_orientacion == "W") {
    _orientacion="N";
   }
 }

void SLDlabs::giro_izda90 (int timeDelay) {
  girar_Izda ();
  delay(timeDelay);
  detener ();
  if (_orientacion == "N") {
    _orientacion="W";
   }else if (_orientacion == "S") {
    _orientacion="E";
   }else if (_orientacion == "E") {
    _orientacion="N";
   }else if (_orientacion == "W") {
    _orientacion="S";
   }
 }
 
void SLDlabs::avance () {
 _IRInicial=sensorLDR1 (_umbral);
 avanzar();
 IRDetector(_IRInicial);
}

void SLDlabs::retroceso () {
  _IRInicial=sensorLDR1 (_umbral);
  retroceder();
  IRDetector(_IRInicial);
 }
 
void SLDlabs::retrocedercasilla () {
  retroceso();
  retroceso();
  
  if (_orientacion == "N") {
    _pos_num=_pos_num - 1;
   }else if (_orientacion == "S") {
    _pos_num=_pos_num + 1;
   }else if (_orientacion == "E") {
    _pos_letra=_pos_letra - 1;
   }else if (_orientacion == "W") {
    _pos_letra=_pos_letra + 1;
   }
 }
 
void SLDlabs::chessMove (int pos_numf, int pos_letraf) {
  if (_pos_num < pos_numf) {
    while (!(_orientacion == "N")) {
      giro_dcha90(1200);
     }
   }else if (_pos_num > pos_numf) {
    while (!(_orientacion == "S")) {
      giro_izda90(1200);
     }
   }
  while (!(_pos_num == pos_numf)) {
    avanzarcasilla();
   }
  if (_pos_letra < pos_letraf) {
    while (!(_orientacion == "E")) {
      giro_dcha90(1200);
     }
   }else if (_pos_letra > pos_letraf) {
    while (!(_orientacion == "W")) {
      giro_izda90(1200);
     }
   }
  while (!(_pos_letra == pos_letraf)) {
    avanzarcasilla();
   }
 }
