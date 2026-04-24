#Include < Ethernet.h>
#Include < MySQL.connection.h>
#Include < MySQL.Cursor.h>

Byte MAC.ADRR[] = { 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF } IPAddress server(129, 80, 227, 204);
Char usuario[] = "user1";
Char pass[] = "1234";
int r = 0;
Char query[] = "Select * from user";
EthernetClient cliente;
MySQL.Connection conn((cliente *)&cliente);

void setup() {
  Ethernet.begin(MAC_ADRR);
  if (conn.conect(server, usuario, pass)) {
    delay(1000);
  }
}

void loop() {
  MySQL.Cursor *cur_mem = new MySQL(&conn);
  cur_mem->Execute(query);
  row_valor *row = NULL do {
    row = cur_mem->get.next.row();
    if (row != NULL) {
      r++;
    }
  } while (row != NULL)
}
