// Модель STM32.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <cmath>

short
q1[4] = { 100, -200, 300, -400 },
q2[4] = { 2,  3, 4,  5 };

short* q3;



short* Q_add(short* q1, short* q2) {
    short* q = new short[4];
    for (char i = 0; i < 4; i++) {
        q[i] = q1[i] + q2[i];
    }
    return q;
}

short* Q_sub(short* q1, short* q2) {
    short* q = new short[4];
    for (char i = 0; i < 4; i++) {
        q[i] = q1[i] + q2[i];
    }
    return q;
}

short* Q_mul(short* q1, short* q2) {
    short* q = new short[4];
    q[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
    q[1] = q1[0] * q2[1] + q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
    q[2] = q1[0] * q2[2] - q1[1] * q2[3] + q1[2] * q2[0] + q1[3] * q2[1];
    q[3] = q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1] + q1[3] * q2[0];
    return q;
}

short* Q_div(short* q1, short* q2) {
    short* q = new short[4];
    short m = q2[0] * q2[0] + q2[1] * q2[1] + q2[2] * q2[2] + q2[3] * q2[3];
    q[0] = q1[0] / m;
    q[1] = -q1[1] / m;
    q[2] = -q1[2] / m;
    q[3] = -q1[3] / m;
    return q;
}

void Q_print(short* q) {
    std::cout << q[0] << " + " << q[1] << "i + " << q[2] << "j + " << q[3] << "k\n";
}

class LED7 {
public:
    int* A, * B, * C, * D, * E, * F, * G;
    LED7(int* A, int* B, int* C, int* D, int* E, int* F, int* G) {
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->E = E;
        this->F = F;
        this->G = G;
    }
    LED7(int* D) {
        this->A = &D[0];
        this->B = &D[1];
        this->C = &D[2];
        this->D = &D[3];
        this->E = &D[4];
        this->F = &D[5];
        this->G = &D[6];
    }
    void draw(wchar_t* screen, int screenWidth, int screenHeight, int shiftX, int shiftY) {
        if (*this->A) {
            screen[screenWidth * shiftY + shiftX + 1] = 9604;
            screen[screenWidth * shiftY + shiftX + 2] = 9604;
            screen[screenWidth * shiftY + shiftX + 3] = 9604;
            screen[screenWidth * shiftY + shiftX + 4] = 9604;
        } else {
            screen[screenWidth * shiftY + shiftX + 1] = ' ';
            screen[screenWidth * shiftY + shiftX + 2] = ' ';
            screen[screenWidth * shiftY + shiftX + 3] = ' ';
            screen[screenWidth * shiftY + shiftX + 4] = ' ';
        }
        if (*this->B) {
            screen[screenWidth * (shiftY + 1) + shiftX + 5] = 9612;
            screen[screenWidth * (shiftY + 2) + shiftX + 5] = 9612;
        } else {
            screen[screenWidth * (shiftY + 1) + shiftX + 5] = ' ';
            screen[screenWidth * (shiftY + 2) + shiftX + 5] = ' ';
        }
        if (*this->C) {
            screen[screenWidth * (shiftY + 4) + shiftX + 5] = 9612;
            screen[screenWidth * (shiftY + 5) + shiftX + 5] = 9612;
        } else {
            screen[screenWidth * (shiftY + 4) + shiftX + 5] = ' ';
            screen[screenWidth * (shiftY + 5) + shiftX + 5] = ' ';
        }
        if (*this->D) {
            screen[screenWidth * (shiftY + 6) + shiftX + 1] = 9600;
            screen[screenWidth * (shiftY + 6) + shiftX + 2] = 9600;
            screen[screenWidth * (shiftY + 6) + shiftX + 3] = 9600;
            screen[screenWidth * (shiftY + 6) + shiftX + 4] = 9600;
        } else {
            screen[screenWidth * (shiftY + 6) + shiftX + 1] = ' ';
            screen[screenWidth * (shiftY + 6) + shiftX + 2] = ' ';
            screen[screenWidth * (shiftY + 6) + shiftX + 3] = ' ';
            screen[screenWidth * (shiftY + 6) + shiftX + 4] = ' ';
        }
        if (*this->E) {
            screen[screenWidth * (shiftY + 4) + shiftX] = 9616;
            screen[screenWidth * (shiftY + 5) + shiftX] = 9616;
        } else {
            screen[screenWidth * (shiftY + 4) + shiftX] = ' ';
            screen[screenWidth * (shiftY + 5) + shiftX] = ' ';
        }
        if (*this->F) {
            screen[screenWidth * (shiftY + 1) + shiftX] = 9616;
            screen[screenWidth * (shiftY + 2) + shiftX] = 9616;
        } else {
            screen[screenWidth * (shiftY + 1) + shiftX] = ' ';
            screen[screenWidth * (shiftY + 2) + shiftX] = ' ';
        }
        if (*this->G) {
            screen[screenWidth * (shiftY + 3) + shiftX + 1] = 9608;
            screen[screenWidth * (shiftY + 3) + shiftX + 2] = 9608;
            screen[screenWidth * (shiftY + 3) + shiftX + 3] = 9608;
            screen[screenWidth * (shiftY + 3) + shiftX + 4] = 9608;
        } else {
            screen[screenWidth * (shiftY + 3) + shiftX + 1] = ' ';
            screen[screenWidth * (shiftY + 3) + shiftX + 2] = ' ';
            screen[screenWidth * (shiftY + 3) + shiftX + 3] = ' ';
            screen[screenWidth * (shiftY + 3) + shiftX + 4] = ' ';
        }
    }
};

class REG7 {
public:
    int* D;
    int* CLK;
    int Q[7] = { 0,0,0,0,0,0,0 };
    REG7(int* D, int* CLK) {
        this->D = D;
        this->CLK = CLK;
    }
    void refresh() {
        if (*this->CLK) {
            for (int i = 0; i < 7; i++) {
                this->Q[i] = this->D[i];
            }
        }  
    }
    void draw(wchar_t* screen, int screenWidth, int screenHeight, int shiftX, int shiftY) {
        screen[screenWidth * (shiftY + 0) + shiftX + 0] = 9500; // ├
        screen[screenWidth * (shiftY + 2) + shiftX + 0] = 9500; // ├
        screen[screenWidth * (shiftY + 0) + shiftX + 6] = 9508; // ┤
        screen[screenWidth * (shiftY + 2) + shiftX + 6] = 9508; // ┤
        screen[screenWidth * (shiftY + 1) + shiftX + 0] = 9474; // │
        screen[screenWidth * (shiftY + 1) + shiftX + 6] = 9474; // │
        for (int i = 1; i < 6; i++) {
            screen[screenWidth * (shiftY + 0) + shiftX + i] = 9524; // ┴
            screen[screenWidth * (shiftY + 2) + shiftX + i] = 9516; // ┬
        }
        screen[screenWidth * (shiftY + 1) + shiftX + 2] = 'r';
        screen[screenWidth * (shiftY + 1) + shiftX + 3] = 'e';
        screen[screenWidth * (shiftY + 1) + shiftX + 4] = 'g';
    }
    void display() {
        std::cout << "Register:\n";
        std::cout << "D: ";
        for (int i = 0; i < 6; i++) {
            std::cout << this->D[i] << ", ";
        }
        std::cout << this->D[6] << '\n';
        std::cout << "CLK: " << *this->CLK << '\n';
        std::cout << "Q: ";
        for (int i = 0; i < 6; i++) {
            std::cout << this->Q[i] << ", ";
        }
        std::cout << this->Q[6] << '\n' << '\n';

    }
};

class DC24 {
public:
    int* INPUT;
    int* D;
    int OUTPUT[25] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0 };
    DC24(int* INPUT, int* D) {
        this->INPUT = INPUT;
        this->D = D;
    }
    void refresh() {
        int n = 0;
        for (int i = 0; i < 5; i++) {
            n += pow(2, i)*this->INPUT[i];
        }
        for (int i = 0; i < 25; i++) {
            if (i == n) {
                this->OUTPUT[i] = 1;
            }
            else {
                this->OUTPUT[i] = 0;
            }
        }
    }
    void display() {
        std::cout << "Decoder:\n";
        std::cout << "input: ";
        for (int i = 0; i < 4; i++) {
            std::cout << this->INPUT[i] << ", ";
        }
        std::cout << this->INPUT[4] << '\n';
        std::cout << "data: " << *this->D << '\n';
        std::cout << "output: ";
        for (int i = 0; i < 24; i++) {
            std::cout << this->OUTPUT[i] << ", ";
        }
        std::cout << this->OUTPUT[24] << '\n' << '\n';
    }
};

class keypad {
public:
    int
        *key_1  ,
        *key_2  ,
        *key_3  ,
        *key_4  ,
        *key_5  ,
        *key_6  ,
        *key_7  ,
        *key_8  ,
        *key_9  ,
        *key_0  ,
        *key_add,
        *key_sub,
        *key_mul,
        *key_div,
        *key_equ,
        *key_res ;
    int* INPUT;
    int OUTPUT[4] = { 0,0,0,0 };

    keypad( 
        int *key_1,
        int *key_2,
        int *key_3,
        int *key_4,
        int *key_5,
        int *key_6,
        int *key_7,
        int *key_8,
        int *key_9,
        int *key_0,
        int *key_add,
        int *key_sub,
        int *key_mul,
        int *key_div,
        int *key_equ,
        int *key_res,
        int *INPUT
        ) {
        this->key_1 = key_1;
        this->key_2 = key_2;
        this->key_3 = key_3;
        this->key_4 = key_4;
        this->key_5 = key_5;
        this->key_6 = key_6;
        this->key_7 = key_7;
        this->key_8 = key_8;
        this->key_9 = key_9;
        this->key_0 = key_0;
        this->key_add = key_add;
        this->key_sub = key_sub;
        this->key_mul = key_mul;
        this->key_div = key_div;
        this->key_equ = key_equ;
        this->key_res = key_res;
        this->INPUT = INPUT;
    }

    void refresh() {
        this->OUTPUT[0] = 0;
        this->OUTPUT[1] = 0;
        this->OUTPUT[2] = 0;
        this->OUTPUT[3] = 0;
        if (this->INPUT[0]) {
            if (*this->key_1)   this->OUTPUT[0] = 1;
            if (*this->key_4)   this->OUTPUT[1] = 1;
            if (*this->key_7)   this->OUTPUT[2] = 1;
            if (*this->key_res) this->OUTPUT[3] = 1;
        }
        if (this->INPUT[1]) {
            if (*this->key_2)   this->OUTPUT[0] = 1;
            if (*this->key_5)   this->OUTPUT[1] = 1;
            if (*this->key_8)   this->OUTPUT[2] = 1;
            if (*this->key_0)   this->OUTPUT[3] = 1;
        }
        if (this->INPUT[2]) {
            if (*this->key_3)   this->OUTPUT[0] = 1;
            if (*this->key_6)   this->OUTPUT[1] = 1;
            if (*this->key_9)   this->OUTPUT[2] = 1;
            if (*this->key_equ) this->OUTPUT[3] = 1;
        }
        if (this->INPUT[3]) {
            if (*this->key_add) this->OUTPUT[0] = 1;
            if (*this->key_sub) this->OUTPUT[1] = 1;
            if (*this->key_mul) this->OUTPUT[2] = 1;
            if (*this->key_div) this->OUTPUT[3] = 1;
        }
    }

    void draw(wchar_t* screen, int screenWidth, int screenHeight, int shiftX, int shiftY) {
        screen[screenWidth * (shiftY + 0) + shiftX + 0] = 9484; // ┌
        screen[screenWidth * (shiftY + 0) + shiftX + 1] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 2] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 3] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 4] = 9516; // ┬
        screen[screenWidth * (shiftY + 0) + shiftX + 5] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 6] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 7] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 8] = 9516; // ┬
        screen[screenWidth * (shiftY + 0) + shiftX + 9] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 10] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 11] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 12] = 9516; // ┬
        screen[screenWidth * (shiftY + 0) + shiftX + 13] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 14] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 15] = 9472; // ─
        screen[screenWidth * (shiftY + 0) + shiftX + 16] = 9488; // ┐

        screen[screenWidth * (shiftY + 1) + shiftX + 0] = 9474; // │
        if (*this->key_1) screen[screenWidth * (shiftY + 1) + shiftX + 2] = 9608; else screen[screenWidth * (shiftY + 1) + shiftX + 2] = '1'; // █
        screen[screenWidth * (shiftY + 1) + shiftX + 4] = 9474; // │
        if (*this->key_2) screen[screenWidth * (shiftY + 1) + shiftX + 6] = 9608; else screen[screenWidth * (shiftY + 1) + shiftX + 6] = '2'; // █
        screen[screenWidth * (shiftY + 1) + shiftX + 8] = 9474; // │
        if (*this->key_3) screen[screenWidth * (shiftY + 1) + shiftX + 10] = 9608; else screen[screenWidth * (shiftY + 1) + shiftX + 10] = '3'; // █
        screen[screenWidth * (shiftY + 1) + shiftX + 12] = 9474; // │
        if (*this->key_add) screen[screenWidth * (shiftY + 1) + shiftX + 14] = 9608; else screen[screenWidth * (shiftY + 1) + shiftX + 14] = '+'; // █
        screen[screenWidth * (shiftY + 1) + shiftX + 16] = 9500; // ├

        screen[screenWidth * (shiftY + 2) + shiftX + 0] = 9500; // ├
        screen[screenWidth * (shiftY + 2) + shiftX + 1] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 2] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 3] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 4] = 9532; // ┼
        screen[screenWidth * (shiftY + 2) + shiftX + 5] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 6] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 7] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 8] = 9532; // ┼
        screen[screenWidth * (shiftY + 2) + shiftX + 9] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 10] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 11] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 12] = 9532; // ┼
        screen[screenWidth * (shiftY + 2) + shiftX + 13] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 14] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 15] = 9472; // ─
        screen[screenWidth * (shiftY + 2) + shiftX + 16] = 9508; // ┤

        screen[screenWidth * (shiftY + 3) + shiftX + 0] = 9474; // │
        if (*this->key_4) screen[screenWidth * (shiftY + 3) + shiftX + 2] = 9608; else screen[screenWidth * (shiftY + 3) + shiftX + 2] = '4'; // █
        screen[screenWidth * (shiftY + 3) + shiftX + 4] = 9474; // │
        if (*this->key_5) screen[screenWidth * (shiftY + 3) + shiftX + 6] = 9608; else screen[screenWidth * (shiftY + 3) + shiftX + 6] = '5'; // █
        screen[screenWidth * (shiftY + 3) + shiftX + 8] = 9474; // │
        if (*this->key_6) screen[screenWidth * (shiftY + 3) + shiftX + 10] = 9608; else screen[screenWidth * (shiftY + 3) + shiftX + 10] = '6'; // █
        screen[screenWidth * (shiftY + 3) + shiftX + 12] = 9474; // │
        if (*this->key_sub) screen[screenWidth * (shiftY + 3) + shiftX + 14] = 9608; else screen[screenWidth * (shiftY + 3) + shiftX + 14] = '-'; // █
        screen[screenWidth * (shiftY + 3) + shiftX + 16] = 9500; // ├

        screen[screenWidth * (shiftY + 4) + shiftX + 0] = 9500; // ├
        screen[screenWidth * (shiftY + 4) + shiftX + 1] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 2] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 3] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 4] = 9532; // ┼
        screen[screenWidth * (shiftY + 4) + shiftX + 5] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 6] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 7] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 8] = 9532; // ┼
        screen[screenWidth * (shiftY + 4) + shiftX + 9] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 10] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 11] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 12] = 9532; // ┼
        screen[screenWidth * (shiftY + 4) + shiftX + 13] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 14] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 15] = 9472; // ─
        screen[screenWidth * (shiftY + 4) + shiftX + 16] = 9508; // ┤

        screen[screenWidth * (shiftY + 5) + shiftX + 0] = 9474; // │
        if (*this->key_7) screen[screenWidth * (shiftY + 5) + shiftX + 2] = 9608; else screen[screenWidth * (shiftY + 5) + shiftX + 2] = '7'; // █
        screen[screenWidth * (shiftY + 5) + shiftX + 4] = 9474; // │
        if (*this->key_8) screen[screenWidth * (shiftY + 5) + shiftX + 6] = 9608; else screen[screenWidth * (shiftY + 5) + shiftX + 6] = '8'; // █
        screen[screenWidth * (shiftY + 5) + shiftX + 8] = 9474; // │
        if (*this->key_9) screen[screenWidth * (shiftY + 5) + shiftX + 10] = 9608; else screen[screenWidth * (shiftY + 5) + shiftX + 10] = '9'; // █
        screen[screenWidth * (shiftY + 5) + shiftX + 12] = 9474; // │
        if (*this->key_mul) screen[screenWidth * (shiftY + 5) + shiftX + 14] = 9608; else screen[screenWidth * (shiftY + 5) + shiftX + 14] = '*'; // █
        screen[screenWidth * (shiftY + 5) + shiftX + 16] = 9500; // ├

        screen[screenWidth * (shiftY + 6) + shiftX + 0] = 9500; // ├
        screen[screenWidth * (shiftY + 6) + shiftX + 1] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 2] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 3] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 4] = 9532; // ┼
        screen[screenWidth * (shiftY + 6) + shiftX + 5] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 6] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 7] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 8] = 9532; // ┼
        screen[screenWidth * (shiftY + 6) + shiftX + 9] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 10] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 11] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 12] = 9532; // ┼
        screen[screenWidth * (shiftY + 6) + shiftX + 13] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 14] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 15] = 9472; // ─
        screen[screenWidth * (shiftY + 6) + shiftX + 16] = 9508; // ┤

        screen[screenWidth * (shiftY + 7) + shiftX + 0] = 9474; // │
        if (*this->key_res) screen[screenWidth * (shiftY + 7) + shiftX + 2] = 9608; else screen[screenWidth * (shiftY + 7) + shiftX + 2] = 'R'; // █
        screen[screenWidth * (shiftY + 7) + shiftX + 4] = 9474; // │
        if (*this->key_0) screen[screenWidth * (shiftY + 7) + shiftX + 6] = 9608; else screen[screenWidth * (shiftY + 7) + shiftX + 6] = '0'; // █
        screen[screenWidth * (shiftY + 7) + shiftX + 8] = 9474; // │
        if (*this->key_equ) screen[screenWidth * (shiftY + 7) + shiftX + 10] = 9608; else screen[screenWidth * (shiftY + 7) + shiftX + 10] = '='; // █
        screen[screenWidth * (shiftY + 7) + shiftX + 12] = 9474; // │
        if (*this->key_div) screen[screenWidth * (shiftY + 7) + shiftX + 14] = 9608; else screen[screenWidth * (shiftY + 7) + shiftX + 14] = '/'; // █
        screen[screenWidth * (shiftY + 7) + shiftX + 16] = 9500; // ├

        screen[screenWidth * (shiftY + 8) + shiftX + 0] = 9492; // └
        screen[screenWidth * (shiftY + 8) + shiftX + 1] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 2] = 9516; // ┬
        screen[screenWidth * (shiftY + 8) + shiftX + 3] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 4] = 9524; // ┴
        screen[screenWidth * (shiftY + 8) + shiftX + 5] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 6] = 9516; // ┬
        screen[screenWidth * (shiftY + 8) + shiftX + 7] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 8] = 9524; // ┴
        screen[screenWidth * (shiftY + 8) + shiftX + 9] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 10] = 9516; // ┬
        screen[screenWidth * (shiftY + 8) + shiftX + 11] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 12] = 9524; // ┴
        screen[screenWidth * (shiftY + 8) + shiftX + 13] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 14] = 9516; // ┬
        screen[screenWidth * (shiftY + 8) + shiftX + 15] = 9472; // ─
        screen[screenWidth * (shiftY + 8) + shiftX + 16] = 9496; // ┘
    }
};

class STM32 {
public:
    int PA[16] = { 0,0,0,0,0, 0, 0,0,0,0,0,0,0, 0,0,0 };
    int PB[16] = {0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0 };
    int* PC[16];
    int& CLK = this->PA[5];

    char symbol = ' ';
    int btn_pressed = 0;
    int btn_processed = 0;
    int step = 0, part = 0, digit = 0;
    char op;
    short q1[4] = { 0,0,0,0 }, q2[4] = { 0,0,0,0 }, q[4] = { 0,0,0,0 };
    short num = 0;
    bool is_neg = false;
    /*STM32() {
        this->step = 0;
    }*/
    void set_data(int d1, int d2, int d3, int d4, int d5, int d6, int d7) {
        this->PA[ 6] = d1;
        this->PA[ 7] = d2;
        this->PA[ 8] = d3;
        this->PA[ 9] = d4;
        this->PA[10] = d5;
        this->PA[11] = d6;
        this->PA[12] = d7;
    }
    void set_symbol() {
        if (this->symbol == ' ')this->set_data(0, 0, 0, 0, 0, 0, 0);
        if (this->symbol == '-')this->set_data(0, 0, 0, 0, 0, 0, 1);
        if (this->symbol == '0')this->set_data(1, 1, 1, 1, 1, 1, 0);
        if (this->symbol == '1')this->set_data(0, 1, 1, 0, 0, 0, 0);
        if (this->symbol == '2')this->set_data(1, 1, 0, 1, 1, 0, 1);
        if (this->symbol == '3')this->set_data(1, 1, 1, 1, 0, 0, 1);
        if (this->symbol == '4')this->set_data(0, 1, 1, 0, 0, 1, 1);
        if (this->symbol == '5')this->set_data(1, 0, 1, 1, 0, 1, 1);
        if (this->symbol == '6')this->set_data(1, 0, 1, 1, 1, 1, 1);
        if (this->symbol == '7')this->set_data(1, 1, 1, 0, 0, 0, 0);
        if (this->symbol == '8')this->set_data(1, 1, 1, 1, 1, 1, 1);
        if (this->symbol == '9')this->set_data(1, 1, 1, 1, 0, 1, 1);
    }
    void choose_reg(int d1, int d2, int d3, int d4, int d5) {
        this->PA[0] = d1;
        this->PA[1] = d2;
        this->PA[2] = d3;
        this->PA[3] = d4;
        this->PA[4] = d5;
    }

    void Q_add() {
        short(&q1)[4] = this->q1;
        short(&q2)[4] = this->q2;
        short(&q )[4] = this->q ;
        for (char i = 0; i < 4; i++) {
            q[i] = q1[i] + q2[i];
        }
    }

    void Q_sub() {
        short(&q1)[4] = this->q1;
        short(&q2)[4] = this->q2;
        short(&q )[4] = this->q ;
        for (char i = 0; i < 4; i++) {
            q[i] = q1[i] - q2[i];
        }
    }

    void Q_mul() {
        short(&q1)[4] = this->q1;
        short(&q2)[4] = this->q2;
        short(&q )[4] = this->q ;
        q[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
        q[1] = q1[0] * q2[1] + q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
        q[2] = q1[0] * q2[2] - q1[1] * q2[3] + q1[2] * q2[0] + q1[3] * q2[1];
        q[3] = q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1] + q1[3] * q2[0];
    }

    /*void Q_div() {
        short(&q1)[4] = this->q1;
        short(&q2)[4] = this->q2;
        short(&q )[4] = this->q ;
        short m = q2[0] * q2[0] + q2[1] * q2[1] + q2[2] * q2[2] + q2[3] * q2[3];
        q2[0] =  q2[0] / m;
        q2[1] = -q2[1] / m;
        q2[2] = -q2[2] / m;
        q2[3] = -q2[3] / m;
        this->Q_mul();
    }*/

    /*void Q_div() {
        short(&q1)[4] = this->q1;
        short(&q2)[4] = this->q2;
        short(&q)[4] = this->q;
        short m = q2[0] * q2[0] + q2[1] * q2[1] + q2[2] * q2[2] + q2[3] * q2[3];
        q2[1] = -q2[1];
        q2[2] = -q2[2];
        q2[3] = -q2[3];
        this->Q_mul();
        q[0] = q[0] / m;
        q[1] = q[1] / m;
        q[2] = q[2] / m;
        q[3] = q[3] / m;
    }*/

    void Q_div() {
        float q1[4], q2[4], q[4];
        for (char i = 0; i < 4; i++) {
            q1[i] = (float) this->q1[i];
            q2[i] = (float)-this->q2[i];
            q [i] = (float) this->q [i];
        }
        q2[0] *= -1;
        float m = q2[0] * q2[0] + q2[1] * q2[1] + q2[2] * q2[2] + q2[3] * q2[3];
        q[0] = q1[0] * q2[0] - q1[1] * q2[1] - q1[2] * q2[2] - q1[3] * q2[3];
        q[1] = q1[0] * q2[1] + q1[1] * q2[0] + q1[2] * q2[3] - q1[3] * q2[2];
        q[2] = q1[0] * q2[2] - q1[1] * q2[3] + q1[2] * q2[0] + q1[3] * q2[1];
        q[3] = q1[0] * q2[3] + q1[1] * q2[2] - q1[2] * q2[1] + q1[3] * q2[0];
        for (char i = 0; i < 4; i++) this->q[i] = (short) q[i] / m;
    }

    void do_op() {
        switch (this->op) {
        case '+': this->Q_add();break;
        case '-': this->Q_sub();break;
        case '*': this->Q_mul();break;
        case '/': this->Q_div();break;
        }
    }
};

wchar_t its(int n) {
    switch (n) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
    }
}

int sti(char c) {
    switch (c) {
    case '0': return 0;
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case '4': return 4;
    case '5': return 5;
    case '6': return 6;
    case '7': return 7;
    case '8': return 8;
    case '9': return 9;
    }
}

int main()
{
    int 
        press_1   = 0,
        press_2   = 0,
        press_3   = 0,
        press_4   = 0,
        press_5   = 0,
        press_6   = 0,
        press_7   = 0,
        press_8   = 0,
        press_9   = 0,
        press_0   = 0,
        press_add = 0,
        press_sub = 0,
        press_mul = 0,
        press_div = 0,
        press_equ = 0,
        press_res = 0;
    STM32 stm;
    DC24 dc(&stm.PA[0], &stm.PA[5]);
    REG7 
        reg_1_1(&stm.PA[6], &dc.OUTPUT[1 ]),
        reg_1_2(&stm.PA[6], &dc.OUTPUT[2 ]),
        reg_1_3(&stm.PA[6], &dc.OUTPUT[3 ]),
        reg_1_4(&stm.PA[6], &dc.OUTPUT[4 ]),
        reg_1_5(&stm.PA[6], &dc.OUTPUT[5 ]),
        reg_1_6(&stm.PA[6], &dc.OUTPUT[6 ]),
                                         
        reg_2_1(&stm.PA[6], &dc.OUTPUT[7 ]),
        reg_2_2(&stm.PA[6], &dc.OUTPUT[8 ]),
        reg_2_3(&stm.PA[6], &dc.OUTPUT[9 ]),
        reg_2_4(&stm.PA[6], &dc.OUTPUT[10]),
        reg_2_5(&stm.PA[6], &dc.OUTPUT[11]),
        reg_2_6(&stm.PA[6], &dc.OUTPUT[12]),

        reg_3_1(&stm.PA[6], &dc.OUTPUT[13]),
        reg_3_2(&stm.PA[6], &dc.OUTPUT[14]),
        reg_3_3(&stm.PA[6], &dc.OUTPUT[15]),
        reg_3_4(&stm.PA[6], &dc.OUTPUT[16]),
        reg_3_5(&stm.PA[6], &dc.OUTPUT[17]),
        reg_3_6(&stm.PA[6], &dc.OUTPUT[18]),

        reg_4_1(&stm.PA[6], &dc.OUTPUT[19]),
        reg_4_2(&stm.PA[6], &dc.OUTPUT[20]),
        reg_4_3(&stm.PA[6], &dc.OUTPUT[21]),
        reg_4_4(&stm.PA[6], &dc.OUTPUT[22]),
        reg_4_5(&stm.PA[6], &dc.OUTPUT[23]),
        reg_4_6(&stm.PA[6], &dc.OUTPUT[24]);
    LED7 
        led_1_1(&reg_1_1.Q[0]),
        led_1_2(&reg_1_2.Q[0]),
        led_1_3(&reg_1_3.Q[0]),
        led_1_4(&reg_1_4.Q[0]),
        led_1_5(&reg_1_5.Q[0]),
        led_1_6(&reg_1_6.Q[0]),

        led_2_1(&reg_2_1.Q[0]),
        led_2_2(&reg_2_2.Q[0]),
        led_2_3(&reg_2_3.Q[0]),
        led_2_4(&reg_2_4.Q[0]),
        led_2_5(&reg_2_5.Q[0]),
        led_2_6(&reg_2_6.Q[0]),

        led_3_1(&reg_3_1.Q[0]),
        led_3_2(&reg_3_2.Q[0]),
        led_3_3(&reg_3_3.Q[0]),
        led_3_4(&reg_3_4.Q[0]),
        led_3_5(&reg_3_5.Q[0]),
        led_3_6(&reg_3_6.Q[0]),

        led_4_1(&reg_4_1.Q[0]),
        led_4_2(&reg_4_2.Q[0]),
        led_4_3(&reg_4_3.Q[0]),
        led_4_4(&reg_4_4.Q[0]),
        led_4_5(&reg_4_5.Q[0]),
        led_4_6(&reg_4_6.Q[0]);
    keypad kp(
        &press_1  ,
        &press_2  ,
        &press_3  ,
        &press_4  ,
        &press_5  ,
        &press_6  ,
        &press_7  ,
        &press_8  ,
        &press_9  ,
        &press_0  ,
        &press_add,
        &press_sub,
        &press_mul,
        &press_div,
        &press_equ,
        &press_res,
        &stm.PB[0]
    );
    stm.PC[0] = &kp.OUTPUT[0];
    stm.PC[1] = &kp.OUTPUT[1];
    stm.PC[2] = &kp.OUTPUT[2];
    stm.PC[3] = &kp.OUTPUT[3];


    int nScreenWidth = 120;			// Console Screen Size X (columns)
    int nScreenHeight = 40;			// Console Screen Size Y (rows)
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenHeight; i++) {
        for (int j = 0; j < nScreenWidth; j++) {
            screen[i * nScreenWidth + j] = ' ';
            //screen[i*nScreenWidth+j] = 9472+ i * nScreenWidth + j;
        }
        //screen[i] = 0x2580+i;
    }

    /*
        0x2580 ▀ 9600
        0x2584 ▄ 9604
        0x2588 █ 9608
        0x258C ▌ 9612
        0x2590 ▐ 9616
        0x2591 ░ 9617
        0x2592 ▒ 9618
        0x2593 ▓ 9619

    */
    //screen[nScreenWidth * nScreenHeight - 1] = '\0';
    /*HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = { nScreenWidth, nScreenHeight };
    SetConsoleScreenBufferSize(hWnd, bufferSize);*/

    system("mode con cols=120 lines=40");

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;
    //q3 = Q_div(q1, q2);
    //Q_print(q3);
    int count = 0;
    //dc.refresh();
    //reg1.refresh();
    //led1.draw(screen, nScreenWidth, nScreenHeight, 1, 1);
    reg_1_1.draw(screen, nScreenWidth, nScreenHeight, 1,   9);
    reg_1_2.draw(screen, nScreenWidth, nScreenHeight, 8,   9);
    reg_1_3.draw(screen, nScreenWidth, nScreenHeight, 15,  9);
    reg_1_4.draw(screen, nScreenWidth, nScreenHeight, 22,  9);
    reg_1_5.draw(screen, nScreenWidth, nScreenHeight, 29,  9);
    reg_1_6.draw(screen, nScreenWidth, nScreenHeight, 36,  9);

    reg_2_1.draw(screen, nScreenWidth, nScreenHeight, 1,  22);
    reg_2_2.draw(screen, nScreenWidth, nScreenHeight, 8,  22);
    reg_2_3.draw(screen, nScreenWidth, nScreenHeight, 15, 22);
    reg_2_4.draw(screen, nScreenWidth, nScreenHeight, 22, 22);
    reg_2_5.draw(screen, nScreenWidth, nScreenHeight, 29, 22);
    reg_2_6.draw(screen, nScreenWidth, nScreenHeight, 36, 22);

    reg_3_1.draw(screen, nScreenWidth, nScreenHeight, 50,  9);
    reg_3_2.draw(screen, nScreenWidth, nScreenHeight, 57,  9);
    reg_3_3.draw(screen, nScreenWidth, nScreenHeight, 64,  9);
    reg_3_4.draw(screen, nScreenWidth, nScreenHeight, 71,  9);
    reg_3_5.draw(screen, nScreenWidth, nScreenHeight, 78,  9);
    reg_3_6.draw(screen, nScreenWidth, nScreenHeight, 85,  9);

    reg_4_1.draw(screen, nScreenWidth, nScreenHeight, 50, 22);
    reg_4_2.draw(screen, nScreenWidth, nScreenHeight, 57, 22);
    reg_4_3.draw(screen, nScreenWidth, nScreenHeight, 64, 22);
    reg_4_4.draw(screen, nScreenWidth, nScreenHeight, 71, 22);
    reg_4_5.draw(screen, nScreenWidth, nScreenHeight, 78, 22);
    reg_4_6.draw(screen, nScreenWidth, nScreenHeight, 85, 22);


    screen[0] = 9484; // ┌
    screen[49] = 9484; // ┌
    screen[nScreenWidth * 13] = 9484; // ┌
    screen[nScreenWidth * 13 + 49] = 9484; // ┌-
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j < 7; j++) {
            screen[i*7+j] = 9472; // ─
            screen[i * 7 + j+49] = 9472; // ─
            screen[i * 7 + j + nScreenWidth * 13] = 9472; // ─
            screen[i * 7 + j + nScreenWidth * 13 + 49] = 9472; // ─
        }
        screen[i * 7 + 7] = 9516; // ┬
        screen[i * 7 + 56] = 9516; // ┬
        screen[i * 7 + 7 + nScreenWidth * 13] = 9516; // ┬
        screen[i * 7 + 56 + nScreenWidth * 13] = 9516; // ┬
    }
    screen[42] = 9488; // ┐
    screen[91] = 9488; // ┐
    screen[42 + nScreenWidth * 13] = 9488; // ┐
    screen[91 + nScreenWidth * 13] = 9488; // ┐
    for (int i = 1; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            screen[i * nScreenWidth + j*7] = 9474; // │
            screen[i * nScreenWidth + j * 7 + 49] = 9474; // │
            screen[(i+13) * nScreenWidth + j * 7] = 9474; // │
            screen[(i+13) * nScreenWidth + j * 7 + 49] = 9474; // │
        }
    }
    screen[nScreenWidth*8] = 9492; // └
    screen[nScreenWidth*8+49] = 9492; // └
    screen[nScreenWidth*21] = 9492; // └
    screen[nScreenWidth*21 + 49] = 9492; // └
    for (int i = 0; i < 6; i++) {
        for (int j = 1; j < 7; j++) {
            screen[nScreenWidth * 8+i * 7 + j] = 9516; // ┬
            screen[nScreenWidth * 8 + i * 7 + j+49] = 9516; // ┬
            screen[nScreenWidth * 21 + i * 7 + j] = 9516; // ┬
            screen[nScreenWidth * 21 + i * 7 + j + 49] = 9516; // ┬
        }
        screen[nScreenWidth * 8+i * 7 + 7] = 9532; // ┼
        screen[nScreenWidth * 8 + i * 7 + 56] = 9532; // ┼
        screen[nScreenWidth * 21 + i * 7 + 7] = 9532; // ┼
        screen[nScreenWidth * 21 + i * 7 + 56] = 9532; // ┼
    }
    screen[nScreenWidth * 8+42] = 9508; // ┤
    screen[nScreenWidth * 8 + 91] = 9508; // ┤
    screen[nScreenWidth * 21 + 42] = 9508; // ┤
    screen[nScreenWidth * 21 + 91] = 9508; // ┤

    screen[nScreenWidth * 12 + 1] = 9560; // ╘
    screen[nScreenWidth * 12 + 50] = 9575; // ╧
    screen[nScreenWidth * 25 + 1] = 9560; // ╘
    screen[nScreenWidth * 25 + 50] = 9575; // ╧
    for (int i = 2; i < 43; i++) {
        screen[nScreenWidth * 12 + i] = 9575; // ╧
        screen[nScreenWidth * 12 + i+49] = 9575; // ╧
        screen[nScreenWidth * 25 + i] = 9575; // ╧
        screen[nScreenWidth * 25 + i + 49] = 9575; // ╧
    }
    for (int i = 43; i < 50; i++) {
        screen[nScreenWidth * 12 + i] = 9552; // ═
        screen[nScreenWidth * 25 + i] = 9552; // ═
        screen[nScreenWidth * 12 + i + 49] = 9552; // ═
        screen[nScreenWidth * 25 + i + 49] = 9552; // ═
    }



    screen[nScreenWidth * 2 + 97] = 9600; // ▀ 
    screen[nScreenWidth * 3 + 97] = 9608; // █ 
    screen[nScreenWidth * 4 + 97] = 9608; // █ 
    screen[nScreenWidth * 5 + 97] = 9608; // █ 
    screen[nScreenWidth * 6 + 97] = 9608; // █ 
    screen[nScreenWidth * 7 + 97] = 9600; // ▀

    screen[nScreenWidth * 15 + 48] = 9600; // ▀ 
    screen[nScreenWidth * 16 + 48] = 9608; // █ 
    screen[nScreenWidth * 17 + 48] = 9608; // █ 
    screen[nScreenWidth * 18 + 48] = 9608; // █ 
    screen[nScreenWidth * 19 + 48] = 9608; // █ 
    screen[nScreenWidth * 20 + 47] = 9600; // ▀ 
    screen[nScreenWidth * 20 + 46] = 9600; // ▀ 
    screen[nScreenWidth * 20 + 45] = 9600; // ▀ 
    screen[nScreenWidth * 20 + 44] = 9600; // ▀ 
    screen[nScreenWidth * 19 + 43] = 9604; // ▄  

    screen[nScreenWidth * 15 + 93] = 9608; // █
    screen[nScreenWidth * 16 + 93] = 9608; // █ 
    screen[nScreenWidth * 17 + 93] = 9608; // █ 
    screen[nScreenWidth * 18 + 93] = 9608; // █ 
    screen[nScreenWidth * 19 + 93] = 9608; // █ 
    screen[nScreenWidth * 17 + 94] = 9608; // █ 
    screen[nScreenWidth * 16 + 95] = 9608; // █ 
    screen[nScreenWidth * 18 + 95] = 9608; // █ 
    screen[nScreenWidth * 15 + 96] = 9608; // █ 
    screen[nScreenWidth * 19 + 96] = 9608; // █ 
    screen[nScreenWidth * 15 + 97] = 9600; // ▀
    screen[nScreenWidth * 19 + 97] = 9604; // ▄ 



    screen[nScreenWidth * 39 +  3] = 9560; // ╘
    screen[nScreenWidth * 39 +  4] = 9552; // ═
    screen[nScreenWidth * 39 +  5] = 9552; // ═
    screen[nScreenWidth * 39 +  6] = 9552; // ═
    screen[nScreenWidth * 39 +  7] = 9575; // ╧
    screen[nScreenWidth * 39 +  8] = 9552; // ═
    screen[nScreenWidth * 39 +  9] = 9552; // ═
    screen[nScreenWidth * 39 + 10] = 9552; // ═
    screen[nScreenWidth * 39 + 11] = 9575; // ╧
    screen[nScreenWidth * 39 + 12] = 9552; // ═
    screen[nScreenWidth * 39 + 13] = 9552; // ═
    screen[nScreenWidth * 39 + 14] = 9552; // ═
    screen[nScreenWidth * 39 + 15] = 9575; // ╧
    screen[nScreenWidth * 39 + 16] = 9552; // ═
    screen[nScreenWidth * 39 + 17] = 9552; // ═
    screen[nScreenWidth * 39 + 18] = 9577; // ╩
    screen[nScreenWidth * 38 + 18] = 9553; // ║
    screen[nScreenWidth * 37 + 18] = 9570; // ╢
    screen[nScreenWidth * 36 + 18] = 9553; // ║
    screen[nScreenWidth * 35 + 18] = 9570; // ╢
    screen[nScreenWidth * 34 + 18] = 9553; // ║
    screen[nScreenWidth * 33 + 18] = 9570; // ╢
    screen[nScreenWidth * 32 + 18] = 9553; // ║
    screen[nScreenWidth * 31 + 18] = 9558; // ╖
    for (int i = 19; i < 98; i++) {
        screen[nScreenWidth * 39 + i] = 9552; // ═
    }
    for (int i = 2; i < 39; i++) {
        screen[nScreenWidth * i + 98] = 9553; // ║
    }
    screen[nScreenWidth * 39 + 98] = 9565; // ╝
    screen[nScreenWidth * 12 + 98] = 9571; // ╣
    screen[nScreenWidth * 25 + 98] = 9571; // ╣

    screen[nScreenWidth * 1 + 98] = 9556; // ╔
    screen[nScreenWidth * 1 + 99] = 9559; // ╗
    screen[nScreenWidth * 2 + 99] = 9553; // ║
    for (int i = 3; i < 31; i++) {
        screen[nScreenWidth * i +  99] = 9567; // ╟
        screen[nScreenWidth * i + 119] = 9570; // ╢
        screen[nScreenWidth * i + 100] = 9508; // ┤
        screen[nScreenWidth * i + 118] = 9500; // ├
    }
    screen[nScreenWidth * 3 + 119] = 9558; // ╖
    screen[nScreenWidth * 31 + 99] = 9553; // ║
    screen[nScreenWidth * 32 + 99] = 9553; // ║
    screen[nScreenWidth * 33 + 99] = 9553; // ║
    screen[nScreenWidth * 34 + 99] = 9562; // ╚
    screen[nScreenWidth * 34 + 100] = 9552; // ═
    screen[nScreenWidth * 34 + 101] = 9552; // ═
    screen[nScreenWidth * 34 + 102] = 9552; // ═
    screen[nScreenWidth * 34 + 103] = 9552; // ═
    screen[nScreenWidth * 34 + 104] = 9575; // ╧
    screen[nScreenWidth * 34 + 105] = 9552; // ═
    screen[nScreenWidth * 34 + 106] = 9575; // ╧
    screen[nScreenWidth * 34 + 107] = 9552; // ═
    screen[nScreenWidth * 34 + 108] = 9575; // ╧
    screen[nScreenWidth * 34 + 109] = 9552; // ═
    screen[nScreenWidth * 34 + 110] = 9575; // ╧
    screen[nScreenWidth * 34 + 111] = 9552; // ═
    screen[nScreenWidth * 34 + 112] = 9575; // ╧
    screen[nScreenWidth * 34 + 113] = 9552; // ═
    screen[nScreenWidth * 34 + 114] = 9575; // ╧
    screen[nScreenWidth * 34 + 115] = 9552; // ═
    screen[nScreenWidth * 34 + 116] = 9552; // ═
    screen[nScreenWidth * 34 + 117] = 9552; // ═
    screen[nScreenWidth * 34 + 118] = 9552; // ═
    screen[nScreenWidth * 34 + 119] = 9565; // ╝
    screen[nScreenWidth * 31 + 119] = 9553; // ║
    screen[nScreenWidth * 32 + 119] = 9553; // ║
    screen[nScreenWidth * 33 + 119] = 9553; // ║

    screen[nScreenWidth * 31 + 100] = 9474; // │
    screen[nScreenWidth * 32 + 100] = 9474; // │
    screen[nScreenWidth * 33 + 100] = 9492; // └
    screen[nScreenWidth * 33 + 101] = 9472; // ─
    screen[nScreenWidth * 33 + 102] = 9472; // ─
    screen[nScreenWidth * 33 + 103] = 9472; // ─
    screen[nScreenWidth * 33 + 104] = 9516; // ┬
    screen[nScreenWidth * 33 + 105] = 9472; // ─
    screen[nScreenWidth * 33 + 106] = 9516; // ┬
    screen[nScreenWidth * 33 + 107] = 9472; // ─
    screen[nScreenWidth * 33 + 108] = 9516; // ┬
    screen[nScreenWidth * 33 + 109] = 9472; // ─
    screen[nScreenWidth * 33 + 110] = 9516; // ┬
    screen[nScreenWidth * 33 + 111] = 9472; // ─
    screen[nScreenWidth * 33 + 112] = 9516; // ┬
    screen[nScreenWidth * 33 + 113] = 9472; // ─
    screen[nScreenWidth * 33 + 114] = 9516; // ┬
    screen[nScreenWidth * 33 + 115] = 9472; // ─
    screen[nScreenWidth * 33 + 116] = 9472; // ─
    screen[nScreenWidth * 33 + 117] = 9472; // ─
    screen[nScreenWidth * 31 + 118] = 9474; // │
    screen[nScreenWidth * 32 + 118] = 9474; // │
    screen[nScreenWidth * 33 + 118] = 9496; // ┘
    screen[nScreenWidth *  1 + 118] = 9474; // │
    screen[nScreenWidth *  2 + 118] = 9474; // │
    screen[nScreenWidth *  1 + 100] = 9474; // │
    screen[nScreenWidth *  2 + 100] = 9474; // │
    screen[nScreenWidth *  0 + 118] = 9488; // ┐
    screen[nScreenWidth *  0 + 100] = 9484; // ┌
    for (int i = 101; i < 118; i++) {
        screen[nScreenWidth * 0 + i] = 9472; // ─
    }

    screen[nScreenWidth * 1 + 107] = 'S';
    screen[nScreenWidth * 1 + 108] = 'T';
    screen[nScreenWidth * 1 + 109] = 'M';
    screen[nScreenWidth * 1 + 110] = '3';
    screen[nScreenWidth * 1 + 111] = '2';

    screen[nScreenWidth * 3 + 101] = 'G';
    screen[nScreenWidth * 3 + 102] = 'N';
    screen[nScreenWidth * 3 + 103] = 'D';

    screen[nScreenWidth * 4 + 101] = 'N';
    screen[nScreenWidth * 4 + 102] = 'C';
    screen[nScreenWidth * 4 + 103] = '1';

    screen[nScreenWidth * 5 + 101] = '3';
    screen[nScreenWidth * 5 + 102] = 'V';
    screen[nScreenWidth * 5 + 103] = '3';

    screen[nScreenWidth * 6 + 101] = 'V';
    screen[nScreenWidth * 6 + 102] = 'B';
    screen[nScreenWidth * 6 + 103] = 'A';
    screen[nScreenWidth * 6 + 104] = 'T';

    screen[nScreenWidth * 7 + 101] = 'P';
    screen[nScreenWidth * 7 + 102] = 'C';
    screen[nScreenWidth * 7 + 103] = '1';
    screen[nScreenWidth * 7 + 104] = '3';

    screen[nScreenWidth * 8 + 101] = 'P';
    screen[nScreenWidth * 8 + 102] = 'C';
    screen[nScreenWidth * 8 + 103] = '1';
    screen[nScreenWidth * 8 + 104] = '4';

    screen[nScreenWidth * 9 + 101] = 'P';
    screen[nScreenWidth * 9 + 102] = 'C';
    screen[nScreenWidth * 9 + 103] = '1';
    screen[nScreenWidth * 9 + 104] = '5';

    screen[nScreenWidth * 10 + 101] = 'P';
    screen[nScreenWidth * 10 + 102] = 'D';
    screen[nScreenWidth * 10 + 103] = '0';

    screen[nScreenWidth * 11 + 101] = 'P';
    screen[nScreenWidth * 11 + 102] = 'D';
    screen[nScreenWidth * 11 + 103] = '1';

    screen[nScreenWidth * 12 + 101] = 'R';
    screen[nScreenWidth * 12 + 102] = 'S';
    screen[nScreenWidth * 12 + 103] = 'T';

    screen[nScreenWidth * 13 + 101] = 'P';
    screen[nScreenWidth * 13 + 102] = 'C';
    screen[nScreenWidth * 13 + 103] = '0';

    screen[nScreenWidth * 14 + 101] = 'P';
    screen[nScreenWidth * 14 + 102] = 'C';
    screen[nScreenWidth * 14 + 103] = '1';

    screen[nScreenWidth * 15 + 101] = 'P';
    screen[nScreenWidth * 15 + 102] = 'C';
    screen[nScreenWidth * 15 + 103] = '2';

    screen[nScreenWidth * 16 + 101] = 'P';
    screen[nScreenWidth * 16 + 102] = 'C';
    screen[nScreenWidth * 16 + 103] = '3';

    screen[nScreenWidth * 17 + 101] = 'P';
    screen[nScreenWidth * 17 + 102] = 'A';
    screen[nScreenWidth * 17 + 103] = '0';

    screen[nScreenWidth * 18 + 101] = 'P';
    screen[nScreenWidth * 18 + 102] = 'A';
    screen[nScreenWidth * 18 + 103] = '1';

    screen[nScreenWidth * 19 + 101] = 'P';
    screen[nScreenWidth * 19 + 102] = 'A';
    screen[nScreenWidth * 19 + 103] = '2';

    screen[nScreenWidth * 20 + 101] = 'P';
    screen[nScreenWidth * 20 + 102] = 'A';
    screen[nScreenWidth * 20 + 103] = '3';

    screen[nScreenWidth * 21 + 101] = 'P';
    screen[nScreenWidth * 21 + 102] = 'A';
    screen[nScreenWidth * 21 + 103] = '4';

    screen[nScreenWidth * 22 + 101] = 'P';
    screen[nScreenWidth * 22 + 102] = 'A';
    screen[nScreenWidth * 22 + 103] = '5';

    screen[nScreenWidth * 23 + 101] = 'P';
    screen[nScreenWidth * 23 + 102] = 'A';
    screen[nScreenWidth * 23 + 103] = '6';

    screen[nScreenWidth * 24 + 101] = 'P';
    screen[nScreenWidth * 24 + 102] = 'A';
    screen[nScreenWidth * 24 + 103] = '7';

    screen[nScreenWidth * 25 + 101] = 'P';
    screen[nScreenWidth * 25 + 102] = 'C';
    screen[nScreenWidth * 25 + 103] = '4';

    screen[nScreenWidth * 26 + 101] = 'P';
    screen[nScreenWidth * 26 + 102] = 'C';
    screen[nScreenWidth * 26 + 103] = '5';

    screen[nScreenWidth * 27 + 101] = 'P';
    screen[nScreenWidth * 27 + 102] = 'B';
    screen[nScreenWidth * 27 + 103] = '0';

    screen[nScreenWidth * 28 + 101] = 'P';
    screen[nScreenWidth * 28 + 102] = 'B';
    screen[nScreenWidth * 28 + 103] = '1';

    screen[nScreenWidth * 29 + 101] = 'P';
    screen[nScreenWidth * 29 + 102] = 'B';
    screen[nScreenWidth * 29 + 103] = '2';

    screen[nScreenWidth * 30 + 101] = 'G';
    screen[nScreenWidth * 30 + 102] = 'N';
    screen[nScreenWidth * 30 + 103] = 'D';
    screen[nScreenWidth * 30 + 104] = '1';

    screen[nScreenWidth * 31 + 103] = 'P';
    screen[nScreenWidth * 31 + 104] = 'B';
    screen[nScreenWidth * 32 + 103] = '1';
    screen[nScreenWidth * 32 + 104] = '0';

    screen[nScreenWidth * 31 + 105] = 'P';
    screen[nScreenWidth * 31 + 106] = 'B';
    screen[nScreenWidth * 32 + 105] = '1';
    screen[nScreenWidth * 32 + 106] = '1';

    screen[nScreenWidth * 31 + 107] = 'P';
    screen[nScreenWidth * 31 + 108] = 'B';
    screen[nScreenWidth * 32 + 107] = '1';
    screen[nScreenWidth * 32 + 108] = '2';

    screen[nScreenWidth * 31 + 109] = 'P';
    screen[nScreenWidth * 31 + 110] = 'B';
    screen[nScreenWidth * 32 + 109] = '1';
    screen[nScreenWidth * 32 + 110] = '3';

    screen[nScreenWidth * 31 + 111] = 'P';
    screen[nScreenWidth * 31 + 112] = 'B';
    screen[nScreenWidth * 32 + 111] = '1';
    screen[nScreenWidth * 32 + 112] = '4';

    screen[nScreenWidth * 31 + 113] = 'P';
    screen[nScreenWidth * 31 + 114] = 'B';
    screen[nScreenWidth * 32 + 113] = '1';
    screen[nScreenWidth * 32 + 114] = '5';

    screen[nScreenWidth * 3 + 114] = 'G';
    screen[nScreenWidth * 3 + 115] = 'N';
    screen[nScreenWidth * 3 + 116] = 'D';
    screen[nScreenWidth * 3 + 117] = '3';

    screen[nScreenWidth * 4 + 115] = 'N';
    screen[nScreenWidth * 4 + 116] = 'C';
    screen[nScreenWidth * 4 + 117] = '2';

    screen[nScreenWidth * 5 + 116] = '5';
    screen[nScreenWidth * 5 + 117] = 'V';

    screen[nScreenWidth * 6 + 115] = 'P';
    screen[nScreenWidth * 6 + 116] = 'B';
    screen[nScreenWidth * 6 + 117] = '9';

    screen[nScreenWidth * 7 + 115] = 'P';
    screen[nScreenWidth * 7 + 116] = 'B';
    screen[nScreenWidth * 7 + 117] = '8';

    screen[nScreenWidth * 8 + 114] = 'B';
    screen[nScreenWidth * 8 + 115] = 'o';
    screen[nScreenWidth * 8 + 116] = 'o';
    screen[nScreenWidth * 8 + 117] = 't';

    screen[nScreenWidth * 9 + 115] = 'P';
    screen[nScreenWidth * 9 + 116] = 'B';
    screen[nScreenWidth * 9 + 117] = '7';

    screen[nScreenWidth * 10 + 115] = 'P';
    screen[nScreenWidth * 10 + 116] = 'B';
    screen[nScreenWidth * 10 + 117] = '6';

    screen[nScreenWidth * 11 + 115] = 'P';
    screen[nScreenWidth * 11 + 116] = 'B';
    screen[nScreenWidth * 11 + 117] = '5';

    screen[nScreenWidth * 12 + 115] = 'P';
    screen[nScreenWidth * 12 + 116] = 'B';
    screen[nScreenWidth * 12 + 117] = '4';

    screen[nScreenWidth * 13 + 115] = 'P';
    screen[nScreenWidth * 13 + 116] = 'B';
    screen[nScreenWidth * 13 + 117] = '3';

    screen[nScreenWidth * 14 + 115] = 'P';
    screen[nScreenWidth * 14 + 116] = 'D';
    screen[nScreenWidth * 14 + 117] = '2';

    screen[nScreenWidth * 15 + 114] = 'P';
    screen[nScreenWidth * 15 + 115] = 'C';
    screen[nScreenWidth * 15 + 116] = '1';
    screen[nScreenWidth * 15 + 117] = '2';

    screen[nScreenWidth * 16 + 114] = 'P';
    screen[nScreenWidth * 16 + 115] = 'C';
    screen[nScreenWidth * 16 + 116] = '1';
    screen[nScreenWidth * 16 + 117] = '1';

    screen[nScreenWidth * 17 + 114] = 'P';
    screen[nScreenWidth * 17 + 115] = 'C';
    screen[nScreenWidth * 17 + 116] = '1';
    screen[nScreenWidth * 17 + 117] = '0';

    screen[nScreenWidth * 18 + 114] = 'P';
    screen[nScreenWidth * 18 + 115] = 'A';
    screen[nScreenWidth * 18 + 116] = '1';
    screen[nScreenWidth * 18 + 117] = '5';

    screen[nScreenWidth * 19 + 114] = 'P';
    screen[nScreenWidth * 19 + 115] = 'A';
    screen[nScreenWidth * 19 + 116] = '1';
    screen[nScreenWidth * 19 + 117] = '4';

    screen[nScreenWidth * 20 + 114] = 'P';
    screen[nScreenWidth * 20 + 115] = 'A';
    screen[nScreenWidth * 20 + 116] = '1';
    screen[nScreenWidth * 20 + 117] = '3';

    screen[nScreenWidth * 21 + 114] = 'P';
    screen[nScreenWidth * 21 + 115] = 'A';
    screen[nScreenWidth * 21 + 116] = '1';
    screen[nScreenWidth * 21 + 117] = '2';

    screen[nScreenWidth * 22 + 114] = 'P';
    screen[nScreenWidth * 22 + 115] = 'A';
    screen[nScreenWidth * 22 + 116] = '1';
    screen[nScreenWidth * 22 + 117] = '1';

    screen[nScreenWidth * 23 + 114] = 'P';
    screen[nScreenWidth * 23 + 115] = 'A';
    screen[nScreenWidth * 23 + 116] = '1';
    screen[nScreenWidth * 23 + 117] = '0';

    screen[nScreenWidth * 24 + 115] = 'P';
    screen[nScreenWidth * 24 + 116] = 'A';
    screen[nScreenWidth * 24 + 117] = '9';

    screen[nScreenWidth * 25 + 115] = 'P';
    screen[nScreenWidth * 25 + 116] = 'A';
    screen[nScreenWidth * 25 + 117] = '8';

    screen[nScreenWidth * 26 + 115] = 'P';
    screen[nScreenWidth * 26 + 116] = 'C';
    screen[nScreenWidth * 26 + 117] = '9';

    screen[nScreenWidth * 27 + 115] = 'P';
    screen[nScreenWidth * 27 + 116] = 'C';
    screen[nScreenWidth * 27 + 117] = '8';

    screen[nScreenWidth * 28 + 115] = 'P';
    screen[nScreenWidth * 28 + 116] = 'C';
    screen[nScreenWidth * 28 + 117] = '7';

    screen[nScreenWidth * 29 + 115] = 'P';
    screen[nScreenWidth * 29 + 116] = 'C';
    screen[nScreenWidth * 29 + 117] = '6';

    screen[nScreenWidth * 30 + 114] = 'G';
    screen[nScreenWidth * 30 + 115] = 'N';
    screen[nScreenWidth * 30 + 116] = 'D';
    screen[nScreenWidth * 30 + 117] = '2';


    while (true) {
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
        if ((GetAsyncKeyState((unsigned short)'1') & 0x8000) || (GetAsyncKeyState( 97) & 0x8000)) press_1   = 1; else press_1   = 0;
        if ((GetAsyncKeyState((unsigned short)'2') & 0x8000) || (GetAsyncKeyState( 98) & 0x8000)) press_2   = 1; else press_2   = 0;
        if ((GetAsyncKeyState((unsigned short)'3') & 0x8000) || (GetAsyncKeyState( 99) & 0x8000)) press_3   = 1; else press_3   = 0;
        if ((GetAsyncKeyState((unsigned short)'4') & 0x8000) || (GetAsyncKeyState(100) & 0x8000)) press_4   = 1; else press_4   = 0;
        if ((GetAsyncKeyState((unsigned short)'5') & 0x8000) || (GetAsyncKeyState(101) & 0x8000)) press_5   = 1; else press_5   = 0;
        if ((GetAsyncKeyState((unsigned short)'6') & 0x8000) || (GetAsyncKeyState(102) & 0x8000)) press_6   = 1; else press_6   = 0;
        if ((GetAsyncKeyState((unsigned short)'7') & 0x8000) || (GetAsyncKeyState(103) & 0x8000)) press_7   = 1; else press_7   = 0;
        if ((GetAsyncKeyState((unsigned short)'8') & 0x8000) || (GetAsyncKeyState(104) & 0x8000)) press_8   = 1; else press_8   = 0;
        if ((GetAsyncKeyState((unsigned short)'9') & 0x8000) || (GetAsyncKeyState(105) & 0x8000)) press_9   = 1; else press_9   = 0;
        if ((GetAsyncKeyState((unsigned short)'0') & 0x8000) || (GetAsyncKeyState(96)  & 0x8000)) press_0   = 1; else press_0   = 0;
        if  (GetAsyncKeyState(                107) & 0x8000)                                      press_add = 1; else press_add = 0;
        if ((GetAsyncKeyState(                189) & 0x8000) || (GetAsyncKeyState(109) & 0x8000)) press_sub = 1; else press_sub = 0;
        if  (GetAsyncKeyState(                106) & 0x8000)                                      press_mul = 1; else press_mul = 0;
        if  (GetAsyncKeyState(                111) & 0x8000)                                      press_div = 1; else press_div = 0;
        if ((GetAsyncKeyState(                187) & 0x8000) || (GetAsyncKeyState( 13) & 0x8000)) press_equ = 1; else press_equ = 0;
        if  (GetAsyncKeyState((unsigned short)'R') & 0x8000)                                      press_res = 1; else press_res = 0;

        /*dc.refresh();
        reg_1_1.refresh();*/
        kp.draw(screen, nScreenWidth, nScreenHeight, 1, 30);

        led_1_1.draw(screen, nScreenWidth, nScreenHeight,  1,  1);
        led_1_2.draw(screen, nScreenWidth, nScreenHeight,  8,  1);
        led_1_3.draw(screen, nScreenWidth, nScreenHeight, 15,  1);
        led_1_4.draw(screen, nScreenWidth, nScreenHeight, 22,  1);
        led_1_5.draw(screen, nScreenWidth, nScreenHeight, 29,  1);
        led_1_6.draw(screen, nScreenWidth, nScreenHeight, 36,  1);

        led_2_1.draw(screen, nScreenWidth, nScreenHeight, 50,  1);
        led_2_2.draw(screen, nScreenWidth, nScreenHeight, 57,  1);
        led_2_3.draw(screen, nScreenWidth, nScreenHeight, 64,  1);
        led_2_4.draw(screen, nScreenWidth, nScreenHeight, 71,  1);
        led_2_5.draw(screen, nScreenWidth, nScreenHeight, 78,  1);
        led_2_6.draw(screen, nScreenWidth, nScreenHeight, 85,  1);

        led_3_1.draw(screen, nScreenWidth, nScreenHeight,  1, 14);
        led_3_2.draw(screen, nScreenWidth, nScreenHeight,  8, 14);
        led_3_3.draw(screen, nScreenWidth, nScreenHeight, 15, 14);
        led_3_4.draw(screen, nScreenWidth, nScreenHeight, 22, 14);
        led_3_5.draw(screen, nScreenWidth, nScreenHeight, 29, 14);
        led_3_6.draw(screen, nScreenWidth, nScreenHeight, 36, 14);

        led_4_1.draw(screen, nScreenWidth, nScreenHeight, 50, 14);
        led_4_2.draw(screen, nScreenWidth, nScreenHeight, 57, 14);
        led_4_3.draw(screen, nScreenWidth, nScreenHeight, 64, 14);
        led_4_4.draw(screen, nScreenWidth, nScreenHeight, 71, 14);
        led_4_5.draw(screen, nScreenWidth, nScreenHeight, 78, 14);
        led_4_6.draw(screen, nScreenWidth, nScreenHeight, 85, 14);

        stm.PB[0] = 1;
        stm.PB[1] = 1;
        stm.PB[2] = 1;
        stm.PB[3] = 1;
        kp.refresh();
        if (*stm.PC[0] + *stm.PC[1] + *stm.PC[2] + *stm.PC[3] == 0) {
            stm.symbol = ' ';
            stm.btn_pressed = 0;
            stm.btn_processed = 0;
        } else {
            stm.btn_pressed = 1;
            if (*stm.PC[0]) {
                screen[nScreenWidth * 39 + 116] = '1';
                stm.PB[1] = 0;
                stm.PB[2] = 0;
                stm.PB[3] = 0;
                kp.refresh();
                if (*stm.PC[0]) {
                    stm.symbol = '1';
                }
                else {
                    stm.PB[1] = 1;
                    kp.refresh();
                    if (*stm.PC[0]) {
                        stm.symbol = '2';
                    }
                    else {
                        stm.PB[2] = 1;
                        kp.refresh();
                        if (*stm.PC[0]) {
                            stm.symbol = '3';
                        }
                        else {
                            stm.symbol = '+';
                        }
                    }
                }
            }
            else {
                screen[nScreenWidth * 39 + 116] = '0';
            }
            if (*stm.PC[1]) {
                screen[nScreenWidth * 39 + 117] = '1';
                stm.PB[1] = 0;
                stm.PB[2] = 0;
                stm.PB[3] = 0;
                kp.refresh();
                if (*stm.PC[1]) {
                    stm.symbol = '4';
                }
                else {
                    stm.PB[1] = 1;
                    kp.refresh();
                    if (*stm.PC[1]) {
                        stm.symbol = '5';
                    }
                    else {
                        stm.PB[2] = 1;
                        kp.refresh();
                        if (*stm.PC[1]) {
                            stm.symbol = '6';
                        }
                        else {
                            stm.symbol = '-';
                        }
                    }
                }
            }
            else {
                screen[nScreenWidth * 39 + 117] = '0';
            }
            if (*stm.PC[2]) {
                screen[nScreenWidth * 39 + 118] = '1';
                stm.PB[1] = 0;
                stm.PB[2] = 0;
                stm.PB[3] = 0;
                kp.refresh();
                if (*stm.PC[2]) {
                    stm.symbol = '7';
                }
                else {
                    stm.PB[1] = 1;
                    kp.refresh();
                    if (*stm.PC[2]) {
                        stm.symbol = '8';
                    }
                    else {
                        stm.PB[2] = 1;
                        kp.refresh();
                        if (*stm.PC[2]) {
                            stm.symbol = '9';
                        }
                        else {
                            stm.symbol = '*';
                        }
                    }
                }
            }
            else {
                screen[nScreenWidth * 39 + 118] = '0';
            }
            if (*stm.PC[3]) {
                screen[nScreenWidth * 39 + 119] = '1';
                stm.PB[1] = 0;
                stm.PB[2] = 0;
                stm.PB[3] = 0;
                kp.refresh();
                if (*stm.PC[3]) {
                    stm.symbol = 'R';
                }
                else {
                    stm.PB[1] = 1;
                    kp.refresh();
                    if (*stm.PC[3]) {
                        stm.symbol = '0';
                    }
                    else {
                        stm.PB[2] = 1;
                        kp.refresh();
                        if (*stm.PC[3]) {
                            stm.symbol = '=';
                        }
                        else {
                            stm.symbol = '/';
                        }
                    }
                }
            }
            else {
                screen[nScreenWidth * 39 + 119] = '0';
            }
        }
        
        if (stm.btn_pressed && !stm.btn_processed) {
            stm.btn_processed = 1;
            if (stm.symbol == 'R') {
                stm.digit = 0;
                stm.part = 0;
                stm.step = 0;
                stm.num = 0;
                stm.is_neg = false;
                for (int i = 0; i < 4; i++) {
                    stm.q1[i] = 0;
                    stm.q2[i] = 0;
                    stm.q[i] = 0;
                }
                stm.set_data(0,0,0,0,0,0,0);
                stm.CLK = 1;

                stm.choose_reg(1, 0, 0, 0, 0); dc.refresh(); reg_1_1.refresh();
                stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();
                stm.choose_reg(1, 1, 0, 0, 0); dc.refresh(); reg_1_3.refresh();
                stm.choose_reg(0, 0, 1, 0, 0); dc.refresh(); reg_1_4.refresh();
                stm.choose_reg(1, 0, 1, 0, 0); dc.refresh(); reg_1_5.refresh();
                stm.choose_reg(0, 1, 1, 0, 0); dc.refresh(); reg_1_6.refresh();

                stm.choose_reg(1, 1, 1, 0, 0); dc.refresh(); reg_2_1.refresh();
                stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();
                stm.choose_reg(1, 0, 0, 1, 0); dc.refresh(); reg_2_3.refresh();
                stm.choose_reg(0, 1, 0, 1, 0); dc.refresh(); reg_2_4.refresh();
                stm.choose_reg(1, 1, 0, 1, 0); dc.refresh(); reg_2_5.refresh();
                stm.choose_reg(0, 0, 1, 1, 0); dc.refresh(); reg_2_6.refresh();

                stm.choose_reg(1, 0, 1, 1, 0); dc.refresh(); reg_3_1.refresh();
                stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();
                stm.choose_reg(1, 1, 1, 1, 0); dc.refresh(); reg_3_3.refresh();
                stm.choose_reg(0, 0, 0, 0, 1); dc.refresh(); reg_3_4.refresh();
                stm.choose_reg(1, 0, 0, 0, 1); dc.refresh(); reg_3_5.refresh();
                stm.choose_reg(0, 1, 0, 0, 1); dc.refresh(); reg_3_6.refresh();

                stm.choose_reg(1, 1, 0, 0, 1); dc.refresh(); reg_4_1.refresh();
                stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();
                stm.choose_reg(1, 0, 1, 0, 1); dc.refresh(); reg_4_3.refresh();
                stm.choose_reg(0, 1, 1, 0, 1); dc.refresh(); reg_4_4.refresh();
                stm.choose_reg(1, 1, 1, 0, 1); dc.refresh(); reg_4_5.refresh();
                stm.choose_reg(0, 0, 0, 1, 1); dc.refresh(); reg_4_6.refresh();
                stm.CLK = 0;
            }
            else {
                if (stm.step == 0 && stm.part == 0 && stm.digit == 0) {
                    stm.num = 0;
                    stm.is_neg = false;
                    for (int i = 0; i < 4; i++) {
                        stm.q1[i] = 0;
                        stm.q2[i] = 0;
                        stm.q[i] = 0;
                    }   
                }
                if (stm.step == 0 || stm.step == 2) {
                    if (stm.digit == 0) {
                        if (stm.symbol == '-') {
                            stm.is_neg = true;
                            stm.digit += 1;
                            stm.set_symbol();
                            stm.CLK = 1;
                            switch (stm.part) {
                            case 0: stm.choose_reg(1, 0, 0, 0, 0); dc.refresh(); reg_1_1.refresh();break;
                            case 1: stm.choose_reg(1, 1, 1, 0, 0); dc.refresh(); reg_2_1.refresh();break;
                            case 2: stm.choose_reg(1, 0, 1, 1, 0); dc.refresh(); reg_3_1.refresh();break;
                            case 3: stm.choose_reg(1, 1, 0, 0, 1); dc.refresh(); reg_4_1.refresh();break;
                            }
                            stm.CLK = 0;
                        } else {
                            if (stm.symbol >= '0' && stm.symbol <= '9') {
                                stm.is_neg = false;
                                stm.digit += 2;
                                stm.num += sti(stm.symbol) * 10000;
                                stm.set_symbol();
                                stm.CLK = 1;
                                switch (stm.part) {
                                case 0: stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();break;
                                case 1: stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();break;
                                case 2: stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();break;
                                case 3: stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();break;
                                }
                                stm.CLK = 0;
                            }
                        }
                    } else {
                        if (stm.symbol >= '0' && stm.symbol <= '9') {
                            stm.num += sti(stm.symbol) * pow(10, 5 - stm.digit);
                            screen[nScreenWidth * 35 + 109] = its((stm.q2[0]) % 10);
                            screen[nScreenWidth * 35 + 108] = its((stm.q2[0] / 10) % 10);
                            screen[nScreenWidth * 35 + 107] = its((stm.q2[0] / 100) % 10);
                            screen[nScreenWidth * 35 + 106] = its((stm.q2[0] / 1000) % 10);
                            screen[nScreenWidth * 35 + 105] = its((stm.q2[0] / 10000) % 10);
                            stm.set_symbol();
                            stm.CLK = 1;
                            switch (stm.part) {
                            case 0: 
                                switch (stm.digit) {
                                case 1: stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();break;
                                case 2: stm.choose_reg(1, 1, 0, 0, 0); dc.refresh(); reg_1_3.refresh();break;
                                case 3: stm.choose_reg(0, 0, 1, 0, 0); dc.refresh(); reg_1_4.refresh();break;
                                case 4: stm.choose_reg(1, 0, 1, 0, 0); dc.refresh(); reg_1_5.refresh();break;
                                case 5: stm.choose_reg(0, 1, 1, 0, 0); dc.refresh(); reg_1_6.refresh();break;
                                }
                                break;
                            case 1:
                                switch (stm.digit) {
                                case 1: stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();break;
                                case 2: stm.choose_reg(1, 0, 0, 1, 0); dc.refresh(); reg_2_3.refresh();break;
                                case 3: stm.choose_reg(0, 1, 0, 1, 0); dc.refresh(); reg_2_4.refresh();break;
                                case 4: stm.choose_reg(1, 1, 0, 1, 0); dc.refresh(); reg_2_5.refresh();break;
                                case 5: stm.choose_reg(0, 0, 1, 1, 0); dc.refresh(); reg_2_6.refresh();break;
                                }
                                break;
                            case 2:
                                switch (stm.digit) {
                                case 1: stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();break;
                                case 2: stm.choose_reg(1, 1, 1, 1, 0); dc.refresh(); reg_3_3.refresh();break;
                                case 3: stm.choose_reg(0, 0, 0, 0, 1); dc.refresh(); reg_3_4.refresh();break;
                                case 4: stm.choose_reg(1, 0, 0, 0, 1); dc.refresh(); reg_3_5.refresh();break;
                                case 5: stm.choose_reg(0, 1, 0, 0, 1); dc.refresh(); reg_3_6.refresh();break;
                                }
                                break;
                            case 3:
                                
                                switch (stm.digit) {
                                case 1: stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();break;
                                case 2: stm.choose_reg(1, 0, 1, 0, 1); dc.refresh(); reg_4_3.refresh();break;
                                case 3: stm.choose_reg(0, 1, 1, 0, 1); dc.refresh(); reg_4_4.refresh();break;
                                case 4: stm.choose_reg(1, 1, 1, 0, 1); dc.refresh(); reg_4_5.refresh();break;
                                case 5: stm.choose_reg(0, 0, 0, 1, 1); dc.refresh(); reg_4_6.refresh();break;
                                }
                                break;
                            }
                            stm.CLK = 0;
                            stm.digit += 1;
                        }
                    }
                    screen[nScreenWidth * 35 + 109] = its((stm.num) % 10);
                    screen[nScreenWidth * 35 + 108] = its((stm.num / 10) % 10);
                    screen[nScreenWidth * 35 + 107] = its((stm.num / 100) % 10);
                    screen[nScreenWidth * 35 + 106] = its((stm.num / 1000) % 10);
                    screen[nScreenWidth * 35 + 105] = its((stm.num / 10000) % 10);
                    if (stm.digit == 6) {
                        stm.digit = 0;
                        if (stm.is_neg) stm.num = -stm.num;
                        if (stm.step == 0) stm.q1[stm.part] = stm.num;
                        if (stm.step == 2) stm.q2[stm.part] = stm.num;
                        stm.num = 0;
                        if (stm.part == 3) {
                            stm.part = 0;
                            stm.step ++;
                        } else {
                            stm.part ++;
                        }
                    }
                    //stm.num
                } else {
                    if (stm.step == 1) {
                        if (stm.symbol == '+' || stm.symbol == '-' || stm.symbol == '*' || stm.symbol == '/') {
                            stm.op = stm.symbol;
                            stm.step++;
                            stm.set_data(0, 0, 0, 0, 0, 0, 0);
                            stm.CLK = 1;

                            stm.choose_reg(1, 0, 0, 0, 0); dc.refresh(); reg_1_1.refresh();
                            stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();
                            stm.choose_reg(1, 1, 0, 0, 0); dc.refresh(); reg_1_3.refresh();
                            stm.choose_reg(0, 0, 1, 0, 0); dc.refresh(); reg_1_4.refresh();
                            stm.choose_reg(1, 0, 1, 0, 0); dc.refresh(); reg_1_5.refresh();
                            stm.choose_reg(0, 1, 1, 0, 0); dc.refresh(); reg_1_6.refresh();

                            stm.choose_reg(1, 1, 1, 0, 0); dc.refresh(); reg_2_1.refresh();
                            stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();
                            stm.choose_reg(1, 0, 0, 1, 0); dc.refresh(); reg_2_3.refresh();
                            stm.choose_reg(0, 1, 0, 1, 0); dc.refresh(); reg_2_4.refresh();
                            stm.choose_reg(1, 1, 0, 1, 0); dc.refresh(); reg_2_5.refresh();
                            stm.choose_reg(0, 0, 1, 1, 0); dc.refresh(); reg_2_6.refresh();

                            stm.choose_reg(1, 0, 1, 1, 0); dc.refresh(); reg_3_1.refresh();
                            stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();
                            stm.choose_reg(1, 1, 1, 1, 0); dc.refresh(); reg_3_3.refresh();
                            stm.choose_reg(0, 0, 0, 0, 1); dc.refresh(); reg_3_4.refresh();
                            stm.choose_reg(1, 0, 0, 0, 1); dc.refresh(); reg_3_5.refresh();
                            stm.choose_reg(0, 1, 0, 0, 1); dc.refresh(); reg_3_6.refresh();

                            stm.choose_reg(1, 1, 0, 0, 1); dc.refresh(); reg_4_1.refresh();
                            stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();
                            stm.choose_reg(1, 0, 1, 0, 1); dc.refresh(); reg_4_3.refresh();
                            stm.choose_reg(0, 1, 1, 0, 1); dc.refresh(); reg_4_4.refresh();
                            stm.choose_reg(1, 1, 1, 0, 1); dc.refresh(); reg_4_5.refresh();
                            stm.choose_reg(0, 0, 0, 1, 1); dc.refresh(); reg_4_6.refresh();
                            stm.CLK = 0;
                        }
                    } else {
                        if (stm.step == 3) {
                            if (stm.symbol == '=') {
                                stm.set_data(0, 0, 0, 0, 0, 0, 0);
                                stm.CLK = 1;

                                stm.choose_reg(1, 0, 0, 0, 0); dc.refresh(); reg_1_1.refresh();
                                stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();
                                stm.choose_reg(1, 1, 0, 0, 0); dc.refresh(); reg_1_3.refresh();
                                stm.choose_reg(0, 0, 1, 0, 0); dc.refresh(); reg_1_4.refresh();
                                stm.choose_reg(1, 0, 1, 0, 0); dc.refresh(); reg_1_5.refresh();
                                stm.choose_reg(0, 1, 1, 0, 0); dc.refresh(); reg_1_6.refresh();

                                stm.choose_reg(1, 1, 1, 0, 0); dc.refresh(); reg_2_1.refresh();
                                stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();
                                stm.choose_reg(1, 0, 0, 1, 0); dc.refresh(); reg_2_3.refresh();
                                stm.choose_reg(0, 1, 0, 1, 0); dc.refresh(); reg_2_4.refresh();
                                stm.choose_reg(1, 1, 0, 1, 0); dc.refresh(); reg_2_5.refresh();
                                stm.choose_reg(0, 0, 1, 1, 0); dc.refresh(); reg_2_6.refresh();

                                stm.choose_reg(1, 0, 1, 1, 0); dc.refresh(); reg_3_1.refresh();
                                stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();
                                stm.choose_reg(1, 1, 1, 1, 0); dc.refresh(); reg_3_3.refresh();
                                stm.choose_reg(0, 0, 0, 0, 1); dc.refresh(); reg_3_4.refresh();
                                stm.choose_reg(1, 0, 0, 0, 1); dc.refresh(); reg_3_5.refresh();
                                stm.choose_reg(0, 1, 0, 0, 1); dc.refresh(); reg_3_6.refresh();

                                stm.choose_reg(1, 1, 0, 0, 1); dc.refresh(); reg_4_1.refresh();
                                stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();
                                stm.choose_reg(1, 0, 1, 0, 1); dc.refresh(); reg_4_3.refresh();
                                stm.choose_reg(0, 1, 1, 0, 1); dc.refresh(); reg_4_4.refresh();
                                stm.choose_reg(1, 1, 1, 0, 1); dc.refresh(); reg_4_5.refresh();
                                stm.choose_reg(0, 0, 0, 1, 1); dc.refresh(); reg_4_6.refresh();
                                stm.CLK = 0;
                                stm.do_op();
                                stm.CLK = 1;

                                if (stm.q[0] < 0) { stm.symbol = '-'; stm.q[0] *= -1; } else stm.symbol = ' ';
                                stm.set_symbol(); stm.choose_reg(1, 0, 0, 0, 0); dc.refresh(); reg_1_1.refresh();
                                stm.symbol = its(stm.q[0] % 10);
                                /*screen[nScreenWidth * 35 + 109] = its((stm.q[0]) % 10);
                                screen[nScreenWidth * 35 + 108] = its((stm.q[0]/10) % 10);
                                screen[nScreenWidth * 35 + 107] = its((stm.q[0]/100) % 10);
                                screen[nScreenWidth * 35 + 106] = its((stm.q[0] / 1000) % 10);
                                screen[nScreenWidth * 35 + 105] = its((stm.q[0] / 10000) % 10);*/
                                //if (stm.q[0]==9) screen[nScreenWidth * 35 + 111] = '1'; else screen[nScreenWidth * 35 + 109] = '0';
                                stm.set_symbol(); stm.choose_reg(0, 1, 1, 0, 0); dc.refresh(); reg_1_6.refresh();
                                stm.symbol = its(stm.q[0]/10 % 10); 
                                stm.set_symbol(); stm.choose_reg(1, 0, 1, 0, 0); dc.refresh(); reg_1_5.refresh();
                                stm.symbol = its(stm.q[0]/100 % 10); 
                                stm.set_symbol(); stm.choose_reg(0, 0, 1, 0, 0); dc.refresh(); reg_1_4.refresh();
                                stm.symbol = its(stm.q[0]/1000 % 10); 
                                stm.set_symbol(); stm.choose_reg(1, 1, 0, 0, 0); dc.refresh(); reg_1_3.refresh();
                                stm.symbol = its(stm.q[0]/10000 % 10); 
                                stm.set_symbol(); stm.choose_reg(0, 1, 0, 0, 0); dc.refresh(); reg_1_2.refresh();

                                if (stm.q[1] < 0) { stm.symbol = '-'; stm.q[1] *= -1; } else stm.symbol = ' ';
                                stm.set_symbol(); stm.choose_reg(1, 1, 1, 0, 0); dc.refresh(); reg_2_1.refresh();
                                stm.symbol = its(stm.q[1] % 10);
                                stm.set_symbol(); stm.choose_reg(0, 0, 1, 1, 0); dc.refresh(); reg_2_6.refresh();
                                stm.symbol = its(stm.q[1] / 10 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 1, 0, 1, 0); dc.refresh(); reg_2_5.refresh();
                                stm.symbol = its(stm.q[1] / 100 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 1, 0, 1, 0); dc.refresh(); reg_2_4.refresh();
                                stm.symbol = its(stm.q[1] / 1000 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 0, 0, 1, 0); dc.refresh(); reg_2_3.refresh();
                                stm.symbol = its(stm.q[1] / 10000 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 0, 0, 1, 0); dc.refresh(); reg_2_2.refresh();

                                if (stm.q[2] < 0) { stm.symbol = '-'; stm.q[2] *= -1; }
                                else stm.symbol = ' ';
                                stm.set_symbol(); stm.choose_reg(1, 0, 1, 1, 0); dc.refresh(); reg_3_1.refresh();
                                stm.symbol = its(stm.q[2] % 10);
                                stm.set_symbol(); stm.choose_reg(0, 1, 0, 0, 1); dc.refresh(); reg_3_6.refresh();
                                stm.symbol = its(stm.q[2] / 10 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 0, 0, 0, 1); dc.refresh(); reg_3_5.refresh();
                                stm.symbol = its(stm.q[2] / 100 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 0, 0, 0, 1); dc.refresh(); reg_3_4.refresh();
                                stm.symbol = its(stm.q[2] / 1000 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 1, 1, 1, 0); dc.refresh(); reg_3_3.refresh();
                                stm.symbol = its(stm.q[2] / 10000 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 1, 1, 1, 0); dc.refresh(); reg_3_2.refresh();

                                if (stm.q[3] < 0) { stm.symbol = '-'; stm.q[3] *= -1; }
                                else stm.symbol = ' ';
                                stm.set_symbol(); stm.choose_reg(1, 1, 0, 0, 1); dc.refresh(); reg_4_1.refresh();
                                stm.symbol = its(stm.q[3] % 10);
                                stm.set_symbol(); stm.choose_reg(0, 0, 0, 1, 1); dc.refresh(); reg_4_6.refresh();
                                stm.symbol = its(stm.q[3] / 10 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 1, 1, 0, 1); dc.refresh(); reg_4_5.refresh();
                                stm.symbol = its(stm.q[3] / 100 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 1, 1, 0, 1); dc.refresh(); reg_4_4.refresh();
                                stm.symbol = its(stm.q[3] / 1000 % 10);
                                stm.set_symbol(); stm.choose_reg(1, 0, 1, 0, 1); dc.refresh(); reg_4_3.refresh();
                                stm.symbol = its(stm.q[3] / 10000 % 10);
                                stm.set_symbol(); stm.choose_reg(0, 0, 1, 0, 1); dc.refresh(); reg_4_2.refresh();
                            }
                        }
                    }
                }
                
            }
        }
        
        screen[nScreenWidth * 38 + 119] = (wchar_t)stm.symbol;
        screen[nScreenWidth * 35 + 113] = 's';
        screen[nScreenWidth * 35 + 114] = 't';
        screen[nScreenWidth * 35 + 115] = 'e';
        screen[nScreenWidth * 35 + 116] = 'p';
        screen[nScreenWidth * 35 + 117] = ':';
        screen[nScreenWidth * 35 + 118] = ' ';
        screen[nScreenWidth * 35 + 119] = its(stm.step);
        screen[nScreenWidth * 36 + 113] = 'p';
        screen[nScreenWidth * 36 + 114] = 'a';
        screen[nScreenWidth * 36 + 115] = 'r';
        screen[nScreenWidth * 36 + 116] = 't';
        screen[nScreenWidth * 36 + 117] = ':';
        screen[nScreenWidth * 36 + 118] = ' ';
        screen[nScreenWidth * 36 + 119] = its(stm.part);
        screen[nScreenWidth * 37 + 112] = 'd';
        screen[nScreenWidth * 37 + 113] = 'i';
        screen[nScreenWidth * 37 + 114] = 'g';
        screen[nScreenWidth * 37 + 115] = 'i';
        screen[nScreenWidth * 37 + 116] = 't';
        screen[nScreenWidth * 37 + 117] = ':';
        screen[nScreenWidth * 37 + 118] = ' ';
        screen[nScreenWidth * 37 + 119] = its(stm.digit);

        //screen[nScreenWidth * 36 + 114] = '1';
        //screen[0] = 
        /*L1.draw(screen, nScreenWidth, nScreenHeight, 2, 1);
        count++;
        if (count == 1000) {
            D[5] = 1;
            R1.write();
        }*/
    }
    return 0;
}

