common:
	gcc -c src/main.c -o bin/main.o

static:

	#
	# Create the object files for the static library (without -fPIC)
	#
	gcc -c src/lib/librow.c -o bin/static/librow.o

	#
	# Create static library
	#

	ar rcs bin/static/librow.a bin/static/librow.o

	#
	# Link statically
	#

	gcc bin/main.o -Lbin/static -lrow -lm -o bin/statically-linked

shared:

	#
	# object files for shared libraries need to be compiled as position independent
	# code (-fPIC) because they are mapped to any position in the address space.
	#
	gcc -c -fPIC -lm src/lib/librow.c -o bin/shared/librow.o

	#
	# Create the shared library
	#

	gcc -shared bin/shared/librow.o -o bin/shared/librow.so

	#
	# Link dinamically with the shared library
	#

	gcc bin/main.o -Lbin/shared -lrow -lm -o bin/use-shared-library

clean:
	rm -rf bin/*.o bin/statically-linked bin/use-shared-library
	rm -rf bin/shared/*
	rm -rf bin/static/*