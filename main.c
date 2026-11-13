/**
 * @file main.c
 * @author ltpe
 * @date 2026-11-11
 * @brief Main function
 */

#include <avr/io.h>
#include <stdlib.h>

typedef struct {
	uint8_t age;
	float height;
} Person;

uint16_t Add8BitNumbers(uint8_t Number1, uint8_t Number2)
{
	return (Number1 + Number2);
}

uint8_t Add8BitNumbers_8(uint8_t Number1, uint8_t Number2)
{
	return (Number1 + Number2);
}

void SwapNumbers(uint16_t *Number1, uint16_t *Number2)
{
	uint16_t TempNumber = *Number1;
	*Number1 = *Number2;
	*Number2 = TempNumber;
}

void SwapNumbers_8(uint8_t *Number1, uint8_t *Number2)
{
	uint8_t TempNumber = *Number1;
	*Number1 = *Number2;
	*Number2 = TempNumber;
}

void updatePerson(Person *p) {
	p->age = 42;        // ændrer alderen
	p->height = 1.85f;  // ændrer højden
}

void updatePerson1(Person *p) {
	(*p).age = 52;        // ændrer alderen
	(*p).height = 1.95f;  // ændrer højden
}

// Ændringerne i funktionen herunder bliver ikke "gemt", da der ikke anvendes en pointer til variablen p af typen Person.
void updatePerson2(Person p)
{
	p.age = 62;
	p.height = 1.90f;
}

int main(void)
{
	uint8_t Var1 = 0xF8;
	uint8_t Var2 = 0x01;

	uint8_t Var3;
	uint8_t Var4;
	uint8_t Var5;
	uint8_t Var6;

	// Sandhedstabel for OR
	// 0     0     0
	// 0     1     1
	// 1     0     1
	// 1     1     1
	
	// Sandhedstabel for AND
	// 0     0     0
	// 0     1     0
	// 1     0     0
	// 1     1     1
	
	// Sandhedstabel for XOR
	// 0     0     0
	// 0     1     1
	// 1     0     1
	// 1     1     0
	
	Var3 = Var1 || Var2;
	// Logisk OR. Hvis enten Var1 eller Var2 er forskellig fra 0, vil
	// Var3 blive lig med 1. Hvis både Var1 og Var2 er lig med 0, vil
	// Var3 blive lig med 0. Var3 kan således kun få værdien 0 eller 1 !!!
	// Med de nuværende værdier af Var1 og Var2 vil Var3 få værdien 0x01.

	// For måske at gøre ovennævnte lidt mere klart, kan man også skrive
	// det på måden vist herunder. Paranteserne i udtrykket er kun
	// medtaget for overskuelighedens skyld og er ikke nødvendige.
	// Med de nuværende værdier af Var1 og Var2 vil Var3 få værdien 0x01.
	Var3 = (Var1 != 0) || (Var2 != 0);

	Var4 = Var1 |  Var2;
	// Bitvis OR. Hver bit position i Var1 udfører en OR operation på den
	// samme bit position i Var2. Var4 vil således kunne få alle værdier mellem
	// 0 og 255 (0x00 - 0xFF).
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0xF9.
	
	Var5 = Var1 && Var2;
	// Logisk AND. Hvis både Var1 og Var2 er forskellig fra 0, vil
	// Var5 blive lig med 1. Hvis enten Var1 eller Var2 (eller begge) er lig med 0, vil
	// Var5 blive lig med 0. Var5 kan således kun få værdien 0 eller 1 !!!
	// Med de nuværende værdier af Var1 og Var2 vil Var5 få værdien 0x01.

	Var6 = Var1 & Var2;
	// Bitvis AND. Hver bit position i Var1 udfører en AND operation på den
	// samme bit position i Var2. Var6 vil således kunne få alle værdier mellem
	// 0 og 255 (0x00 - 0xFF).
	// Med de nuværende værdier af Var1 og Var2 vil Var6 få værdien 0x00.
	
	
	Var4 = (Var1 != 0) | (Var2 != 0);
	// Kodelinjen herover er lidt fræk. Her blander vi faktisk en bitvis or operator
	// med 2 logiske operatorer != 0.
	// Da inputtene til den sidste operation (den bitvise or operation) begge kun kan have
	// værdien 0 eller 1 (afhængig af værdierne af Var1 og Var2) vil vores output
	// Var4 kun kunne have værdien 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x01.

	Var4 = (Var1 != 0) ||  (Var2 != 0);
	// Kodelinjen herover indeholder "kun" logiske operatorer. Derfor vil vores vores output 
	// (afhængig af værdierne af Var1 og Var2) kun kunne få værdien 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x01.
	
	Var4 = (Var2 != 0) |  Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kunne antage alle værdier mellem 0 og 255.
	// Dette skyldes at det ene input (Var1) til vores sidste operation
	// (den bitvise or operation) kan antage alle værdier mellem 0 og 255.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0xF9.
	
	Var4 = (Var1 != 0) | (Var2 != 0) | Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kunne antage alle værdier mellem 0 og 255.
	// Dette skyldes at det ene input (Var1) til vores sidste operation
	// (den bitvise or operation) kan antage alle værdier mellem 0 og 255.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0xF9.
	
	Var4 = (Var1 != 0 || Var2 != 0) | Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kunne antage alle værdier mellem 0 og 255.
	// Dette skyldes at det ene input (Var1) til vores sidste operation
	// (den bitvise or operation) kan antage alle værdier mellem 0 og 255.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0xF9.
	
	Var4 = (Var1 != 0) | ((Var2 != 0) | Var1);
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kunne antage alle værdier mellem 0 og 255.
	// Dette skyldes at udtrykket der står til højre for den sidste operation
	// (den bitvise or operation) => (Var2 != 0 | Var1)
	// kan antage alle værdier mellem 0 og 255.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0xF9.
	
	Var4 = (Var1 != 0) || ((Var2 != 0) | Var1);
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kun kunne antage værdierne 0 eller 1. Dette skyldes at
	// den sidste operation er en logisk or.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x01.
	
	
	
	Var4 = (Var1 != 0) & (Var2 != 0);
	// Kodelinjen herover er lidt fræk. Her blander vi faktisk en bitvis or operator
	// med 2 logiske operatorer != 0.
	// Da inputtene til den sidste operation (den bitvise or operation) begge kun kan have
	// værdien 0 eller 1 (afhængig af værdierne af Var1 og Var2) vil vores output
	// Var4 kun kunne have værdien 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x01.
	
	Var4 = (Var1 != 0) &&  (Var2 != 0);
	// Kodelinjen herover indeholder "kun" logiske operatorer. Derfor vil vores vores output
	// (afhængig af værdierne af Var1 og Var2) kun kunne få værdien 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x01.
	
	Var4 = (Var2 != 0) &  Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. 
	// Da vi laver en bitvis And operation til sidst, og den første operand kun
	// kan have værdierne 0 eller 1, kan output kun have værdierne 0 eller 1. 
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x00.
	
	Var4 = (Var1 != 0) & (Var2 != 0) & Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer.
	// Da vi laver en bitvis And operation til sidst, og de 2 første operander kun
	// kan have værdierne 0 eller 1, kan output kun have værdierne 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x00.
	
	Var4 = (Var1 != 0 && Var2 != 0) & Var1;
	// Igen er vi lidt frække og blander bitvise og logiske operatorer.
	// Da vi laver en bitvis And operation til sidst, og de 2 første operander kun
	// kan have værdierne 0 eller 1, kan output kun have værdierne 0 eller 1.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x00.
	
	Var4 = (Var1 != 0) && ((Var2 != 0) & Var1);
	// Igen er vi lidt frække og blander bitvise og logiske operatorer. Her vil vores output (afhængig
	// af værdierne af Var1 og Var2) kun kunne antage værdierne 0 eller 1. Dette skyldes at
	// den sidste operation er en logisk and.
	// Med de nuværende værdier af Var1 og Var2 vil Var4 få værdien 0x00.
	
	PORTB = (1 << PB4) || (1 << PB2);
	// Forkert måde at sætte PORT B op på. Port B vil altid få værdien 1. Det vil sige Port B
	// bit position 0 vil blive sat. Og det var ikke vores mening !!!
	// PORTB vil få værdien 0x01.

	PORTB = (1 << PB4) | (1 << PB2);
	// Rigtig måde at sætte PORT B op på. Port B vil nu få værdien 0x14. Og det var det, vi gerne
	// ville. Sætte bit 2 og bit 4 i Port B og resette alle andre bit i Port B.
	// PORTB vil få værdien 0x14.

	PORTB |= (1 << PB0);
	// Efter den initielle opsætning af Port B ønsker vi nu at sætte bit 0 i Port B uden at røre
	// ved nogen af de andre bit i PORT B.
	// Port B får nu værdien 0x15.

	PORTB = PORTB | (1 << PB0);
	// Sætningen PORTB |= (1 << PB0); kunne også være skrevet som vist lige berover.
	// Port B får nu værdien 0x15.
	
	PORTB |= ( (1 << PB7) | (1 << PB6) );
	// Efter den initielle opsætning af Port B ønsker vi nu at sætte bit 7 og bit 6 i Port B uden at
	// røre ved nogen af de andre bit i PORT B.
	// Port B får nu værdien 0xD5.

	PORTB &= ~(1 << PB2);
	// Efter den initielle opsætning af Port B ønsker vi nu at resette bit 2 i Port B uden at røre
	// ved nogen af de andre bit i PORT B.
	// Port B får nu værdien 0xD1.

	PORTB &= ~( (1 << PB7) | (1 << PB6) );
	// Efter den initielle opsætning af Port B ønsker vi nu at resette bit 7 og bit 6 i Port B uden
	// at røre ved nogen af de andre bit i PORT B.
	// Port B får nu værdien 0x11.
	
	PORTB ^= (1 << PB2);
	// Her toggler vi ved brug af en Exclusive OR bit 2 i PORT B. Da værdien af PORT B er 0x11, 
	// før vi udfører den Exclusive OR operation, vil PB2 blive sat efter operationen.
	// Port B får nu værdien 0x51.
	
	PORTB ^= (1 << PB2);
	// Her toggler vi ved brug af en Exclusive OR bit 2 i PORT B. Da værdien af PORT B er 0x51,
	// før vi udfører den Exclusive OR operation, vil PB2 blive nulstillet efter operationen.
	// Port B får nu værdien 0x11.
	
	
	uint8_t tal = 8;
	uint8_t tal1 = 0;
	
	// Hav altid konstanten på venstre side af lighedstegnet i en if sætning. 
	// Hvis/når man glemmer det ene lighedstegn, vil man få en compiler fejl, hvilket 
	// vi er meget gladere for en logisk fejl, som kan tage rigtig lang tid at finde. 
	if (10 == tal)
	{
		tal1 = tal * 2;
	}
	else
	{
		tal1 = tal * 4;
	}
	
	// Den letteste måde at blive "overbevist" om, at det der Pointer halløj faktisk er
	// uundværlig, er ved at se på Port manupulation. 
	// Hvis vi "bare" modtager Port adressen for en given port, kan vi operere på indholdet 
	// af denne port ved blot at sætte værdien af en given Pointer til denne Port Adresse.
	// For eksempel: p_16 = 0x0024; 
	// Og da det er jo er en Pointer, kan vi efterfølgende operere på indholdet af Pointeren 
	// og dermed ændre (1) eller læse (2) indholdet på Porten.
	// (1): *p_16 = 0x0202;
	// (2): uint16_t myPortValue = *p_16;
	
	uint8_t *p_8;
	uint16_t *p_16;

	p_16 = (uint16_t *)0x0024;
	// p_16 peger nu på adresse 0x0024 i IO Memory => DDRB
	// Syntaksen (uint16_t *) er en typecast, der fortæller compileren, at vi ønsker at behandle
	//  adressen 0x0024 som en pointer til en uint16_t (16 bit unsigned integer).	

	// Vi burde have skrevet p_16 = (uint16_t *)&DDRB; 
	// For ikke at anvende magiske tal i vores i vores kode. Og
	// det er jo ikke særlig smart at anvende magiske tal i vores kode, da vi så ikke kan
	// genbruge koden på en anden MCU (Mikroprocessor), hvor DDRB måske ligger på en anden 
	// adresse. Og det er jo netop hele ideen med at anvende en compiler, at vi kan 
	// genbruge koden på forskellige MCU'er (Mikroprocessorer).

	*p_16 = 0x0302;
	// Sæt indholdet af adresse 0x0024 (DDRB) til 0x02 og
	// indholdet af adresse 0x0025 (PORT B) til 0x03.
	
	p_16++;
	// Tæl p_16 op med 1. Da p_16 er en 16 bit pointer (2 byte pointer), og vi opererer med 8 bit Memory,
	// vil p_16 efterfølgende pege på adresse 0x0026 (0x0024 + 0x02 = 0x0026)

	p_8 = (uint8_t *)0x0024;
	// p_8 peger nu på adresse 0x0024 i IO Memory => DDRB
	// Syntaksen (uint8_t *) er en typecast, der fortæller compileren, at vi ønsker at behandle 
	// adressen 0x0024 som en pointer til en uint8_t (8 bit unsigned integer).
	
	// Vi burde have skrevet p_8 = (uint8_t *)&DDRB; 
	// For ikke at anvende magiske tal i vores i vores kode. Og
	// det er jo ikke særlig smart at anvende magiske tal i vores kode, da vi så ikke kan
	// genbruge koden på en anden MCU (Mikroprocessor), hvor DDRB måske ligger på en anden 
	// adresse. Og det er jo netop hele ideen med at anvende en compiler, at vi kan 
	// genbruge koden på forskellige MCU'er (Mikroprocessorer).		

	*p_8 |= 0x04;  // Eller også *p_8 |= (1 << PB2);
	// Udfør en OR operation med indholdet af adresse 0x0024 (DDRB) for at sætte bit 2 (PB2)
	// DDRB er nu lig med : 0x06
	
	p_8 = p_8 + 1;
	// Tæl p_8 op med 1. p_8 peger nu på adresse 0x0025 (PORT B) 
	*p_8 |= 0x04; // Eller også *p_8 |= (1 << PB2);
	// Udfør en OR operation med indholdet af adresse 0x0025 (PORT B) for at sætte bit 2 (PB2)
	// PORT B er nu lig med : 0x07

	*p_8 |= (1 << PB4);
	// Udfør en OR operation med indholdet af adresse 0x0025 (PORT B) for at sætte bit 4 (PB4)
	// PORT B er nu lig med : 0x17

	*p_8 &= ~(1 << PB1);
	// Udfør en AND operation med indholdet af adresse 0x0025 (PORT B) for at cleare bit 1 (PB1)
	// ~(1 << PB1) = 0b11111110 (0xFE)
	// PORT B er nu lig med : 0x16

	
	uint16_t *p_malloc;

	p_malloc = (uint16_t *)malloc(sizeof(uint16_t));  
	// Her allokerer vi RAM til pointger variablen p_malloc.
	if (0 == p_malloc)
	{
		//printf("ERROR: Out of memory\n");
		return 1;
	}
	*p_malloc = 50;
	free(p_malloc); 
	// Her frigiver vi den allokerede RAM igen
	
	uint16_t i;
	uint16_t j;
	
	i = 0x1234;
	j = 0x5678;
	
	SwapNumbers(&i, &j);
	
	SwapNumbers_8((uint8_t *)&i, (uint8_t *)&j);
	
	Person p1 = {25, 1.70f};
		
	updatePerson(&p1);
	updatePerson1(&p1);
	updatePerson2(p1);

	
	uint8_t AddResult_8;
	uint16_t AddResult;

	AddResult = Add8BitNumbers(0xaa, 0xbb);
	
	AddResult_8 = Add8BitNumbers(0xaa, 0xbb);
	
	AddResult = Add8BitNumbers_8(0xaa, 0xbb);
	
    /* Replace with your application code */
    while (1) 
    {
    }
}
