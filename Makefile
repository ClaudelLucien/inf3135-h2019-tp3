CP= $(shell cat cp.txt)

RAC=-Wall -pedantic -std=c99 -lm

default:tp3


outils.o: outils.h outils.c
	@gcc $(RAC) -c outils.c

structure.o:structure.h structure.c
	@gcc $(RAC) -c structure.c


tp3.o: tp3.c
	@gcc $(RAC) -c tp3.c


tp3: outils.o structure.o tp3.o
	@gcc $(RAC) -o tp3 tp3.o outils.o structure.o

test:

	@for file in data/* ; do ./tp3 -c $(CP) -i $$file -o sortie; done ;


clean:

	
	@rm -f code.txt
	@rm -f *.o
	@rm -f outils.o
	@rm -f tp2
	@rm -rf data.zip
	@rm -f tp3
	@rm -f res.out 
	
data:
	@wget -q  https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip
	unzip data.zip
	mkdir data
	mv data.txt ./data

resultat:
	./tp3 -c CLAL12049707 -i data.txt -o resultat.txt
	git add resultat.txt
	git commit
	git push
