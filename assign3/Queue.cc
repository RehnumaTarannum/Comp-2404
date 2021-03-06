/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Brig.cc
 *   Purpose:   Assignment 3 , Comp 2404
 *   Author:    Rehnuma Tarannum, Abdul Bin Asif Niazi
 *   Date:      Mar 10 2015
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include "Queue.h"
#include "Pirate.h"
#include "defs.h"
#include <string>
#include <cstdlib>

using namespace std;

Queue::Queue(): head(0)
{}

Queue::Queue(Queue& old){
                    Node* temp = old.head;
                    head = 0;
                    while(temp != 0){
                    push(temp->data);
                    temp = temp->next;
                    }
}

Queue::~Queue(){
	Node* currNode = head;
	Node* nextNode;

  	while (currNode != 0) {
    		nextNode = currNode->next;
		delete currNode->data;
    		delete currNode;
    		currNode = nextNode;
  	} 
}

int Queue::push(Pirate* p){
     Node* newNode;
     newNode = new Node;
     newNode->data = p;
     newNode->next = 0;
          
          if (head==0){
            head = newNode;  
          }
          else{
           Node* curr = head;
            while(curr->next != 0){
             curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
          }
      return C_OK;
}

void Queue::pop(){
     if (!empty()){
     
     if (head->next==NULL){
     Node* currentNode =head;
     head=0;
     }
     else{
     Node* currentNode = head;
     currentNode=currentNode->next;
     currentNode->prev = 0;
     delete head;
     head = currentNode;
     }
}
    
}
          


Pirate* Queue::front(){
return head->data;        
}

bool Queue::empty(){
     if (head==0){
        return true;
     }
     return false;     
}

Pirate* Queue::find(int n){
        Node* currentNode = head;
        while (currentNode!=0){
              if (currentNode->data->getId() == n){      
                 return currentNode->data;
              }
              currentNode = currentNode->next;
        }
        
        return 0;
}

void Queue::remove(int n, Pirate* p){
     if (!empty()){
	Node* currentNode = head;

        while (currentNode!=0){
		int num = currentNode->data->getId();
		
		if (num == n){ 

                 //int pSpace = currentNode->data->getSpace();    
                 if(currentNode == head){

                                //pop();
				if (head->next==NULL){
    			 		Node* currentHead =head;
     					head=0;
     				}
     				else{
     					Node* currentHead = head;
     					currentHead=currentHead->next;
     					currentHead->prev = 0;
     					//delete head;
     					head = currentHead;
     				}
                               
                                p = currentNode->data;            
                 }
                 else if(currentNode->next == 0){

                                           Node* temp = currentNode->prev;
                                           temp->next =0;
					 
                                           
                                           p = currentNode->data;
                  }
                 else{  
                          Node* begin = currentNode->prev;
                          Node* end = currentNode->next;
                          begin->next = end;
                          end->prev = begin;
			 
                        
                          p = currentNode->data;
                 }
             
              }
               currentNode = currentNode->next;
        }
        }
}

