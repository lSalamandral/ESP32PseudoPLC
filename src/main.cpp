/*
By Salamandra Desings

Carga de instrucciones digitales y analogicas para ESP32 por medio de web.

Proyecto solicitado para la materia Tecnicas Digitales 3.

Fecha de finalizacion V1.0.3: 26/07/2022.

*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <WebServer.h>
#include <WiFiClientSecure.h>
#include <data.h>
#include <web.h>
#include <string.h>
#include <iostream>
#include <map>
#include <ArduinoJson.h>
#include <UniversalTelegramBot.h>
#include <list>
#define BOT_TOKEN "5471819848:AAHVCy0erquv6qS-___Rb9DMuse2c075BxM"
#define CHAT_ID "5248562862"

const TickType_t xDelay = 1 / portTICK_PERIOD_MS;
QueueHandle_t xQueue = NULL;
std::list<TaskHandle_t> tareas;
TaskHandle_t xHandle=NULL;
bool AND(int a,int b,int d,bool c){
bool aux;
switch (b) //hola como estas
{
case 0:
  aux=digitalRead(13);
  break;
  case 1:
  aux=digitalRead(12);
  break;
  case 2:
  aux=digitalRead(14);
  break;
  case 3:
  aux=digitalRead(27);
  break;
  case 23:
        aux=digitalRead(18);
        break; 
        case 24:
        aux=digitalRead(19);
        break; 
        case 25:
        aux=digitalRead(20);
        break;
        case 26:
        aux=digitalRead(21);
        break;

default:
  break;
}
if(d==14){
  aux=!aux;
}
if (a==14){
  aux=c&aux;
  aux=!aux;
  return aux;
}
if(a!=14){ 
return c&aux;
}
}
bool OR(int a,int b,int d, bool c){
bool aux;
switch (b)
{
case 0:
  aux=digitalRead(13);
  break;
  case 1:
  aux=digitalRead(12);
  break;
  case 2:
  aux=digitalRead(14);
  break;
  case 3:
  aux=digitalRead(27);
  break;
  case 23:
        aux=digitalRead(18);
        break; 
        case 24:
        aux=digitalRead(19);
        break; 
        case 25:
        aux=digitalRead(20);
        break;
        case 26:
        aux=digitalRead(21);
        break;

default:
  break;
}
if(d==14){
  aux=!aux;
}
if (a==14){
  return !(c|aux);
}
else{
return c|aux;
}
}
bool MAYOR(int a, int c){
int aux;
  switch (a)
{
        case 4:
        aux=analogRead(33);
        break;
        case 5:
        aux=analogRead(32);
        break;
        case 6:
        aux=analogRead(35);
        break;
        case 7:
        aux=analogRead(34);
        break;
}
return c>=aux;
}
bool MENOR(int a, int c){
int aux;
  switch (a)
{
        case 4:
        aux=analogRead(33);
        break;
        case 5:
        aux=analogRead(32);
        break;
        case 6:
        aux=analogRead(35);
        break;
        case 7:
        aux=analogRead(34);
        break;
}
return c<aux;
}
void instruccion(void *parametros)  //Procedimiento base en la cual se basan las tareas
{
  Serial.println("Tarea creada!");
  void *pointer;
  std::vector<String> vector;
  std::vector<String> data{"D1", "D2", "D3", "D4", "A1", "A2", "A3", "A4", "S1", "S2", "S3", "S4", "AND", "OR", "NOT", "MAYOR", "MENOR", "SET", "RESET", "SEGUIDORA", "SET_MS", "SET_SEG", "SET_MIN","1S","2S","3S","4S","Null"};
  std::vector<int> luna;
  bool state=0;
  int salida=0,analog=0,time=0;

  if (xQueue != NULL)
  {
    if (xQueueReceive(xQueue, &(pointer), (TickType_t)10) == pdPASS)
    {
      Serial.println("Recibido la direccion");
    }
  }
  std::vector<String> &pval = *((std::vector<String> *)pointer);

  for (int i = 0; i < pval.size(); i++)
  {
    vector.push_back(pval[i]);
  }
  
    for (String v : vector)
  { 
      for (int i = 0; i < data.size(); i++)
      {
        if(data[i]==v){
          luna.push_back(i);
        }
      }
      
  }

   vTaskSuspend(NULL);
  Serial.println("Tarea Resumida");
  
 

  while (1)
  {
    for(int t=0;t<luna.size();t++){
      switch (luna[t])
      {
        case 0:
        state=digitalRead(13);
        break;
        case 1:
        state=digitalRead(12);
        break;
        case 2:
        state=digitalRead(14);
        break;
        case 3:
        state=digitalRead(27);
        break;
        case 4:
        analog=analogRead(33);
        break;
        case 5:
        analog=analogRead(32);
        break;
        case 6:
        analog=analogRead(35);
        break;
        case 7:
        analog=analogRead(34);
        break;
        case 8:
        salida=18;
        break;
        case 9:
        salida=19;
        break;
        case 10:
        salida=21;
        break;
        case 11:
        salida=22;
        break;
        case 12:
        state=AND(luna[t+1],luna[t+2],luna[t+3],state);
        t=t+3;
        break;
        case 13:
        state=OR(luna[t+1],luna[t+2],luna[t+3],state);
        t=t+3;
        break;
        case 14:
        state=!state;
        break;
        case 15:
        state=MAYOR(luna[t+1],analog);
        t++;
        break;
        case 16:
        state=MENOR(luna[t+1],analog);
        t++;
        break;
        case 17:
        if(state==1){
        digitalWrite(salida, HIGH);
        }
        break;
        case 18:
        if(state==1){
        digitalWrite(salida, LOW);
        }
        break;
        case 19:
        Serial.println(state);
        if(state==1){
        digitalWrite(salida, HIGH);
        }
        if(state==0){
        digitalWrite(salida, LOW);
        }
        break; 
        case 20:
        if (state==1)
        {
          time=vector[vector.size()-1].toInt();
          Serial.print("La salida se habilitara por ");
          Serial.print(time);
          Serial.println(" ms");
          digitalWrite(salida, HIGH);
          vTaskDelay(xDelay*time);
          digitalWrite(salida, LOW);
          vTaskDelay(xDelay*100);
          
        }
        break;   
         break; 
        case 21:
        if (state==1)
        {
          time=vector[vector.size()-1].toInt();
          Serial.print("La salida se habilitara por ");
          Serial.print(time);
          Serial.println(" S");
          digitalWrite(salida, HIGH);
          vTaskDelay(xDelay*time*1000);
          digitalWrite(salida, LOW);
          vTaskDelay(xDelay*100);
          
        }
        break;
         break; 
        case 22:
        if (state==1)
        {
          time=vector[vector.size()-1].toInt();
          Serial.print("La salida se habilitara por ");
          Serial.print(time);
          Serial.println(" Min");
          digitalWrite(salida, HIGH);
          vTaskDelay(xDelay*time*1000*60);
          digitalWrite(salida, LOW);
          vTaskDelay(xDelay*100);
         
        }
        break;
        case 23:
        state=digitalRead(18);
        break; 
        case 24:
        state=digitalRead(19);
        break; 
        case 25:
        state=digitalRead(21);
        break;
        case 26:
        state=digitalRead(22);
        break;
      default:
        break;
       
      }
    }
 
  }
  
}

const unsigned long BOT_MTBS = 1000;
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);
unsigned long bot_lasttime;
WiFiMulti wifiMulti;
int pinLed = 2;
boolean Estado = false;

const uint32_t TiempoEsperaWifi = 5000;

unsigned long TiempoActual = 0;
unsigned long TiempoAnterior = 0;
const long TiempoCancelacion = 500;
WebServer servidor(80);
void ActualizarWifi()
{
  if (wifiMulti.run(TiempoEsperaWifi) != WL_CONNECTED)
  {
    Serial.println("No conectado a Wifi!");
  }
}
void handleRoot()            //Manejo de la pagina WEB
{
  servidor.send(200, "text/html", Pagina);
}
void datastring()         // Recepcion de Json, des-serializacion del mismo, tratamiento de los parametros de las instrucciones, creacion de tareas y envio del vector dinamico
{                         //creacion de tareas y envio del vector dinamico
  String states = servidor.arg("informacion");
  DynamicJsonDocument doc(4096);
  String data;
  std::vector<String> valores;
  void *ponterVal = (void *)&valores;
  

  DeserializationError err = deserializeJson(doc, states);
  if (err)
  {
    Serial.print(F("deserializeJson() failed with code "));
  }
  Serial.println(err.f_str());
  JsonObject root = doc.as<JsonObject>();
  for (JsonPair kv : root)
  {
    data = kv.value().as<char *>();
    if (data != "True")
    {
      valores.push_back(data);
    }
    if (data == "True")
    {

      xQueue = xQueueCreate(1, sizeof(&ponterVal));

      if (xQueue != NULL)
      {
        
        Serial.print("Queues creadas con ");
        Serial.print(valores.size());
        Serial.println(" datos");
        Serial.println("Tratando de crear tarea");
        xTaskCreatePinnedToCore(instruccion, "1", 2500, NULL, 1, &xHandle,1);
        tareas.push_back(xHandle);
        Serial.println("Intento de creacion de tarea realizado");
        xQueueSend(xQueue, (void *)&ponterVal, (TickType_t)0);
        Serial.println("Queue enviada");
        vTaskDelay(xDelay * 100);
      }
      else
      {
        Serial.println("fallo la creacion de la lista");
      }
      vQueueDelete(xQueue);
      valores.clear();
    }
  }
}
void ejecutar(){                // Cuando se activa el boton de ejecutar se resumen todas las tareas que son suspendidas en su creacion, 
if(tareas.size()!=0){           // o que fueron pausadas por el procedimiento pausar().
Serial.println("Ejecutando");
  for(TaskHandle_t t:tareas){
   vTaskResume(t);
  }
}
else{
  Serial.println("No hay tareas para ejecutar");
}

}
void detener(){                  //Detiene todas las tareas ejecutan instrucciones y las borra
  Serial.println("Deteniendo y eliminando instrucciones...");
   for(TaskHandle_t t:tareas){
   vTaskDelete(t);
  }
tareas.clear();
digitalWrite(18, LOW);
digitalWrite(19, LOW);
digitalWrite(21, LOW);
digitalWrite(22, LOW);
  

}
void pausar(){              //Suspende todas las tareas que ejecutan instrucciones 
  Serial.print("Pausando ");
  Serial.print(tareas.size());
  Serial.println(" tareas");
    for(TaskHandle_t t:tareas){
   vTaskSuspend(t);
  }

}
void TaskReq(){
 servidor.send(200,"text/plane",String(tareas.size()));

}

void Conectividad(void *parametros)     //Manejo de todas las funciones WEB
{


  servidor.on("/ejecutar", ejecutar);
  servidor.on("/detener",detener);
  servidor.on("/pausar",pausar);
  servidor.on("/tasks",HTTP_GET, TaskReq);


  while (1)
  {
    vTaskDelay(xDelay);
  }
}
void setup()
{
  Serial.begin(115200);
  Serial.println("\nIniciando multi Wifi");

  wifiMulti.addAP(ssid_1, password_1);                  //Utilizando la libreria MultiWIFI puedo cargar multiples puntos de acceso.
  wifiMulti.addAP(ssid_2, password_2);
  wifiMulti.addAP(ssid_3, password_3);
  wifiMulti.addAP(ssid_4, password_4);
  wifiMulti.addAP(ssid_5, password_5);
  wifiMulti.addAP(ssid_6, password_6);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  WiFi.mode(WIFI_STA);
  Serial.print("Conectando a Wifi ..");
  while (wifiMulti.run(TiempoEsperaWifi) != WL_CONNECTED)
  {
    Serial.print(".");
  }
  Serial.println(".. Conectado");
  Serial.print("SSID:");
  Serial.print(WiFi.SSID());
  const String ip = WiFi.localIP().toString().c_str();
  Serial.print(" ID:");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "La IP local del ESP32 es: " + ip, "");    //Control del bot de telegram que me permite recibir la ip que fue asignada
  servidor.begin();
  pinMode(33, INPUT);
  pinMode(32, INPUT);
  pinMode(35, INPUT);
  pinMode(34, INPUT);
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(14, INPUT);
  pinMode(27, INPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(18, HIGH);
  delay(200);
  digitalWrite(19, HIGH);
  delay(200);
  digitalWrite(21, HIGH);
  delay(200);
  digitalWrite(22, HIGH);
  delay(200); 
  digitalWrite(18, LOW);
  delay(200);
  digitalWrite(19, LOW);
  delay(200);
  digitalWrite(21, LOW);
  delay(200);
  digitalWrite(22, LOW);
  delay(200);
  servidor.on("/", handleRoot);
  servidor.on("/info", datastring);
  xTaskCreatePinnedToCore(Conectividad, "WEBServer", 1024, NULL, 1, NULL, 0); //Creacion de la tarea
  
}

void loop()
{
  servidor.handleClient();
}
