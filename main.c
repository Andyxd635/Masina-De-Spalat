#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

int main()
 { 
   int VectorStare = 0b00000000;
   int temperatura = 0x00;
   int viteza = 0x00;
   int parametrii[] = {temperatura, viteza};
    DDRE = 0x00; //configuram pinii de pe portul E ca fiind de intrare si asteptam comanda de la utilizator 
    PORTE = 0xFF; 
 
void Uscare(){
 int timpUscare = 0;
   int regulator = 40;
   while(timpUscare < 15){
      timpUscare++;
}

while (regulator != 0){
   viteza = regulator; // Oprirea nu trebuie sa fie brusca, ci sa existe o franare
   regulator--;
}
VectorStare = 0b00100000; // Masina este deblocata si se pot scoate rufele

}

   void Clatire(){
      int timpClatire = 0;
      while (timpClatire < 19){
	 timpClatire++;
   }
   VectorStare = 0b10010000;
   Uscare();
}

   void Spalare(){
  int timpSpalare= 0;
   while(timpSpalare < 20){
   timpSpalare++; 
      }
    VectorStare = 0b10001000;
 Clatire();     
 }
   
   void Prespalare(int x[]){
      int timpPrespalare = 0;
      while(timpPrespalare < 30){
	 timpPrespalare++;
   }
   VectorStare = 0b10000100;
   Spalare();
}
   
   void Parametrii(){
      int regulator=0;
      while(regulator < 40){
	temperatura = regulator;
	viteza = regulator;
	regulator++;
   }
   VectorStare = 0b10000010;   // in acest moment masina de spalat este blocata, nu putem sa deschidem trapa si urmeaza sa se execute programul de prespalare
   Prespalare(parametrii);
}

  void Asteptare(){
     while(1){
   if(!(PINE & ( 1 << PE0 ))){
      VectorStare = 0b00000001;
      Parametrii();
  }
  else
     continue;
}

}  
   // Write your code here
   while (1){
      Asteptare();
   return 0;
 }
 }
