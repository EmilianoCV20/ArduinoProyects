#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
bool bandera=false;
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress ip(192,168,0,102);
IPAddress subnet(255,255,255,0);
IPAddress gateway(192,168,0,1);
IPAddress dns(8,8,8,8);

//IPAddress server(150,136,254,73);
IPAddress server(132,226,34,79);
 
//char usuario[] = "user1";            
//char pass[] = "1234";
//char db_name[] = "Arduino"; 

char usuario[] = "Admin";            
char pass[] = "1234";
char db_name[] = "Arduino"; 

char INSERT_SQL[] = "Insert Into Arduino.Temperatura(temperatura,ubicacion) Values(43.1,'Emili')";

EthernetClient cliente;
MySQL_Connection conn((Client *)&cliente);

void setup() {
  
  Serial.begin(9600);
  //Ethernet.begin(mac, ip, dns, gateway, subnet);
  Serial.println("Inicializando");

  if(Ethernet.begin(mac)==0) {
    while(true);
  }
  Serial.println(Ethernet.localIP());

  Serial.println("Conectando...");
  if (conn.connect(server, 3306, usuario, pass)) {
    delay(1000);
  }
  else
    Serial.println("Connection failed.");
}


void loop() {
 if (bandera==false){
  delay(2000);

  Serial.println("Insertando Datos");

 
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  cur_mem->execute(INSERT_SQL);
  
  delete cur_mem;
  bandera=true;
 }
}
