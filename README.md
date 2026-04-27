**Tool for analyzing sites and detecting pishing sites**

**OUTPUT**





Analyzing: http://192.168.1.1/paypaI-login

[+20] No HTTPS - not encrypted
[+40] TYPO: Common brand impersonation
[+30] IP: Uses raw IP instead of domain

=== RESULT ===
Risk Score: 90/100
VERDICT: DANGER - Likely phishing.










**COMPile & Run**




g++ src/main.cpp -o phishcheck -std=c++11
./phishcheck http://192.168.1.1/paypaI-login
