Rem path of Google Chrome browser
set BrowserChrome="c:/Program Files (x86)/Google/Chrome/Application/chrome.exe"

Rem path of FireFox browser
set BrowserFireFox="C:\Program Files\Mozilla Firefox\firefox.exe"

Rem the path of directory of loading files
set fileDir=../TestFiles

Rem Patterns of target files
set Patterns= *.cpp *.h

cd .\Debug\
start Executive.exe %BrowserFireFox% %fileDir% %Patterns%
cd ..
