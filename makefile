all:
	python3 make.py

#debug using sh not cmd
debugsh: all
	./midnight

debugwin:
	build
	midnight