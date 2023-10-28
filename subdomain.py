import socket
import sys

def check_host(host, port):
    try:
        sock = socket.create_connection((host, port), timeout=5)
        return True
    except Exception as e:
        return False

def check_subdomains(domain, wordlist):
    with open(wordlist, "r") as subdomains:
        for subdomain in subdomains:
            subdomain = subdomain.strip() + "." + domain
            if check_host(subdomain, 80):
                print("[X] Found subdomain:", subdomain)


if len(sys.argv) < 2:
    #print("Kullanım: python script.py <hedef_site> <wordlist_dosyası>")
    sys.exit(1)

target_domain = sys.argv[1]
wordlist = "wordlist.txt" if len(sys.argv) < 3 else sys.argv[2]

check_subdomains(target_domain, wordlist)
