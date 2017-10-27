/*******************************************************
  Incluimos las librerias necesarias que se usaran
*/

#include <AddicoreRFID.h>
#include <SPI.h>
#include <string.h>
#include <Keyboard.h>

/* *****************************************************
   Declaracion de variables globales a utilizar
*/

AddicoreRFID myRFID; // creamos el objeto AddicoreRFID para controlar el modulo RFID
#define MAX_LEN 16

//////////////////////////////////////////////////////
//CONFIGURAMOS LOS PINES DEL RFID
//////////////////////////////////////////////////////
const int chipSelectPin = 10;
const int resetPin = 9;

void setup(){
  Serial.begin(9600);                       //Iniciamos la comunicacion Serial
  while(!Serial){}
  Serial.println("Serial Inicializado");
  Keyboard.begin();
  SPI.begin();                              //Iniciamos la libreria SPI
  pinMode(chipSelectPin,OUTPUT);            //Configuramos el pin 2 como salida para activar el modulo RFID
  digitalWrite(chipSelectPin,LOW);          //Activamos el modulo RFID
  pinMode(resetPin,OUTPUT);                 //Configuramos el pin 9 como salida para resetear el modulo RFID
  digitalWrite(resetPin,HIGH);
  myRFID.AddicoreRFID_Init();

}

void loop(){
  unsigned char status;
  unsigned char str[MAX_LEN];
  String code_id = "";
  String codigoDB =""; // variable para codigo de la base de datos
  str[1] = 0x4400;
  status = myRFID.AddicoreRFID_Request(PICC_REQIDL,str);
  if (status == MI_OK){
    Serial.println("Tarjeta RFID Detectada");
    //PROCEDEMOS A LEER EL CODIGO DE LA TARJETA
    code_ide = myRFID.AddicoreRFID_Anticoll(str);
    // comunicacion serial para obtener codigo de DB poner en una variable
    if(!(valido(codigo,codigoBD))){
	// enviar pulso de 220
    }
  }
}

void procesarCodigo([]codigo ,String codigo){
   if(codigo =="10115522582"){
      Serial.print("Hola Ernesto");
   }
   if(codigo =="24542120185"){
      Serial.print("Hola Hugo");
   }
   if(codigo =="11712417446"){
      Serial.print("Hola Rafo");
   }
}

boolean valido([]codigo ,String codigo){
	boolean res = false;
	for(int i = 0; i <codigo.length(); i++ ){
		if(codigo[i] != codigo[i]){
			res = true;
			i = codigo.length();
		}
	}
	return res;
}
