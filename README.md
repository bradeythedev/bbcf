# bbcf - Bradeythedev's Brain Compiler Fuck

## Installation

#### BBCF was created for Unix-like systems, such as Ubuntu and other Linux distributions. The script `bbcf` relies on the existence of `/bin/sh`, so if you are a Windows user, WSL is probably your best option.

### Releases
To download a release, head to the releases tab and download `bbfc`, `bbcfc`, `install.sh` and `README.md` from your preferred release. When they have been downloaded into a common location, open a terminal in their parent folder and run `chmod +x install.sh && sudo ./install.sh`. If you use an operating system that does not use `sudo`, such as a BSD, you may need to use an alternative command, like `doas`. If you are unsure of your OS's equivalent, you could alternatively run `su` then `./install.sh`. If you do not wish to install the `bbcf` script, and only the `bbcfc` executable, run `./install.sh -s` instead.

### Build from source
To build from source, open a terminal and run `git clone https://github.com/bradeythedev/bbcf`. Now run `cd bbcf` to enter the repo's directory, and then `make` to build it. If you do not wish to install BBCF to your `$PATH`, you are done. However, if you want to be able to use the `bbcf` or `bbcfc` commands from anywhere on your system, you will need to run `sudo make install`. If you do not want to install the `bbcf` script to your `$PATH`, and only the `bbcfc` executable, run `sudo make nobbcfinstall` instead. If your system does not use `sudo`, you may need to use an equivalent in its place, or log in as root with `su`.

If you want to build another version of BBCF, you can use the `make clean` command in the same directory, and `sudo make uninstall` or `sudo make nobbcfuninstall`.

## Using BBCF

### The `bbcf` script
You will notice two executables when you install BBCF, `bbcf` and `bbcfc`. `bbcf` is a shell script (which relies on `sh`) that provides a wrapper for the actual executable - `bbcfc`. This wrapper allows you to use a more familiar compiler syntax: `bbcf FILENAME`. You can use BBCF without this script (by using the `bbcfc` command directly), and you can choose to not install `bbcf` at all.

### Interfacing with `bbcfc` directly
The `bbcfc` executable is the actual brainfuck compiler, but interfacing with it requires your brainfuck code to be piped into it, and it prints the resulting C code to the standard output. This can be achieved in a shell by running `cat FILENAME | bbcfc > OUTPUT.c`. The `bbcf` script runs exactly that command, but it also compiles the C code with the `cc` command.

## Brainfuck

### Language
Brainfuck is an esoteric programming language created in 1993. It is designed to be minimal, and uses only 8 characters to interact with memory.

### Implementation
BBCF allocates a 1024 character array for every brainfuck program, which the program is free to use as it wishes. Each character that represents a brainfuck instruction ('<', '>', '-', '+', '.', ',', '[', ']') has a static definition in the form of a function (with the exception of '[' and ']'). In the outputted C code, the respective functions are defined, and called from the main() function. '[' and ']', however, is simply a `while` loop, that will continue looping until the value it checks is equivalent to zero.

## The future of BBCF

### Current state
BBCF is in what is most likely its final form. I have one potential feature set that is yet to be included, but it is unlikely I will continue BBCF's development. BBCF was intended as a simple project that would allow me to learn some C, learn something about compilers, and take a look at brainfuck.

### Contributing
That being said, I will accept pull requests for bug fixes, however, I will most likely NOT accept pull requests for feature updates. If you think BBCF has more potential (for some reason), then feel free to fork it and continue development yourself.

Thanks for visiting the repo - *and don't forget to star BBCF because the more stars your repo has, the cooler you are (and I want to look cool obviously)*