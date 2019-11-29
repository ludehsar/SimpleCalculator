/*
 * SimpleCalculator.c
 *
 * Created: 16-Oct-19 01:31:38 AM
 * Author : Group H
 */

#include <avr/io.h>
#include <util/delay.h>

// Labeling certain ports according to the configuration of the circuit.
// This may help to understand the code very well.
#define KeypadDirectionRegister DDRB
#define KeypadPortControl PORTB
#define KeypadPortValue PINB

#define First7SegmentDisplayDirectionRegister DDRC
#define First7SegmentDisplayPortControl PORTC
#define Second7SegmentDisplayDirectionRegister DDRD
#define Second7SegmentDisplayPortControl PORTD

// Key combination of keypad
unsigned char keys[4][4] = {
	{'1', '2', '3', '+'},
	{'4', '5', '6', '-'},
	{'7', '8', '9', '*'},
	{'C', '0', '=', '/'}
};
int calculatedValue;
int secondValue;
unsigned char stackedOperator;
uint8_t display[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111
};

void initialize();
void reset();
unsigned char scanKeypad();
void addDigitToTheSecondValue(uint8_t val);
void print(int val);
void process(unsigned char operator);

int main(void)
{
	initialize();
	
    while (1)
    {
		unsigned char key = scanKeypad();
		if (key != '?') {
			if (key >= '0' && key <= '9') {
				uint8_t k = (uint8_t) (key - '0');
				addDigitToTheSecondValue(k);
			} else {
				if (key == 'C') process(key);
				else if (stackedOperator != '=') {
					process(stackedOperator);
					stackedOperator = key;
				}
				else { // stackedOperator is currently empty
					stackedOperator = key;
					if (secondValue != 0) process('=');
				}
			}
		}
    }
	
	return 0;
}

void initialize()
{
	process('C');
	
	KeypadDirectionRegister = 0b00001111; // By default, the rows will be the output and the columns will be the input.
	
	First7SegmentDisplayDirectionRegister = 0b11111111;
	Second7SegmentDisplayDirectionRegister = 0b11111111;
}

// Always checks whether a key is pressed or not.
// If pressed, returns the key information.
unsigned char scanKeypad()
{
	KeypadPortControl = 0b11110000;
	for (int i = 0; i < 4; ++i) {
		KeypadPortControl = ~(1 << i);
		for (int j = 4; j < 8; ++j) {
			if (!(KeypadPortValue & (1 << j))) {
				while (!(KeypadPortValue & (1 << j))) _delay_ms(50);
				return keys[i][j - 4];
			}
		}
	}
	return '?';
}

// adds digit to the back of the second value
// and then prints the value
void addDigitToTheSecondValue(uint8_t val)
{
	secondValue = secondValue * 10 + (int) val;
	secondValue %= 100;
	print(secondValue);
}

void process(unsigned char operator)
{
	switch (operator) {
		case 'C':
			calculatedValue = 0;
			secondValue = 0;
			stackedOperator = '=';
			print(calculatedValue);
			break;
		
		case '=':
			calculatedValue = secondValue;
			secondValue = 0;
			calculatedValue %= 100;
			print(calculatedValue);
			break;
			
		case '+':
			calculatedValue += secondValue;
			secondValue = 0;
			calculatedValue %= 100;
			print(calculatedValue);
			break;
			
		case '-':
			calculatedValue -= secondValue;
			secondValue = 0;
			if (calculatedValue < 0) calculatedValue = -calculatedValue;
			calculatedValue %= 100;
			print(calculatedValue);
			break;
			
		case '*':
			calculatedValue *= secondValue;
			secondValue = 0;
			calculatedValue %= 100;
			print(calculatedValue);
			break;
		
		case '/':
			calculatedValue /= secondValue;
			secondValue = 0;
			calculatedValue %= 100;
			print(calculatedValue);
			break;
	}
}

void print(int val)
{
	uint8_t firstDigit = (uint8_t) (val / 10);
	uint8_t secondDigit = (uint8_t) (val % 10);
	First7SegmentDisplayPortControl = display[firstDigit];
	Second7SegmentDisplayPortControl = display[secondDigit];
	Second7SegmentDisplayPortControl |= (display[firstDigit] & (1 << 6)) << 1;
}
