//Включить библиотеки
#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>
#include <DallasTemperature.h>


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);



//Объявляем пины подключения
const sw1 = 5; //Выключатель 1
const sw2 = 6; //Выключатель 2
const ONE_WIRE_BUS = 2; //Линия ONE_WIRE;


//Объявляем переменные и константы
boolean sw1State; //Состояние выключателя 1
boolean sw2State; //Состояние выключателя 2
boolean sw3State; //Состояние выключателя 3
boolean sw4State; //Состояние выключателя 4
boolean sw5State; //Состояние выключателя 5
boolean sw6State; //Состояние выключателя 6

byte mac[] = { 0x54, 0x34, 0x41, 0x30, 0x30, 0x31 };  
IPadress ('192.168.0.77');
char mac ('5165615616');
//Функция переключения выключателя
//принимает в качестве аргумента
//номер выключателя: 1, 2, ..., 6.
//Получив номер, функция изменяет его состояние
//без всяких проверок
funtction swCase (swN){
                if(swN==1){
                    sw1Sate=!sw1State;
                    digitalWrite(sw1, sw1tate);
                }else if (swN==2){
                    sw2State=!sw2State;
                    digitalWrite(sw2, sw2State);
                }else if (swN==3){
                    sw3State=!sw3State;
                    digitalWrite(sw3, sw3State);
                }else if(swN==4){
                    sw4State=!sw4State;
                    digitalWrite(sw4, sw4State);
                }else if(swN==5){
                    sw5State=!sw5State;
                    digitalWrite(sw5, sw5State);
                }else if (swN==6){
                    sw6State=!sw6State;
                    digitalWrite(sw6, sw6State);
                } 
}

void setup(){
    pinMode (sw1, OUTPUT);
    pinMode (sw2, OUTPUT);
    Serial.begin(9600);
    Ethernet.begin(mac);
}

void loop(){
    //Если клиент приконектился, 
    //то отправляем ему данные метедом GET
    if(client.connect(IPadress, port)){
        client.print ("GET/add_data.php?");
        client.print ("ztw=");
        client.print (temp('id'));
        client.print ("&");
        client.print ("&");
        client.print ("zto=");
        client.print (temp('id2'));
        client.println (" HTTP/1.1");
        client.print ( "HOST: " );
        client.println (IPadress);
        client.println ("Connection: close");
        client.println ();
        client.println ();
        //Задержка
        delay(200);
        
        //Пока есть данные от клиента
        //пишем их в переменную swN,
        //которая является аргументом функции
        while(client.available()){
            var swN = client.read();
            swCase(swN);
        }
    }
}