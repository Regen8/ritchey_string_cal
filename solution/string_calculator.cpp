#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    switch(digit){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            throw std::invalid_argument("You suck.");
    }
    return -1;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    switch(decimal){
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return '2';
        case 3:
            return '3';
        case 4:
            return '4';
        case 5:
            return '5';
        case 6:
            return '6';
        case 7:
            return '7';
        case 8:
            return '8';
        case 9:
            return '9';
        default:
            throw std::invalid_argument("You suck.");
    }
    return '\0';
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    string trimmed = "";
    bool leading = true;
    for(int i = 0; i < num.size(); i++){
        if( (i == 0) && (num.at(0) == '-')){
            trimmed += num.at(i);
        }
        else if( (num.at(i) == '0') && leading){
            continue;
        }
        else{
            trimmed += num.at(i);
            leading = false;
        }
    }
    if(trimmed.size() == 0 || (trimmed.size() == 1 && trimmed.at(0) == '-')){
        return "0";
    }
    return trimmed;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    string res_string = "";
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);
    const int MAX_NUM_DIGITS = 1000;
    char res[MAX_NUM_DIGITS];
    for(int i = 0; i < MAX_NUM_DIGITS; i++){
        res[i] = '0';
    }

    bool negatives = false;
    int min_digits = (lhs.size() < rhs.size()) ? lhs.size() : rhs.size();
    int max_digits = (lhs.size() > rhs.size()) ? lhs.size() : rhs.size();
    if(lhs.at(0) == '-' && rhs.at(0) == '-'){
        min_digits -= 1;
        max_digits -= 1;
        negatives = true;
    }

    int place_count = 0;
    int add_place_result = 0;
    bool previous_carried = false;

    for(int i = 0; i < min_digits; i++){
        add_place_result = digit_to_decimal(lhs.at(lhs.size()-1-place_count)) + digit_to_decimal(rhs.at(rhs.size()-1-place_count));
        if(previous_carried){
            add_place_result += 1;
        }
        if(add_place_result > 9){
            previous_carried =  true;
            add_place_result -= 10;
        }
        else {
            previous_carried = false;
        }
        //cout << "added place result: " << add_place_result << endl;
        res[MAX_NUM_DIGITS - 1 - place_count] = decimal_to_digit(add_place_result);
        place_count++;
    }

    string longer_side = (lhs.size() > rhs.size()) ? lhs : rhs;
    for(int i = place_count; i < max_digits; i++){
        add_place_result = digit_to_decimal(longer_side.at(longer_side.size()-1-place_count));
        if(previous_carried){
            add_place_result += 1;
        }
        if(add_place_result > 9){
            previous_carried = true;
            add_place_result -= 10;
        }else{
            previous_carried = false;
        }
        res[MAX_NUM_DIGITS - 1 - place_count] = decimal_to_digit(add_place_result);
        place_count++;
    }

    if(previous_carried){
         res[MAX_NUM_DIGITS - 1 - place_count] = '1';
         place_count++;
    }
    if(negatives){
        res[MAX_NUM_DIGITS - 1 - place_count] = '-';
    }


    /*
    cout << "Calculated Res Solution: " << endl;
    for(int i = 0; i < MAX_NUM_DIGITS; i++){
        cout << res[i];
    }
    cout << endl;
    */
    
    for(int i = 0; i < MAX_NUM_DIGITS; i++){
        res_string += res[i];
    }
    res_string = trim_leading_zeros(res_string);
    
   //cout << "Calculated Res String" << res_string << endl;

    return res_string;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    lhs = trim_leading_zeros(lhs);
    rhs = trim_leading_zeros(rhs);

    int num_negatives = 0;
    if(lhs.at(0) == '-'){
        num_negatives++;
        lhs = lhs.substr(1);
    }
    if(rhs.at(0) == '-'){
        num_negatives++;
        rhs = rhs.substr(1);
    }
    
    string count = "0";
    while(true){}

    return "";
}
