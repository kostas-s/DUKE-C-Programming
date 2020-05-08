all: maxSeq.o test-subseq

maxSeq.o: maxSeq.c
	gcc -c maxSeq.c
test-subseq: test-subseq.c maxSeq.c
	gcc -o test-subseq test-subseq.c maxSeq.c
clean:
	rm maxSeq.o test-subseq.o
