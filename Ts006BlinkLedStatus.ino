/*
  Blink met Led_status Bool variabele.
*/
#define FALSE  0
#define TRUE   1

#define AantalStrings 16
const String  GETAL_STRINGS[]  =  {"Nul","Eén" , "Twee", "Drie", "Vier", "Vijf", "Zes", "Zeven", "Acht" , "Negen", "Tien" , "Elf", "Twaalf", "Dertien", "Veertien", "Vijftien"  };

// Declareer geheugen voor een variabele
// De bool is een echte digitale variabele en kan alleen TRUE (1) of FALSE (0) aannemen.
bool Led_Status = FALSE; // Declareer Led_Status en initialiseer die gelijk op FALSE
// Een opdracht in 'C' wordt afgesloten met een puntcomma ';'


// Reserveer geheugen voor een variabele en geef het een naam.
byte byteTeller = 0; // maak de varuiabele aan en zet de waarde op nul.
// Een byte is 8 bit lang en kan daardoor 256 waarden aannemen (2^8) van 0 tot 255.


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);   // open the serial port at 9600 bps:    
}

// the loop function runs over and over again forever
void loop() 
{
  Serial.println( "" );
  Serial.println( "Begin loop" );     
  //   init                  voorwaarde               teller bewerking. 
  for( byteTeller=0;         byteTeller < 15;        byteTeller = byteTeller + 1 ) // probeer byteTeller++ eens i.p.v.  byteTeller = byteTeller + 1
  {
    digitalWrite(LED_BUILTIN, Led_Status);  
    
    //  Als de vergelijking tussen de haakjes waar is worden de opdracht daarop volgend uitgevoerd.   
    if (byteTeller < 5)    
      delay(200);                       // wait for a 200 msecond
    else    
      delay(50);                       // wait for a 50 msecond
    Serial.print ( GETAL_STRINGS[byteTeller]);
    Serial.print ("\t");
    
    Serial.println( byteTeller );       
    Led_Status = !Led_Status;
  } 
}
