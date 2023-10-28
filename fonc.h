#include<iostream>
#include<string>
#include<cstring>
#include<curl/curl.h>
#include<fstream>


using namespace std;


string whois(const string web_site){
	string command = "whois " + web_site + " > " + web_site + "/whois." + web_site + ".txt";
	return command;
	}

string dig(const string web_site){
	string command = "dig " + web_site + " > " + web_site + "/dig." + web_site + ".txt";
	return command;
	}

string nmap(const string web_site){
	string command = "nmap -T4 -A -v " + web_site + " > "+web_site+"/nmap."+web_site+".txt";
	return command;
	}

string nslookup(const string web_site){
	string command = "nslookup " + web_site + " > " + web_site + "/nslookup." + web_site + ".txt";
	return command;
	}
	
string DetermineProtocol(const string& url) {
    CURL* curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); 
        CURLcode result = curl_easy_perform(curl);

        if (result == CURLE_OK) {
            curl_easy_cleanup(curl);
            return "https://";
        }

        curl_easy_cleanup(curl);
    }

    return "http://";
}

string dirb(string  protocol, string const web_site){
	string url = protocol + web_site;
	string dirb_command = " gnome-terminal -- /bin/sh -c 'dirb "+protocol+""+web_site+"/'";
	return dirb_command;
	}




/*
string dnsenum(const string web_site){
	string command = "dnsenum " + web_site + " > " + web_site + "/dnsenum." + web_site + ".txt";
	return command;
	}
*/
