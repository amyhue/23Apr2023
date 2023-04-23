#include <iostream>
#include <string>
using namespace std;

void drunkVigenere() {
	string encrypted, key;
	string decrypted = "";

	cin >> encrypted >> key;

	for (int i = 0; i < encrypted.size(); i++) {
		int shift = int(key[i]) - int('A');

		int decryptLetter;
		if (i % 2 == 0) {
			if (int(encrypted[i]) - shift >= int('A'))
				decryptLetter = int(encrypted[i]) - shift;
			else {
				int newShift = shift - (encrypted[i] - int('A'));
				decryptLetter = int('Z') - newShift + 1;
			}
		}
		else {

			if(int(encrypted[i]) + shift <= int('Z'))
				decryptLetter = int(encrypted[i]) + shift;
			else {
				int newShift = shift - (int('Z') - encrypted[i]);
				decryptLetter = int('A') + newShift - 1;
			}
		}

		decrypted += char(decryptLetter);

	}

	cout << decrypted;
}