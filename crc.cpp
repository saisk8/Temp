#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int crc(char input[], char output[], const char gp[], int mode) {
  unsigned int j, k;
  strcpy(output, input);
  if (mode) {
    for (j = 1; j < strlen(gp); j++)
      strcat(output, "0");
  }
  for (j = 0; j < strlen(input); j++)
    if (output[j] == '1')
      for (k = 0; k < strlen(gp); k++) {
        if (output[j + k] == gp[k])
          output[j + k] = '0';
        else
          output[j + k] = '1';
      }
  cout << "The checksum calculated is: " << output;
  for (j = 0; j < strlen(output); j++)
    if (output[j] == '1')
      return 1;
  return 0;
}

int main() {
  char input[50], output[50], receive[50];

  // 16-bit CRC-CCITT specification G(x): x^16+x^12+x^5+1
  const char gp[18] = "10001000000100001";

  cout << "Enter the input message in binary: ";
  cin >> input;

  crc(input, output, gp, 1);
  cout << "\nThe transmitted message is: " << input << output + strlen(input);

  cout << "\n\nEnter the recevied message in binary: ";
  cin >> receive;

  if (!crc(receive, output, gp, 0))
    cout << "\nNo error in data\n";
  else
    cout << "\nError in data transmission has occurred\n";

  return 0;
}