#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"
#define MAX_SIZE 10
#define INPUT_SIZE 1



int main() {

    struct person removed_member_customer;
    struct person removed_member_noncustomer;
    
    char input[INPUT_SIZE];
    scanf("%s", input);
    int case_no = atoi(input);

    switch(case_no)
    {
      case 1:
        printf("Using customer and non-customer queues:\n");
        printf("---------------------------------------\n");

        // TODO:
        // Create two queues of type queue, named customer and non-customer, 
        // and do as requested in the assignment document:
        struct queue* bankQueueCustomer;
        struct queue* bankQueueNonCustomer;
        // Create empty customer and non-customer queues of size 5 each
        bankQueueCustomer = create(5);
        bankQueueNonCustomer = create(5);
        // First, 4 non-customers come to the bank.
        
        for(int i=1;i<=4;i++){
          struct person new;
          new.isClient = false ;
          new.money = i * 100.0;
          add(bankQueueNonCustomer,new);
        }

        printf("4 non-customers are added to non-customer queue:\n");
        printf("Customer queue:\n");
        display_all(bankQueueCustomer);

        printf("Non-customer queue:\n");
        display_all(bankQueueNonCustomer);
        printf("\n");


        // Then 2 people who are customers   come in.
       for(int i=1;i<=2;i++){
          struct person new;
          new.isClient = true ;
          new.money = i * 100.0;
          add(bankQueueCustomer,new);
        }

        printf("2 customers are added to customer queue:\n");
        printf("Customer queue:\n");
        display_all(bankQueueCustomer);

        printf("Non-customer queue:\n");
        display_all(bankQueueNonCustomer);
        printf("\n");


        // Then 3 people take turns at the bank and exit their queues. 
        // But here, first the queue of customers will be empty, 
        // then the queue of non-customers will start to be processed.  
        // Therefore, until there are no more people in the customer queue, 
        //the customers will take turns to do their bank transactions

removed_member_customer = remove_person(bankQueueCustomer);
removed_member_customer = remove_person(bankQueueCustomer);
removed_member_noncustomer = remove_person(bankQueueNonCustomer);



printf("3 people exit the queue (2 customer, 1 non-customer):\n");
printf("Customer queue:\n");
display_all(bankQueueCustomer);

printf("Non-customer queue:\n");
display_all(bankQueueNonCustomer);
printf("\n");

break;
      
      case 2:
        printf("Using solely one queue:\n");
        printf("------------------------\n");

        // TODO
        // Create a queue of type queue, 
        // do the things requested in the assignment document
      
        // Create an empty queue of size 10

        // Add 5 non-customers to queue

        struct queue* bankQueue = create(10) ;
        printf("5 non-customers are added to queue:\n");
        for(int i=1;i<=5;i++){
          struct person new;
          new.isClient = false ;
          new.money = i * 100.0;
          add(bankQueue,new);
        }
        display_all(bankQueue);
        printf("\n");


        // Add 2 bank customers to the queue.

        printf("2 customers are added to queue:\n");
        for(int i=6;i<=7;i++){
          struct person new;
          new.isClient = true ;
          new.money = i * 100.0;
          add_customer(bankQueue,new);
        }
        display_all(bankQueue);
        printf("\n");


        // Add 4 new non-customers to the queue 
        // (Note that it will give an error if the queue is full)


        printf("4 non-customers are added to queue:\n");
        for(int i=8;i<=11;i++){
          struct person new;
          new.isClient = false ;
          new.money = i * 100.0;
          add(bankQueue,new);
        }
        display_all(bankQueue);
        printf("\n");

        // First remove 2 people from the queue. 

        printf("2 people are removed from the queue:\n");
        removed_member_customer = remove_person(bankQueue);
        removed_member_customer = remove_person(bankQueue);
        display_all(bankQueue);
        printf("\n");


        // Then add 1 non-bank customer
       
        
        printf("1 non-customers are added to queue:\n");
         for(int i=12;i<=12;i++){
          struct person new;
          new.isClient = false ;
          new.money = i * 100.0;
          add(bankQueue,new);
        }
        display_all(bankQueue);
        printf("\n");
      

        break;
    }

    return 0;
}
