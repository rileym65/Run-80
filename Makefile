OBJECTS=\
	debugger.o\
	evaluate.o \
	main.o\
	mterm.o\
	z80.o \
	z801byte.c \
	z80cb.c \
	z80dd.c \
	z80ed.c \
	z80fd.c \
	z80dis1byte.o\
	z80discb.o\
	z80disdd.o\
	z80dised.o\
	z80disfd.o

DEFS += -DDEDGC

run80:	$(OBJECTS)
	$(CC) $(DEFS) $(OBJECTS) $(LIB_PATH) $(LIBS) -o run80

z80test: z80test.o z80.o z80cb.o z80dd.o z80fd.o z80ed.o z801byte.o
	$(CC) z80test.o z80.o z80cb.o z80dd.o z80fd.o z80ed.o z801byte.o $(LIBS) -o z80test

clean:
	-rm *.o
	-rm trs
	-rm z80test

debugger.o: header.h
main.o: header.h
z801byte.o: header.h
z80.o: z80.h
z80cb.o: z80.h
z80dd.o: z80.h
z80fd.o: z80.h
z80ed.o: z80.h
z80dis1byte.o: z80.h
z80discb.o: z80.h
z80disdd.o: z80.h
z80dised.o: z80.h
z80disfd.o: z80.h
