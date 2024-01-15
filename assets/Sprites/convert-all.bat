@echo off

:: Process all PNG files using grit
for %%F in (*.png) do (
    C:\devkitPro\tools\bin\grit "%%F" -ftb -fh! -gTFF00FF -gb -gB8 -mR8 -mLs
)

:: Rename BIN files (remove .bin extension)
for %%F in (*.bin) do (
    move "%%F" "%%~nF"
)

:: Move PAL, IMG, MAP files to the specified directory
move *.pal *.img C:\devkitPro\examples\nds\MYTESTGAME\nitrofiles\Sprites