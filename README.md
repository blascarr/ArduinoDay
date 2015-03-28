# ArduinoDay
En este repositorio se encuentra la librería "SLDlabs" creada para el taller de Arduino de Zaragoza 2015. 
El proyecto preparado es un chasis con dos ruedas sobre el que va montado la placa controladora Arduino con un driver L298N para controlar los dos motores RC. 
Además dispone de un sensor desarrollado para este taller, que consta de un LED y dos fotoresistencias y que nos ayudara a medir el nivel de color de la superficie sobre la que se mueve.
Desde esta librería podremos controlar el modelo de coche siguelineas preparado para el taller con las siguientes funciones:

		SLDlabs ();
		bool sensorLDR1 (int value);
		bool sensorLDR2 (int value);
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

Con estos modos de interacción os propondremos realizar una serie de ejercicios. 
Mucha suerte y esperemos que os guste.

Pablo Aliaga
Adrián Blasco
