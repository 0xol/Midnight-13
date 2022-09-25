CC = gcc
CCFLAGS = -I C:\ray64\raylib-4.2.0\src -Iexternal -Os
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP -Os

#append " -mwindows" to linker flags for release builds / disables console

SRCDIR = core
OBJDIR = bin

all: compile
	$(CC) $(OBJDIR)/*.o -o main.exe $(LDFLAGS)

compile:
	$(CC) -c $(SRCDIR)/init.c -o $(OBJDIR)/init.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/unit.c -o $(OBJDIR)/unit.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/graphics.c -o $(OBJDIR)/graphics.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/texture.c -o $(OBJDIR)/texture.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/map.c -o $(OBJDIR)/map.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/menu.c -o $(OBJDIR)/menu.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/sandbox.c -o $(OBJDIR)/sandbox.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/player.c -o $(OBJDIR)/player.o $(CCFLAGS)

debug: all
	main

package: compile
	$(CC) $(OBJDIR)/*.o -o main.exe $(LDFLAGS) -mwindows
	rm package -r
	mkdir package
	
	cp main.exe package/main.exe
	cp textures package/textures -r
	cd package && tar -cf midnight.zip *

	