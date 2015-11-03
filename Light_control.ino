#include <livolo.h>
/*  real remote id: 6400; 19303
    virtual remote id: 10550; 8500;7400
    Keycodes from real remote:
    #1  - 0;
    #2  - 96;
    #3  - 120;
    #4  - 24;
    #5  - 80;
    #6  - 48;
    #7  - 108; 
    #8  - 12;
    #9  - 72;
    #10 - 40;
    OFF - 106;                          */
//Кнопки(коды) выключателей Livolo
const sw1=0;        //Выключатель 1 (Основной свет)
const sw2=96;       //Выключатель 2 (Основной свет)
const sw3=120;      //Выключатель 3 (Щелевой свет)
const sw4=24;       //Выключатель 4 (Щелевой свет)
const sw5=80;       //Выключатель 5 (Картинная подсветка)
const id=6400;      //Код пульта
Livolo livolo(8)    //Передатчик подключен к 8 пину
EthrnetClient client; 
IPadress ip="192.168.0.77"; //IP сервера
const port=80;              //Порт сервера

void setup(){
    Serial.begin(9600);
    Ethernet.begin(mac);
}
void loop() {
     if(clent.connect(ip, port)){
         Serial.println ("Connected");
         while(client.available()){
             command = client.read();
             if(command==1){
                 livolo.sendButton(id, sw1);
             }else if(command==2){
                 livolo.sendButton(id, sw2);
             }else if(command==3){
                 livolo.sendButton(id, sw3);
             }else if(command==4){
                 livolo.sendButton(id, sw4);
             }else if(command==5){
                 livolo.sendButton(id,sw5);
             }
         }
     }else{
         Serial.println ("Connection error");
     }
}
