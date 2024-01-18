@echo off

:: Process all PNG files using grit
for %%F in (*.png *.bmp) do (
    C:\devkitPro\tools\bin\grit "%%F" -ftb -fh! -gTFF00FF -gt -gB8 -mR8 -mLs
)

:: Rename BIN files (remove .bin extension)
for %%F in (*.bin) do (
    move "%%F" "%%~nF"
)

:: Move PAL, IMG, MAP files to the specified directory
move *.pal *.img *.map C:\devkitPro\examples\nds\MYTESTGAME\nitrofiles\Bg