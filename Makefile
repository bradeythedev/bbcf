build:
	cc -o bbcfc bbcfc.c
clean:
	rm bbcfc
	rm bbcfc.o
install:
	chmod +x bbcf
	chmod +x bbcfc
	cp bbcf /usr/bin
	cp bbcfc /usr/bin
nobbcfinstall:
	chmod +x bbcfc
	cp bbcfc /usr/bin
uninstall:
	rm /usr/bin/bbcf
	rm /usr/bin/bbcfc
nobbcfuninstall:
	rm /usr/bin/bbcfc