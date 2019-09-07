#include <Adafruit_GFX.h>
#include <SWTFT.h> // spécifiques au matériel bibliothèque

//Les tiges de contrôle pour l’écran LCD peuvent être assignés au tout numérique ou  analogique épingles... mais nous allons utiliser les broches analogiques car cela nous permet de  double vers le haut les broches avec l’écran tactile (Voir l’exemple de peinture TFT). //
#define LCD_CS A3 // Chip Select va à Analog 3 // 
#define LCD_CD A2 // commande/données va à Analog 2 // 
#define LCD_WR A1 // écriture LCD va à Analog 1 // 
#define LCD_RD A0 // LCD lecture va à analogique 0

#define LCD_RESET A4 // peut alternativement il suffit de connecter à la broche de remise à zéro de l’Arduino

//Lorsque vous utilisez la carte de dérivation uniquement, utilisez ces lignes 8 données à l’écran LCD: / / pour l’Arduino Uno, Duemilanove, Diecimila, etc: / / D0 connectée à la broche numérique 8 (Remarquez ce sont / / D1 connectée à la broche numérique 9 pas dans l’ordre!) / / D2 connectée à la broche numérique 2 / / D3 connectée à la broche numérique 3 / / D4 connectée à la borne numérique 4 / / D5 connectée à la broche numérique 5 / / D6 connectée à la broche numérique 6 / / D7 connectée à la broche numérique 7 / / pour l’Arduino Mega , utiliser des broches numériques 22 à 29 / / (dans l’en-tête de 2 rangées à l’extrémité de la planche).

//Assigner des noms lisibles par l’homme à certaines valeurs communes de couleur 16-bit : 
#define noir 0 x 0000 
#define BLUE 0x001F 
#define rouge 0xF800 
#define vert 0x07E0 
#define CYAN 0x07FF 
#define MAGENTA 0xF81F 
#define jaune 0xFFE0 
#define blanc 0xFFFF

//SWTFT tft ; Si vous utilisez le bouclier, toutes les lignes de données et de contrôle sont fixés, et / / une déclaration plus simple peut éventuellement être utilisée: / / SWTFT tft ;

void setup(void) {TFT.reset() ;

identificateur d’uint16_t = TFT.readID() ; 
TFT.Begin(identifier) ; }

void loop(void) {pour (rotation uint8_t = 0; rotation = 1; rotation ++) {TFT.setRotation(rotation) ; testText() ; delay(20000);}}

unsigned long testFillScreen() {unsigned long début = micros() ; 
TFT.fillScreen(BLACK) ; 
TFT.fillScreen(RED) ; 
TFT.fillScreen(GREEN) ; 
TFT.fillScreen(BLUE) ; 
TFT.fillScreen(BLACK) ; 
micros() retour - début;}

unsigned long testText() {TFT.fillScreen(BLACK) ; }
unsigned long début = micros()
TFT.setTextColor(WHITE) ; 
TFT.setTextSize(1) ; 
TFT.setCursor (0, 0), 
TFT.println (" Zhungu robotique!") ;

TFT.setTextColor(GREEN) ; 
TFT.setTextSize(2) ; 
TFT.println ("moteur temp ~ 56 degrés C") ; 
TFT.setTextColor(WHITE) ;

TFT.println ("ESC Temp ~ 50 degrés C") ; 
TFT.setTextColor(MAGENTA) ;

TFT.println ("détecteur de méthane ~ 20ppm") ; 
TFT.setTextColor(CYAN) ;

TFT.println ("capteur d’hydrogène ~ 0,2 ppm") ; 
TFT.setTextColor(RED) ;

TFT.println ("sonde Co2 ~ 70ppm") ; 
TFT.setTextColor(MAGENTA) ;

TFT.println ("pression atmosphérique ~ 100011Pa") ; 
TFT.setTextColor(GREEN) ;

TFT.println ("Current temp ~ 30 degrés C") ; 
TFT.setTextColor(YELLOW) ;

TFT.println (" humidité actuelle est 50 % ") ; 
TFT.setTextColor(CYAN) ;

TFT.println ("Altutude ~ 45m") ; 
TFT.setTextColor(WHITE) ;

TFT.println ("tension restant ~ 7.6V") ; 
TFT.setTextColor(BLUE) ;

TFT.println ("appel de courant ~ 12 a") ; 
TFT.setTextColor(GREEN) ; 
TFT.println (" l’indice UV est 12mW/cm ^ 2 ") ; 
TFT.setTextColor(RED) ; 
TFT.println ("intensité lumineuse est 930 Lux ") ;

retour micros() - start ; }
