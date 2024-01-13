# NDS_Game

This is my work in progress NDS game, it is likely that if you are seeng this it is because I have posted this on a forum in hopes of getting help

MY SOURCES: (just some useful links that I used for dev)
https://github.com/devkitPro/libnds/tree/master/source // libNDS source code, very useful for finding out how/why something works
https://devkitpro.org/viewforum.php?f=38 // Top post about GRIT was pretty neat
https://github.com/WiIIiam278/breaking-bad-ds/tree/main // Pretty cool project I found on youtube, based some of the way I am handling stuff on this

MY ENVIRONMENT:
IDE:
    VS Code
    -if you replicate everything I have regarding "devkitpro", my "c_cpp_properties.json" should give you intellisense on this to some degree(can certainly be improved)
DEVKITPRO CONFIGURATION:
    I have the "nflib" and "nitro-engine" kits both placed in the root of my "devkitpro" installation
    "devkitpro" is installed on the root of my "C" drive

OTHER NOTES:
"TempFolder" is only there for when I want to test something and pretend that a certain file is not in the project since the makefile doesnt look in there
I have already compiled this project on here, in order to compile it yourself you need to:
    -Replicate my environment regarding devkitpro
    -Open CMD in the root of this project and type "make clean", execute this
    -Type "make clean", execute this