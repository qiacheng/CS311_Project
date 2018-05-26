#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//prototypes
bool check_floating_string(string &inputStr);
bool initialSignState(char strArray[], int strLength, int strPosition);
bool dotStateAfterInitialSign(char strArray[], int strLength, int strPosition);
bool initialState(char strArray[], int strLength, int strPosition);
bool q1State(char strArray[], int strLength, int strPosition);
bool q2State(char strArray[], int strLength, int strPosition);
bool q3State(char strArray[], int strLength, int strPosition);
bool dotState(char strArray[], int strLength, int strPosition);
bool eState(char strArray[], int strLength, int strPosition);
bool signStateAfterEstate(char strArray[], int strLength, int strPosition);
bool acceptState(){return true;};
bool deadState(){return false;};

int main() {
    ifstream inFile;
    inFile.open("floating.txt");
    //check if file exists

    if(!inFile){
        cout << "File not exist" << endl;
        return 0;
    }

    string inputStr;
    string result;
    while(inFile >> inputStr){
        if(check_floating_string(inputStr))
           result = "Accepted";
        else
           result = "Rejected";
       cout << setw(30) << left << inputStr << setw(15) << result << endl;
       result = "";
    }
    return 0;
}


bool check_floating_string(string &inputStr){

    int strLength = int(inputStr.length());
    bool result;
    //parse string to an array of chars
    char strArray[strLength + 1];
    strcpy(strArray, inputStr.c_str());
    //ASCII
    result = initialState(strArray, strLength, 0);
    return result;
}

//initial State
bool initialState(char strArray[], int strLength, int strPosition){
    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // 0 - 9 numbers 48-57
    if(strASCII == 43 || strASCII == 45){
        return initialSignState(strArray, strLength, strPosition + 1);
    }
    else if(strASCII == 46){
        //if current char is . , transit to dotState.
        return dotStateAfterInitialSign(strArray, strLength, strPosition + 1);
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit loop back to q1State.
        return q1State(strArray,strLength, strPosition + 1);
    }
    return false;
}

bool initialSignState(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return deadState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // 0 - 9 number 48-57
    if(strASCII == 46){
        //if current char is . transit to dotState.
        return dotStateAfterInitialSign(strArray, strLength, strPosition + 1);
    }
    if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit to 13State.
        return q1State(strArray, strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool q1State(char strArray[], int strLength, int strPosition){

    //end of string, halt and accept
    if (strPosition == strLength)
        return acceptState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // e symbol 101
    // 0 - 9 number 48-57

    if(strASCII == 46){
        //if current char is . transit to dotState.
        return dotState(strArray, strLength, strPosition + 1);
    }
    else if(strASCII == 69 || strASCII == 101){
        //if current char is E or e, transit to eState.
        return eState(strArray, strLength, strPosition + 1);
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit loop back to q1State.
        return q1State(strArray,strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool q2State(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return acceptState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // e symbol 101
    // 0 - 9 number 48-57
    if(strASCII == 69 || strASCII == 101){
        //if current char is E, transit to E state.
        return eState(strArray,strLength, strPosition + 1);
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit loop back to q2State.
        return q2State(strArray,strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool q3State(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return acceptState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // 0 - 9 number 48-57
    if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit loop back to q3State.
        return q3State(strArray,strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool dotState(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return acceptState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // e symbol 101
    // 0 - 9 number 48-57
    if(strASCII == 69 || strASCII == 101) {
        //if current char is E or e, transit to e state
        return eState(strArray, strLength, strPosition + 1);
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit to q2State.
        return q2State(strArray,strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool dotStateAfterInitialSign(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return acceptState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // e symbol 101
    // 0 - 9 number 48-57
    if(strASCII == 69 || strASCII == 101) {
        //if current char is E or e, transit to deadState
        return deadState();
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit to q1State.
        return q1State(strArray,strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool eState(char strArray[], int strLength, int strPosition){
    //end of string, halt and go dead because ends with e
    if (strPosition == strLength)
        return deadState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // 0 - 9 number 48-57
    if(strASCII == 43 || strASCII == 45){
        return signStateAfterEstate(strArray, strLength, strPosition + 1);
    }
    else if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit to q3State.
        return q3State(strArray, strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}

bool signStateAfterEstate(char strArray[], int strLength, int strPosition){
    //end of string, halt and accept
    if (strPosition == strLength)
        return deadState();

    //convert string to ASCII value
    //current ASCII value
    int strASCII= int(strArray[strPosition]);
    // ASCII value
    // + sign 43
    // - sign 45
    // . symbol 46
    // E symbol 69
    // 0 - 9 number 48-57
    if(strASCII >= 48 && strASCII <= 57){
        //if current char is a number from 0-9, transit to q3State.
        return q3State(strArray, strLength, strPosition + 1);
    }
    else{
        return deadState();
    }
}
