//--------------------------------------------------------------------------------------------
void loop() {
int pulsante= Legge_Pulsanti();
if (pulsante !=0){
  Serial.println(pulsante);
  doActionsArray [pulsante] ();
  }
}
