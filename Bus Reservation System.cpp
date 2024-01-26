// LOGIN    USER : sharjeel      PASS : sharjeel
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <sstream>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void mainmenu();
void mainmenu1();
void addbus();
void delbus();
void editbus();
void businfo(string no);
void allbuses();
void bookticket();
void passenger(string bsno);
void searchbus();
void loadfiles();
void savefiles();
void busview();
void busview(string);
void availablebus( string to , string from);
void searchavbus();
void busDetailView(string no);
void availablebuses();
void reserveseat();
void bookingrecords();
void searchbookingrecords();
void welcome();
void loading();


string avseats[100][2];
int av=0;

string fbus[50];
int fb=0;


struct bus
{
	string no;
	string name;
	string from;
	string to;
	string fare;
	string ardate;
	string artime;
};
bus b;

struct client
{
	string name;
	string CNIC;
	string phone;
	string bname;
	string bno;
	string nSeats;
	string seats[50];
	string fare;
	string from;
	string to;	
};
client c;
string TNO;

fstream file3("Tickting_Records.txt", ios::app);




void addbus()                                                   // Add Bus
{
	system("cls");			
	cout<<"\n";
	cout<<"\n--------------------------------------  A D D  N E W  B U S  --------------------------------------------\n";
	cout<<"\n";
	
	no:
	cout<<"\n\t\tEnter Bus no : ";
	cin>>b.no;
	if(b.no.length() > 5){
		cout<<"\tEnter Less then 5 \n";
		goto no;
	}
	
	gname:
	cout<<"\t\tEnter Bus Name : ";
	cin.ignore();
	getline(cin , b.name);
	if(b.name.length() < 20){
		for(int i=0 ; i< b.name.length() ; i++){
			if( !isdigit( b.name[i] ) ){
				
			}
			else{
				cout<<"\tEnter Alphabets...\n";
				goto gname;
			}
		}
	}
	else{
		cout<<"\tEnter Less then 20...\n";
		goto gname;
	}
		
	gfrom:
	cout<<"\t\tArival from : ";
	cin>>b.from;
	if(b.from.length() < 15){
		for(int i=0 ; i< b.from.length() ; i++){
			if( !isdigit( b.from[i] ) ){
				
			}
			else{
				cout<<"\tEnter Alphabets...\n";
				goto gfrom;
			}
		}
	}
	else{
		cout<<"\tEnter Less then 15...\n";
		goto gfrom;
	}
	
	gto:
	cout<<"\t\tTo : ";
	cin>>b.to;
	if(b.to.length() < 15){
		for(int i=0 ; i< b.to.length() ; i++){
			if( !isdigit( b.to[i] ) ){
				
			}
			else{
				cout<<"\tEnter Alphabets...\n";
				goto gto;
			}
		}
	}
	else{
		cout<<"\tEnter Less then 15...\n";
		goto gto;
	}
	
	gfare:
	cout<<"\t\tFare : ";
	cin>>b.fare;
	if(b.fare.length() < 5){
		for(int i=0 ; i< b.fare.length() ; i++){
			if( isdigit( b.fare[i] ) ){
				
			}
			else{
				cout<<"\tEnter Numbers...\n";
				goto gfare;
			}
		}
	}
	else{
		cout<<"\tEnter Less then 5...\n";
		goto gfare;
	}
	
	gd:
	cout<<"\t\tArival date : ";
	cin>>b.ardate;
	if(b.ardate.length() < 10){
		for(int i=0 ; i< b.ardate.length() ; i++){
			if( !isalpha( b.ardate[i] ) ){
				
			}
			else{
				cout<<"\tInvalid Input...\n";
				goto gd;
			}
		}
	}
	else{
		cout<<"\tInvalid Input...\n";
		goto gd;
	}
	
	gt:
	cout<<"\t\tArival time : ";
	cin>>b.artime;
	if(b.artime.length() < 10){
		for(int i=0 ; i< b.artime.length() ; i++){
			if( !isalpha( b.artime[i] ) ){
				
			}
			else{
				cout<<"\tInvalid Input...\n";
				goto gt;
			}
		}
	}
	else{
		cout<<"\tInvalid Input...\n";
		goto gt;
	}
	
	ofstream fbusin("busdata.txt", ios::app);
	if(!fbusin.is_open()){
		cout<<"File is missing...";
	}
	else{
		fbusin<<b.no<<endl;
		fbusin<<b.name<<endl;		
		fbusin<<b.from<<endl;
		fbusin<<b.to<<endl;
		fbusin<<b.fare<<endl;
		fbusin<<b.ardate<<endl;
		fbusin<<b.artime<<endl;
		
		cout<<"\n\n\t\t New Bus Added Successfully...";
		
			
	}
	fbusin.close();

	avseats[av][0]=b.no;
	avseats[av][1]="deeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";//45 + d
	av++;	
	savefiles();
	mainmenu();
	// b.no
	// b.name
	// b.seats
	// b.from
	// b.to
	// b.ardate
	// b.artime
	
}


      
void delbus()
{
	
	
	system("cls");			
	cout<<"\n";
	cout<<"\n--------------------------------------  D E L E T E   B U S  --------------------------------------------\n";
	cout<<"\n";
	
	string busno;
	string del[100][7];
	int c=0;
	ifstream dbus("busdata.txt");
	if(!dbus.is_open()){
		cout<<"File is missing...";
	}
	else{
		
		cout<<"Enter Bus No to Delete Bus Details : ";
		cin>>busno;
		
		while(!dbus.eof()){
			getline(dbus,del[c][0]);   // no
			getline(dbus,del[c][1]);   //name
			getline(dbus,del[c][2]);  //from
			getline(dbus,del[c][3]);//to
			getline(dbus,del[c][4]);//fare
			getline(dbus,del[c][5]);//date
			getline(dbus,del[c][6]);//time
			
			if(dbus.eof()){
				break;
			}
			c++;
						
		}
		dbus.close();
		
		bool found = false;
		
		ofstream dbus2("busdata.txt", ios::app);
		for(int j=0;j<c;j++){
			if(del[j][0]==busno){
				found = true;
				y:
				system("cls");
				cout<<"\n--------------------------------- B U S   D E T A I L S  --------------------------------\n";
					
				cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(8)<<"Fare"<<setw(12)<<"Date"<<setw(8)<<"Time";
						
				cout<<endl<<endl;
				cout<<left<<setw(5)<<del[j][0]<<setw(20)<<del[j][1]<<setw(15)<<del[j][2]<<setw(15)<<del[j][3]<<setw(8)<<del[j][4]<<setw(12)<<del[j][5]<<setw(8)<<del[j][6];
				
				cout<<"\n\n-----------------------------------------------------------------------------------------\n";
				found = true;
				cout<<"\t\tAre you sure you want to Delete this Bus ?\n";
				ji:
				cout<<"\t\tEnter ( Y / N ) : ";
				char yn;
				cin>>yn;
				if(yn == 'Y' || yn == 'y'){
					del[j][0]="delete";
					for(int i=0;i<av;i++){
						if(avseats[i][0]==busno){
							avseats[i][0]="delete";
							
						}
					}
					savefiles();
					cout<<"\n\t\tDeletion Successfull...\n";
					getch();
				}
				else if(yn == 'N' || yn == 'n'){
					cout<<"\n\t\tDeletion Canceled...\n";
					getch();
				}
				else{
					goto ji;
				}
				
				
				
				break;
				
			}
			if(found==false){
					cout<<"Bus not found...\n";
				}
			
		
		}
		
		fstream e;
		e.open("busdata.txt", ios::out | ios::trunc);
		e.close();
		
		for(int l=0;l<c;l++){
			if(del[l][0]!="delete"){
				
				dbus2<<del[l][0]<<endl;//no
				dbus2<<del[l][1]<<endl;//name
				dbus2<<del[l][2]<<endl;//from
				dbus2<<del[l][3]<<endl;//to
				dbus2<<del[l][4]<<endl;//fare
				dbus2<<del[l][5]<<endl;//date
				dbus2<<del[l][6]<<endl;//time
			}
		}
		
	}
	

		
	mainmenu();
	
}



void editbus()
{
		system("cls");			
	cout<<"\n";
	cout<<"\n--------------------------------------  E D I T   B U S  D E T A I L S--------------------------------------------\n";
	cout<<"\n";
	
	string busno;
	string del[100][7];
	int c=0;
	ifstream dbus("busdata.txt");
	if(!dbus.is_open()){
		cout<<"File is missing...";
	}
	else{
		
		cout<<"Enter Bus No to Edit Bus Details : ";
		cin>>busno;
		
		while(!dbus.eof()){
			getline(dbus,del[c][0]);   // no
			getline(dbus,del[c][1]);   //name
			getline(dbus,del[c][2]);  //from
			getline(dbus,del[c][3]);//to
			getline(dbus,del[c][4]);//fare
			getline(dbus,del[c][5]);//date
			getline(dbus,del[c][6]);//time
			
			if(dbus.eof()){
				break;
			}
			c++;
						
		}
		dbus.close();
		
		bool found = false;
		
		ofstream dbus2("busdata.txt", ios::app);
		for(int j=0;j<c;j++){
			if(del[j][0]==busno){
				found = true;
				y:
				system("cls");
				cout<<"\n--------------------------------- B U S   D E T A I L S  --------------------------------\n";
					
				cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(8)<<"Fare"<<setw(12)<<"Date"<<setw(8)<<"Time";
						
				cout<<endl<<endl;
				cout<<left<<setw(5)<<del[j][0]<<setw(20)<<del[j][1]<<setw(15)<<del[j][2]<<setw(15)<<del[j][3]<<setw(8)<<del[j][4]<<setw(12)<<del[j][5]<<setw(8)<<del[j][6];
				
				cout<<"\n\n-----------------------------------------------------------------------------------------\n";
				found = true;
				int change;
				cout<<"\nWhat d you want to change...?";			
				cout<<"\n  1     2       3         4           5           6              7          0    ";
				cout<<"\n  No   Name   Arival   Departure     Fare     Arival Date    Arival Time   Exit  \n\t";
				jj:
				cout<<"Enter 0-7 : ";
				cin>>change;
				cin.ignore();
				
				if(change == 1){
					no:
					cout<<"\n\t\tEnter Bus no : ";
					cin>>b.no;
					if(b.no.length() > 5){
						cout<<"\tEnter Less then 5 \n";
						goto no;
					}
					del[j][0]=b.no;
					for(int k=0;k<av;k++){
						if(avseats[k][0]==busno){
							avseats[k][0]= del[j][0];				
						}
					}
					savefiles();
				}
				
				else if(change == 2){
					gname:
					cout<<"\t\tEnter Bus Name : ";
					getline(cin , b.name);
					if(b.name.length() < 20){
						for(int i=0 ; i< b.name.length() ; i++){
							if( !isdigit( b.name[i] ) ){
								
							}
							else{
								cout<<"\tEnter Alphabets...\n";
								goto gname;
							}
						}
					}
					else{
						cout<<"\tEnter Less then 20...\n";
						goto gname;
					}
					del[j][1]=b.name;
				}
				
				else if(change == 3){
					gfrom:
					cout<<"\t\tArival from : ";
					cin>>b.from;
					if(b.from.length() < 15){
						for(int i=0 ; i< b.from.length() ; i++){
							if( !isdigit( b.from[i] ) ){
								
							}
							else{
								cout<<"\tEnter Alphabets...\n";
								goto gfrom;
							}
						}
					}
					else{
						cout<<"\tEnter Less then 15...\n";
						goto gfrom;
					}
					del[j][2]=b.from;
				}
				else if(change == 4 ){
					gto:
					cout<<"\t\tTo : ";
					cin>>b.to;
					if(b.to.length() < 15){
						for(int i=0 ; i< b.to.length() ; i++){
							if( !isdigit( b.to[i] ) ){
								
							}
							else{
								cout<<"\tEnter Alphabets...\n";
								goto gto;
							}
						}
					}
					else{
						cout<<"\tEnter Less then 15...\n";
						goto gto;
					}
					del[j][3]=b.to;
				}
				else if(change == 5){
					gfare:
					cout<<"\t\tFare : ";
					cin>>b.fare;
					if(b.fare.length() < 5){
						for(int i=0 ; i< b.fare.length() ; i++){
							if( isdigit( b.fare[i] ) ){
								
							}
							else{
								cout<<"\tEnter Numbers...\n";
								goto gfare;
							}
						}
					}
					else{
						cout<<"\tEnter Less then 5...\n";
						goto gfare;
					}
					del[j][4]=b.fare;
				}
				else if(change == 6 ){
					gd:
					cout<<"\t\tArival date : ";
					cin>>b.ardate;
					if(b.ardate.length() < 10){
						for(int i=0 ; i< b.ardate.length() ; i++){
							if( !isalpha( b.ardate[i] ) ){
								
							}
							else{
								cout<<"\tInvalid Input...\n";
								goto gd;
							}
						}
					}
					else{
						cout<<"\tInvalid Input...\n";
						goto gd;
					}
					del[j][5]=b.ardate;
				}
				else if(change == 7){
					gt:
					cout<<"\t\tArival time : ";
					cin>>b.artime;
					if(b.artime.length() < 10){
						for(int i=0 ; i< b.artime.length() ; i++){
							if( !isalpha( b.artime[i] ) ){
								
							}
							else{
								cout<<"\tInvalid Input...\n";
								goto gt;
							}
						}
					}
					else{
						cout<<"\tInvalid Input...\n";
						goto gt;
					}
					del[j][6]=b.artime;
				}
				else if(change == 0){
					
				}
				else{
					cout<<"Invalid Input...";
					goto jj;
				}
				
				if(change >0 && change <=7){
					cout<<"\tDo you want to edit another field ";
					char yn;
					ji:
					cout<<"( Y / N ) : ";
					cin>>yn;
					if(yn == 'Y' || yn == 'y'){
						system("cls");
						goto y;
					}
					if(yn == 'N' || yn == 'n'){
						
					}
					else{
						cout<<"\tEnter ";
						goto ji;
					}
				}
				
				break;
				
			}
			if(found==false){
					cout<<"Bus not found...\n";
				}
			
		
		}
		
		fstream e;
		e.open("busdata.txt", ios::out | ios::trunc);
		e.close();
		
		for(int l=0;l<c;l++){
			if(del[l][0]!="delete"){
				
				dbus2<<del[l][0]<<endl;//no
				dbus2<<del[l][1]<<endl;//name
				dbus2<<del[l][2]<<endl;//from
				dbus2<<del[l][3]<<endl;//to
				dbus2<<del[l][4]<<endl;//fare
				dbus2<<del[l][5]<<endl;//date
				dbus2<<del[l][6]<<endl;//time
			}
		}
		
	}
	
	
	mainmenu();
}




void allbuses()                            //     All busses
{
	system("cls");
	cout<<"\n----------------------------------- A L L   B U S E S  --------------------------------\n\n";
	cout<<endl;	
	cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(7)<<"Fare"<<setw(12)<<"Date"<<setw(7)<<"Time"<<"Seats";	
	cout<<endl<<endl;
	
	
	ifstream favbus("busdata.txt");
	if(!favbus.is_open()){
		cout<<"File is missing...";
	}
	else{
		string f;
		int seats;
		while(!favbus.eof()){
			getline(favbus,b.no);
			getline(favbus,b.name);
			getline(favbus,b.from);
			getline(favbus,b.to);
			getline(favbus,f);
			getline(favbus,b.ardate);
			getline(favbus,b.artime);
//			cout<<setw(7)<<b.no<<setw(15)<<b.name<<setw(14)<<b.from<<setw(11)<<b.to<<setw(11)<<b.ardate<<setw(11)<<b.artime<<endl;
			if(favbus.eof()){
				break;
			}
			
			for(int i=0;i<av;i++){
				if(b.no == avseats[i][0]){						
					seats=0;
					for(int j=1;j<46;j++){								
						if(avseats[i][1][j] == 'e'  ){									
							seats++;
						}		
														
					}
					
									
				}
			}
			cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<f<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
			cout<<endl;
			
		}
	}
	cout<<"\n-----------------------------------------------------------------------------------------\n\n";
	favbus.close();
	getch();
	mainmenu();
}


void availablebuses() 
{
	system("cls");
	cout<<"\n----------------------------------- A V A I L A B L E   B U S E S  --------------------------------\n\n";
	cout<<endl;	
	cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(7)<<"Fare"<<setw(12)<<"Date"<<setw(7)<<"Time"<<"Seats";	
	cout<<endl<<endl;
	
	
	ifstream favbus("busdata.txt");
	if(!favbus.is_open()){
		cout<<"File is missing...";
	}
	else{
		int seats;
		while(!favbus.eof()){
			getline(favbus,b.no);
			getline(favbus,b.name);
			getline(favbus,b.from);
			getline(favbus,b.to);
			getline(favbus,b.fare);
			getline(favbus,b.ardate);
			getline(favbus,b.artime);
//			cout<<setw(7)<<b.no<<setw(15)<<b.name<<setw(14)<<b.from<<setw(11)<<b.to<<setw(11)<<b.ardate<<setw(11)<<b.artime<<endl;
			if(favbus.eof()){
				break;
			}
			
			for(int i=0;i<av;i++){
				if(b.no == avseats[i][0]){						
					seats=0;
					for(int j=1;j<46;j++){								
						if(avseats[i][1][j] == 'e'  ){									
							seats++;
						}		
														
					}									
				}
			}
			
			if(seats > 0){				
				cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<b.fare<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
				cout<<endl;
			}
			
		}
	}
	cout<<"\n-----------------------------------------------------------------------------------------\n\n";
	favbus.close();
	getch();
	mainmenu();
}




void passenger(string bsno )
{	
	system("cls");	
	cout<<"\n----------------------------------  S E A T   B O O K I N G  --------------------------------\n\n";

	cout<<"\t\t\t ENTER PASSENGER DETAILS    :   \n";
	
	gname:
	cout<<"\t\t\t NAME    :   ";
	cin.ignore();
	getline(cin,c.name);
	if(c.name.length() < 20){
		for(int i=0 ; i< c.name.length() ; i++){
			if( !isdigit( c.name[i] ) ){
				
			}
			else{
				cout<<"\tEnter Alphabets...\n";
				goto gname;
			}
		}
	}
	else{
		cout<<"\tEnter Less then 20...\n";
		goto gname;
	}
	
	gphone:
	cout<<"\t\t\t PHONE NO      :   ";	
	cin>>c.phone;
	if(c.phone.length() <= 13){
		for(int i=0 ; i< c.phone.length() ; i++){
			if( isdigit( c.phone[i] ) ){
				
			}
			else{
				cout<<"\tEnter Valid Phone No...\n";
				goto gphone;
			}
		}
	}
	else{
		cout<<"\tEnter Valid Phone ...\n";
		goto gphone;
	}
	
	gcnic:
	cout<<"\t\t\t CNIC NO      :   ";	
	cin>>c.CNIC;
	if(c.CNIC.length() == 13){
		for(int i=0 ; i< c.CNIC.length() ; i++){
			if( isdigit( c.CNIC[i] ) ){
				
			}
			else{
				cout<<"\tEnter Valid CNIC...\n";
				goto gcnic;
			}
		}
	}
	else{
		cout<<"\tEnter 13 digit CNIC...\n";
		goto gcnic;
	}
		
		
	int se=0;
	for(int i=0;i<av;i++){
		if(bsno == avseats[i][0]){						
			se=0;
			for(int j=1;j<46;j++){								
				if(avseats[i][1][j] == 'e'  ){									
					se++;
				}											
			}						
		}
	}
	cout<<"\t\t\t NO OF SEATS YOU WANT TO BOOK (Only "<<se<<" are available) :   ";
	gnseats:
	cin>>c.nSeats;
	
	for(int i=0 ; i< c.nSeats.length() ; i++){
		if( isdigit( c.nSeats[i] ) ){
		
		}
		else{
			cout<<"\t\t\t Enter Integer  : \n";
			goto gnseats;
		}
	}
	
	int csno;
	istringstream (c.nSeats) >> csno;
		
	if(csno > se){
		cout<<"\t\t\t Only "<<se<<" Seats are available...\n";
		goto gnseats;				
	}
	else if(csno == se){
		char yn;
		int r=0;
		cout<<"\t\t\t Do you want to book all seats ";
		cin>>yn;
		if(yn=='Y' || yn=='y'){
			for(int i=0;i<av;i++){
				if(bsno == avseats[i][0]){		
						for(int t=1;t<46;t++){
							if(avseats[i][1][t] == 'e' ){
								avseats[i][1].replace(t,1,"b");
								string str4;
								stringstream ss;
								ss << t;
								ss >> str4;
								c.seats[r] = str4;
								r++;										
							}
						}
					
				}
			}
		}
		else if(yn=='N' || yn=='n'){
			
		}
		else{
			
		}
	}
	else if(csno <=0){
		
	}
	else if(csno < se){
		
		int r=0;
		cout<<"\t\t\t ENTER SEAT NO's RESPECTIVELY\n";
		for(int j = 0 ; j < csno ; j++){
			c:
			cout<<"\t\t\t "<<j+1<<" : ";
			cin>>c.seats[j];
			for(int k=0;k<c.seats[j].length();k++){
				if(!isdigit(c.seats[j][k])){
					cout<<"\t\t\tEnter Number : ";
					goto c;
				}
			}
			int seno;
			istringstream(c.seats[j]) >> seno;
			for(int i=0;i<av;i++){
				if(bsno == avseats[i][0]){		
						if(avseats[i][1][seno] == 'e' ){
							avseats[i][1].replace(seno,1,"b");
						}
						else{
							cout<<"\n\tSeat Not Available, Try Another...\n";
							goto c;
						}
					
				}
			}
		}
	}
	
	savefiles();
	ifstream pseat("busdata.txt");
	if(!pseat.is_open()){
		cout<<"File is missing...";
	}
	else{
		int f;
		int ttn;
		while(!pseat.eof()){
			getline(pseat,b.no);
			getline(pseat,b.name);
			getline(pseat,b.from);
			getline(pseat,b.to);
			getline(pseat,b.fare);
			getline(pseat,b.ardate); 
			getline(pseat,b.artime);
			if(bsno==b.no){			
				istringstream(b.fare) >> f;
				
				
				ifstream t("Tno.txt");
				if(!t){
					ofstream g("Tno.txt");
					g<<0;
					g.close();
				}
				else{
					
					t>>ttn;
					ttn++;
					ofstream x("Tno.txt");
					x<<ttn;
					x.close();
				}
				file3<<ttn<<endl;
				file3<<c.name<<endl;
				file3<<c.phone<<endl;
				file3<<c.CNIC<<endl;
				file3<<b.name<<endl;
				file3<<bsno<<endl;
				
				file3<<c.nSeats<<endl;
				for(int v=0;v<csno;v++){
					file3<<c.seats[v]<<endl;
				}
								
				file3<<b.from<<endl;
				file3<<b.to<<endl;
				
				int tf=f*csno;
				stringstream ss;
				ss << tf;
				ss >> c.fare;
							
				file3<<c.fare<<endl;
				
				
				cout<<"\n\n\t\t ==========================================================================\n\n";
				
				cout<<"\t\t                           BUS  RESERVATION  SYSTEM                      \n";		
				cout<<"\t\t                                 Invoice Slip                            \n";
				cout<<"\t\t        T.No : "<<ttn<<"\n";
				cout<<"\t\t ==========================================================================\n";
				cout<<"\t\t        Name                : "<<c.name<<endl;
				cout<<"\t\t        Phone               : "<<c.phone<<endl;
				cout<<"\t\t        CNIC                : "<<c.CNIC<<endl;
				cout<<"\t\t        BUS Name            : "<<b.name<<endl;
				cout<<"\t\t        BUS No              : "<<bsno<<endl;
				cout<<"\t\t        Arrival             : "<<b.from<<endl;
				cout<<"\t\t        Destination         : "<<b.to<<endl;
				cout<<"\t\t        Arival Date         : "<<b.ardate<<endl;
				cout<<"\t\t        Arival Time         : "<<b.artime<<endl;
				cout<<"\t\t        No.of Seats         : "<<c.nSeats<<endl;
				cout<<"\t\t        Seat No's           : ";
				for(int v=0;v<csno;v++){
					cout<<c.seats[v]<<", ";
				}
				cout<<endl;
				cout<<"\t\t        Total Fare          : "<< b.fare<<" x "<<c.nSeats<<" = "<<c.fare<<endl;
				
				cout<<"\n\t\t ==========================================================================\n";
				cout<<"\n\t\tPlease Remember your Ticket No \n\t\tThe Ticket can not be generated again....\n";
				getch();
				break;
			}
		}
		
		
		
	}
	
	system("pause");	
	
}

void bookingrecords()
{
	system("cls");	
	cout<<"\n----------------------------------  B O O K I N G  R E C O R D S  --------------------------------\n\n";
	ifstream record("Tickting_Records.txt");
	if(!record){
		cout<<"\t\tError! Tickting_Records.txt Not Found....\n";
	}
	else{
		
		// tno  passenger name  phone Cnic  bsname  bsno   from    to    no.of seats   total fare  seats
		cout<<left<<setw(5)<<"T.No"<<setw(20)<<"Passenger Name"<<setw(15)<<"Phone No"<<setw(15)<<"CNIC"<<setw(20)<<"Bus Name"<<setw(8)<<"Bus No"<<setw(15)<<"Arival From"<<setw(15)<<"To"<<setw(5)<<"No.S"<<setw(10)<<"Fare"<<"Seats"<<endl;
		while(!record.eof()){
			getline(record,TNO);
			getline(record,c.name);
			getline(record,c.phone);
			getline(record,c.CNIC);
			getline(record,c.bname);
			getline(record,c.bno);
			getline(record,c.nSeats);
			int num;
			istringstream(c.nSeats) >> num;
			for(int n=0;n<num;n++){				
				getline(record,c.seats[n]);
			}
			getline(record,c.from);
			getline(record,c.to);
			getline(record,c.fare);
			if(record.eof()){
				break;
			}
			
			cout<<left<<setw(5)<<TNO<<setw(20)<<c.name<<setw(15)<<c.phone<<setw(15)<<c.CNIC<<setw(20)<<c.bname<<setw(8)<<c.bno<<setw(15)<<c.from<<setw(15)<<c.to<<setw(5)<<c.nSeats<<setw(10)<<c.fare;
			for(int n=0;n<num;n++){				
				cout<<c.seats[n]<<", ";
			}
			cout<<endl;	
		}
	}
	record.close();
	getch();
	mainmenu();
}


void searchbookingrecords()
{
	system("cls");	
	cout<<"\n------------------------------ S E A R C H  B O O K I N G  R E C O R D S  ----------------------------\n\n";
	string tick;
	cout<<"\t\t\t Enter Ticket No to view Booking Records : ";
	cin>>tick;
	
	bool found = false;
	
	ifstream record("Tickting_Records.txt");
	if(!record){
		cout<<"\t\tError! Tickting_Records.txt Not Found....\n";
	}
	else{
		
		while(!record.eof()){
			getline(record,TNO);
			getline(record,c.name);
			getline(record,c.phone);
			getline(record,c.CNIC);
			getline(record,c.bname);
			getline(record,c.bno);
			getline(record,c.nSeats);
			int num;
			istringstream(c.nSeats) >> num;
			for(int n=0;n<num;n++){				
				getline(record,c.seats[n]);
			}
			getline(record,c.from);
			getline(record,c.to);
			getline(record,c.fare);
			if(record.eof()){
				break;
			}
			
			if(TNO == tick){
				
				found = true;

				cout<<"\t T.No                   :  "<<TNO<<endl;
				cout<<"\t Passenger Name         :  "<<c.name <<endl;
				cout<<"\t Phone No               :  "<<c.phone <<endl;
				cout<<"\t CNIC                   :  "<<c.CNIC <<endl;
				cout<<"\t Bus Name               :  "<<c.bname <<endl;
				cout<<"\t Bus No                 :  "<<c.bno <<endl;
				cout<<"\t Arival From            :  "<<c.from <<endl;
				cout<<"\t To                     :  "<<c.to <<endl;
				cout<<"\t No.of Seats            :  "<<c.nSeats <<endl;
				cout<<"\t Fare                   :  "<<c.fare <<endl;
				cout<<"\t Seats                  :  ";
					
				for(int n=0;n<num;n++){				
					cout<<c.seats[n];
					if(n<num-1){
						cout<<", ";
					}
				}
				cout<<endl;	
//				cout<<left<<setw(5)<<TNO<<setw(20)<<c.name<<setw(15)<<c.phone<<setw(15)<<c.CNIC<<setw(20)<<c.bname<<setw(8)<<c.bno<<setw(15)<<c.from<<setw(15)<<c.to<<setw(5)<<c.nSeats<<setw(10)<<c.fare;
//				for(int n=0;n<num;n++){				
//					cout<<c.seats[n]<<", ";
//				}
//				cout<<endl;	
			}
		}
	}
	record.close();
	if(found == false){
		cout<<"\t\t\t No records found...\n";
	}
	getch();
	mainmenu();
}


void businfo(string no)
{	
		
	system("cls");
	
	
	int seats = 0;
	ifstream fseats("busdata.txt");
	if(!fseats.is_open()){
		cout<<"File is missing...";
	}
	else{
		string f;
		while(!fseats.eof()){
			getline(fseats,b.no);
			getline(fseats,b.name);
			getline(fseats,b.from);
			getline(fseats,b.to);
			getline(fseats,f);
			getline(fseats,b.ardate);
			getline(fseats,b.artime);
			if(no==b.no){
				cout<<"\n\n--------------------------------- B U S   D E T A I L S  --------------------------------\n\n";
				
				cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(8)<<"Fare"<<setw(12)<<"Date"<<setw(8)<<"Time"<<"Seats";
					
				cout<<endl<<endl;
				for(int i=0;i<av;i++){
					if(b.no == avseats[i][0]){						
						seats=0;
						for(int j=1;j<46;j++){								
							if(avseats[i][1][j] == 'e'  ){									
								seats++;
							}		
															
						}
						
										
					}
				}
				cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<f<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
				cout<<endl;
				break;
			}
			
				
								
		}
					
			
	}
		
	
	
	fseats.close();
	
	cout<<"\n-------------------------------------------------------------------------------------------\n";

	system("pause>nul");	
	
}

void searchbus()
{	
	system("cls");
	cout<<"\n\n-----------------------------  S E A R C H  A V A I L A B L E  B U S  ---------------------------------\n";
	string no,from,to;
	bool found = false;
	int choice;
	cout<<"\n\tEnter your Destination : ";
	cin>>to;
	cout<<"\n\tEnter your City : ";
	cin>>from;	
	
	
	
	ifstream fseats("busdata.txt");
	if(!fseats.is_open()){
		cout<<"File is missing...";
	}
	else{
		string f;
		while(!fseats.eof()){
			getline(fseats,b.no);			
			getline(fseats,b.name);
			getline(fseats,b.from);
			getline(fseats,b.to);
			getline(fseats,f);
			getline(fseats,b.ardate);
			getline(fseats,b.artime);
			int seats=0;
			if(fseats.eof()){
				break;
			}
			if(from==b.from){
				if(to==b.to)
				{
					for(int i=0;i<av;i++){
						if(b.no == avseats[i][0]){						
							seats=0;
							for(int j=1;j<46;j++){								
								if(avseats[i][1][j] == 'e'  ){									
									seats++;
								}		
																
							}
							
									
						}
					}
					
					system("cls");
					cout<<"\n\n------------------------------------- A V A I L A B L E  B U S E S  ------------------------------------\n";
					cout<<endl<<endl;
					
					cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Destination"<<setw(7)<<"Fare"<<setw(12)<<"Date"<<setw(7)<<"Time"<<"Seats";	
					cout<<endl<<endl;
					cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<f<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
					cout<<endl;
					
					no=b.no;
					found = true;
					break;
				}
			}
			
			
								
			}
					
			
		}
		
	
	
	fseats.close();
	
	cout<<"\n---------------------------------------------------------------------------------------------\n";

	if(found == false)
	{
		cout<<"\t\tBus not Found...\n";
		getch();
		
	}
	mainmenu();
	
}

void searchavbus(){
	system("cls");
	cout<<"\n\n-----------------------------  S E A R C H  A V A I L A B L E  B U S  ---------------------------------\n";
	string from,to;
	cout<<"\n\tEnter your Destination : ";
	cin>>to;
	cout<<"\n\tEnter your City : ";
	cin>>from;
	
	availablebus( to , from );
	
	string bsno;
	cout<<"\n\t\tEnter Bus No to view Bus Details and Seats : ";
	ll:
	cin>>bsno; 
	bool found = false;
	for(int i=0;i<fb;i++){
		if(bsno == fbus[i]){
			found=true;
		}
	}
	if(found== false){
		cout<<"\t\tEnter Bus No From Above Available Bus List : ";
		goto ll;
	}
	else{
		busDetailView(bsno);
	}
	getch();
	mainmenu();
}

void reserveseat()
{
	system("cls");
	cout<<"\n\n-----------------------------  S E A T  R E S E R V A T I O N  ---------------------------------\n";
	string from,to;
	cout<<"\n\tEnter your Destination : ";
	cin>>to;
	cout<<"\n\tEnter your City : ";
	cin>>from;
	
	availablebus( to , from );
	
	string bsno;
	cout<<"\n\t\tEnter Bus No to view Bus Details and Seats : ";
	ll:
	cin>>bsno; 
	bool found = false;
	for(int i=0;i<fb;i++){
		if(bsno == fbus[i]){
			found=true;
		}
	}
	if(found== false){
		cout<<"\t\tEnter Bus No From Above Available Bus List : ";
		goto ll;
	}
	else{
		busDetailView(bsno);
	}
	char yn;
	cout<<"\n\t\tDo you want to book seat ";
	oo:
	cout<<"( Y / N ) : ";
	cin>>yn;
	if(yn == 'Y' || yn == 'y'){
		// book seet function
		passenger(bsno);
	}
	else if(yn == 'N' || yn == 'n'){
		
	}
	else{
		cout<<"\t\tEnter ";
		goto oo;
	}
	
	getch();
	mainmenu();
	
}


void availablebus( string to , string from)
{	
	system("cls");
	system("cls");
	cout<<"\n\n------------------------------------- A V A I L A B L E  B U S E S  ------------------------------------\n";
	cout<<endl<<endl;
	
	cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Destination"<<setw(7)<<"Fare"<<setw(12)<<"Date"<<setw(7)<<"Time"<<"Seats";	
	cout<<endl<<endl;
	bool found = false;	
	
	ifstream fseats("busdata.txt");
	if(!fseats.is_open()){
		cout<<"File is missing...";
	}
	else{
		string f;
		while(!fseats.eof()){
			getline(fseats,b.no);			
			getline(fseats,b.name);
			getline(fseats,b.from);
			getline(fseats,b.to);
			getline(fseats,f);
			getline(fseats,b.ardate);
			getline(fseats,b.artime);
			int seats=0;
			if(fseats.eof()){
				break;
			}
			if(from==b.from){
				if(to==b.to)
				{
					for(int i=0;i<av;i++){
						if(b.no == avseats[i][0]){						
							seats=0;
							for(int j=1;j<46;j++){								
								if(avseats[i][1][j] == 'e'  ){									
									seats++;
								}		
																
							}
							
									
						}
					}
					
					if(seats > 0){
						cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<f<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
						cout<<endl;
						fbus[fb]=b.no;
						fb++;
						found = true;
					}
				}
			}
			
			
								
			}
					
			
		}
		
	
	
	fseats.close();
	
	cout<<"\n---------------------------------------------------------------------------------------------\n";
	

	if(found == false)
	{
		cout<<"\t\t NO BUS FOUND...\n";
		getch();
		
	}
	
}

void viewBusDetails()
{
	system("cls");
	string bsno;
	cout<<"\n\t\tEnter Bus No to view Bus Details and Seats : ";
	cin>>bsno;
	
	bool found = false;
	for(int i=0;i<av;i++){
		if(bsno == avseats[i][0]){						
			found = true;				
		}
	}
	
	if(found == false){
		cout<<"\t\tNo Bus Found : ";
	}
	else{
		busDetailView(bsno);
	}
	getch();
	mainmenu();
}
void busDetailView(string no)
{	
	system("cls");
	
	int seats = 0;
	ifstream fseats("busdata.txt");
	if(!fseats.is_open()){
		cout<<"File is missing...";
	}
	else{
		string f;
		while(!fseats.eof()){
			getline(fseats,b.no);
			getline(fseats,b.name);
			getline(fseats,b.from);
			getline(fseats,b.to);
			getline(fseats,f);
			getline(fseats,b.ardate);
			getline(fseats,b.artime);
			if(no==b.no){
				cout<<"\n--------------------------------- B U S   D E T A I L S  --------------------------------\n";
				
				cout<<left<<setw(5)<<"No"<<setw(20)<<"Bus Name"<<setw(15)<<"Arival"<<setw(15)<<"Departure"<<setw(8)<<"Fare"<<setw(12)<<"Date"<<setw(8)<<"Time"<<"Seats";
					
				cout<<endl<<endl;
				for(int i=0;i<av;i++){
					if(b.no == avseats[i][0]){						
						seats=0;
						for(int j=1;j<46;j++){								
							if(avseats[i][1][j] == 'e'  ){									
								seats++;
							}		
															
						}
						
										
					}
				}
				cout<<left<<setw(5)<<b.no<<setw(20)<<b.name<<setw(15)<<b.from<<setw(15)<<b.to<<setw(8)<<f<<setw(12)<<b.ardate<<setw(8)<<b.artime<<seats;
				cout<<endl;
				
				for(int i=0;i<av;i++){
					if(no == avseats[i][0]){
						
						
//						int seats=0;
//						for(int j=1;j<46;j++){
//							
//							if(avseats[i][1][j] == 'e' ){
//								
//								seats++;
//							}
//						}
						
						
						cout<<"\n----------------------------------- B U S   S E A T S   V I E W  --------------------------------\n";
						cout<<"\t\t\t\t\t\t\t      ( D R I V E R )\n";
						for(int j=1;j<46;j++){
							
							if(avseats[i][1][j] == 'e' ){
						
								SetConsoleTextAttribute(h,2);
								if(j%2==1 && j<42 ){
									cout<<"\t\t"<<setw(2)<<j<< ". (Empty)  ";
								}
								else{
									cout<<setw(2)<<j<< ". (Empty)  ";
								}
//								seats++;
							}
							
							else if(avseats[i][1][j] == 'b' ){
								
								SetConsoleTextAttribute(h,8);
								if(j%2==1  && j<42 ){
									cout<<"\t\t"<<setw(2)<<j<< ". (Booked) ";
								}
								else{
									cout<<setw(2)<<j<< ". (Booked) ";
								}
								
							}
							if(j%4==0 && j<42){
								cout<<endl;
							}
							SetConsoleTextAttribute(h,9);
							
						}
						cout<<"\n\n\t\t\t\t\t"<<seats<<" Seats Available \n";
						
			//			avseats[i][1].replace(seatno,1,str);
						
					}
				}	
				break;
			}
			
				
								
		}
					
			
	}
		
	
	
	fseats.close();
	
	cout<<"\n-------------------------------------------------------------------------------------------\n";

	system("pause>nul");	
	
}

void busview()
{
	system("cls");
	string n;
	cout<<"\n\n----------------------------------- B U S   S E A T S   V I E W  --------------------------------\n\n";
	cout<<"\t\t\t Enter Bus No : ";
	cin>>n;
	busview(n);
}

void busview(string no)
{
	system("cls");
	for(int i=0;i<av;i++){
		if(no == avseats[i][0]){
			
			
			int seats=0;
			for(int j=1;j<46;j++){
				
				if(avseats[i][1][j] == 'e' ){
					
					seats++;
				}		
				
				
			}
			
			
			cout<<"\n----------------------------------- B U S   S E A T S   V I E W  --------------------------------\n\n";
			cout<<"\t\t\t\t\t\t\t      ( D R I V E R )\n";
			for(int j=1;j<46;j++){
				
				if(avseats[i][1][j] == 'e' ){
					
					if(j%2==1 && j<42 ){
						cout<<"\t\t"<<setw(2)<<j<< ". (Empty)  ";
					}
					else{
						cout<<setw(2)<<j<< ". (Empty)  ";
					}
					seats++;
				}
				
				else if(avseats[i][1][j] == 'b' ){
					
					if(j%2==1  && j<44 ){
						cout<<"\t\t"<<setw(2)<<j<< ". (Booked) ";
					}
					else{
						cout<<setw(2)<<j<< ". (Booked) ";
					}
					
				}
				if(j%4==0 && j<42){
					cout<<endl;
				}
				
				
			}
			cout<<"\n\t\t\t"<<seats<<" Seats Available \n";
			cout<<"\n\n-------------------------------------------------------------------------------------------\n\n";
			
//			avseats[i][1].replace(seatno,1,str);
			
		}
	}
	getch();
}



void loadfiles(){
	ifstream fin("seats.txt");
	if(!fin){
	}
	else{
		int i=0;
		while(fin){
			if(fin.eof())
			{
				break;
			}
			getline(fin,avseats[i][0]);
			if(avseats[i][0]==""){
				continue;
			}
			getline(fin,avseats[i][1]);
			i++;
		}
		av=i;
	}
	
}

void savefiles(){
	fstream erase;
	erase.open("seats.txt", ios::out | ios::trunc);
	erase.close();
	
	ofstream save("seats.txt", ios::app);
	for(int i=0;i<av;i++){
		if(avseats[i][0]!="delete"){
			save<<avseats[i][0]<<endl<<avseats[i][1]<<endl;
		}
				
		
	}
	save.close();
	
}

bool login()
{	
	int count = 0;
	do{
		string user, pass;
		string u = "sharjeel", p = "sharjeel";
		system("cls");
		
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\n\t\t B U S   R E S E R V A T I O N   S Y S T E M   L O G I N  \n";		
		cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<"\n\n\t\t\t USERNAME           :  ";
		cin>>user;
		cout<<"\n\n\t\t\t PASSWORD        :  ";
		SetConsoleTextAttribute(h,17);
		cin>>pass;
		SetConsoleTextAttribute(h,9);
		count++;
		if(user == u){
			if(pass == p){					
				cout<<"\n\n\t\t\t\t Authentication...";	
				Sleep(500);			
				cout<<"\n\n\t\t\t\t Login Successfull...";
				Sleep(500);	
				return true;
			}
			else{
				
				cout<<"\n\n\t\t\t\t Authentication...";	
				Sleep(1000);			
				system("cls");
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				cout<<"\n\t\t B U S   R E S E R V A T I O N   S Y S T E M   L O G I N  \n";		
				cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
				cout<<"\n\n\t\t\t\t Password Not Matched....\n";
				getch();
			}
		}
		else{
			cout<<"\n\n\t\t\t\t Authentication...";	
			Sleep(1000);			
			system("cls");
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout<<"\n\t\t B U S   R E S E R V A T I O N   S Y S T E M   L O G I N  \n";		
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout<<"\n\n\t\t\t\t UserName Not Matched....\n";
			getch();
		}
	}while(count <3);
	system("cls");
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\t\t B U S   R E S E R V A T I O N   S Y S T E M   L O G I N  \n";		
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n\n\t\t\t\t Login Failure...\n";
	Sleep(500);
	cout<<"\n\n\t\t\t\t Closing System...\n";
	Sleep(500);
	return false;
}


void welcome()
{
	system("cls");
	string a1 = "WELCOME" , a2 = "TO" , a3 = "BUS RESERVATION", a4= "MANAGEMENT SYSTEM";
	
	cout<<"\n\n\n\n";
	cout<<"            \t                        ";
	for(int i =0;i<a1.length() ; i++){
		cout<<a1[i]<<" ";
		Sleep(20);
	}
	cout<<"\n\n";
	
	cout<<"              \t                               ";
	for(int i =0;i<a2.length() ; i++){
		cout<<a2[i]<<" ";
		Sleep(20);
	}
	cout<<"\n\n";
	
	cout<<"                \t        ";
	for(int i =0;i<a3.length() ; i++){
		cout<<a3[i]<<" ";
		Sleep(20);
	}
	cout<<"\n\n";
	
	cout<<"                  \t       ";
	for(int i =0;i<a4.length() ; i++){
		cout<<a4[i]<<" ";
		Sleep(20);
	}
	cout<<"\n\n";
	
	Sleep(1000);
	

}


void loading()
{
	system("cls");
	char x = 219;	
	cout<<"\n\n\n\n\n\n\n\n\t\t"<<"\t\t\t  L O A D I N G ...\n\n\t\t\t";
	for(int i=0 ; i<50 ; i++){
		if(i<21)
		Sleep(1);
		if(i==4 || i==21 )
		Sleep(50); // <windows.h>
		else if (i==10 || i==50 || i==35)
		Sleep(300);
		cout<<x;
		if(i==49){
		cout<<"\n\n\t\t\t\t\t    D O N E ...";
		}
	
	}
	Sleep(900);
}


int main()
{
	system("title  Bus Reservation Management System.");
		
	SetConsoleTextAttribute(h,9); 
//	SetConsoleTextAttribute(h,8); // booked
//	SetConsoleTextAttribute(h,2); // empty
	loading();
	welcome();
	
	
	if(login() == true){
		
		loadfiles();
		mainmenu();
		savefiles();
	}	
	
	system("pause");
	return 0;
}

void mainmenu()                                              // MAIN MENU
{
	system("CLS");	
	cout<<"\n\n";
	cout<<"\n-----------------------------------  M A I N  M E N U --------------------------------\n\n";
	cout<<"\t\t\t\t";
	
	cout<<" 1. Add New Bus\n\t\t\t\t"; 
	cout<<" 2. Show All Buses Details \n\t\t\t\t"; 
	cout<<" 3. Remove Bus \n\t\t\t\t";
	cout<<" 4. Edit Bus Details \n\n\t\t\t\t";
	
	cout<<" 5. Available Buses \n\t\t\t\t";	
	cout<<" 6. View Bus Details \n\t\t\t\t";
	cout<<" 7. Search Your Bus \n\t\t\t\t"; 
	cout<<" 8. Reserve Seat \n\t\t\t\t"; 
	cout<<" 9. Booking Records \n\t\t\t\t"; 
	cout<<"10. Search Booking Records \n\t\t\t\t"; 
	 	
	cout<<" 0. Exit\n\t\t\t\t";

	int choice;
	
	cout<<"\n\t\t Enter your choice : ";
	ii:
	cin>>choice;
	cin.ignore();
	
	switch(choice)
	{
		case 0:
			cout<<endl;
			break;
		case 1:
			addbus(); //
			break;
		case 2:
			allbuses();
			break;
		case 3:			
			delbus();			
			break;
		case 4:
			editbus();
			break; 
		case 5:
			// available buses
			availablebuses();
			break;
		case 6:
			// view bus details
			viewBusDetails();
			break;
		case 7:
			// search available bus
			searchavbus();
			break;
		case 8:
			//reserve seat
			reserveseat();
			break;
		case 9:
			//Booking Records
			bookingrecords();
			break;
		case 10:
			searchbookingrecords();
			break;
		default:
			cout<<"\t\tEnter 0-9 : ";
			goto ii;
	}
	
}

