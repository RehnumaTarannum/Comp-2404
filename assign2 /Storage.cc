/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Brig.cc
 *   Purpose:   Assignment 2 , Comp 2404
 *   Author:    Rehnuma Tarannum, Abdul Bin Asif Niazi
 *   Date:      Feb 24 2015
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Storage.h"
using namespace std;

Storage::Storage (){
	cellArray = new CArray; 
}	

Storage::~Storage (){
	delete cellArray;
	
}


void Storage::retrieve(CArray** cells) {

	*cell = cellArray;
}

void Storage::update (UpdateType action, CArray* cells) {
	switch (action){
		case ADD:
			
			cellArray = cells;
			break;
	}
}
