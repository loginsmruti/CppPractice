F1=server
F2=client
SF1=$(F1).c
SF2=$(F2).c
OF1=$(F1).o
OF2=$(F2).o
ALL:server client
server:$(OF1)
	gcc -o server $(OF1) 
$(OF1):$(SF1) header.h
	gcc -o $(OF1) $(SF1) -Wall -c -g
client:$(OF2) header.h
	gcc -o client $(OF2) 
$(OF2):$(SF2) 
	gcc -o $(OF2) $(SF2) -Wall -c -g
 

