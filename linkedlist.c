#include<stdio.h>
#include "link.h"
#include<stdlib.h>
int main()      
{
        int choice;
        while(1){
                printf("\n 1.Create");
                printf("\n 2.Display");
                printf("\n 3.Insert at the beginning ");
                printf("\n 4.Insert at the end");
                printf("\n 5.Insert at specified position ");
                printf("\n 6.Delete from beginning ");
                printf("\n 7.Delete from the end ");
                printf("\n 8.Delete from specified position");
                printf("\n 9.search an element");
                printf("\n 10.search position");
                printf("\n Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                        	
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        display();
                                        break;
                        case 4:
                                        insert_end();
                                        display();
                                        break;
                        case 5:
                                        insert_pos();
                                        display();
                                        break;
                        case 6:
                                        delete_begin();
                                        display();
                                        break;
                        case 7:
                                        delete_end();
                                        display();
                                        break;
                        case 8:
                                        delete_pos();
                                        display();
                                        break;
                        case 9:
                                        	findelem();
                                        	break;
                        case 10:
                                        		findpos();
                                        		break;
                                        		case 11:
                                        			isempty();
                                        			break;
                        
                        default:
                                       exit(1);
                                        break;
                }
        }
        return 0;
}
