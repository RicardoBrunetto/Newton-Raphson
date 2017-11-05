all: execute
	@echo "Sucesso!"

compile:
	@pdflatex --interaction=batchmode main

clear: compile
	@rm -f *.synctex.gz
	@rm -f *.aux
	@rm -f *.log
	@rm -f *.out
	@rm -f *.blg
	@rm -f *.bbl

clear_W: compile
	@del *.synctex.gz 2>NUL
	@del *.aux 2>NUL
	@del *.log 2>NUL
	@del *.out 2>NUL
	@del *.blg 2>NUL
	@del *.bbl 2>NUL

execute: clear_W
	@start "" main.pdf
