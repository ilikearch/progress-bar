#pragma once
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#define NUM 101
#define SPACE ' '
#define POINT '.'
#define STYLE '='

typedef void(*flush_t)(double total,double current);

void FlushProcess(double total, double current);
void download(flush_t f);
