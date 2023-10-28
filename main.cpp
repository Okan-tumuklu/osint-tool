#include<iostream>
#include<string>
#include<netdb.h>
#include<unistd.h>
#include"fonc.h"
using namespace std;



int main(void){

	string web_site;
	string exit = "exit";
	
	while(1){
		
	cout << "  ___      _       _              _            _   _      " << endl;
    cout << " / _ \\ ___(_)_ __ | |_    ___  ___(_)_ __ _ __ | |_( )___  " << endl;
    cout << "| | | / __| | '_ \\| __|  / __|/ __| | '__| '_ \\| __|// __| " << endl;
    cout << "| |_| \\__ \\ | | | | |_   \\__ \\ (__| | |  | |_) | |_  \\__ \\ " << endl;
    cout << " \\___/|___/_|_| |_|\\__|  |___/\\___|_|_|  | .__/ \\__| |___/ " << endl;
    cout << "                                        |_|                " << endl;
    cout << " Coder by_ Okan.Tumuklu .." << endl;
    cout << "____________________________" << endl;

	
	cout << "Web-Site (exampile google.com) :";
	getline(cin, web_site);

		
		if(web_site == exit){
				cout << "Exit...\n";
				break;
			}
		else {
				string command = "mkdir " + web_site;
				system(command.c_str());
				
				//for subdomain
				//string subcommand = "gnome-terminal -- /bin/sh -c 'python3 subdomain.py "+web_site+" wordlist.txt > "+web_site+"/subdomain."+web_site+".txt'";
				string subcommand = "gnome-terminal -- /bin/sh -c 'python3 subdomain.py "+web_site+" wordlist.txt'";
				system(subcommand.c_str());
				cout << "Subdomains are being written to a file, please do not close the empty window.\n";

				
				//For whois
				string whois_v = whois(web_site);
				system(whois_v.c_str());
				cout << "Whois finish.\n";
				
				//for dig
				string dig_v = dig(web_site);
				system(dig_v.c_str());
				cout << "Dig finish.\n";
				//for nmap
				string nmap_v = nmap(web_site);
				system(nmap_v.c_str());
				cout << "Nmap finish.\n";
				
				//for nslookup
				string nslookup_v = nslookup(web_site);
				system(nslookup_v.c_str());
				cout << "nslookup finish.\n";
				
				//for http or https
				string url = "https://" + web_site;
				string protocol = DetermineProtocol(web_site);
				
				//for dirb
				string dirb_v = dirb(protocol, web_site);
				system(dirb_v.c_str());
				cout << "The Dirb scan results are being written to a file, please do not close the empty window.\n";
				
				/*
				//for dnsenum
				string dnsenum_v = dnsenum(web_site);
				system(dnsenum_v.c_str());
				cout << "Dnsenum finish.\n";
				*/
				
				sleep(5);
				system("clear");
				
			}
	}



	
	return 0;
}
