/*
MIT License

Copyright (c) 2022 Erik van Zijst <erik.van.zijst@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
/*
 * Sound code derived from https://github.com/robsoncouto/arduino-songs by Robson Couto.
 */
#include <stdint.h>
#include "sound.h"

// TODO: put in progmem
int16_t tetris_notes[200] = {
    //Based on the arrangement at https://www.flutetunes.com/tunes.php?id=192
    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,

    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,
    NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8,

    NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,
    NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,
    NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,
    NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4,
    

    NOTE_E5,2,  NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,2,   NOTE_A4,2,
    NOTE_GS4,2,  NOTE_B4,4,  REST,4, 
    NOTE_E5,2,   NOTE_C5,2,
    NOTE_D5,2,   NOTE_B4,2,
    NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,
    NOTE_GS5,2, REST, 2,
};

const melody_t tetris_melody = {
    .notes = tetris_notes,
    .len = 100,             // sizeof(tetris_notes) / 2
    .tempo = 144
};

const uint16_t supermario_notes[618] = {
    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,8, //1
    NOTE_G5,4, REST,4, NOTE_G4,8, REST,4, 
    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 3
    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,
    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 3
    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4,NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

    REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//7
    REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
    REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
    NOTE_C5,2, REST,2,

    REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8,//repeats from 7
    REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8,
    REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4,
    NOTE_C5,2, REST,2,

    NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,//11
    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,

    NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,//13
    REST,1, 
    NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,
    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
    NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // 19

    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

    NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, // repeats from 19
    NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4,
    NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8,
    REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4,

    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//23
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
    NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,

    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,//repeats from 23
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //26
    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
    NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
    NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8,
    REST,1,

    NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, //33
    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,
    NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4,
    NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, 
    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8,

    NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, //40
    NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4,
    NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2,
    NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8,
    NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
};

const melody_t supermario_melody = {
    .notes = supermario_notes,
    .len = 618,
    .tempo = 200
};

const int16_t gameover_notes[24] = {
    NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4, //45
    NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8, NOTE_AS4,-8, NOTE_GS4,-8,
    NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2,  
};

const melody_t gameover_melody = {
    .notes = gameover_notes,
    .len = 12,
    .tempo = 144
};

// Super Mario flagpole sequence
const int16_t victory_notes[] = {
        NOTE_G2, 9,
        NOTE_C3, 9,
        NOTE_E3, 9,
        NOTE_G3, 9,
        NOTE_C4, 9,
        NOTE_E4, 9,
        NOTE_G4, 3,
        NOTE_E4, 3,

        NOTE_GS2, 9,
        NOTE_C3, 9,
        NOTE_DS3, 9,
        NOTE_GS3, 9,
        NOTE_C4, 9,
        NOTE_DS4, 9,
        NOTE_GS4, 3,
        NOTE_DS4, 3,
        NOTE_AS2, 9,
        NOTE_D3, 9,
        NOTE_F3, 9,
        NOTE_AS3, 9,
        NOTE_D4, 9,
        NOTE_F4, 9,
        NOTE_AS4, 3,
        NOTE_B4, 9,
        NOTE_B4, 9,
        NOTE_B4, 9,
        NOTE_C5, 1
};

const melody_t victory_melody = {
        .notes = victory_notes,
        .len = sizeof(victory_notes) / 4,
        .tempo = 188
};
