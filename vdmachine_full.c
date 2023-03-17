#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> // Boolean
#include "windows.h"

// Create struct
struct Stuff
{
	char target;    
	char name[11];  
	int money;	
	int count;		
}; 

int main()
{
	// Struct information
	struct Stuff item[3] =
	{
		{'A', "Juice", 10, 3 },
		{'B', "Coffee", 15, 3 },
		{'C', "Tea", 20, 3 },
	};

	int itemCount = 3; 
	char input;        // input A,B,C
	char str[11];	   // input char array of string
	int userCoin;	   // insert coin
	int coin;		   // total
	int outCoin;	   // change
	int kind;		   // type of coins
	bool number;

	while (1)
	{
		//  Print the information

		printf(" |Target  Products     Price  Pcs | \n");

		for (int select = 0; select < itemCount; select++)
		{
			printf(" | (%c)    %-13s $%2d   %2d  | \n", item[select].target, item[select].name, item[select].money, item[select].count);
		}
		printf("\n Please select an item: \n");

		// Input str[] 
		fgets(str, sizeof(str), stdin);
		rewind(stdin); // Clean buffer

		if (strlen(str) != 2)
		{
			printf("Enter error\n");
			continue;
		}
		else
		{
			// Input = str[0];
			for (int select = 0; select < itemCount; select++)
			{
				// if: choose one product
				if (str[0] == item[select].target)
				{
					// if: sold out
					if (item[select].count == 0)
					{
						printf(" %s was sold out. \n\n", item[select].name);
					}
					// eles: in stock
					else
					{
						// Print the information
						printf("\n %s is $%d \n", item[select].name, item[select].money);
						printf("\n Please insert the coins. \n *[1,5,10,50] ONLY* : \n");

						// initial
						userCoin = 0;
						coin = 0;
						outCoin = 0;
						kind = 0;

						// Insert coins
						// Insert coins < price
						while (userCoin < item[select].money)
						{
							// Input
							fgets(str, sizeof(str), stdin);
							rewind(stdin); // Clean buffer

							number = true;

							// Only number can input
							// Boolean
							for (int insert = 0; insert < (strlen(str) - 1); insert++)
							{
									if ((str[insert] != '0')
										&& (str[insert] != '1')
										&& (str[insert] != '2')
										&& (str[insert] != '3')
										&& (str[insert] != '4')
										&& (str[insert] != '5')
										&& (str[insert] != '6')
										&& (str[insert] != '7')
										&& (str[insert] != '8')
										&& (str[insert] != '9'))
									{
										number = false; 
										break;
									}
								
							}			

							if (number)
							{
								// Transfer str[] to int 
								coin = atoi(str);

								// Determine the type of coins
								switch (coin)
								{
								case 1:
									userCoin += coin;
									break;

								case 5:
									userCoin += coin;
									break;

								case 10:
									userCoin += coin;
									break;

								case 50:
									userCoin += coin;
									break;

									// Other type
								default:
									printf(" Enter error \n");
									break;
								}

								printf(" Coins %d/%d \n", userCoin, item[select].money);
							}

							// Give change
							outCoin = userCoin - item[select].money;
							if (outCoin >= item[select].money)
							{
								printf("\n Give change: %d \n\n", outCoin);

								// Type of coins
								// NT$ 50
								kind = outCoin / 50;
								if (kind > 0)
								{
									printf(" $50: %d\n", kind);
									outCoin %= 50;
								}

								// NT$ 10
								kind = outCoin / 10;
								if (kind > 0)
								{
									printf(" $10: %d\n", kind);
									outCoin %= 10;
								}

								// NT$ 5
								kind = outCoin / 5;
								if (kind > 0)
								{
									printf(" $5: %d\n", kind);
									outCoin %= 5;
								}

								// NT$ 1
								kind = outCoin;
								if (kind > 0)
								{
									printf(" $1: %d\n", kind);
									outCoin %= 1;
								}
							}
							else
							{
								continue;
							}
							printf("\n\n Thx, have a nice day : ) \n\n\n");

							// Reduce an amount
							item[select].count--;

							Sleep(1000);
						}
					}
				}
			}
		}
	}
}
			
