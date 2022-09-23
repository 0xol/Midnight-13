CC = gcc

CCFLAGS = -I C:\ray64\raylib-4.2.0\src -Iexternal -Os
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP -Os

#append " -mwindows" to linker flags for release builds / disables console

SRCDIR = core
OBJDIR = bin

all:
	$(CC) -c $(SRCDIR)/init.c -o $(OBJDIR)/init.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/unit.c -o $(OBJDIR)/unit.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/graphics.c -o $(OBJDIR)/graphics.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/texture.c -o $(OBJDIR)/texture.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/map.c -o $(OBJDIR)/map.o $(CCFLAGS)
	$(CC) -c $(SRCDIR)/menu.c -o $(OBJDIR)/menu.o $(CCFLAGS)

	$(CC) $(OBJDIR)/*.o -o main.exe $(LDFLAGS)

debug: all
	main