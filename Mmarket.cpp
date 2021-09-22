#include<iostream>
#include<string>
#include<fstream>
#include <algorithm>
#include <sstream>

/* Namespaces */
using namespace std;

/* Function Headers */
void customer(); // Customer Function Header
void membership(); //Membership Function Header
void staff(); //staff Function Header
string * *items(fstream & file);// Function to show the items from file
fstream handle("Mmarket-Items.txt"); //Definition of file and file name
string * *itemsFromFile = items(handle);
string bill[100][2]; //global array that will show the bill
int ic, pc; // Global veriables
string name;// Globle veriable

int main() { // main function
 //Variables definition
 int select;
	string memberCode;
	 string staffCode;
	 cout << "\t\t\t\t\t************************************" << endl;
	 cout << "\t\t\t\t\t\tWelcome to our market" << endl;
	 cout << "\t\t\t\t\t************************************" << endl;
	 cout << "Please dear valuable customer enter your name: "; getline(cin, name);
	 cout << "Enter [1] If you are customer" << endl;
	 cout << "Enter [2] If you are member" << endl;
     cout << "Enter [3] If you are staff" << endl;
	 cout << "Input: "; 
	 cin >> select;
	 /* If and else if loop to know the user is customer or member or staff */
		 if (select == 1) {
		 customer(); //call customer function
		
	}
	else if (select == 2) {
		
			 cout << "please enter the member code:" << endl;
		cin >> memberCode;
		if (memberCode == "member" || memberCode == "MEMBER") { /* The loop is for the
		member entered wrong code */
			 membership(); // call membership function
			
		}
		 else {
			cout << " the code is wrong" << endl;
			cout << "please enter the member code again " << endl;
			cin >> memberCode;
			if (memberCode == "member" || memberCode == "MEMBER") {
				membership(); // call membership function 
			
			}
			else {
				cout << " the code is wrong" << endl;
				cout << "please enter the member code last time " << endl;
				cin >> memberCode;
				if (memberCode == "member" || memberCode == "MEMBER") {
					 membership(); // call membership function
					
				}
				else {
					 /*If member enter the code three times wrong the program will retur
					n mine funcion */
						 cout << "sorry your are not member" << endl;
					 cout << "///////////////////////////////////////////////////////" << endl;
					 return main();
					
				}
				
					
			}
			
				
		}
		
			
	}
	 else if (select == 3) {
		
			 cout << "please enter the staff code" << endl;
		 cin >> staffCode;
		 if (staffCode == "staff" || staffCode == "STAFF") {
			 staff(); // call staff function
			
		}
		 else {
			 cout << " the code is wrong" << endl;
			 cout << "please enter the staff code again " << endl;
			 cin >> staffCode;
			 if (staffCode == "staff" || staffCode == "STAFF") { /* The if /else if loop
			is for the member entered wrong code */
				 staff();// call staff function
				
			}
			 else {
				 cout << " the code is wrong" << endl;
				 cout << "please enter the staff code last time " << endl;
				 cin >> staffCode;
				 if (staffCode == "staff" || staffCode == "STAFF") {
					 staff();// call staff function
					
				}
				else {
					 cout << "sorry your are not staff" << endl;
					 cout << "*************" << endl;
					 return main();
					
				}
				
			}
			
		}
		
			
	}
	 else {
		 cout << "FATAL ERROR! Whatever it is you have done. Don't do it again please" << endl;
		 return main();
		
	}
	
}

string * *items(fstream & file) {/*This functio to read from file*/
	
		 string content;
	 string * *items = 0;
	 items = new string * [8];
	 for (size_t h = 0; h < 8; h++)
		 {
		 items[h] = new string[2];
		 }
	
		 int i, k;
	 i = k = 0;
	 while (getline(file, content))
		 {
		
			 istringstream iss(content);//enable interoperation between stream buffer
		 string sub;
		 while (iss >> sub)// take iss and put it into sub
			 {
			 items[i][k] = sub;
			 k++;
			 }
		 k = 0;
		 i++;
		 }
	 return items;
	
}


void customer()
{
	 //Variables definition.
		 int itemsCount = 0;
	 int itemChoice = 0;
	 float total = 0.0;
	 float discount = 0.0;
	 float amount = 0;
	 for (size_t i = 0; i < 8; i++)/* for loop to show items from file */
		 {
		 cout << "[" << i + 1 << "]" << itemsFromFile[i][0];
		
			 cout << endl;
		 }
	
		
		 cout << "how many items that you want to buy" << endl;
	 cin >> itemsCount;
	 cout << "choose the item by typing number from [1]to[8] " << endl;
	
		 ic = pc = 0;
	 for (int x = 0; x < itemsCount; x++) {
		 cin >> itemChoice;
		 if (itemChoice == 1) { // if /else if loop for eight items.
			 total += 299;
			 cout << " Microwave[299MYR]" << endl;
			 if (ic > 100) // if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Microwave";
				 pc++;
				 bill[ic][pc] = "299";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 2) {
			 total += 40;
			 cout << " Iron[40MYR]" << endl;
			 if (ic > 100) // if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 bill[ic][pc] = "Iron";
				 pc++;
				 bill[ic][pc] = "40";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 3) {
			 total += 80;
			 cout << " Rice Cooker[80MYR]" << endl;
			 if (ic > 100) // if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Rice Cooker";
				 pc++;
				 bill[ic][pc] = "80";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 4) {
			 total += 50;
			 cout << " Hair Dryer[50MYR]" << endl;
			 if (ic > 100) // if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Hair Dryer";
				 pc++;
				 bill[ic][pc] = "50";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 5) {
			 total += 12;
			 cout << " Shoe Rack[12MYR] " << endl;
			 if (ic > 100) // if loop for bill 
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Shoe Rack";
				 pc++;
				 bill[ic][pc] = "12";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 6) {
			 total += 24;
			 cout << " KitchenCarpet[24MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Kitchen carpet";
				 pc++;
				 bill[ic][pc] = "24";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 7) {
			 total += 40;
			 cout << "MicroSD=40" << endl;
			 if (ic > 100) // if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "MicroSD";
				 pc++;
				 bill[ic][pc] = "40";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 8) {
			 total += 10;
			 cout << "Mini Speaker=10" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Mini Speaker";
				 pc++;
				 bill[ic][pc] = "10";
				 ic++;
				 pc = 0;
				 }
			
				
		}
		
			
			
	}
	 cout << "-----------------------------------" << endl;
	 cout << "the total =[" << total << "]" << endl; // total.
	
		
		 if (total >= 300) {
		 discount = total;
		 amount = total * 0.05;
		 discount -= amount;
		 cout << "the discount =[" << amount << "]" << endl;// the discount.
		
			 cout << "the total after discount =[ " << discount << "]" << endl; // total after discount.
			
	}
	
		 string yes_no;
	 cout << "Would you like to print out your bill? [y/n]? "; cin >> yes_no;
	 /* Transform to lowercase */
		 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
	 if (yes_no == "y") //If user entered y the bill will be printed.
		 {
		 for (size_t i = 0; i < itemsCount; i++)
			 {
			 for (size_t j = 0; j < 2; j++)
				 {
				 if (j == 0)
					 {
					 cout << i + 1 << "- " << bill[i][j];
					 }
				 else
					 {
					 cout << "\t\tRM" << bill[i][j];
					 }
				
					 }
			 cout << endl;
			 }
		 cout << "----------------------------------------------------------------------------" << endl;
			 discount = total;
		 cout << "Total: \t\t\tRM" << total << endl;
		 cout << "the discount: \t\tRM" << amount << endl;
		 cout << "Total after discount: RM" << discount - amount << endl;
		 cout << "Would you like to save your bill in file? [y/n]"; cin >> yes_no;
		 /* Transform to lowercase */
			 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
		 if (yes_no == "y") // this if to print out the bill into file.
			 {
			 ofstream file("bill.txt");
			 if (file.is_open())
				 {
				 file << "A bill for: " << name << endl;
				 for (size_t i = 0; i < itemsCount; i++)
					 {
					 for (size_t j = 0; j < 2; j++)
						 {
						 if (j == 0)
							 {
							 file << i + 1 << "- " << bill[i][j];
							 }
						 else
							 {
							 file << "\t\tRM" << bill[i][j];
							 }
						
							 }
					
						 file << endl;
					 }
				 file << "----------------------------------------------------------------------------" << endl;
					 file << "Total: \t\t\tRM" << total << endl;
				 file << "the discount \t\t" << amount << endl;
				 file << "Total after discount: RM" << discount - discount << endl;
				 }
			 file.close();
			 cout << "Thank you for shopping with us!" << endl;
			
				 }
		 else
			 {
			 cout << "Thank you for shopping with us!" << endl;
			 }
		 }
	 else
		 {
		 cout << "Thank you for shopping with us!" << endl;
		 }
	}

void membership()
{
	 //Variables definition
		 int itemsCount = 0;
	 int itemChoice = 0;
	 float total = 0.0;
	 float discount = 0.0;
	 float amount = 0;
	 for (size_t i = 0; i < 8; i++)/* for loop to show items from file */
		 {
		 cout << "[" << i + 1 << "]" << itemsFromFile[i][1];
		
			 cout << endl;
		 }
	 cout << "how many items that you want to buy" << endl;
	 cin >> itemsCount;
	 cout << "choose the item by typing number from [1]to[8] " << endl;
	
		 ic = pc = 0;
	 for (int x = 0; x < itemsCount; x++) { // if /else if loop for eight items.
		 cin >> itemChoice;
		 if (itemChoice == 1) {
			 total += 250;
			 cout << " Microwave[250MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {
				 /* open bill array and put item name and price*/
					 bill[ic][pc] = "Microwave";
				 pc++;
				 bill[ic][pc] = "250";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 2) {
			 total += 35;
			 cout << " Iron[35MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {/* open bill array and put item name and price*/
				 bill[ic][pc] = "Iron";
				 pc++;
				 bill[ic][pc] = "35";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 3) {
			 total += 75;
			 cout << " Rice Cooker[75MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 {/* open bill array and put item name and price*/
				 bill[ic][pc] = "Rice Cooker";
				 pc++;
				 bill[ic][pc] = "75";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 4) {
			 total += 47;
			 cout << " Hair Dryer[47MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Hair Dryer";
				 pc++;
				 bill[ic][pc] = "47";
				 ic++;
				 pc = 0;
				 }
			
				
		}
		 else if (itemChoice == 5) {
			 total += 12;
			 cout << " Shoe Rack[12MYR] " << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Shoe Rack";
				 pc++;
				 bill[ic][pc] = "12";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 6) {
			 total += 24;
			 cout << " KitchenCarpet[24MYR]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "KitchenCarpet";
				 pc++;
				 bill[ic][pc] = "24";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 7) {
			 total += 35;
			 cout << "MicroSD[35]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "MicroSD";
				 pc++;
				 bill[ic][pc] = "35";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 8) {
			 total += 10;
			 cout << "Mini Speaker[10]" << endl;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Mini Speaker";
				 pc++;
				 bill[ic][pc] = "10";
				 ic++;
				 pc = 0;
				 }
			
		}
		
			
			
	}
	 cout << "-----------------------------------" << endl;
	 cout << "The total =[" << total << "]" << endl;
	
		
		 if (total >= 300) {
		 discount = total;
		 amount = total * 0.05;
		 discount -= amount;
		 cout << "the discount =[" << amount << "]" << endl;// the discount.
		
			 cout << "the total after discount =[ " << discount << "]" << endl; // total after discount.
			
	}
	 string yes_no;
	 cout << "Would you like to print out your bill? [y/n]? "; cin >> yes_no;
	 /* Transform to lowercase */
		 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
	 if (yes_no == "y") // print out the bill
		 {
		 for (size_t i = 0; i < itemsCount; i++)
			 {
			 for (size_t j = 0; j < 2; j++)
				 {
				 if (j == 0)
					 {
					 cout << i + 1 << "- " << bill[i][j];
					 }
				 else
					 {
					 cout << "\t\tRM" << bill[i][j];
					 }
				
					 }
			 cout << endl;
			 }
		 cout << "----------------------------------------------------------------------------" << endl;
			 discount = total;
		 cout << "Total: \t\t\tRM" << total << endl;
		 cout << "the discount\t\t" << amount << endl;
		 cout << "Total after discount: RM" << discount - amount << endl;
		 cout << "Would you like to save your bill in file? [y/n]"; cin >> yes_no;
		 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
		 if (yes_no == "y") // print out the bill into file
			 {
			 ofstream file("bill.txt");
			 if (file.is_open())
				 {
				 file << "A bill for: " << name << endl;
				 for (size_t i = 0; i < itemsCount; i++)
					 {
					 for (size_t j = 0; j < 2; j++)
						 {
						 if (j == 0)
							 {
							 file << i + 1 << "- " << bill[i][j];
							 }
						 else
							 {
							 file << "\t\tRM" << bill[i][j];
							 }
						
							 }
					
						 file << endl;
					 }
				 file << "----------------------------------------------------------------------------" << endl;
					 file << "Total: \t\t\tRM" << total << endl;
				 file << "the discount\t\t" << amount << endl;
				 file << "Total after discount: RM" << discount - amount << endl;
				 }
			 file.close();
			 cout << "Thank you for shopping with us!" << endl;
			
				 }
		 else
			 {
			 cout << "Thank you for shopping with us!" << endl;
			 }
		 }
	 else
		 {
		 cout << "Thank you for shopping with us!" << endl;
		 }
	}

void staff()
{
	 //Variables definition
		 int itemsCount = 0;
	 int itemChoice = 0;
	 float total = 0.0;
	 float amount = 0.0;
	
		
		 for (size_t i = 0; i < 8; i++)/* for loop to show items from file */
		 {
		 cout << "[" << i + 1 << "]" << itemsFromFile[i][0];
		
			 cout << endl;
		 }
	
		 cout << "How many items would you like to buy? "; cin >> itemsCount;
	 cout << "Choose the item by typing number from [1] to [8] " << endl;
	 for (int x = 0; x < itemsCount; x++) { // if /else if loop for eight items.
		 cin >> itemChoice;
		 if (itemChoice == 1) {
			 total += 299;
			 cout << " Microwave[299MYR]" << endl;
			 amount += 10;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Microwave";
				 pc++;
				 bill[ic][pc] = "299";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 2) {
			 total += 40;
			 cout << " Iron[40MYR]" << endl;
			 amount += 5;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Iron";
				 pc++;
				 bill[ic][pc] = "40";
				 ic++;
				 pc = 0;
				 }
			
				
		}
		 else if (itemChoice == 3) {
			 total += 80;
			 cout << " Rice Cooker[80MYR]" << endl;
			 amount += 5;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Rice Cooker";
				 pc++;
				 bill[ic][pc] = "80";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 4) {
			 total += 50;
			 cout << " Hair Dryer[50MYR]" << endl;
			 amount += 5;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Hair Dryer";
				 pc++;
				 bill[ic][pc] = "50";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 5) {
			 total += 12;
			 cout << " Shoe Rack[12MYR] " << endl;
			 amount += 1;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Shoe Rack";
				 pc++;
				 bill[ic][pc] = "12";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 6) {
			 total += 24;
			 cout << " KitchenCarpet[24MYR]" << endl;
			 amount += 1;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "KitchenCarpet";
				 pc++;
				 bill[ic][pc] = "24";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 7) {
			 total += 40;
			 cout << "MicroSD[40]" << endl;
			 amount += 5;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "MicroSD";
				 pc++;
				 bill[ic][pc] = "40";
				 ic++;
				 pc = 0;
				 }
			
		}
		 else if (itemChoice == 8) {
			 total += 10;
			 cout << "Mini Speaker[10]" << endl;
			 amount += 1;
			 if (ic > 100)// if loop for bill
				 {
				 cout << "MAXIMUM REACHED";
				 }
			 else
				 { /* open bill array and put item name and price*/
				 bill[ic][pc] = "Mini speaker";
			 pc++;
				 bill[ic][pc] = "10";
				 ic++;
				 pc = 0;
				 }
			
		}
		
	}
	 cout << "-----------------------------------" << endl;
	 cout << "The total: RM" << total << endl; //Total
	 cout << "Total discount: RM" << amount << endl; // The discount
	 cout << "Total after discount: RM" << total - amount << endl;// Total after discoun

		
		 string yes_no;
	 cout << "Would you like to print out your bill? [y/n]? "; cin >> yes_no;
	 /* Transform to lowercase */
		 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
	 if (yes_no == "y")// print out the bill
		 {
		 for (size_t i = 0; i < itemsCount; i++)
			 {
			 for (size_t j = 0; j < 2; j++)
				 {
				 if (j == 0)
					 {
					 cout << i + 1 << "- " << bill[i][j];
					 }
				 else
					 {
					 cout << "\t\tRM" << bill[i][j];
					 }
				
					 }
			 cout << endl;
			 }total += amount;
		 cout << "----------------------------------------------------------------------------" << endl;
			 cout << "Total: \t\t\tRM" << total << endl;
		 cout << "Total discount\t\tRM" << amount << endl;
		 cout << "Total after discount: RM" << total - amount << endl;
		 cout << "Would you like to save your bill in file ? [y/n]"; cin >> yes_no;
		 transform(yes_no.begin(), yes_no.end(), yes_no.begin(), ::tolower);
		 if (yes_no == "y") // print out the bill into file
			 {
			 ofstream file("bill.txt");
			 if (file.is_open())
				 {
				 file << "A bill for: " << name << endl;
				 for (size_t i = 0; i < itemsCount; i++)
					 {
					 for (size_t j = 0; j < 2; j++)
						 {
						 if (j == 0)
							 {
							 file << i + 1 << "- " << bill[i][j];
							 }
						 else
							 {
							 file << "\t\tRM" << bill[i][j];
							 }
						
							 }
			
						 file << endl;
					 }
				 file << "----------------------------------------------------------------------------" << endl;
					 file << "Total: \t\t\tRM" << total << endl;
				 file << "Total discount:\t\tRM" << amount << endl;
				 file << "Total after discount: RM" << total - amount << endl;
				 }
			 file.close();
			 cout << "Thank you for shopping with us!" << endl;
			
				 }
		 else
			 {
			 cout << "Thank you for shopping with us!" << endl;
			 }
		 }
	 else
		 {
		 cout << "Thank you for shopping with us!" << endl;
		 }
	
		}