@ECHO OFF
COLOR 02

REM Tampilkan teks pembuka
ECHO ==============================================
ECHO            ALGORITMA DAN PEMROGRAMAN
ECHO                FAHMI NOOR FIQRI
ECHO ==============================================
ECHO.
ECHO.
ECHO  1. Luas Segi Tiga
ECHO  2. Keliling Segi Lima
ECHO  3. Rerata Data
ECHO  4. Rerata Data menggunakan Array
ECHO.

REM Ambil input
SET /P pilihan=Masukkan pilihan:
ECHO.

REM Cek input, apakah valid?
IF %pilihan% leq 0 GOTO TIDAK_SESUAI
IF %pilihan% geq 5 GOTO TIDAK_SESUAI

REM Siapkan file input
TYPE NUL > input.txt
START /WAIT notepad.exe input.txt

REM Jalankan program
IF %pilihan% == 1 (
    START /B /WAIT segi_tiga.exe
)
IF %pilihan% == 2 (
    START /B /WAIT segi_lima.exe
)
IF %pilihan% == 3 (
    START /B /WAIT rerata.exe
)
IF %pilihan% == 4 (
    START /B /WAIT rerata_array.exe
)

REM Buka output
START output.txt
GOTO SELESAI

REM Blok kode TIDAK_SESUAI
:TIDAK_SESUAI
ECHO.
ECHO Perintah harus antara 1-4.

REM Hentikan program
:SELESAI
ECHO.
PAUSE