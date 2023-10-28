# osint-scirpt

Certainly, here is the description and usage guide translated into English:

Project Name: OSINT Tool Guide

Description:
This OSINT (Open Source Intelligence) tool can be used to gather and analyze information related to a website or domain. Please note that the tool saves all scan results in a folder named after the website. Below is a step-by-step guide on how to install and use the tool.

Installation:

First, make the setup.sh file executable by using the following command:
chmod +x setup.sh

Then, run the following command to install the necessary packages:
./setup.sh

Compilation:
To compile the tool, use the following command:
g++ main.cpp -lcurl -o osint_tool


Usage:
To run the tool, use the following command:
./osint_tool

Tool Functions:
This OSINT tool can perform the following functions:

Lists subdomains related to a website.
Uses the Dirb tool to find directories and pages.
Performs a Whois query.
Executes a Dig query.
Conducts an Nmap scan.
Performs an Nslookup query.
Saves all scan results in a folder named after the website.
Notes:

Ensure that the required packages are installed and the compilation process is successful before using the tool's full functionality.
For more in-depth information, documentation, and usage examples related to the project, please review the code
