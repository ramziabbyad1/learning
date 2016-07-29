#Compile and link source file hello.c into exe a.exe
gcc hello.c;

#set permissions (unnessecary for me)
chmod a+x a;

#bash exe with path
./a;

#CMD exe doesn't work for me
#a;

#compile and link with executable name hello
gcc -o hello hello.c;

chmod a+x hello;

./hello;

# hello; doesn't work in CMD

#-g debug info, -o output executable name, -Wall print all warning msgs
g++ -Wall -g -o Hello hello.cpp;
echo "dir listing";
ls -l;
rm Hello.exe;
echo "list after rm";
ls -l;

#compile only with -c
g++ -c -Wall -g hello.cpp;
echo "compile only.. creates .o obj file";
ls -l;
echo "link object files into exe using ld.exe";
g++ -g -o Hello hello.o;
ls -l;

#preprocess using cpp.exe
echo "preprocess using cpp rm old compiled";
rm hello.[^c];
rm Hello.exe;
cpp hello.c > hello.i;
ls -lt | grep hello;
echo "compile pp'ed source code into assembly for my processor";
gcc -S hello.i;
echo "hello.s is assembly code";
ls -lt | grep hello;
echo "Assembly: convert .s to machine code in object file hello.o";
as -o hello.o hello.s;
ls -lt | grep hello;
echo "Linked: ld.exe links obj code with library code to produce executable";
ld -o hello.exe hello.o;
ls -lt | grep hello;
