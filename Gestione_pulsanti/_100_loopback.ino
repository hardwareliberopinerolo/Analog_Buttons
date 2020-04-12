

void Set_click(){
  Serial.println(F("Set Click"));
 }
//------------------------------------------------------------------------------------------ 
void Set_hold(){
  Serial.println(F("Set Hold"));
  }
//------------------------------------------------------------------------------------------
void Left_click(){
  Serial.println(F("Left Click"));
  }
//------------------------------------------------------------------------------------------
void Left_hold(){
    Serial.println(F("Left Hold"));
  }
//------------------------------------------------------------------------------------------
void Right_click(){
  Serial.println(F("Right Click"));
  }
//------------------------------------------------------------------------------------------
void Right_hold(){
    Serial.println(F("Right Hold"));
  }
//------------------------------------------------------------------------------------------

void Up_click(){
  Serial.println(F("Up Click"));
  }
//------------------------------------------------------------------------------------------
void Up_hold(){
    Serial.println(F("Up Hold"));
  }
//------------------------------------------------------------------------------------------
void Down_click(){
  Serial.println(F("Down Click"));
  }
//------------------------------------------------------------------------------------------
void Down_hold(){
    Serial.println(F("Down Hold"));
  }
//------------------------------------------------------------------------------------------
void Nulla(){}
//------------------------------------------------------------------------------------------

typedef void (*GeneralFunction) (); // From https://www.gammon.com.au/callbacks 
GeneralFunction doActionsArray [] =  { // array of function pointers
Nulla,
Right_click,
Right_hold,
Up_click,
Up_hold,
Down_click,
Down_hold,
Left_click,
Left_hold,
Set_click,
Set_hold,
};
