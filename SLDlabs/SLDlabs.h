/* ============================================
SLDlabs library code for Arduino Course Control
Copyright (c) 2015 Adrián Blasco & Pablo Aliaga

Dlabs Hackerspace Zaragoza
===============================================
*/

#ifndef _SLDlabs_H_
#define _SLDlabs_H_
#include <Arduino.h>

class SLDlabs
{
	public: 
		SLDlabs ();
		bool sensorLDR1 (int value);
		bool sensorLDR2 (int value);
		int  valorLDR1();
		int  valorLDR2();
		void mover (int M11, int M12, int M21, int M22);
		void avanzar ();
		void retroceder ();
		void girar_Dcha ();
		void girar_Izda ();
		void detener ();
		void avanzar_V (int V);
		void retroceder_V (int V);
		void girar_Dcha_V (int V);
		void girar_Izda_V (int V);
		void rueda_dcha (int V);
		void rueda_izda (int V);
		void IRDetector (bool IRantes);
		void avanzarcasilla ();
		void giro_dcha90 (int timeDelay);
		void giro_izda90 (int timeDelay);
		void avance ();
		void retroceso ();
		void retrocedercasilla ();
		void chessMove (int pos_numf, int pos_letraf);

		bool _IRInicial=false;
		bool _IRdespues=false;
		String _orientacion="N";
		int _pos_num=1;
		int _pos_letra=1;

		int _umbral =750;
		int _valLDR1 =0;
		int _valLDR2 =0;
	private:
		//int _ControlPins[]={5,6,9,10};
		int _M11 = 5;
		int _M12 = 6;
		int _M21 = 9;
		int _M22 = 10;
		int _pinLDR1 = 0;
		int _pinLDR2 =1;
};

#endif
