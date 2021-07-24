F1=server
F2=client
SF1=$(F1).c
SF2=$(F2).c
OF1=$(F1).o
OF2=$(F2).o
ALL:server client
server:$(OF1)
	gcc -o server $(OF1) -pthread 
$(OF1):$(SF1) 
	gcc -o $(OF1) $(SF1) -Wall -c -g
client:$(OF2)
	gcc -o client $(OF2) -pthread 
$(OF2):$(SF2) 
	gcc -o $(OF2) $(SF2) -Wall -c -g
 

