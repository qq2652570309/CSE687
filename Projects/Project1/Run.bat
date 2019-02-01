Rem path of browser
set Browser="c:/Program Files (x86)/Google/Chrome/Application/chrome.exe"

Rem the path of directory of loading files
set fileDir=../TestFiles

Rem Patterns of target files
set Patterns= *.cpp *.h

cd .\Debug\
start Executive.exe %Browser% %fileDir% %Patterns%
cd ..
