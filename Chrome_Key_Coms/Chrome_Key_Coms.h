#ifndef CHROME_KEY_COMS_H
#define CHROME_KEY_COMS_H

#include <Arduino.h>

void tabMultiplier(int count);

void blink(int count);

void openCrosh();

void batteryTest();

void testCamera(int openGal, int waitGal, int toPlay);

void powerwash();

void powerwashConfOld();

void networkSelect();

void acceptTerms(int count);

void finishPowerwash();

void logout();

#endif
