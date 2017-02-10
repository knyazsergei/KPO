// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Controller.h"

int main()
{
	CController controller;
	controller.ReadData("input.txt");
	controller.SaveData("output.txt");

    return EXIT_SUCCESS;
}

