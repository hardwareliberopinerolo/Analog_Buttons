


//--------------------------------------------------------------------------------------------
int Legge_Pulsanti(){

static int vA0=0;
static int vA0_pre=0;
//const int soglia =20;
static unsigned long t_pre=0;
//unsigned long th_pre=0;
static int st=0;
static bool bot=1;
//bool both=1;
static int clickn=1;
static int holdn=1;


//Serial.println(st);

switch(st){

  case 0:{
    vA0=analogRead(0);
    if (vA0 < 1000){
       st=1;
       bot=1;
       vA0_pre=vA0;
      t_pre=millis();
     
     }
     else{    st=0; }
     return 0;
  break;
  }

case 1: {
      vA0=analogRead(0);
      if (vA0>1000){
        if ((millis()- t_pre)<Dt_rimb){ st=0; }
        else if ((millis()- t_pre)< Dt_click && bot==1){ st=2; }
        else{st=0; }
      }        
 
      else{
        if ((millis()- t_pre)> Dt_hold){
        st=4;
        }
        else{st=1; }
      }
      return 0;
      break;
}

case 2:{
  //Serial.println(st);
  Serial.print(F("click"));
  Serial.println(clickn);
  ++clickn;
  st=0;
  bot=0;
  return Decodifica_Pulsanti(vA0_pre, 0);
  Serial.println(Decodifica_Pulsanti(vA0_pre, 0));
 
  break;
}

/*
case 3: {
  break;
}
*/

 case 4: {
   Serial.print(F("hold"));
   Serial.println(holdn);
  ++holdn;
   t_pre=millis();
   bot=0;
  st=1;
  return Decodifica_Pulsanti(vA0, 1);
  //Serial.println(Decodifica_Pulsanti(vA0, 1));
   break;
  }


}//end switch

//delay(100);
}

//--------------------------------------------------------------------------------------------

int Decodifica_Pulsanti(int valore_analogico, bool tipo){
  int pulsante_premuto=0;
 Serial.println(valore_analogico);
 Serial.println(tipo);
  switch(valore_analogico){

    case 0 ... 50:{ //Right
    if (tipo ==0){ pulsante_premuto=1;}
    else{ pulsante_premuto=2;}
    break;
    }
     
    case 70 ... 150:{ //Up
    if (tipo ==0){ pulsante_premuto=3;}
    else{ pulsante_premuto=4;}
    break;
    }

    case 200 ... 300:{ //Down
    if (tipo ==0){ pulsante_premuto=5;}
    else{ pulsante_premuto=6;}
    break;
    }

    case 350 ... 450:{ //Left
    if (tipo ==0){ pulsante_premuto=7;}
    else{ pulsante_premuto=8;}
    break;
    }

    case 500 ... 650:{ //Set
    if (tipo ==0){ pulsante_premuto=9;}
    else{ pulsante_premuto=10;}
    break;
    }
  }
 return pulsante_premuto;
}
