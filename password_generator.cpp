#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void checkPasswordQuality(bool inkUpper, bool inkLower, bool inkDigits, bool inkSpecial, int pwdLength) {
    int ratingPoints = 0;
    if (inkUpper) ratingPoints++;
    if (inkLower) ratingPoints++;
    if (inkDigits) ratingPoints++;
    if (inkSpecial) ratingPoints++;
    
    cout << "\n>>> METRIC ANALYSIS <<<" << endl;
    
    if (pwdLength < 8) {
        cout << "STATUS: FAILED [Minimum 8 characters required]" << endl;
    } else if (ratingPoints == 4) {
        cout << "STATUS: OPTIMAL [Excellent complexity]" << endl;
    } else if (ratingPoints == 3) {
        cout << "STATUS: SATISFACTORY" << endl;
    } else if (ratingPoints == 2) {
        cout << "STATUS: MODERATE" << endl;
    } else {
        cout << "STATUS: WEAK [Low diversity]" << endl;
    }
    cout << ">>>>>>>>>>>>>>>>>>>>>>>" << endl;
}

int main() {
    // Making sure the random generator stays unique using time seed
    srand(static_cast<unsigned int>(time(0)));

    // Different sets of characters
    const string alphaSmall = "abcdefghijklmnopqrstuvwxyz";
    const string alphaCapital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string numericBits = "0123456789";
    const string specialChars = "@#$&!*?%=-_+^";

    int finalLength;
    char optUpper, optLower, optDigits, optSpecial;

    cout << ">>>>SECURE CREDENTIAL SYSTEM<<<<" << endl;
    
    cout << "Enter target character count: ";
    cin >> finalLength;

    if (finalLength <= 0) {
        cout << "Execution Error: Invalid length." << endl;
        return 1;
    }

    // Interactive user prompts
    cout << "Include uppercase elements? (y/n): ";
    cin >> optUpper;
    cout << "Include lowercase elements? (y/n): ";
    cin >> optLower;
    cout << "Include numeric elements? (y/n): ";
    cin >> optDigits;
    cout << "Include symbolic elements? (y/n): ";
    cin >> optSpecial;

    // Mapping inputs to true/false variables
    bool hasCaps = (optUpper == 'y' || optUpper == 'Y');
    bool hasSmall = (optLower == 'y' || optLower == 'Y');
    bool hasNums = (optDigits == 'y' || optDigits == 'Y');
    bool hasSyms = (optSpecial == 'y' || optSpecial == 'Y');

    // Merging selected characters into a master pool
    string masterPool = "";
    if (hasCaps)  masterPool += alphaCapital;
    if (hasSmall) masterPool += alphaSmall;
    if (hasNums)  masterPool += numericBits;
    if (hasSyms)  masterPool += specialChars;

    // Fallback option if user declines everything
    if (masterPool.length() == 0) {
        cout << "\n[System Override: No selection made. Initializing default text pool.]" << endl;
        masterPool = alphaSmall;
        hasSmall = true;
    }

    // Building the random password string
    string finalPassword = "";
    for (int idx = 0; idx < finalLength; idx++) {
        int position = rand() % masterPool.length();
        finalPassword += masterPool[position];
    }

    // Final result
    cout << "\nGenerated Output: " << finalPassword << endl;
    
    // Evaluation call
    checkPasswordQuality(hasCaps, hasSmall, hasNums, hasSyms, finalLength);

    return 0;
}