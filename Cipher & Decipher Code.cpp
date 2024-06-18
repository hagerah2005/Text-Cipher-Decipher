// FCAI – Structured Programming – 2024
// Program Description: The main idea of this program is to use mathematical or logical operations to transform plaintext (readable data) into ciphertext (unreadable data) and vice versa.
// Last Modification Date: 11/03/2024
// Author1: Ayman Ahmed Abdelsamie    
// Author2: Merehan Ibrahim Elmotasem Hassan    
// Author3: Hager Ahmed Mohamed    
// Teaching Assistant: Rana Abdelkader
/*
   Who did what: Author1 --> Affine cipher
                 Author2 --> Simple substitution cipher
                 Author3 --> Morse code
*/



#include <iostream>
#include <limits>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cctype>
#include <map>
#include <sstream>
using namespace std;


// Functions declaration
int affine_cipher();
int simple_substitution_cipher();
int morse_code();


int main() {
    int choice;
    cout << "Ahlan ya user ya habibi, there are three cipher programs to encrypt or decrypt your message" << endl;
    cout << "Which cipher do you like to choose?\n 1- Affine cipher\n 2- Simple substitution cipher\n 3- Morse code\n 4- End" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " INVALID INPUT ya user ya habibi\n Which cipher do you like to choose?\n 1- Affine cipher\n 2- Simple substitution cipher\n 3- Morse code\n 4- End" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    if (choice == 1) {
        affine_cipher();
    }
    else if (choice == 2) {
        simple_substitution_cipher();
    }
    else if (choice == 3) {
        morse_code();
    }
    else if (choice == 4) {
        return 0;
    }
    return 0;
}



// Start of Affine cipher
int affine_cipher() {

// Unordered map to store every character and its value
    unordered_map<char , int>affine_dictionary;
    affine_dictionary['A'] = 0;
    affine_dictionary['B'] = 1;
    affine_dictionary['C'] = 2;
    affine_dictionary['D'] = 3;
    affine_dictionary['E'] = 4;
    affine_dictionary['F'] = 5;
    affine_dictionary['G'] = 6;
    affine_dictionary['H'] = 7;
    affine_dictionary['I'] = 8;
    affine_dictionary['J'] = 9;
    affine_dictionary['K'] = 10;
    affine_dictionary['L'] = 11;
    affine_dictionary['M'] = 12;
    affine_dictionary['N'] = 13;
    affine_dictionary['O'] = 14;
    affine_dictionary['P'] = 15;
    affine_dictionary['Q'] = 16;
    affine_dictionary['R'] = 17;
    affine_dictionary['S'] = 18;
    affine_dictionary['T'] = 19;
    affine_dictionary['U'] = 20;
    affine_dictionary['V'] = 21;
    affine_dictionary['W'] = 22;
    affine_dictionary['X'] = 23;
    affine_dictionary['Y'] = 24;
    affine_dictionary['Z'] = 25;

// Reversed one
    unordered_map<int , char>reversed_affine_dictionary;
    reversed_affine_dictionary[0] = 'A';
    reversed_affine_dictionary[1] = 'B';
    reversed_affine_dictionary[2] = 'C';
    reversed_affine_dictionary[3] = 'D';
    reversed_affine_dictionary[4] = 'E';
    reversed_affine_dictionary[5] = 'F';
    reversed_affine_dictionary[6] = 'G';
    reversed_affine_dictionary[7] = 'H';
    reversed_affine_dictionary[8] = 'I';
    reversed_affine_dictionary[9] = 'J';
    reversed_affine_dictionary[10] = 'K';
    reversed_affine_dictionary[11] = 'L';
    reversed_affine_dictionary[12] = 'M';
    reversed_affine_dictionary[13] = 'N';
    reversed_affine_dictionary[14] = 'O';
    reversed_affine_dictionary[15] = 'P';
    reversed_affine_dictionary[16] = 'Q';
    reversed_affine_dictionary[17] = 'R';
    reversed_affine_dictionary[18] = 'S';
    reversed_affine_dictionary[19] = 'T';
    reversed_affine_dictionary[20] = 'U';
    reversed_affine_dictionary[21] = 'V';
    reversed_affine_dictionary[22] = 'W';
    reversed_affine_dictionary[23] = 'X';
    reversed_affine_dictionary[24] = 'Y';
    reversed_affine_dictionary[25] = 'Z';



    // Variables
    int a, b, c;
    int ch_value;
    int ci_value;
    int de_value;
    string result;
    string message;
    int choice = -1;

    while (choice !=3) {

        // Program starts
        cout << "WELCOME TO AFFINE CIPHER PROGRAM" << endl; // Welcome message
        cout << "What do you like to do today?\n 1- Cipher a message\n 2- Decipher a message\n 3- Return to main menu"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout
                    << "INVALID INPUT\n What do you like to do today?\n 1- Cipher a message\n 2- Decipher a message\n 3- Return to main menu"
                    << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }

        if (choice == 1) {

            cout << "The encryption equation is (ax + b) mod 26 where x is the numeric value of the letter to cipher"
                 << endl;
            cout << "Please note that any characters except ALPHABETIC will be appended as it is" << endl;

            cout << "Enter the value for 'a' (Positive Integer): ";
            cin >> a;
            while (cin.fail() || a <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n Enter the value for 'a' (Positive Integer): ";
                cin >> a;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the value for 'b' (Positive Integer): ";
            cin >> b;
            while (cin.fail() || b <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n Enter the value for 'b' (Positive Integer): ";
                cin >> b;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the message you want to cipher it: ";
            getline(cin, message);
            transform(message.begin(), message.end(), message.begin(), ::toupper);

            for (char ch: message) {
                auto ch_finder = affine_dictionary.find(ch);
                if (isalpha(ch)) {
                    ch_value = ch_finder->second;
                    ci_value = (a * ch_value + b) % 26;
                    auto encrypted_ch = reversed_affine_dictionary.find(ci_value);
                    result.push_back(encrypted_ch->second);
                } else {
                    result.push_back(ch);
                }
            }
            cout << "Original message: " << message << endl;
            cout << "Encrypted message: " << result << endl;
        }

        if (choice == 2) {
            cout
                    << "The decryption equation is (c(y - b)) mod 26 where y is the numeric value of the letter to decipher and ((a * c) % 26) must = 1"
                    << endl;
            cout << "Please note that Any characters except ALPHABETIC will be appended as it is" << endl;

            cout << "Enter the value for 'a' (Positive Integer): ";
            cin >> a;
            while (cin.fail() || a <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n Enter the value for 'a' (Positive Integer): ";
                cin >> a;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the value for 'b' (Positive Integer): ";
            cin >> b;
            while (cin.fail() || b <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n Enter the value for 'b' (Positive Integer): ";
                cin >> b;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter the value for 'c' (Positive Integer): ";
            cin >> c;
            while (cin.fail() || c <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "INVALID INPUT\n Enter the value for 'c' (Positive Integer): ";
                cin >> c;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');


            // Check the condition of the decryption equation
            while ((a * c) % 26 != 1) {
                cout << "Sorry but you have to enter the values again and make sure that ((a * c) % 26) = 1" << endl;

                cout << "Enter the value for 'a' (Positive Integer): ";
                cin >> a;
                while (cin.fail() || a <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID INPUT\n Enter the value for 'a' (Positive Integer): ";
                    cin >> a;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter the value for 'b' (Positive Integer): ";
                cin >> b;
                while (cin.fail() || b <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID INPUT\n Enter the value for 'b' (Positive Integer): ";
                    cin >> b;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter the value for 'c' (Positive Integer): ";
                cin >> c;
                while (cin.fail() || c <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID INPUT\n Enter the value for 'c' (Positive Integer): ";
                    cin >> c;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter the message you want to decipher it: ";
            getline(cin, message); // Getting the decrypted message
            transform(message.begin(), message.end(), message.begin(), ::toupper); // Make all characters UPPERCASE

            for (char ch: message) {
                auto ch_finder = affine_dictionary.find(ch);
                if (isalpha(ch)) {
                    ch_value = ch_finder->second;
                    de_value = (c * (ch_value - b)) % 26;
                    while (de_value < 0) {
                        de_value += 26;
                    }
                    auto decrypted_ch = reversed_affine_dictionary.find(de_value);
                    result.push_back(decrypted_ch->second);
                } else {
                    result.push_back(ch);
                }
            }
            cout << "Decrypted message: " << message << endl;
            cout << "Original message: " << result << endl;
        }

        if (choice == 3) {
            cout << "Thank you for using affine cipher!" << endl;
            main();
        }
    }

    return 0;
}
// End of Affine cipher









// Start of Simple substitution cipher
int simple_substitution_cipher() {

    string key, plain_text, cipher_alphabet, plain_cipher, cipher_text;
    int choice = -1;
    while (choice != 3) {
        cout << "WELCOME TO SIMPLE SUBSTITUTION CIPHER PROGRAM" << endl; // Welcome message
        // Get user's choice
        cout << "What do you like to do today?\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Return to main menu\n";
        cout << "Choose a number:";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT" << endl;
            cout << "What do you like to do today?\n";
            cout << "1. Encrypt\n";
            cout << "2. Decrypt\n";
            cout << "3. Return to main menu\n";
            cout << "Choose a number:";
            cin >> choice;
        }

        if (choice == 1) {
            cout << "Please enter your key (five different letters): ";
            cin >> key;
            // Check if the key is all uppercase
            bool is_uppercase_key = (key.begin(), key.end(), ::isupper);
            // If the key is all uppercase, convert it to lowercase
            if (is_uppercase_key) {
                transform(key.begin(), key.end(), key.begin(), ::tolower);
            }

            // Loop until a valid key is entered
            while (true) {

                // Check if the key is of length 5 and contains only alphabetic characters
                if (key.size() != 5 || !all_of(key.begin(), key.end(), ::isalpha)) {
                    cout << "try again. Please enter five different letters:";
                    cin >> key;
                    continue; // Restart the loop to prompt again for input
                }

                // Check if each character is unique
                bool uniqueChars = true;
                for (int i = 0; i < key.size(); ++i) {
                    for (int j = i + 1; j < key.size(); ++j) {
                        if (key[i] == key[j]) {
                            uniqueChars = false;
                            break;
                        }
                    }
                    if (!uniqueChars) break; // Exit the loop if duplicate found
                }

                // If any characters are not unique, prompt for input again
                if (!uniqueChars) {
                    cout << "try again. Please enter five different letters:" << endl;
                    cin >> key;
                    continue; // Restart the loop to prompt again for input
                }

                // If we reached here, the input is valid, so break out of the loop
                break;
            }


            string plain_alphabet = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < key.size(); ++i) {
                plain_alphabet.erase(remove(plain_alphabet.begin(), plain_alphabet.end(), key[i]),
                                     plain_alphabet.end());
            }
            cipher_alphabet = plain_alphabet.insert(0, key);
            cout << "Please enter your plain text: ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, plain_text);
            for (int i = 0; i < plain_text.size(); ++i) {
                if (isspace(plain_text[i])) {
                    plain_text[i] = ' '; // Keep spaces unchanged
                } else if (isdigit(plain_text[i])) {
                    // Keep digits unchanged
                } else if (ispunct(plain_text[i])) {
                    // Keep punctuation unchanged
                } else if (plain_text[i] == 'a' || plain_text[i] == 'A') {
                    plain_text[i] = cipher_alphabet[0];
                } else if (plain_text[i] == 'b' || plain_text[i] == 'B') {
                    plain_text[i] = cipher_alphabet[1];
                } else if (plain_text[i] == 'c' || plain_text[i] == 'C') {
                    plain_text[i] = cipher_alphabet[2];
                } else if (plain_text[i] == 'd' || plain_text[i] == 'D') {
                    plain_text[i] = cipher_alphabet[3];
                } else if (plain_text[i] == 'e' || plain_text[i] == 'E') {
                    plain_text[i] = cipher_alphabet[4];
                } else if (plain_text[i] == 'f' || plain_text[i] == 'F') {
                    plain_text[i] = cipher_alphabet[5];
                } else if (plain_text[i] == 'g' || plain_text[i] == 'G') {
                    plain_text[i] = cipher_alphabet[6];
                } else if (plain_text[i] == 'h' || plain_text[i] == 'H') {
                    plain_text[i] = cipher_alphabet[7];
                } else if (plain_text[i] == 'i' || plain_text[i] == 'I') {
                    plain_text[i] = cipher_alphabet[8];
                } else if (plain_text[i] == 'j' || plain_text[i] == 'J') {
                    plain_text[i] = cipher_alphabet[9];
                } else if (plain_text[i] == 'k' || plain_text[i] == 'K') {
                    plain_text[i] = cipher_alphabet[10];
                } else if (plain_text[i] == 'l' || plain_text[i] == 'L') {
                    plain_text[i] = cipher_alphabet[11];
                } else if (plain_text[i] == 'm' || plain_text[i] == 'M') {
                    plain_text[i] = cipher_alphabet[12];
                } else if (plain_text[i] == 'n' || plain_text[i] == 'N') {
                    plain_text[i] = cipher_alphabet[13];
                } else if (plain_text[i] == 'o' || plain_text[i] == 'O') {
                    plain_text[i] = cipher_alphabet[14];
                } else if (plain_text[i] == 'p' || plain_text[i] == 'P') {
                    plain_text[i] = cipher_alphabet[15];
                } else if (plain_text[i] == 'q' || plain_text[i] == 'Q') {
                    plain_text[i] = cipher_alphabet[16];
                } else if (plain_text[i] == 'r' || plain_text[i] == 'R') {
                    plain_text[i] = cipher_alphabet[17];
                } else if (plain_text[i] == 's' || plain_text[i] == 'S') {
                    plain_text[i] = cipher_alphabet[18];
                } else if (plain_text[i] == 't' || plain_text[i] == 'T') {
                    plain_text[i] = cipher_alphabet[19];
                } else if (plain_text[i] == 'u' || plain_text[i] == 'U') {
                    plain_text[i] = cipher_alphabet[20];
                } else if (plain_text[i] == 'v' || plain_text[i] == 'V') {
                    plain_text[i] = cipher_alphabet[21];
                } else if (plain_text[i] == 'w' || plain_text[i] == 'W') {
                    plain_text[i] = cipher_alphabet[22];
                } else if (plain_text[i] == 'x' || plain_text[i] == 'X') {
                    plain_text[i] = cipher_alphabet[23];
                } else if (plain_text[i] == 'y' || plain_text[i] == 'Y') {
                    plain_text[i] = cipher_alphabet[24];
                } else if (plain_text[i] == 'z' || plain_text[i] == 'Z') {
                    plain_text[i] = cipher_alphabet[25];
                }
            }
            cout << "Encrypted text: " << plain_text << endl;
        }
        else if (choice == 2) {
            cout << "Please enter your key (five different letters):";
            cin >> key;
            // Check if the key is all uppercase
            bool is_uppercase_key = (key.begin(), key.end(), ::isupper);
            // If the key is all uppercase, convert it to lowercase
            if (is_uppercase_key) {
                transform(key.begin(), key.end(), key.begin(), ::tolower);
            }


            // Loop until a valid key is entered
            while (true) {

                // Check if the key is of length 5 and contains only alphabetic characters
                if (key.size() != 5 || !all_of(key.begin(), key.end(), ::isalpha)) {
                    cout << "try again. Please enter five different letters:";
                    cin >> key;
                    continue; // Restart the loop to prompt again for input
                }

                // Check if each character is unique
                bool uniqueChars = true;
                for (int i = 0; i < key.size(); ++i) {
                    for (int j = i + 1; j < key.size(); ++j) {
                        if (key[i] == key[j]) {
                            uniqueChars = false;
                            break;
                        }
                    }
                    if (!uniqueChars) break; // Exit the loop if duplicate found
                }

                // If any characters are not unique, prompt for input again
                if (!uniqueChars) {
                    cout << "try again. Please enter five different letters:" << endl;
                    cin >> key;
                    continue; // Restart the loop to prompt again for input
                }

                // If we reached here, the input is valid, so break out of the loop
                break;
            }

            string plain_alphabet = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < key.size(); ++i) {
                plain_alphabet.erase(remove(plain_alphabet.begin(), plain_alphabet.end(), key[i]),
                                     plain_alphabet.end());
            }
            cipher_alphabet = plain_alphabet.insert(0, key);
            cout << "Please enter your cipher text: ";
            cin.ignore(); // Ignore the newline character left in the input buffer
            getline(cin, cipher_text);

            for (int i = 0; i < cipher_text.size(); ++i) {
                if (isspace(cipher_text[i])) {
                    cipher_text[i] = ' '; // Keep spaces unchanged
                } else if (isdigit(cipher_text[i])) {
                    // Keep digits unchanged
                } else if (ispunct(cipher_text[i])) {
                    // Keep punctuation unchanged
                } else if (cipher_text[i] == cipher_alphabet[0]) {
                    cipher_text[i] = 'a';
                } else if (cipher_text[i] == cipher_alphabet[1]) {
                    cipher_text[i] = 'b';
                } else if (cipher_text[i] == cipher_alphabet[2]) {
                    cipher_text[i] = 'c';
                } else if (cipher_text[i] == cipher_alphabet[3]) {
                    cipher_text[i] = 'd';
                } else if (cipher_text[i] == cipher_alphabet[4]) {
                    cipher_text[i] = 'e';
                } else if (cipher_text[i] == cipher_alphabet[5]) {
                    cipher_text[i] = 'f';
                } else if (cipher_text[i] == cipher_alphabet[6]) {
                    cipher_text[i] = 'g';
                } else if (cipher_text[i] == cipher_alphabet[7]) {
                    cipher_text[i] = 'h';
                } else if (cipher_text[i] == cipher_alphabet[8]) {
                    cipher_text[i] = 'i';
                } else if (cipher_text[i] == cipher_alphabet[9]) {
                    cipher_text[i] = 'j';
                } else if (cipher_text[i] == cipher_alphabet[10]) {
                    cipher_text[i] = 'k';
                } else if (cipher_text[i] == cipher_alphabet[11]) {
                    cipher_text[i] = 'l';
                } else if (cipher_text[i] == cipher_alphabet[12]) {
                    cipher_text[i] = 'm';
                } else if (cipher_text[i] == cipher_alphabet[13]) {
                    cipher_text[i] = 'n';
                } else if (cipher_text[i] == cipher_alphabet[14]) {
                    cipher_text[i] = 'o';
                } else if (cipher_text[i] == cipher_alphabet[15]) {
                    cipher_text[i] = 'p';
                } else if (cipher_text[i] == cipher_alphabet[16]) {
                    cipher_text[i] = 'q';
                } else if (cipher_text[i] == cipher_alphabet[17]) {
                    cipher_text[i] = 'r';
                } else if (cipher_text[i] == cipher_alphabet[18]) {
                    cipher_text[i] = 's';
                } else if (cipher_text[i] == cipher_alphabet[19]) {
                    cipher_text[i] = 't';
                } else if (cipher_text[i] == cipher_alphabet[20]) {
                    cipher_text[i] = 'u';
                } else if (cipher_text[i] == cipher_alphabet[21]) {
                    cipher_text[i] = 'v';
                } else if (cipher_text[i] == cipher_alphabet[22]) {
                    cipher_text[i] = 'w';
                } else if (cipher_text[i] == cipher_alphabet[23]) {
                    cipher_text[i] = 'x';
                } else if (cipher_text[i] == cipher_alphabet[24]) {
                    cipher_text[i] = 'y';
                } else if (cipher_text[i] == cipher_alphabet[25]) {
                    cipher_text[i] = 'z';
                }
            }
            cout << "Decrypted text: " << cipher_text << endl;
        } else if (choice == 3) {
            cout << "Thank you for using simple substitution cipher!" << endl;
            main();
        }
    }
    return 0;
}
// End of simple substitution cipher









// Start of Morse code
// Function to convert text to Morse code
string text_to_morse(const string & text) {
    // Morse code mapping
    map<char, string> morse_code_map
            { {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},
            {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
            {'i', ".."},
            {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"},
            {'n', "-."}, {'o', "---"}, {'p', ".--."}, {'q', "--.-"},
            {'r', ".-."},
            {'s', "..."}, {'t', "-"}, {'u', "..-"}, {'v', "...-"},
            {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."},
            {'1', ".----"},
            {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},          {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
            {'0', "-----"}, {' ', " "}, {'.', ".-.-.-"}, {',', "--..--"},            {'?', "..--.."}, {'\'', ".----."}, {'!', "-.-.--"},
            {'/', "-..-."},
            {'(', "-.--."}, {')', "-.--.-"}, {'&', ".-..."},
            {':', "---..."}, {';', "-.-.-."}, {'=', "-...-"},
            {'+', ".-.-."}, {'-', "-....-"},
            {'_', "..--.-"}, {'\"', ".-..-."}, {'$', "...-..-"},
            {'@', ".--.-."} };

    stringstream result;
    // Loop through each character in the text
    for (char c : text) {
        if (c == ' ') {
            result << "   "; // Add three spaces for word separation
        }
            //check if the character is in the map
        else if (morse_code_map.find(tolower(c)) != morse_code_map.end()) {
            result << morse_code_map[tolower(c)] << " ";
        }
        else {
            cout << "Invalid text: " << c << endl;
            return ""; // Stop processing and return an empty string
        }
    }

    return result.str(); // Return the Morse code as a string
}


// Function to convert Morse code to text
string morse_to_text(const string & morse_code) {
    // Reverse Morse code mapping
    map<string, char > morse_to_text_map
            { {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},
            {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'},
            {"..", 'i'},
            {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'}, {"--", 'm'},
            {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'}, {"--.-", 'q'},
            {".-.", 'r'},
            {"...", 's'}, {"-", 't'}, {"..-", 'u'}, {"...-", 'v'},
            {".--", 'w'}, {"-..-", 'x'}, {"-.--", 'y'}, {"--..", 'z'},
            {".----", '1'}, {"..---", '2'}, {"...--", '3'}, {"....-", '4'},          {".....", '5'}, {"-....", '6'}, {"--...", '7'}, {"---..", '8'},
            {"----.", '9'}, {"-----", '0'},
            {" ", ' '}, {".-.-.-", '.'}, {"--..--", ','}, {"..--..", '?'},           {".----.", '\''}, {"-.-.--", '!'}, {"-..-.", '/'},
            {"-.--.", '('},
            {"-.--.-", ')'}, {".-...", '&'}, {"---...", ':'},
            {"-.-.-.", ';'}, {"-...-", '='}, {".-.-.", '+'},
            {"-....-", '-'}, {"..--.-", '_'},
            {".-..-.", '\"'}, {"...-..-", '$'}, {".--.-.", '@'} };

    // Split the Morse code into words
    stringstream result;
    stringstream morse_stream(morse_code);
    string morse_symbol;

    // Loop through each morse symbol in the Morse code
    while (morse_stream >> morse_symbol) {
        if (morse_to_text_map.find(morse_symbol) != morse_to_text_map.end()) { //check if the morse symbol is in the map
            result << morse_to_text_map[morse_symbol];
        }
        else {
            cout << "Invalid Morse code " << endl;
            return ""; // Stop processing and return an empty string
        }
    }

    return result.str();
}

// Morse Code function
int morse_code() {
    cout << "WELCOME TO MORSE CODE TRANSLATOR" << endl;

    int choice = -1;

    while (choice != 3) {

        // Display menu
        cout << "What would you like to do?" << endl;
        cout << "" << endl;
        cout << "1- Cipher text to Morse code" << endl;
        cout << "2- Decipher Morse code to text" << endl;
        cout << "3- Return to main menu \n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT" << endl;
            cout << "What would you like to do?" << endl;
            cout << "" << endl;
            cout << "1- Cipher text to Morse code" << endl;
            cout << "2- Decipher Morse code to text" << endl;
            cout << "3- Return to main menu \n" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }

        // Switch based on user choice
        switch (choice) {
            // Case 1: Cipher text to Morse code
            case 1:
            {
                cin.ignore(); // Ignore previous newline character
                string text;
                bool valid = false;

                while (!valid){
                    cout << "Enter text to convert to Morse code:" << endl;
                    getline(cin, text); // Read all text from user

                    string morse_code = text_to_morse(text);

                    if (!morse_code.empty())
                    {
                        cout << "Morse code of the text is: " << morse_code << endl;
                        valid = true;
                    }
                    else
                    {
                        cout << "plese enter a valid text" << endl;
                    }
                }

                break;
            }

                // Case 2: Decipher Morse code to text
            case 2:
            {
                cin.ignore(); // Ignore previous newline character
                string morse_code;
                bool valid = false;

                while (!valid){
                    cout << "Enter Morse code to convert to text: " << endl;
                    getline(cin, morse_code);

                    string text = morse_to_text(morse_code);

                    if (!text.empty())
                    {
                        cout << "Text of the Morse code is: " << text << endl;
                        valid = true;
                    }
                    else
                    {
                        cout << "plese enter a valid Morse code" << endl;
                    }
                }
                break;
            }

                // Case 3: Return to main menu
            case 3: {
                cout << "Thank you for using Morse code translator!" << endl;
                main();
            }

                // Default case: Invalid choice
            default: {
                morse_code();
                break;
            }
        }
    }

    return 0;
}